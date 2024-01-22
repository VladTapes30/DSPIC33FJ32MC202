
#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FOSC 10000000UL // 10MHZ // La UL es usined long
#define FCY  FOSC/2     // Este es la frecuencia maquina, por cada 2 pulsos
                        //tenemos un cyclo maquina
#include<xc.h>          //esta es la biblioteca del cristal


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

