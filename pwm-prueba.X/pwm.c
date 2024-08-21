
#include <p33FJ32MC202.h>
#include <libpic30.h>
#define PERIODO_PRX 50000
uint16_t duty;

void PWM_init()
{
    T2CONbits.TON    = 0;//apagando
    /*MAPIANDO OUTPUT*/
    TRISBbits.TRISB8 = 0;//in 1  out 0// 
    RPOR4bits.RP8R   = 0b10010;//asignando el OC1(pwm) a pin rb8 
    OC1CONbits.OCM   = 0;//limpiando registros
    /*formula para calcular el periodo
     * PWM Period = [(PRy) + 1] ? TCY ? (TMRy Prescale Value) 
     * 52khz = [PR2+1]*(2/10MHZ)*1
     * TCY = 2/FOSC = 2/10 000 000 = 200nS
       PWM Period = 1/PWM Frequency = 1/52 kHz = 19.2us
       PWM Period = (PR2 + 1) * TCY * (Timer2 Prescale Value)
       19.2us = (PR2 + 1) * 200ns * 1 ----> 52khz  PR2 = 95
     * 20ms   = (PR2 + 1) * 200nS * 1 ---> 50hz    PR2 = 100 000
     * 10ms   = (PR2 + 1) * 200nS * 1 ---> 100hz   PR2 = 50 000
      
     */
    PR2   = PERIODO_PRX; //PERIODO 95
    OC1RS = 1; //(DUTY CICLE))
    OC1R  = 1;  //donde inicia
    
    OC1CON = 0x0006;
    //OC1CONbits.OCTSEL = 0; //timer 2 para pwm
    //OC1CONbits.OCM    = 0b110;//habilitar el pwm
    
    /*CONFIGURACION DEL TIMER 2*/
    T2CONbits.TCKPS   = 0;//PRECALER DE 1:1
    
    /*INTERRUPCIONES*/
    IEC0bits.T2IE     = 1;//interrupcion on
    IPC1bits.T2IP     = 2;//prioridad
    IFS0bits.T2IF     = 0;//FLANCO DE BAJADA
    T2CONbits.TON     = 1;//timer1 on
}

void __attribute__ ((interrupt,no_auto_psv)) _T2Interrupt (void)
{
    IFS0bits.T2IF =  0;
    if(duty < PERIODO_PRX){
        OC1RS = duty;
        duty = duty + 500;//recuerda mover el osiloscopio
    }
    else{
        duty = 1;
        OC1RS = 1;
    }
}
