/** ****************************************************************************************
* \mainpage  Es10-Lib. Pulsanti 
*
* @brief  Scrittura del codice in linguaggio C per la gestione dei pulsanti sulla scheda STM32L476 

*  Configurazione dei pin GPIO
*   Utilizzo delle maschere per le operazioni di set, reset 

*  Ogni pulsante della scheda deve svolgere una funzione 
* 
* @author Simone Perrone 5L 
* @date  28/9/2021  
* @version 1.0  28/9/2021  Progetto completo di librerie per led, pulsanti e clock
* @version 1.1  Nessuna modifica apportata fino ad ora
*/

#include "stm32l4xx.h"                  	// Device header
#include <stdio.h>
#include "led.h"
#include "pulsanti.h"
#include "interrupt.h"
#include "SysClock.h"
#include "LCD.h"
#include "Ultrasuoni.h" 

int main(){
	LedInit();													//Inizializzazione Led
	SwInit();														//Inizializzazione Pulsanti
	InterruptInit();										//Abilitazione interrupt sui pulsanti
	SysClockInit();											//Configurazione Clock a 80 Hz
	LCD_Init();													//Configurazione LCD
	LCD_DisplayString((uint8_t *)"0");	//
	UltrasuoniInit();										//Inizializzazione sensore a ultrasuoni
	
	while(1){												//Loop infinito
		Sensore_lampeggio();
	}
}
	