#include "system.h"
#include "timers.h"
#include<libpic30.h>

//prototipos
void func();

int main() 
{
    TRISBbits.TRISB0 = 0;
    
    Timer1_init();
    T1_SetInterrupHandler(func);
    while (1) 
    {
        
    }
    return 0;
}

void func()
{
    LATBbits.LATB0 = !LATBbits.LATB0;
}