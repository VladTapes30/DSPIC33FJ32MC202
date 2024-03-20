#include"system.h"
#include"ADC.h"
#include <stdio.h>
#include <libpic30.h>

uint16_t lectura_adc;
int main()
{
    TRISB = 0x0000;
    adc_init();
    while(1)
    {
        lectura_adc = ADC_Read(0);
        PORTB = lectura_adc;
        __delay_ms(100);
    }
    return 0;
}
