#include "system.h"
#include <libpic30.h>

int main ()
{
    TRISBbits.TRISB0 = 0;
    
    while(1)
    {
        LATBbits.LATB0 = 0;
        __delay_ms(500);
        LATBbits.LATB0 = 1;
        __delay_ms(500);
    }
}
