/* 
 * File:   i2c.h
 * Author: ASUS
 *
 * Created on 2 de septiembre de 2023, 12:32 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define I2C_Write 0x00
#define I2C_Read  0x01
/*prototipos*/
void I2C1_Init(uint16_t fscl);
void I2C1_Start(void);
void I2C1_Restart(void);
void I2C1_Stop(void);
void I2C1_Write_Addr_Slave(uint8_t addr, uint8_t dir);
void I2C1_Write_Data(uint8_t data);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

