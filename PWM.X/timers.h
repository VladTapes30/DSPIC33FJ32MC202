/* 
 * File:   timers.h
 * Author: achem
 *
 * Created on 17 de mayo de 2024, 12:45 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif
//prototipos
void Timer1_init();

void T1_SetInterrupHandler (void(*InterrupHandler)(void));


#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

