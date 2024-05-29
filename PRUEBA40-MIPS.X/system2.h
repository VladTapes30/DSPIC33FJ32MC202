/* 
 * File:   system2.h
 * Author: achem
 *
 * Created on 27 de abril de 2024, 12:27 AM
 */

#ifndef SYSTEM2_H
#define	SYSTEM2_H

#ifdef	__cplusplus
extern "C" {
#endif

/*agregando prueba*/
//#define Fin 10000000UL
//#define clock_m 32
//#define clock_n1 2
//#define clock_n2 2

#define FOSC 80000000UL
    ///////////////////////////
//#define FOSC 10000000UL // 10MHZ // La UL es usined long
#define FCY  FOSC/2     // Este es la frecuencia maquina, por cada 2 pulsos
                        //tenemos un cyclo maquina
#include<xc.h>          //esta es la biblioteca del cristal

/*modificar la formula de fosc, porque es diferente con los 40 mips
 en el data esta la formula pagina 103*/

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM2_H */

