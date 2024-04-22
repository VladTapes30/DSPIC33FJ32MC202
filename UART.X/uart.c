#include"system.h"

#define BAUDRATE 9600

void UART_init()
{
    //tx pin --- pin de trasmision
    TRISBbits.TRISB8 = 0;//in 1  out 0// salida
    RPOR4bits.RP8R   = 0b11;//asiganando con pps tx del uart 1
    
    //rx pin --- pin de resepcion
    TRISBbits.TRISB9 = 1;//entrada
    RPINR18bits.U1RXR = 9;//tabla del pps pagina 133
                          //asignando rb9 como rx del uart1
    
    /*configuracion de uart*/
    U1MODEbits.UARTEN = 0;//apagar
    U1MODEbits.STSEL  = 0;//bit de stop
    U1MODEbits.PDSEL  = 0;//solo data sin pariedad
    U1MODEbits.BRGH   = 0;//elegir la velocidad 16 clock
    
    U1BRG = (uint16_t)((FCY/16/BAUDRATE)-1);//casteo
    
    U1STAbits.UTXEN   = 1; //habilitar trasmicion pin
    U1MODEbits.UARTEN = 1; //encender uart
}

void UART_putc (char c)//trasmitir un caracter por medio de pintx
{
    while(U1STAbits.UTXBF == 1);
    U1TXREG = c;
}

void UART_puts (char *s)
{
    while(*s)
        UART_putc(*s++);
}

//char x;  char *p;
//x = 5;   p = &x;
//scanf("%d",&pedro);


