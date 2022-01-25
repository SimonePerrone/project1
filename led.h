/** ****************************************************************************************
* @file led.h
* @brief Dichiarazione delle librerie utilizzate per i led
* 
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1 
*/

/*File con dichiarazione del prototipo
  delle funzioni utilizzate */

//Prototipi delle funzioni
/** ****************************************************************************************
* @brief Abilitazione clock sul GPIOB
* @see Configurazione output: bit 5 a 0; Configurazione output: bit 4 a 1;
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedInit(void); 						//Inizializzazione entrambi led

/** ****************************************************************************************
* @brief Accensione dei Led
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedOn(void);								//Accensione entrambi led	

/** ****************************************************************************************
* @brief Abilitazione lampeddio dei Led
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedBlink(int led, int nLamp, int ms);			//Funzione Blink con passaggio di parametri: led e n° lampeggi

//Funzioni SysTick
void SystickInit(void);
void DelaySystick1Ms(int ms);

//Funzioni led Rosso
/** ****************************************************************************************
* @brief Abilitazione del pin del Led Rosso
* @see Configurazione output: bit 5 a 0; Configurazione output: bit 4 a 1;
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedRedInit(void);						//Inizializzazione

/** ****************************************************************************************
* @brief Accensione del Led Rosso
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedRedOn(void);						//Accensione

/** ****************************************************************************************
* @brief Spegnimento Led Rosso
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedRedOff(void);						//Spegnimento 

/** ****************************************************************************************
* @brief Inverto lo stato del Led: se acceso lo spegne e vicersa se spento lo accede
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedRedToggle(void);					//Inversione stato

/** ****************************************************************************************
* @brief Ciclo ripeturo nLamp volte per lampeggio: utilizziamo al suo interno la LedRedToggle
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedRedBlink(int nLamp, int ms);					//Lampeggio

/** ****************************************************************************************
* @brief Vedere lo stato in cui si trova il Led Rosso
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int LedRedCheck(void);

/** ****************************************************************************************
* @brief Funzione finale utilizzata per il lampeggio del Led Rosso
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedRedTask(int Ton, int t);

//Funzioni led Verde
/** ****************************************************************************************
* @brief Abilitazione del pin del Led Rosso
* @see Configurazione come output: bit 17 a 0; Configurazione come output: bit 16 a 1;
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedGreenInit(void);					//Inizializzazione

/** ****************************************************************************************
* @brief Accensione del Led Verde
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedGreenOn(void);						//Accensione

/** ****************************************************************************************
* @brief Spegnimento Led Verde
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedGreenOff(void);						//Spegnimento 

/** ****************************************************************************************
* @brief Inverto lo stato del Led: se acceso lo spegne e vicersa se spento lo accede
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedGreenToggle(void);					//Inversione stato

/** ****************************************************************************************
* @brief Ciclo ripeturo nLamp volte per lampeggio del Led: utilizziamo al suo interno la LedRedToggle
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedGreenBlink(int nLamp, int ms);					//Lampeggio

/** ****************************************************************************************
* @brief Funzione finale utilizzata per il lampeggio del Led Verde
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void LedGreenTask (int Ton, int t);

/** ****************************************************************************************
* @brief Vedere lo stato in cui si trova il Led Verde
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int LedGreenCheck(void);

void LedRedTask(int Ton, int t);
