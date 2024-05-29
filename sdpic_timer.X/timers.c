
#include <p33FJ32MC202.h>

void(*T1_InterruptHandler)(void);//puntero a funcion

void Timer1_init()
{
    T1CONbits.TON   = 0;//modulo off
    T1CONbits.TCS   = 0;//elegir el clock
    T1CONbits.TCKPS = 1;//elegir el prescaler
    TMR1 = 0; //EMPIEZA EL TIMER
    
    //timer para contar 50ms
    /*PR1 = FCY *T /PRESCALER -1
      PR1 = ((FCY *50ms) /8)-1 
     *PR1 = 31249
     */
    PR1 = 31249;
    
    /*CONFIGURANDO INTRUPCION DE TIMER1*/
    IEC0bits.T1IE = 1;//interrupcion on
    IPC0bits.T1IP = 2;//prioridad
    IFS0bits.T1IF = 0;//FLANCO DE BAJADA
    T1CONbits.TON = 1;//timer1 on
}

void __attribute__ ((interrupt,no_auto_psv)) _T1Interrupt (void)
{
    IFS0bits.T1IF = 0;
    if(T1_InterruptHandler)//checar si contiene algo
    {
         T1_InterruptHandler();
    }
}

void T1_SetInterrupHandler (void(*InterrupHandler)(void))
{
    T1_InterruptHandler = InterrupHandler;
}