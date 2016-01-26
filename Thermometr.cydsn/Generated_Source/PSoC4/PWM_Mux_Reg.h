/*******************************************************************************
* File Name: PWM_Mux_Reg.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_PWM_Mux_Reg_H) /* CY_CONTROL_REG_PWM_Mux_Reg_H */
#define CY_CONTROL_REG_PWM_Mux_Reg_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} PWM_Mux_Reg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    PWM_Mux_Reg_Write(uint8 control) ;
uint8   PWM_Mux_Reg_Read(void) ;

void PWM_Mux_Reg_SaveConfig(void) ;
void PWM_Mux_Reg_RestoreConfig(void) ;
void PWM_Mux_Reg_Sleep(void) ; 
void PWM_Mux_Reg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define PWM_Mux_Reg_Control        (* (reg8 *) PWM_Mux_Reg_Sync_ctrl_reg__CONTROL_REG )
#define PWM_Mux_Reg_Control_PTR    (  (reg8 *) PWM_Mux_Reg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_PWM_Mux_Reg_H */


/* [] END OF FILE */
