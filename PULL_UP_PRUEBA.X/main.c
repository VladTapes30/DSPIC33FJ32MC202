#include"system.h"
#include<libpic30.h>

int main ()
{
    //configurando como entradas
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    TRISAbits.TRISA4 = 1;
    TRISBbits.TRISB10 = 1;
    ////////////
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    //configurando como digitales
    AD1PCFGLbits.PCFG0 =1;//AN0
    AD1PCFGLbits.PCFG1 =1;//AN1
    AD1PCFGLbits.PCFG2 =1;//AN2
    AD1PCFGLbits.PCFG3 =1;//AN3
    AD1PCFGLbits.PCFG4 =1;//AN4
    AD1PCFGLbits.PCFG5 =1;//AN5
    //CONFIGURACION DE PULL_UP
    CNPU1bits.CN2PUE  = 1;
    CNPU1bits.CN3PUE  = 1;
    CNPU2bits.CN30PUE = 1;
    CNPU2bits.CN29PUE = 1;
    CNPU1bits.CN0PUE  = 1;
    CNPU2bits.CN16PUE = 1;
    while (1)
    {
        
      /*  LATBbits.LATB0 = PORTAbits.RA0;
        LATBbits.LATB1 = PORTAbits.RA1;
        LATBbits.LATB4 = PORTAbits.RA2;
        LATBbits.LATB5 = PORTAbits.RA3;
        LATBbits.LATB6 = PORTAbits.RA4;*/
    }
    return 0;
}
