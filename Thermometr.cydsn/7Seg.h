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
#include <Project.h>

#define Number_Of_Segments 4
#define Video_Memory_Size 17
#define LCD_SPI_SS_Number 0
#define Refresh_Time 200

#define Symbol_minus 0xBF
#define Symbol_C 0xC6
#define Symbol_H 0x89
#define Symbol_T 0x87
#define Symbol_Degrees 0x9C
#define Symbol_Procent 0xA3
#define Symbol_Space 0xFF


void Display_Test_1(void);
void Display_Test_2(void);
void Init_Video_Memory();
void Display_Write_Numer(uint8 Number, uint8 Segment);
void Display_Write_Mem(void);
void Display_Scroll_Video_Memory(void);
void Display_Set_Video_Memory(void);

/* [] END OF FILE */
