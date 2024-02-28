#include "system.h"
#include "interrupcion.h"
#include <libpic30.h>

void incremento();//prototipos

char contador = 0;
char cont_u = 0;
char cont_d = 0;

int main()
{
    TRISB = 0x0000;//0b0000 0000 1000 0000
    
    ext_int0_init();//inicializacion de la interrupcion
    
    int0_set_int_head(incremento);//callback para interrupcion
    //HAL --- HARDWARE ABTACTI LAYER
    
    while(1)
    {
        LATB = (contador<<8) & 0xff00;
        //contador = 5 
        //0000 0000 0000 0101
        //0000 0101 0000 0000
        //1111 1111 0000 0000
        //0000 0101 0000 0000
        cont_d = (contador / 10);
        cont_u = (contador - (cont_d * 10));
              
    }
    return 0;
}

void incremento()
{
    if ((contador >= 0)&&(contador <= 99))
    contador += 1;   //contador ++  
    //(contador >= 0)&&(contador <= 99) ?  contador += 1 : contador += 0;
}
