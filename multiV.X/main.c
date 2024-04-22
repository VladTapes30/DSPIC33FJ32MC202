#include "system.h"
#include "ADC.h"
#include <libpic30.h>

float READ;
uint16_t READ2;//ESCALAR PARA ELIMMINAR EL PUNTO DECIMAL
char C,D,DU,U;
int main()
{
    TRISB = 0x0000;
    adc_init();
    
    while(1)
    {
       // READ  = ((ADC_Read(AN0))*(3.3))/ 4095;
        READ = (ADC_Read(AN0))*(0.000805);
        READ2 = READ * 100;
        //PORTB =  READ2;
       // __delay_ms(100);
        C = READ2 / 100;
        DU = READ2 - (C*100);
        D = DU /10;
        U = DU - (D*10);
             /*MANDANDO LA DECENA PRIMERO Y DESACTIVANDO EL DIGITO DE UNIDADES*/
        LATB = C & 0x000f;
        LATBbits.LATB4 = 1;//MUESTRO EL DIGITO DE LAS DECENAS
        LATBbits.LATB7 = 1;
        __delay_ms(50);
        LATBbits.LATB4 = 0;//APAGO EL DIGITO DE DECENAS
             /*MANDANDO LA DECENA PRIMERO Y DESACTIVANDO EL DIGITO DE UNIDADES*/
        LATB = D & 0x000f;
        LATBbits.LATB5 = 1;//MUESTRO EL DIGITO DE LAS DECENAS
        __delay_ms(50);
        LATBbits.LATB5 = 0;//APAGO EL DIGITO DE DECENAS
             /*MANDANDO LA DECENA PRIMERO Y DESACTIVANDO EL DIGITO DE UNIDADES*/
        LATB = U & 0x000f;
        LATBbits.LATB6 = 1;//MUESTRO EL DIGITO DE LAS DECENAS
        __delay_ms(50);
        LATBbits.LATB6 = 0;//APAGO EL DIGITO DE DECENAS
    }
    return 1;
}
