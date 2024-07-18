/* 
 * File:   system.h
 * Author: achem
 *
 * Created on 10 de agosto de 2023, 11:16 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include<xc.h>          //esta es la biblioteca del cristal
    
#define FOSC 10000000UL // 10MHZ // La UL es usined long
#define FCY  FOSC/2     // Este es la frecuencia maquina, por cada 2 pulsos
                        //tenemos un cyclo maquina




#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

