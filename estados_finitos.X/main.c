#include "system.h"
#include"uart_int.h"
#include<libpic30.h>

#define off 0
#define on  1

typedef enum
{
    led_on_state,
            led_off_state
}led_states;

unsigned int estados;//uint16_t // char = uint8_t // float = uint32_t

int main()
{
    TRISBbits.TRISB0 = 0;
    /*estado inicial o arranque*/
    estados = led_on_state;
    
    while (1) 
    {
        switch (estados)
        {
            case led_on_state:
                PORTBbits.RB0 = on;
                __delay_ms(2000);
                estados = led_off_state;
                break;
            case led_off_state:
                PORTBbits.RB0 = off;
                __delay_ms(2000);
                break;
        }    
    }
    return 0;
}
