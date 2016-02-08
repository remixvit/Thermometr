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
#define Timer_Display_Print 3

extern void HDC1050_Get_Temp_And_Humi();
extern void HDC1050_Request_Conversion();
extern volatile uint8 VideoMemory[Video_Memory_Size];
volatile uint8 ActionFlag = 0;
volatile uint8 Simofor = 0;
volatile uint8 Counter = 0;
volatile uint8 Video_Pointer = 0;

void HDC_Put_Result();
void HDC_Start_Convert();
void Display_Print();


void HDC_Put_Result()
{
	HDC1050_Get_Temp_And_Humi();
    Display_Set_Video_Memory();
    System_Timer_Add(Timer_Sensor_Request, Second);
}

void HDC_Start_Convert()
{
	HDC1050_Request_Conversion();
	System_Timer_Add(Timer_Sensor_Get_Temp, Second);
}

void Display_Print()
{
    if(VideoMemory[Video_Pointer] == Symbol_Stop)
    {
        Video_Pointer = 0;
    }
	Display_Scroll_Video_Memory(Video_Pointer);
}


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    System_Timer_Start();
    SCB_2_Start();
    HDC1050_Request_Conversion();
    CyDelay(100);
    HDC1050_Get_Temp_And_Humi();
    Init_Video_Memory();
    Display_Set_Video_Memory();
    LED_SEG_PWM_Start();
    LED_SEG_PWM_WriteCompare2(225);
    SCB_1_Start();
	System_Timer_Add(Timer_Display_Scroll, Second);
	HDC_Start_Convert();
    System_Timer_Add(Timer_Display_Print, 1);
	System_Timer_Add(Timer_Display_Scroll, Second);
	HDC_Start_Convert();
    for(;;)
    {
        if(System_Timer_Flag[Timer_Display_Scroll].Flag == 1)
        {
            System_Timer_Flag[Timer_Display_Scroll].Flag = 0;
			Video_Pointer++;
            System_Timer_Add(Timer_Display_Scroll, Second);
        }
        
        if(System_Timer_Flag[Timer_Sensor_Request].Flag == 1)
        {
            System_Timer_Flag[Timer_Sensor_Request].Flag = 0;
            HDC_Start_Convert();
        }
        
        if(System_Timer_Flag[Timer_Sensor_Get_Temp].Flag == 1)
        {
            System_Timer_Flag[Timer_Sensor_Get_Temp].Flag = 0;
            HDC_Put_Result();
        }
        
		if(System_Timer_Flag[Timer_Display_Print].Flag == 1)
        {
            System_Timer_Flag[Timer_Display_Print].Flag = 0;
			Display_Print();
            System_Timer_Add(Timer_Display_Print, 1);
        }
    }
}

/* [] END OF FILE */
