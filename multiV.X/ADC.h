/* 
 * File:   ADC.h
 * Author: vlad
 *
 * Created on 11 de marzo de 2024, 09:25 AM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
    typedef enum
    {
        AN0,
                AN1,
                AN2,
                AN3,
                AN4,
                AN5
    }CHANNEL;
//PROTOTIPOS
void adc_init();
uint16_t ADC_Read(CHANNEL channel);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

