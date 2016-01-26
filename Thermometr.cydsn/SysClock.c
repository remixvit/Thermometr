/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "SysClock.h"

void System_Timer_Start()
{
    LED_SEG_PWM_Start();
    Timer_Interrupt_StartEx(System_Timer_ISR);
    volatile uint8_t Scroll = 0;
    for(Scroll = 0; Scroll < MAX_Number_Of_Sys_Timer; Scroll++)
    {
        System_Timer[Scroll].Number = 255;
        System_Timer[Scroll].Time = 0;
        System_Timer_Flag[Scroll].Flag = 0;
    }
}
void System_Timer_Add(uint8 New_Number, uint32 New_Time)
{
    CyGlobalIntDisable;
    volatile uint8 i;
    for(i = 0; i < MAX_Number_Of_Sys_Timer; i++)
    {
        if(System_Timer[i].Number == New_Number)
        {
            System_Timer[i].Time = New_Time;
            System_Timer_Flag[New_Number].Flag = 0;
            CyGlobalIntEnable;
            return;
        }
    }
    for(i = 0; i < MAX_Number_Of_Sys_Timer; i++)
    {
        if(System_Timer[i].Number == 255)
        {
            System_Timer[i].Number = New_Number;
            System_Timer[i].Time = New_Time;
            System_Timer_Flag[New_Number].Flag = 0;
            CyGlobalIntEnable;
            return;
        }
    }
    CyGlobalIntEnable;
 }

void System_Timer_Remove(uint8 Number)
{
    CyGlobalIntDisable;
    volatile uint8 i;
    for(i = 0; i < 10; i++)
    {
        if(System_Timer[i].Number == Number)
        {
            System_Timer[i].Number = 255;
            System_Timer_Flag[Number].Flag = 0;
            CyGlobalIntEnable;
            break;
        }
    }
    CyGlobalIntEnable;
}

CY_ISR(System_Timer_ISR)
{
    CyGlobalIntDisable;
    volatile uint8 i;
    for(i = 0; i < MAX_Number_Of_Sys_Timer; i++)
    {
        if(System_Timer[i].Number == 255) continue;
        if(System_Timer[i].Time != 0)
        {
            System_Timer[i].Time--;
        }
        else
        {
            System_Timer_Flag[System_Timer[i].Number].Flag = 1;
            System_Timer[i].Number = 255;
        }
    }
    CyGlobalIntEnable;
}

//////////////////////////////////

/* [] END OF FILE */
