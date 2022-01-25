#include "stm32l4xx.h"                  	// Device header
#include "Ultrasuoni.h"
#include "SysClock.h"
#include "Led.h"
#include "LCD.h"
#include <stdio.h>

#define Tempo_Trig_acceso 15
#define Periodo_Trig 500000

int Ton;
int T;
int flag_misura;
int misura;

void UltrasuoniInit (void){
	TrigConfig();
	EchoConfig();
	Echo();
}

void TrigConfig (void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
	GPIOE->MODER |= GPIO_MODER_MODER14_0;
	GPIOE->MODER &= ~GPIO_MODER_MODE14_1;
}

void TrigOn (void){
	GPIOE->ODR |= GPIO_ODR_OD14;
}

void TrigOff(void){
  GPIOE->ODR &= ~ GPIO_ODR_OD14;	
}

int TrigCheck(void){
	if((GPIOE->ODR & GPIO_ODR_OD14)==0)
		return 0;
	else
		return 1;
}

void TrigTask (int tempo_accensione, int tempo_tot){
	static int tiniziale;
	static char inizio=1;
	int tempo;
	int misura;
	if (inizio){
		TrigOn();
		inizio=0;
		tiniziale= micros();
	}
	else 
		tempo= micros()-tiniziale;
	if(TrigCheck() && (tempo>=tempo_accensione)){
		TrigOff();
	}
	else if (tempo>=tempo_tot){
		TrigOn();
		tiniziale=micros();
	}
}

void UsInit (void){
	EchoConfig();
}

void EchoConfig (void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
  GPIOE->MODER &= ~GPIO_MODER_MODE15_0;
  GPIOE->MODER &= ~GPIO_MODER_MODE15_1;
  GPIOE->PUPDR &= ~GPIO_PUPDR_PUPD15_0;
  GPIOE->PUPDR |= GPIO_PUPDR_PUPD15_1;
}

void Echo (void){	
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI15_Msk;
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI15_PE;
	EXTI->RTSR1 |= EXTI_RTSR1_RT15;
	EXTI->FTSR1 |= EXTI_FTSR1_FT15;
	EXTI->IMR1 |= EXTI_IMR1_IM15;
	NVIC_SetPriority(EXTI15_10_IRQn,2);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler (void){
	static int time;
	int time_f;
	if ((GPIOE->IDR & GPIO_IDR_ID15_Msk)){
		time=micros();
	}
	else {
		time_f=micros()-time;
		misura=time_f/58;
		StampoValore();
		ControlloMisura();
		CalcoloTempiLampeggio();
	}
	EXTI->PR1 |= EXTI_PR1_PIF15;
}

void Sensore_lampeggio (void){
	TrigTask(Tempo_Trig_acceso,Periodo_Trig);
	if (flag_misura==0)
		LedGreenOff();
	else
		LedGreenTask(Ton,T);
}

void StampoValore(void){
	char CM[6];
	sprintf(CM,"%d",misura);
	LCD_Clear();
	LCD_DisplayString((uint8_t *)CM);
}

void ControlloMisura (void){
	if (misura>100)						//Se la misura>1m il flag sarà 0
		flag_misura=0;
	else
		flag_misura=1;				//Se la misura<1m il flag sarà 1
}

void CalcoloTempiLampeggio(void){
	T=misura*10;
	Ton=T*0.5;
}
