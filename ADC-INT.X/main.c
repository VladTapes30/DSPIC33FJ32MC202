#include "system.h"
#include "uart_int.h"
#include "ADC.h"
#include <stdio.h>
#include <libpic30.h>

void ADC1_Result();

int main() 
{
    adc_init();
    UART_init();
    ADC1_SetInterruptHandler(ADC1_Result);
    while (1) 
    {
        /*PROGRAMA REPETITIVO*/
        
    }
    return 0;
}

void ADC1_Result()
{
    printf("el valor del adc es: %u",ADC_Read(0));
}