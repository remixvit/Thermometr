/*******************************************************************************
* File Name: SCB_2_PM.c
* Version 3.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SCB_2.h"
#include "SCB_2_PVT.h"

#if(SCB_2_SCB_MODE_I2C_INC)
    #include "SCB_2_I2C_PVT.h"
#endif /* (SCB_2_SCB_MODE_I2C_INC) */

#if(SCB_2_SCB_MODE_EZI2C_INC)
    #include "SCB_2_EZI2C_PVT.h"
#endif /* (SCB_2_SCB_MODE_EZI2C_INC) */

#if(SCB_2_SCB_MODE_SPI_INC || SCB_2_SCB_MODE_UART_INC)
    #include "SCB_2_SPI_UART_PVT.h"
#endif /* (SCB_2_SCB_MODE_SPI_INC || SCB_2_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(SCB_2_SCB_MODE_UNCONFIG_CONST_CFG || \
   (SCB_2_SCB_MODE_I2C_CONST_CFG   && (!SCB_2_I2C_WAKE_ENABLE_CONST))   || \
   (SCB_2_SCB_MODE_EZI2C_CONST_CFG && (!SCB_2_EZI2C_WAKE_ENABLE_CONST)) || \
   (SCB_2_SCB_MODE_SPI_CONST_CFG   && (!SCB_2_SPI_WAKE_ENABLE_CONST))   || \
   (SCB_2_SCB_MODE_UART_CONST_CFG  && (!SCB_2_UART_WAKE_ENABLE_CONST)))

    SCB_2_BACKUP_STRUCT SCB_2_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: SCB_2_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_2_Sleep(void)
{
#if(SCB_2_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SCB_2_SCB_WAKE_ENABLE_CHECK)
    {
        if(SCB_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_2_I2CSaveConfig();
        }
        else if(SCB_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_2_EzI2CSaveConfig();
        }
    #if(!SCB_2_CY_SCBIP_V1)
        else if(SCB_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_2_SpiSaveConfig();
        }
        else if(SCB_2_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_2_UartSaveConfig();
        }
    #endif /* (!SCB_2_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        SCB_2_backup.enableState = (uint8) SCB_2_GET_CTRL_ENABLED;

        if(0u != SCB_2_backup.enableState)
        {
            SCB_2_Stop();
        }
    }

#else

    #if (SCB_2_SCB_MODE_I2C_CONST_CFG && SCB_2_I2C_WAKE_ENABLE_CONST)
        SCB_2_I2CSaveConfig();

    #elif (SCB_2_SCB_MODE_EZI2C_CONST_CFG && SCB_2_EZI2C_WAKE_ENABLE_CONST)
        SCB_2_EzI2CSaveConfig();

    #elif (SCB_2_SCB_MODE_SPI_CONST_CFG && SCB_2_SPI_WAKE_ENABLE_CONST)
        SCB_2_SpiSaveConfig();

    #elif (SCB_2_SCB_MODE_UART_CONST_CFG && SCB_2_UART_WAKE_ENABLE_CONST)
        SCB_2_UartSaveConfig();

    #else

        SCB_2_backup.enableState = (uint8) SCB_2_GET_CTRL_ENABLED;

        if(0u != SCB_2_backup.enableState)
        {
            SCB_2_Stop();
        }

    #endif /* defined (SCB_2_SCB_MODE_I2C_CONST_CFG) && (SCB_2_I2C_WAKE_ENABLE_CONST) */

#endif /* (SCB_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SCB_2_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SCB_2_Wakeup(void)
{
#if(SCB_2_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SCB_2_SCB_WAKE_ENABLE_CHECK)
    {
        if(SCB_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            SCB_2_I2CRestoreConfig();
        }
        else if(SCB_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SCB_2_EzI2CRestoreConfig();
        }
    #if(!SCB_2_CY_SCBIP_V1)
        else if(SCB_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            SCB_2_SpiRestoreConfig();
        }
        else if(SCB_2_SCB_MODE_UART_RUNTM_CFG)
        {
            SCB_2_UartRestoreConfig();
        }
    #endif /* (!SCB_2_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != SCB_2_backup.enableState)
        {
            SCB_2_Enable();
        }
    }

#else

    #if (SCB_2_SCB_MODE_I2C_CONST_CFG  && SCB_2_I2C_WAKE_ENABLE_CONST)
        SCB_2_I2CRestoreConfig();

    #elif (SCB_2_SCB_MODE_EZI2C_CONST_CFG && SCB_2_EZI2C_WAKE_ENABLE_CONST)
        SCB_2_EzI2CRestoreConfig();

    #elif (SCB_2_SCB_MODE_SPI_CONST_CFG && SCB_2_SPI_WAKE_ENABLE_CONST)
        SCB_2_SpiRestoreConfig();

    #elif (SCB_2_SCB_MODE_UART_CONST_CFG && SCB_2_UART_WAKE_ENABLE_CONST)
        SCB_2_UartRestoreConfig();

    #else

        if(0u != SCB_2_backup.enableState)
        {
            SCB_2_Enable();
        }

    #endif /* (SCB_2_I2C_WAKE_ENABLE_CONST) */

#endif /* (SCB_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */