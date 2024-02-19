#include"system.h"
#include<libpic30.h>
#include <p33FJ32MC202.h>
//prototipos
void led0_toogle();
void led1_toogle();

int main()
{
    
    
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