#include "system.h"
#include <p33FJ32MC202.h>
#include "btn.h"
#include <stdbool.h>


#define BTN1_TRIS  TRISBbits.TRISB5 //CAMBIO POR LA SIMULACION
#define BTN2_TRIS  TRISBbits.TRISB6

#define BTN1_PORT  PORTBbits.RB5
#define BTN2_PORT  PORTBbits.RB6

#define PU_BTN1    CNPU2bits.CN27PUE
#define PU_BTN2    CNPU2bits.CN24PUE

#define INPUT 1
#define OUTPUT 0

#define PU_ENABLE  1
#define PU_DISABLE 0

#define BTN_PRESSED 1
#define BTN_DISPRESSED 0

void BTN_ENABLE(button btn)
{
    /*inicializacion de los botones*/
    switch (btn)
    {
        case SW1:
            BTN1_TRIS = INPUT;
            PU_BTN1   = PU_ENABLE;
            break;
        case SW2:
            BTN2_TRIS = INPUT;
            PU_BTN2   = PU_ENABLE;
            break;
        case SW_NONE:
            break;
    }
}

bool btn_Ispressed(button btn)
{
    switch(btn)
    {
        case SW1:
            return (BTN1_PORT == BTN_PRESSED) ? true : false;
            
        case SW2:
            return (BTN2_PORT == BTN_PRESSED) ? true : false;
        case SW_NONE:
            break;
    }
}
