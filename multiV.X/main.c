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
        READ2 = READ * 100;//lectura de adc por 100 para eliminar el punto
        LATB = READ2;
             
        C = READ2 / 100; //centenas
        DU = READ2 - (C*100);
        D = DU /10;//decenas
        U = DU - (D*10);//unidades
        
        /*MANDANDO LA CENTENAS PRIMERO*/
        LATB = C & 0x000f;
        LATBbits.LATB4 = 1;//DIGITO DE LAS CENTENAS
        LATBbits.LATB7 = 1;//PUNTO DECIMAL EN EL DISPLAY
        __delay_ms(50);
        LATBbits.LATB4 = 0;//APAGAR LAS CENTENAS
           
        /*MANDANDO LA DECENA PRIMERO*/
        LATB = D & 0x000f;
        LATBbits.LATB5 = 1;//DECENAS ON
        __delay_ms(50);
        LATBbits.LATB5 = 0;//DECENAS OFF
            
        /*MANDANDO LA UNIDADES*/
        LATB = U & 0x000f;
        LATBbits.LATB6 = 1;//UNIDADES ON
        __delay_ms(50);
        LATBbits.LATB6 = 0;//UNIDADES OFF
    }
    return 1;
}
