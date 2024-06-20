#include "system.h"
#include <stdio.h>
#include "ADC.h"
#include "uart_int.h"
#include <libpic30.h>


typedef struct
{
    uint32_t Ladc;//dato del adc
    uint16_t Lescal;//temperatura
}sensor_lm35;

int main() 
{
    sensor_lm35 lm35_adc;
    
    adc_init();
    UART_init();
    
    
    while (1) 
    {
        lm35_adc.Ladc = ADC_Read(AN0);
        /*ADC ES 12 POR LO TATANTO
         4095 = 3.3V
         * LM35 ----> 1.5 = 150°C
         * 1.5*4095/3.3 = 1861.36 ---> 1861
         * 0V  ---> 0 DATA      ---> 0°C
         * 1.5V ---> 1861 DATOS ---> 150°C
         */
        /*haciendo el escalamiento*/
        lm35_adc.Lescal = (lm35_adc.Ladc * 150UL) / 1861UL;
        //lm35_adc.Lescal = (lm35_adc.Ladc / 12.4); //opcion
        
        //PORTB = (uint16_t)lm35_adc.Lescal;
        
        printf("la lectura del adc = %u\r\n",(uint16_t)lm35_adc.Ladc);
        printf("la temperatura es  = %u\r\n",lm35_adc.Lescal);
        __delay_ms(500);
    }
    return 0;
}