/* 
 * File:   leds.h
 * Author: achem
 *
 * Created on 6 de junio de 2024, 09:31 AM
 */

#ifndef LEDS_H
#define	LEDS_H

#ifdef	__cplusplus
extern "C" {
#endif
    typedef enum
    {
        LGREEN,
                LRED
    }COLOR_LED;

/*prototipos*/
void LED_ENABLE (COLOR_LED LED);
void LED_ENC (COLOR_LED LED);
void LED_APA (COLOR_LED LED);

#ifdef	__cplusplus
}
#endif

#endif	/* LEDS_H */

