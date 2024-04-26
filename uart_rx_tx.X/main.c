#include"system.h"
#include "uart_int.h"
#include<libpic30.h>
#include <stdio.h>

typedef enum
{
    A_LETTER = 'A',
    B_LETTER,
    C_LETTER,
    D_LETTER,
    E_LETTER,
    NONE
}STATES;

STATES ESTADOS = NONE;
uint8_t charRx;
unsigned char h = 55;
void __attribute__ ((interrupt,no_auto_psv))_U1RXInterrupt(void)
{
    IFS0bits.U1RXIF = 0;
    if (U1STAbits.OERR == 1)
        U1STAbits.OERR = 0;
    else if ((U1STAbits.FERR == 0) && (U1STAbits.PERR == 0))
    {
        charRx = (uint8_t)(U1RXREG);
        ESTADOS = charRx;
    }
}

int main()
{
    UART_init();
    while(1)
    {
      switch(ESTADOS)
      {
            case 'A':
                //UART_puts("Letra A recibida\r\n");
                printf("HOLA TU NUMERO ES: %u \r\n",h);
                ESTADOS = NONE;
            break;
            case 'B':
                UART_puts("Letra B recibida\r\n");
                ESTADOS = NONE;
            break;
            case 'C':
                UART_puts("Letra C recibida\r\n");
                ESTADOS = NONE;
            break;
            case 'D':
                UART_puts("Letra D recibida\r\n");
                ESTADOS = NONE;
            break;
            case 'E':
                UART_puts("Letra E recibida\r\n");
                ESTADOS = NONE;
            break;
            case NONE:
                Sleep();//bajo consumo de energia
                //no utilizar en prctica examen
            break;
      }
    }
    return 0;
}
