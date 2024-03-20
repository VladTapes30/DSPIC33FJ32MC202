#include "system.h"
#include "ADC.h"
#include <libpic30.h>
float READ;
uint16_t READ2;
int main()
{
    TRISB = 0x0000;
    adc_init();
    
    while(1)
    {
       // READ  = ((ADC_Read(AN0))*(3.3))/ 4095;
        READ = (ADC_Read(AN0))*(0.000805);
        READ2 = READ * 100;
        PORTB =  READ2;
        __delay_ms(100);
    }
    return 1;
}
