
#include <p33FJ32MC202.h>


void ext_int0_init()//inicializar la interrupcion
{
    /**
     * flag *** te dice si la interrucion a sucedido
     * enable *** prender y apagar 
     * projority *** prioridad de interrupcion
     */
    IFS0bits.INT0IF    = 0;//resetiar la bandera
    IPC0bits.INT0IP    = 1;//prioridad mayor a cpu
    INTCON2bits.INT0EP = 0;//flanco de bajada (+ -)
    TRISBbits.TRISB7   = 1;//entrada la int0
    CNPU2bits.CN23PUE  = 1;//pull-up activar
    IEC0bits.INT0IE    = 1;//encender interrupcion externa 0
}
void ext_int1_init()//inicializar la interrupcion
{
    /**
     * flag *** te dice si la interrucion a sucedido
     * enable *** prender y apagar 
     * projority *** prioridad de interrupcion
     */
    IFS1bits.INT1IF    = 0;//resetiar la bandera
    IPC5bits.INT1IP    = 1;//prioridad mayor a cpu
    INTCON2bits.INT1EP = 0;//flanco de bajada (+ -)
    RPINR0bits.INT1R   = 8;//0b1000 utilizando el pps
    TRISBbits.TRISB8   = 1;//entrada
    CNPU2bits.CN22PUE  = 1;//pull-up activar
    IEC1bits.INT1IE    = 1;//encender interrupcion externa 0
}

void __attribute__ ((interrupt)) _INT0Interrupt (void)
{
    
}