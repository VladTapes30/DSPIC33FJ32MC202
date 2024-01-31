/* 
 * File:   system.h
 * Author: achem
 *
 * Created on 24 de enero de 2024, 08:19 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FOSC 10000000UL //CISTRAL DE 10MHZ
#define FCY FOSC/2 //CICLO DE INTRUCCION O CICLO MAQUINA
#include <xc.h>
    
#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

