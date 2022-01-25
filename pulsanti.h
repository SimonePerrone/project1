/** ****************************************************************************************
* @file pulsanti.h
* @brief Dichiarazione delle librerie utilizzate per i pulsanti
* 
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1 
*/

/*File con dichiarazione del prototipo
  delle funzioni utilizzate */
  
//Funzioni pulsanti
/** ****************************************************************************************
* @brief Inizializzazione pulsanti
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
void SwInit(void);							

/** ****************************************************************************************
* @brief Pressione centrale
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int SwCxPress(void);						

/** ****************************************************************************************
* @brief Pressione a sinistra
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int SwSxPress(void);						
/** ****************************************************************************************
* @brief Pressione a destra
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int SwDxPress(void);						

/** ****************************************************************************************
* @brief Pressione pulsante UP
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int SwUpPress(void);						

/** ****************************************************************************************
* @brief Pressione pulsante DOWN
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int SwDwPress(void);						

/** ****************************************************************************************
* @brief Abilitazione tasto centrale
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int pulseInPA0 (void);

/** ****************************************************************************************
* @brief Abilitazione tasto di sinistra
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int pulseInPA1 (void);

/** ****************************************************************************************
* @brief Abilitazione tasto di destra
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int pulseInPA2 (void);

/** ****************************************************************************************
* @brief Abilitazione tasto UP
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int pulseInPA3 (void);

/** ****************************************************************************************
* @brief Abilitazione tasto DOWN
*
* @author Simone Perrone 5L
* @date 28/9/2021
* @version 1.0 28/9/2021 Prima versione del file led.h
* @version 1.1
*/
int pulseInPA5 (void);
