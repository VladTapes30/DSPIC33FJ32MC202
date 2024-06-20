#include "bsp/system.h"
#include "bsp/app_switch_led.h"
#include "bsp/btn.h"
#include "bsp/leds.h"
#include <libpic30.h>

int main()
{
    SYSTEM_Initialize(POLLING);
    while (1) 
    {
        app_switch_led();
    }
    return 0;
}
