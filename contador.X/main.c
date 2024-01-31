#include "system.h"
#include <libpic30.h>

uint8_t i; 

int main()
{
//    TRISBbits.TRISB0 = 0;
//    TRISBbits.TRISB1 = 0;
//    TRISBbits.TRISB2 = 0;
//    TRISBbits.TRISB3 = 0;
//    TRISBbits.TRISB4 = 0;
//    TRISBbits.TRISB5 = 0;
//    TRISBbits.TRISB6 = 0;
//    TRISBbits.TRISB7 = 0;
    TRISB = 0x0000; // 0B 0000 0000 0000 0000
    LATB  = 0;
    while(1)
    {
        for(i = 0 ; i<=255 ; i++)
        {
            LATB = i;
            __delay_ms(300);
        }
    }
}
