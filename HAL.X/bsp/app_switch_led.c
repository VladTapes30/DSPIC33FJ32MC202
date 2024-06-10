#include "../bsp/system.h"
#include "app_switch_led.h"
#include "btn.h"
#include "leds.h"
#include <stdbool.h>

void app_switch_led()
{
    if (btn_Ispressed(SW1))
    {
        LED_ENC(LGREEN);
    }
    else
    {
        LED_APA(LGREEN);
    }
    /*ES LO MISMO SOLO QUE UTILIZANDO OPERADORES*/
    (btn_Ispressed(SW2)) ? LED_ENC(LRED) : LED_APA(LRED);
}
