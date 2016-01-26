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

volatile const uint32 HDC1050_Slave_Adress = 0x40;
volatile int8 Temp = 10;
volatile uint8 Humi = 10;

void HDC1050_Get_Temp_And_Humi();
void HDC1050_Request_Conversion();


void HDC1050_Request_Conversion(){
    uint8 Request[] = {0};
    SCB_2_I2CMasterClearStatus();
    SCB_2_I2CMasterWriteBuf(HDC1050_Slave_Adress, Request, 1, SCB_2_I2C_MODE_COMPLETE_XFER);
    while((SCB_2_I2CMasterStatus() & SCB_2_I2C_MSTAT_WR_CMPLT) == 0){}
}

void HDC1050_Get_Temp_And_Humi(){
    uint8 Bufer[4];
    SCB_2_I2CMasterClearStatus();
    SCB_2_I2CMasterReadBuf(HDC1050_Slave_Adress, Bufer, 4, SCB_2_I2C_MODE_COMPLETE_XFER);
    while((SCB_2_I2CMasterStatus() & SCB_2_I2C_MSTAT_RD_CMPLT) == 0){}
    SCB_2_I2CMasterClearStatus();
    Temp = ((((Bufer[0] << 8) + Bufer[1]) * 165 + 0x8000) >> 16) - 40;
    Humi = (((Bufer[2] << 8) + Bufer[3]) * 100 + 0x8000) >> 16;
}
/* [] END OF FILE */
