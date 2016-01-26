/*******************************************************************************
* File Name: NRF_IRQ_ISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_NRF_IRQ_ISR_H)
#define CY_ISR_NRF_IRQ_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void NRF_IRQ_ISR_Start(void);
void NRF_IRQ_ISR_StartEx(cyisraddress address);
void NRF_IRQ_ISR_Stop(void);

CY_ISR_PROTO(NRF_IRQ_ISR_Interrupt);

void NRF_IRQ_ISR_SetVector(cyisraddress address);
cyisraddress NRF_IRQ_ISR_GetVector(void);

void NRF_IRQ_ISR_SetPriority(uint8 priority);
uint8 NRF_IRQ_ISR_GetPriority(void);

void NRF_IRQ_ISR_Enable(void);
uint8 NRF_IRQ_ISR_GetState(void);
void NRF_IRQ_ISR_Disable(void);

void NRF_IRQ_ISR_SetPending(void);
void NRF_IRQ_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the NRF_IRQ_ISR ISR. */
#define NRF_IRQ_ISR_INTC_VECTOR            ((reg32 *) NRF_IRQ_ISR__INTC_VECT)

/* Address of the NRF_IRQ_ISR ISR priority. */
#define NRF_IRQ_ISR_INTC_PRIOR             ((reg32 *) NRF_IRQ_ISR__INTC_PRIOR_REG)

/* Priority of the NRF_IRQ_ISR interrupt. */
#define NRF_IRQ_ISR_INTC_PRIOR_NUMBER      NRF_IRQ_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable NRF_IRQ_ISR interrupt. */
#define NRF_IRQ_ISR_INTC_SET_EN            ((reg32 *) NRF_IRQ_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the NRF_IRQ_ISR interrupt. */
#define NRF_IRQ_ISR_INTC_CLR_EN            ((reg32 *) NRF_IRQ_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the NRF_IRQ_ISR interrupt state to pending. */
#define NRF_IRQ_ISR_INTC_SET_PD            ((reg32 *) NRF_IRQ_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the NRF_IRQ_ISR interrupt. */
#define NRF_IRQ_ISR_INTC_CLR_PD            ((reg32 *) NRF_IRQ_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_NRF_IRQ_ISR_H */


/* [] END OF FILE */
