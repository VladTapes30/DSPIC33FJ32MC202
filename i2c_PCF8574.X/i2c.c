#include "system.h"

void I2C1_Init(uint16_t fscl)
{
    float delay  = 0.00000012;  //120ns delay
    float i2cbrg = (((1/fscl)-delay)*FCY)-2;
    I2C1BRG = i2cbrg;
    I2C1CONbits.I2CEN = 1;
}

void I2C1_Start(void)
{
    I2C1CONbits.SEN = 1;
    while(I2C1CONbits.SEN == 1);  //espera a que finalice la condicion de start
}
void I2C1_Restart(void)
{
    I2C1CONbits.RSEN = 1;
    while(I2C1CONbits.RSEN == 1);
}
void I2C1_Stop(void)
{
    I2C1CONbits.PEN = 1;
    while(I2C1CONbits.PEN == 1);
}
void I2C1_Write_Addr_Slave(uint8_t addr, uint8_t dir)
{
    I2C1TRN = (addr & 0b11111110) | (dir & 0b00000001);
    while(I2C1STATbits.TRSTAT);  //esperamos a que finalice la transmision del master
}
void I2C1_Write_Data(uint8_t data)
{
    I2C1TRN = data;
    while(I2C1STATbits.TRSTAT);  //esperamos a que finalice la transmision del master
}