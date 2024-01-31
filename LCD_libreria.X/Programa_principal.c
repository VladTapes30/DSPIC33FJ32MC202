#include "system.h"
#include <libpic30.h>
#include "Configuracion.h"
#include "LCD_Libreria.h"

void main() {
    LCD_Init();
    TRISBbits.TRISB8 = 0;
    while(1){
        LCD_XY(0,0);
        LCD_Cadena("vladimir");
        __delay_ms(100);
        //LCD_XY(1,5);
        //LCD_Cadena("=D");
        //__delay_ms(100);
        
        LATBbits.LATB8 = 1;
        __delay_ms(100);
        LATBbits.LATB8 = 0;
        __delay_ms(100);
        
    }
}
