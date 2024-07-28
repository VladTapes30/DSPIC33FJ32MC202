#include "system.h"
#include "ADC.h"
#include "uart_int.h"
#include <libpic30.h>
#include <stdio.h>

#define SAMPLES 2
#define k       3
typedef struct
{
    uint16_t adc;
    uint16_t n[SAMPLES];
}input;

input x;
uint16_t y;
uint16_t read_adc;

int main() 
{
    adc_init();
    UART_init();
    int i;
    printf("iniciando el muestreo 3s\r\n");
    __delay_ms(3000);
    
    while (1) 
    {
        for (i=0; i<8; i++)
        {
            /*submuestreo  x(k*n)*/
            x.adc  = ADC_Read(AN0);//OBTENIENDO LA LECTURA DEL ADC
            x.n[0] = x.adc;//asignando nuestra señal a x(n)cuando n vale 0
            
            printf("señal x(%u)= %u\r\n ",i,x.n[0]);//señal de referencia
            
            if ((i % k) == 0)
            {
               y = x.n[0];
            
               printf("-------------> x (%u * k) = %u \r\n",i,y);
               __delay_ms(200); 
            }
        }
        printf("\r\n-----------------------------\r\n");
    }
    return 0;
}

