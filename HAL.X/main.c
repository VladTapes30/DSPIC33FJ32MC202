#include "bsp/system.h"
#include "bsp/app_switch_led.h"
#include "bsp/btn.h"
#include "bsp/leds.h"
#include <libpic30.h>

int main()
{
    /*INICIALIZANDO BOTONES*/
    BTN_ENABLE(SW1);
    BTN_ENABLE(SW2);
    /*INICIALIZANDO LEDS*/
    LED_ENABLE(LRED);
    LED_ENABLE(LGREEN);
            
    while (1) 
    {
        app_switch_led();
        
    }
    return 0;
}
