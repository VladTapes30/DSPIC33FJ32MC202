#include "system.h"
#include "i2c.h"
#include <libpic30.h>


int main() 
{
    uint8_t counter = 0;
    I2C1_Init(100);
    while (1) 
    {
        I2C1_Start();
        I2C1_Write_Addr_Slave(0x40, I2C_Write);
        I2C1_Write_Data(counter);
        I2C1_Stop();
        
        counter++;
        if(counter == 256)
            counter = 0;
        __delay_ms(400);
        
    }
    return 0;
}
