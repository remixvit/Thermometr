/*******************************************************************************
* File Name: NRF_IRQ.h  
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

#if !defined(CY_PINS_NRF_IRQ_H) /* Pins NRF_IRQ_H */
#define CY_PINS_NRF_IRQ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NRF_IRQ_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NRF_IRQ_Write(uint8 value) ;
void    NRF_IRQ_SetDriveMode(uint8 mode) ;
uint8   NRF_IRQ_ReadDataReg(void) ;
uint8   NRF_IRQ_Read(void) ;
uint8   NRF_IRQ_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NRF_IRQ_DRIVE_MODE_BITS        (3)
#define NRF_IRQ_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NRF_IRQ_DRIVE_MODE_BITS))

#define NRF_IRQ_DM_ALG_HIZ         (0x00u)
#define NRF_IRQ_DM_DIG_HIZ         (0x01u)
#define NRF_IRQ_DM_RES_UP          (0x02u)
#define NRF_IRQ_DM_RES_DWN         (0x03u)
#define NRF_IRQ_DM_OD_LO           (0x04u)
#define NRF_IRQ_DM_OD_HI           (0x05u)
#define NRF_IRQ_DM_STRONG          (0x06u)
#define NRF_IRQ_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NRF_IRQ_MASK               NRF_IRQ__MASK
#define NRF_IRQ_SHIFT              NRF_IRQ__SHIFT
#define NRF_IRQ_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NRF_IRQ_PS                     (* (reg32 *) NRF_IRQ__PS)
/* Port Configuration */
#define NRF_IRQ_PC                     (* (reg32 *) NRF_IRQ__PC)
/* Data Register */
#define NRF_IRQ_DR                     (* (reg32 *) NRF_IRQ__DR)
/* Input Buffer Disable Override */
#define NRF_IRQ_INP_DIS                (* (reg32 *) NRF_IRQ__PC2)


#if defined(NRF_IRQ__INTSTAT)  /* Interrupt Registers */

    #define NRF_IRQ_INTSTAT                (* (reg32 *) NRF_IRQ__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NRF_IRQ_DRIVE_MODE_SHIFT       (0x00u)
#define NRF_IRQ_DRIVE_MODE_MASK        (0x07u << NRF_IRQ_DRIVE_MODE_SHIFT)


#endif /* End Pins NRF_IRQ_H */


/* [] END OF FILE */
