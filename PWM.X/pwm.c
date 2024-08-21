
#include <p33FJ32MC202.h>

#define TIMER_P 50000
uint16_t duty;

void PWM_Init()
{ 
    T2CONbits.TON    = 0;//APAGANDO TIMER 2
    /*mapping*/
    TRISBbits.TRISB8 = 0;
    RPOR4bits.RP8R   = 0b10010;//mapiando la salida a rb8
    OC1CONbits.OCM   = 0;//limpiamos registro
    /*
     * PWM Period = [(PRy) + 1] ? TCY ? (TMRy Prescale Value)
     * 52KHZ = [PR2+1]*(2/10MHZ)* 1
     * 52KHZ ---> 19.2uS
     * PR2   = (19.2uS / (2/10MHZ)) - 1 
     * PR2   =   95  ---> 52KHZ
     * 19.2us = (PR2 + 1) * 200ns * 1 ----> 52khz  PR2 = 95
     * 20ms   = (PR2 + 1) * 200nS * 1 ---> 50hz    PR2 = 100 000
     * 10ms   = (PR2 + 1) * 200nS * 1 ---> 100hz   PR2 = 50 000
     */
    PR2   = TIMER_P;//REGISTRO PARA LA CUENTA DEL TIMER
    OC1RS = 1; //DONDE BAJA MI SEÑAL//CICLO DE TRABAJO
    OC1R  = 1; //DONDE SUBE MI SEÑAL
    
    OC1CON = 0x0006;
    ///ACTIVAR TIMER
    T2CONbits.TCKPS   = 0;//PRECALER DE 1:1
    
    /*INTERRUPCION DE TIMER*/
    IEC0bits.T2IE = 1;
    IPC1bits.T2IP = 2;
    IFS0bits.T2IF = 0;
    
    /*encender el timer*/
    T2CONbits.TON = 1;
}

void __attribute__ ((interrupt,no_auto_psv)) _T2Interrupt (void)
{
   IFS0bits.T2IF = 0; 
   if (duty < TIMER_P)
   {
       OC1RS = duty;
       duty = duty + 50;
   }
   else
   {
       duty = 1;
       OC1RS = duty;
   }
}
