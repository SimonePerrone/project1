/** ****************************************************************************************
* @file led.h
* @brief Dichiarazione delle librerie utilizzate per il funzionamento del SysClock
* 
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1 
*/

#include <stdint.h>
void MSIInit(uint8_t range);
void pllInit(uint8_t M, uint8_t N, uint8_t R);
void SysClockInit(void);

void delayMicroseconds(uint64_t us);
void delay(uint64_t ms);
void SysTick_Handler (void);
uint64_t micros(void);
uint64_t millis(void);
