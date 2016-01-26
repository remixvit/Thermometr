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

#include <7Seg.h>
#include <stdlib.h>

volatile const uint8 Font[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
volatile uint8 VideoBufer[Number_Of_Segments];
volatile uint8 VideoMemory[Video_Memory_Size];
extern int8 Temp;
extern uint8 Humi;

void Display_Test_1()
{
    volatile uint8 Scroll = 0;
    volatile uint8 Symbol = 0;
    SCB_1_SpiSetActiveSlaveSelect(LCD_SPI_SS_Number);
    for(Scroll = 0; Scroll < 4; Scroll++)
    {
        PWM_Mux_Reg_Write(Scroll);
        for(Symbol = 0; Symbol < 10; Symbol++)
        {
            SCB_1_SpiUartWriteTxData(Font[Symbol]);
            while (0u != (SCB_1_SpiUartGetTxBufferSize() + SCB_1_GET_TX_FIFO_SR_VALID))
            {
            }
            CyDelay(500);
        }
    }
}
void Display_Test_2()
{
    volatile uint8 Scroll = 0;
    volatile uint8 Symbol = 5;
    volatile uint8 Brigh = 0;
    SCB_1_SpiSetActiveSlaveSelect(LCD_SPI_SS_Number);
    while(1)
    {
        PWM_Mux_Reg_Write(Scroll);
        LED_SEG_PWM_WriteCompare2(Brigh);
        SCB_1_SpiUartWriteTxData(Font[Symbol]);
        while (0u != (SCB_1_SpiUartGetTxBufferSize() + SCB_1_GET_TX_FIFO_SR_VALID))
        {
        }
        Scroll++;
        if(Scroll > 4)
        {
            Scroll = 0;
            Brigh++;
        }
    }
}

void Init_Video_Memory()
{
    volatile uint8 Scroll;
    for(Scroll = 0; Scroll < Video_Memory_Size; Scroll++)
    {
        VideoMemory[Scroll] = 0x00;
    }
}

void Display_Write_Numer(uint8 Number, uint8 Segment)
{
    if((Number < 10) && (Segment < Number_Of_Segments))
    {
        PWM_Mux_Reg_Write(Segment);
        SCB_1_SpiUartWriteTxData(Font[Number]);
        while (0u != (SCB_1_SpiUartGetTxBufferSize() + SCB_1_GET_TX_FIFO_SR_VALID))
        {
        }
    }
}

void Display_Set_Video_Memory(void)
{
    volatile uint8 Scroll = 0;
    VideoMemory[Scroll] = Symbol_T;
    Scroll++;
    VideoMemory[Scroll] = Symbol_Space;
    Scroll++;
    
        if(Temp < 0)
        {
            VideoMemory[Scroll] = Symbol_minus;
            Scroll++;
        }
        if(abs(Temp) > 10)
        {
            VideoMemory[Scroll] = Font[(abs(Temp)) / 10];
            Scroll++;
            VideoMemory[Scroll] = Font[(abs(Temp)) % 10];
            Scroll++;
        }
        else
        {
            VideoMemory[Scroll] = Font[Temp];
            Scroll++;
        }
    
    VideoMemory[Scroll] = Symbol_Degrees;
    Scroll++;
    VideoMemory[Scroll] = Symbol_C;
    Scroll++;
    VideoMemory[Scroll] = Symbol_Space;
    Scroll++;
    VideoMemory[Scroll] = Symbol_H;
    Scroll++;
    VideoMemory[Scroll] = Symbol_Space;
    Scroll++;
    
        if(Humi > 10)
        {
            VideoMemory[Scroll] = Font[Humi / 10];
            Scroll++;
            VideoMemory[Scroll] = Font[Humi % 10];
            Scroll++;
        }
        else
        {
            VideoMemory[Scroll] = Font[Humi];
            Scroll++;
        }
        VideoMemory[Scroll] = Symbol_Degrees;
        Scroll++;
        VideoMemory[Scroll] = Symbol_Procent;
        Scroll++;
}

void Display_Scroll_Video_Memory(void)
{
    volatile uint8 Scroll = 0;
    for(Scroll = 0; Scroll < 4; Scroll++)
    {
        VideoBufer[Scroll] = VideoMemory[Scroll];
    }
    for(Scroll = 0; Scroll < 16; Scroll++)
    {
        VideoMemory[Scroll] = VideoMemory[Scroll+1];
    }
}

void Display_Write_Mem(void)
{
    volatile uint8 Scroll;
    for(Scroll = 0; Scroll < 4; Scroll++)
    {
        if(VideoBufer[Scroll] == 0)
        {
            VideoBufer[Scroll] = Symbol_Space;
        }
            SCB_1_SpiUartWriteTxData(VideoBufer[Scroll]);
            while (0u != (SCB_1_SpiUartGetTxBufferSize() + SCB_1_GET_TX_FIFO_SR_VALID))
            {
            }
            PWM_Mux_Reg_Write(Scroll);
            CyDelayUs(Refresh_Time);
    }
}

/* [] END OF FILE */
