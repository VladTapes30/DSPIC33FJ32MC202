#include "system.h"
#include "btn.h"
#include <stdbool.h>
#include <p33FJ32MC202.h>

#define BTN1_TRIS  TRISBbits.TRISB2
#define BTN2_TRIS  TRISBbits.TRISB3

#define BTN1_PORT  PORTBbits.RB2
#define BTN2_PORT  PORTBbits.RB3

#define PU_BTN1    CNPU1bits.CN6PUE
#define PU_BTN2    CNPU1bits.CN7PUE

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
           // PU_BTN1   = PU_ENABLE;
            break;
        case SW2:
            BTN2_TRIS = INPUT;
           // PU_BTN2   = PU_ENABLE;
            break;
    }
}

bool btn_Ispressed(button btn)
{
    switch(btn)
    {
        case SW1:
            return ((BTN1_PORT == BTN_PRESSED) ? true : false);
            
        case SW2:
            return ((BTN2_PORT == BTN_PRESSED) ? true : false);
    }
    return true;
}
