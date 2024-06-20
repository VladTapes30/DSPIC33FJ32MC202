#include "system.h"
#include "btn.h"
#include "leds.h"
#include "app_switch_led.h"
#include <stdbool.h>

void app_switch_led()
{
    if (btn_Ispressed(SW1) == 0)
    {
        LED_ENC(LGREEN);
    }
    else
    {
        LED_APA(LGREEN);
    }
    /*ES LO MISMO SOLO QUE UTILIZANDO OPERADORES*/
    (btn_Ispressed(SW2)) ? LED_APA(LRED) : LED_ENC(LRED);
}
