#include"system.h"
#include<libpic30.h>

int main()
{   
    TRISBbits.TRISB0 = 0;//LA PALABRA BITS ES PARA EXPECIFICAR EL BIT (NO AFECTAR OTRO)
    TRISAbits.TRISA0 = 1;
    //COMO TIENE UNA FUNCION POR DEFECTO ANALOGICO
    //TENGO QUE INDICAR QUE VA A SER DIGITAL+
    //EN ALGUNOS MICROS SE HACE CON LOS REGISTOS ANSEL PERO EN EL CASO DEL
    //DSPIC SE HACE CON LOS REGISTRO AD1PCFGL (ESTA EN LA HOJA DE DATO)
    //HAY UN BIT PARA CADA ENTRADA ANALOGICA
    
    /*ANX = PCFGX donde X es 0 hasta 5(MC202), de 0 a 8 para (MC304)
     *CADA PIN ANX CORRESPONDE A UN BIT DE PCFGX DEL REGISTRO AD1PCFGL
     * 
     * LA HOJA DE DATOS EXPECIFICA QUE SI LO PONES EN 1 SON PINES DIGITALES Y SI
     * ESTA EN 0 SON PINS ANALOGICOS (POR DEFECTO ESTAN EN 0X00)
     *AN0 = PCFG0
     *AN1 = PCFG1
     *AN2 = PCFG2
      ...
     AN5  = PCFG5
     */
    AD1PCFGLbits.PCFG0 = 1;//configuracion de pin analogo como digital
    CNPU1bits.CN2PUE  = 1;//habilito resistencia pull up en RA0/CN2
    /*en el esquematico del sdpic las siglas cn significan que puedes
      activar resistencias pull up si las necesitas
      con el registro  CNPU, ahi vas ha encontrar uan espeficica
      para tu cn en este caso CNPU2 = CN pull up 2*/
    while(1)
    {
        //CON PORT HACEMOS LECTURA DE PUERTOS SEGUN EL DATA
        if (PORTAbits.RA0 == 0)//(PORTAbits.RA0 == 0)
            LATBbits.LATB0 = 1;//led on
        else
            LATBbits.LATB0 = 0;//led off
    }
    return 0;
}
