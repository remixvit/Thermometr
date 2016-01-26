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
#include <7Seg.h>
#include <SysClock.h>

#define Timer_Display_Scroll 0
#define Timer_Sensor_Request 1
#define Timer_Sensor_Get_Temp 2

extern void HDC1050_Get_Temp_And_Humi();
extern void HDC1050_Request_Conversion();
volatile uint8 ActionFlag = 0;
volatile uint8 Simofor = 0;
volatile uint8 Counter = 0;




int main()
{
    volatile uint8 Watcher = 0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    System_Timer_Start();
    SCB_2_Start();
    HDC1050_Request_Conversion();
    CyDelay(100);
    HDC1050_Get_Temp_And_Humi();
    Init_Video_Memory();
    Display_Set_Video_Memory();
    Display_Scroll_Video_Memory();
    LED_SEG_PWM_Start();
    LED_SEG_PWM_WriteCompare2(200);
    SCB_1_Start();
    System_Timer_Add(Timer_Display_Scroll, Second);
    System_Timer_Add(Timer_Sensor_Request, (Second*25));
    for(;;)
    {
        if(System_Timer_Flag[Timer_Display_Scroll].Flag == 1)
        {
            System_Timer_Flag[Timer_Display_Scroll].Flag = 0;
            Display_Scroll_Video_Memory();
            Watcher++;
            if(Watcher == Video_Memory_Size)
            {
                Display_Set_Video_Memory();
                Watcher = 0;
            }
            System_Timer_Add(Timer_Display_Scroll, Second);
        }
        
        if(System_Timer_Flag[Timer_Sensor_Request].Flag == 1)
        {
            System_Timer_Flag[Timer_Sensor_Request].Flag = 0;
            HDC1050_Request_Conversion();
            System_Timer_Add(Timer_Sensor_Get_Temp, Second);
        }
        
        if(System_Timer_Flag[Timer_Sensor_Get_Temp].Flag == 1)
        {
            System_Timer_Flag[Timer_Sensor_Get_Temp].Flag = 0;
            HDC1050_Get_Temp_And_Humi();
            System_Timer_Add(Timer_Sensor_Request, (Second*2));
        }
        Display_Write_Mem();
    }
}

/* [] END OF FILE */
