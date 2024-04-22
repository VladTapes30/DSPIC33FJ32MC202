#include"system.h"
#include"stdio.h"
#include "uart.h"
#include<libpic30.h>

const uint8_t str[13]="VLADIMIR 58\r\n";

int main()
{
    UART_init();
    while(1)
    {
        UART_puts(str);
        __delay_ms(500);
       printf("%s",str); 
       
    }
}
/*IMPLEMENTAR EN LA PRACTICA DE ADC*/