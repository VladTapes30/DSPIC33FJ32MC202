#include"system.h"

void I2C1_Init(uint16_t fscl)
{
    float delay  = 0.00000012;
    float i2cbrg = (((1/fscl)-delay)*FCY)-2;
    I2C1BRG = i2cbrg;
    I2C1CONbits.I2CEN = 1;
}

void I2C1_Start(void)
{
    I2C1CONbits.SEN = 1;
    while(I2C1CONbits.SEN == 1); //espero a que finalice el star
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

void I2C1_Write_Addr_Slave(uint8_t addr,uint8_t dir)
{
    I2C1TRN = (addr & 0b11111110) | (dir & 0b00000001);//enmascarando para cortar el registro porque la direccion solo es del bit 1 al 7 y el otro el l bit 0
    while(I2C1STATbits.TRSTAT);//esperando que se termine la carga   
}

void I2C1_Write_Data(uint8_t data)
{
    I2C1TRN = data;
    while(I2C1STATbits.TRSTAT);//ESPERAMOS A QUE FINALICE LA TRASMIION DE LS DATOS
}
