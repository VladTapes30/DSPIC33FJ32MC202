#include "system.h"
#include <libpic30.h>

#define MAX 0x80//directivas//macros

uint8_t i;
int main()
{
    TRISB = 0xFF00;//1111 1111 0000 0000
    LATB  = 0x0001;//0000 0000 0000 0001
    while(1)
    {
        for(i=0; i != MAX ; i++)//80 = decimal 0x80 = hexadecimal
        {
             __delay_ms(200);
            LATB = LATB<<1;
             __delay_ms(200);
        }    
    }
}
