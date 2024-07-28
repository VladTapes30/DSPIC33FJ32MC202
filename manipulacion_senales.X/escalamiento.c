#include "system.h"
#include "ADC.h"
#include "uart_int.h"
#include <libpic30.h>
#include <stdio.h>

#define SAMPLES 2
#define alfa    0.5L
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
            /*escalamiento alfa * x(n)*/
            x.adc = ADC_Read(AN0);//OBTENIENDO LA LECTURA DEL ADC
            x.n[0] = x.adc;       //asignando la entra a x(n) donde n es 0 
            y = (alfa)* x.n[0];      //escalando la señal
            
            printf("muestra actual= %u ---> desplazamiento = %u \r\n",x.adc,y);
            __delay_ms(200);
        }
        printf("\r\n-----------------------------\r\n");
    }
    return 0;
}
