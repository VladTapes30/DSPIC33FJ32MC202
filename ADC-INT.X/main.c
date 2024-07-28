#include "system.h"
#include "uart_int.h"
#include "ADC.h"
#include <stdio.h>
#include <libpic30.h>

void ADC1_Result();

uint16_t adc_result;

int main() 
{
    adc_init();
    UART_init();
    ADC1_SetInterruptHandler(ADC1_Result);
    while (1) 
    {
        /*PROGRAMA REPETITIVO*/
        adc_result = ADC_Read(AN0);
       //printf("%u\r\n",adc_result);
        __delay_ms(200);
    }
    return 0;
}

void ADC1_Result()
{
    printf("el valor del adc es: %u\r\n",ADC_Read(0));
    __delay_ms(200);
        
}