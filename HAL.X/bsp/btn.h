/* 
 * File:   btn.h
 * Author: achem
 *
 * Created on 6 de junio de 2024, 09:35 AM
 */

#ifndef BTN_H
#define	BTN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdbool.h>
    
    typedef enum
    {
        SW1,
        SW2,
                SW_NONE
    }button;
    
void BTN_ENABLE(button btn);
bool btn_Ispressed(button btn);

#ifdef	__cplusplus
}
#endif

#endif	/* BTN_H */

