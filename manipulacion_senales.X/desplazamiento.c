#include "system.h"
#include "ADC.h"
#include "uart_int.h"
#include <libpic30.h>
#include <stdio.h>

#define SAMPLES 2
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
    printf("iniciando el muestreo 3s");
    __delay_ms(3000);
    
    while (1) 
    {
        for (i=0; i<8; i++)
        {
            x.adc = ADC_Read(AN0);//OBTENIENDO LA LECTURA DEL ADC

            x.n[1] = x.n[0]; //GUARDANDO MUESTRA ANTERIOR
            x.n[0] = x.adc;  //ASIGNANDO MUESTRA ACTUAL
            /**
             * x.n[0] = 6;
             * x.n[1] = 5;
             * @return 
             */
            y = x.n[1]; //salida de la muestra desplazada
            printf("muestra actual= %u ---> desplazamiento = %u \r\n",x.adc,y);
            __delay_ms(200);
        }
    }
    return 0;
}
