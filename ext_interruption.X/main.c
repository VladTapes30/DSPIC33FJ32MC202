#include"system.h"
#include "interrupcion.h"
#include<libpic30.h>
#include <p33FJ32MC202.h>
//prototipos
void led0_toogle();
void led1_toogle();
void led2_toogle();

int main()
{
    //declarar como salida rbo rb1
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    
    ext_int0_init();//INICIA CONFI DE INT0
    ext_int1_init();//INICIO CONFI DE INT1
    
    int0_set_int_head(led0_toogle);
    int1_set_int_head(led1_toogle);
    
    while(1)
    {
        
    }
    return 0;
}

void led0_toogle()
{
  LATBbits.LATB0 = !LATBbits.LATB0;  
}
void led1_toogle()
{
    LATBbits.LATB1 = !LATBbits.LATB1;
}
void led2_toogle()
{
    LATBbits.LATB2 = !LATBbits.LATB2;
}