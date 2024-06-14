#include "system.h"
#include "leds.h"

#define LED_GREEN_TRIS TRISBbits.TRISB0
#define LED_RED_TRIS   TRISBbits.TRISB1

#define LED_GREEN_LAT  LATBbits.LATB0
#define LED_RED_LAT    LATBbits.LATB1

#define OUTPUT 0
#define INPUT  1

#define LED_ON  1
#define LED_OFF 0

void LED_ENABLE (COLOR_LED LED)
{
    /*FUNCION PARA DEFINIER SI ES ENTRADA O SALIDA*/
    switch (LED)
    {
        case LGREEN:
            LED_GREEN_TRIS = OUTPUT;
            break;
        case LRED:
            LED_RED_TRIS = OUTPUT;
            break;     
        case LNONE:
            break;
    }
}
void LED_ENC (COLOR_LED LED)
{
    /*FUNCION PARA ENCENDER*/
    switch(LED)
    {
        case LGREEN:
            LED_GREEN_LAT = LED_ON;
            break;
        case LRED:
            LED_RED_LAT   = LED_ON;
            break;
        case LNONE:
            break;
    }
}
void LED_APA (COLOR_LED LED)
{
    switch(LED)
    {
        case LGREEN:
            LED_GREEN_LAT = LED_OFF;
            break;
        case LRED:
            LED_RED_LAT   = LED_OFF;
            break;
        case LNONE:
            break;
    }
}