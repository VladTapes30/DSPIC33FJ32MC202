#include "system2.h"
#include <libpic30.h>


int main()
{
     /*configuracion del PLL*/
    CLKDIVbits.PLLPRE  = 0;
    PLLFBDbits.PLLDIV  = 0x1E;
    CLKDIVbits.PLLPOST = 0;
    
    TRISB = 0X0000;
    
    while(1)
    {
        LATBbits.LATB0 = 1;
        __delay_ms(300);
        LATBbits.LATB0 = 0;
        __delay_ms(300);
    }
    return 0;
}