/* 
 * File:   system.h
 * Author: achem
 *
 * Created on 10 de agosto de 2023, 09:57 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define FOSC 10000000UL // 10MHZ // La UL es usined long
#define FCY  FOSC/2     // Este es la frecuencia maquina, por cada 2 pulsos
                        //tenemos un cyclo maquina
#include<xc.h>          //esta es la biblioteca del cristal
#include <libpic30.h>

    typedef enum
    {
        POLLING,
                INTERRUPTION
    }SYSTEM_STATE;
    
    void SYSTEM_Initialize(SYSTEM_STATE state);
#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

