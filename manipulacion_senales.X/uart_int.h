/* 
 * File:   uart.h
 * Author: achem
 *
 * Created on 10 de abril de 2024, 09:34 AM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif
/*prototipos*/
void UART_init();
void UART_putc (char c);
void UART_puts (char *s);



#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

