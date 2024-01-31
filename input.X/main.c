#include "system.h"
#include <libpic30.h>

int main ()
{
    TRISBbits.TRISB0 = 0;//salida led
    TRISAbits.TRISA0 = 1;//entrada
    
    AD1PCFGLbits.PCFG0 = 1;// pin AN0 COMO DIGITAL
    CNPU1bits.CN2PUE = 1;//activar resistencias pull-up
    while(1)
    {
        if (PORTAbits.RA0 == 0)
        {
            LATBbits.LATB0 = 1;
            __delay_ms(100);
        }
        else
        {
            LATBbits.LATB0 = 0;
        }
    }
}

