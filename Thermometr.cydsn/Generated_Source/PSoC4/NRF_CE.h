/*******************************************************************************
* File Name: NRF_CE.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_NRF_CE_H) /* Pins NRF_CE_H */
#define CY_PINS_NRF_CE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NRF_CE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NRF_CE_Write(uint8 value) ;
void    NRF_CE_SetDriveMode(uint8 mode) ;
uint8   NRF_CE_ReadDataReg(void) ;
uint8   NRF_CE_Read(void) ;
uint8   NRF_CE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NRF_CE_DRIVE_MODE_BITS        (3)
#define NRF_CE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NRF_CE_DRIVE_MODE_BITS))

#define NRF_CE_DM_ALG_HIZ         (0x00u)
#define NRF_CE_DM_DIG_HIZ         (0x01u)
#define NRF_CE_DM_RES_UP          (0x02u)
#define NRF_CE_DM_RES_DWN         (0x03u)
#define NRF_CE_DM_OD_LO           (0x04u)
#define NRF_CE_DM_OD_HI           (0x05u)
#define NRF_CE_DM_STRONG          (0x06u)
#define NRF_CE_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NRF_CE_MASK               NRF_CE__MASK
#define NRF_CE_SHIFT              NRF_CE__SHIFT
#define NRF_CE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NRF_CE_PS                     (* (reg32 *) NRF_CE__PS)
/* Port Configuration */
#define NRF_CE_PC                     (* (reg32 *) NRF_CE__PC)
/* Data Register */
#define NRF_CE_DR                     (* (reg32 *) NRF_CE__DR)
/* Input Buffer Disable Override */
#define NRF_CE_INP_DIS                (* (reg32 *) NRF_CE__PC2)


#if defined(NRF_CE__INTSTAT)  /* Interrupt Registers */

    #define NRF_CE_INTSTAT                (* (reg32 *) NRF_CE__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NRF_CE_DRIVE_MODE_SHIFT       (0x00u)
#define NRF_CE_DRIVE_MODE_MASK        (0x07u << NRF_CE_DRIVE_MODE_SHIFT)


#endif /* End Pins NRF_CE_H */


/* [] END OF FILE */
