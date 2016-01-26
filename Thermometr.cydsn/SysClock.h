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
#include <project.h>
#define MAX_Number_Of_Sys_Timer 5
#define Timer_Flag_MCU_Sleep 0
#define Timer_Flag_Check_Shield 1
#define Timer_Flag_NRF_Send_Packet 2
#define Timer_Flag_Check_Button 4

#define Second 3921
#define Minute (Second*60)
#define Hour 3600000



#define On 1
#define Off 0

volatile typedef struct
{
    volatile uint8 Number;
    volatile uint32 Time;
} System_Timer_Main_Struct[MAX_Number_Of_Sys_Timer];
volatile typedef struct
{
    uint8 Flag;
} System_Timer_Flag_Struct[MAX_Number_Of_Sys_Timer];

System_Timer_Flag_Struct System_Timer_Flag;
System_Timer_Main_Struct System_Timer;
void System_Timer_Add(uint8 New_Number, uint32 New_Time);
void System_Timer_Remove(uint8 Number);
void System_Timer_Start();

CY_ISR(System_Timer_ISR);

/////////////////////////////////

/* [] END OF FILE */
