/*******************************************************************************
* File Name: NRF_IRQ.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "NRF_IRQ.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NRF_IRQ_PC =   (NRF_IRQ_PC & \
                                (uint32)(~(uint32)(NRF_IRQ_DRIVE_MODE_IND_MASK << (NRF_IRQ_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NRF_IRQ_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NRF_IRQ_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void NRF_IRQ_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NRF_IRQ_DR & (uint8)(~NRF_IRQ_MASK));
    drVal = (drVal | ((uint8)(value << NRF_IRQ_SHIFT) & NRF_IRQ_MASK));
    NRF_IRQ_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NRF_IRQ_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NRF_IRQ_DM_STRONG     Strong Drive 
*  NRF_IRQ_DM_OD_HI      Open Drain, Drives High 
*  NRF_IRQ_DM_OD_LO      Open Drain, Drives Low 
*  NRF_IRQ_DM_RES_UP     Resistive Pull Up 
*  NRF_IRQ_DM_RES_DWN    Resistive Pull Down 
*  NRF_IRQ_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NRF_IRQ_DM_DIG_HIZ    High Impedance Digital 
*  NRF_IRQ_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NRF_IRQ_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NRF_IRQ__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NRF_IRQ_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro NRF_IRQ_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NRF_IRQ_Read(void) 
{
    return (uint8)((NRF_IRQ_PS & NRF_IRQ_MASK) >> NRF_IRQ_SHIFT);
}


/*******************************************************************************
* Function Name: NRF_IRQ_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 NRF_IRQ_ReadDataReg(void) 
{
    return (uint8)((NRF_IRQ_DR & NRF_IRQ_MASK) >> NRF_IRQ_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NRF_IRQ_INTSTAT) 

    /*******************************************************************************
    * Function Name: NRF_IRQ_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 NRF_IRQ_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NRF_IRQ_INTSTAT & NRF_IRQ_MASK);
		NRF_IRQ_INTSTAT = maskedStatus;
        return maskedStatus >> NRF_IRQ_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
