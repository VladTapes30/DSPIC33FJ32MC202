#include "system.h"
#include<libpic30.h>

//PROTOTIPOS
void RED_LED();
void GREEN_LED();

void (*pf)(void); // punteros a funcion
int main()
{
    TRISB = 0xFFF0;//1111 1111 1111 0000
    pf = GREEN_LED;
    pf();
    while(1)
    {
        
    }
}

void RED_LED()
{
    LATBbits.LATB0 = 1;
}

void GREEN_LED()
{
    LATBbits.LATB1 = 1;
}