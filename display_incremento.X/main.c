#include "system.h"
#include "interrupcion.h"
#include <libpic30.h>
#include <p33FJ32MC202.h>

void incremento();//prototipos

char contador = 0;
char cont_u = 0;
char cont_d = 0;

int main()
{
    TRISB = 0x0000;//0b0000 0000 1000 0000
    
    ext_int0_init();//INICIALIZANDO LA CUNFIGURACION DE LAS INTERRUPCIONES
    
    int0_set_int_head(incremento);//callback para interrupcion
    //HAL --- HARDWARE ABTACTI LAYER CON PUNTEROS A FUNCION
    
    while(1)
    {
        //LATB = (contador<<8) & 0xff00;
        //contador = 5 
        //0000 0000 0000 0101
        //0000 0101 0000 0000
        //1111 1111 0000 0000
        //0000 0101 0000 0000
        
        /*SEPARACION EN DECENAS Y UNIDADES*/
        cont_d = (contador / 10);//decenas
        cont_u = (contador - (cont_d * 10));//unidades
        
        /*MANDANDO LA DECENA PRIMERO Y DESACTIVANDO EL DIGITO DE UNIDADES*/
        LATB = cont_d & 0x000f;
        LATBbits.LATB4 = 1;//MUESTRO EL DIGITO DE LAS DECENAS
        __delay_ms(50);
        LATBbits.LATB4 = 0;//APAGO EL DIGITO DE DECENAS
        
        LATB = cont_u & 0x000f;
        LATBbits.LATB5 = 1;//MUESTRO EL DIGITO DE LAS UNIDADES
        __delay_ms(50);
        LATBbits.LATB5 = 0;//APAGO EL DIGITO DE LAS UNIDADES
    }
    return 0;
}

void incremento()
{
    if ((contador >= 0)&&(contador < 99)) contador += 1;   //contador ++ 
    else contador = 0;
    //(contador >= 0)&&(contador < 99) ?  contador += 1 : contador = 0;
    //esta es una opcion con el operador condicional
}
