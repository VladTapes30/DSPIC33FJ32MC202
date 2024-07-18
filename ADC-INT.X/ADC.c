/************************************************************/
/*MODIFICACION DE ARCHIVO ADC. C PARA AGREGAR INTERRUPCION*/
/*************************************************************/
#include "system.h"
#include "ADC.h"
#include<libpic30.h>
#include <p33FJ32MC202.h>

/*manejador*/
void (*ADC1_InterruptHandler)(void);

void adc_init()
{
    AD1PCFGLbits.PCFG0 = 0;//aseguro que es analoga
    TRISAbits.TRISA0   = 1;//digo que es entrada
    
    /*INTERRUPCION CONFIGURACION*/
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 1;
    IPC3bits.AD1IP = 2;//mas proridad
    /*adc configuracion*/
    AD1CON1bits.ADON  = 0;//off adc
    AD1CON1bits.AD12B = 1;//modo 12 bits
    AD1CON1bits.FORM  = 0b00;//formato entero
    AD1CON1bits.SSRC  = 0b000;//elegir funte de clock
    AD1CON1bits.SAMP  = 0;//muestreo induvidual
    AD1CON2bits.VCFG  = 0b000;//voltajes de referencia
    AD1CON2bits.CHPS  = 0b00;//channel 0 elegir
    AD1CON3bits.ADRC  = 0;//FUNTE DE CLOCK CONVERSION
    AD1CON3bits.ADCS  = 0b100;//velocidad de muestreo
    AD1CON1bits.ASAM  = 0;//MODO MANULA MUESTREO
    AD1CON1bits.ADON  = 1;//on adc  
}

uint16_t ADC_Read(int channel)//0--> an0
{
    AD1CHS0bits.CH0SA = channel;//elegir el canal
    AD1CON1bits.SAMP  = 1;//activar muestreo
    __delay_us(10);
    AD1CON1bits.SAMP  = 0;//desactivar muestreo
    while(!AD1CON1bits.DONE);//esperar hasta que se termine la conversion
    
    return ADC1BUF0;
}

void __attribute__ ((interrupt,no_auto_psv)) _ADC1Interrupt(void)
{
    IFS0bits.AD1IF = 0;
    /*ejecutar*/ 
    if(ADC1_InterruptHandler)
    ADC1_InterruptHandler();
}

void ADC1_SetInterruptHandler (void (*Interrupt)(void))
{
    ADC1_InterruptHandler = Interrupt;
}