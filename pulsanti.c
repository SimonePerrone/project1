#include "stm32l4xx.h"          // Device header
#include "pulsanti.h"
#include "SysClock.h"

void SwInit(void){
	
	//Pulsante centrale
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE0_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE0_1;
	
	//Pulsante Sinistro
	GPIOA->MODER &= ~GPIO_MODER_MODE1_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE1_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE1_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE1_1;
	
	//Pulsante Destro
	GPIOA->MODER &= ~GPIO_MODER_MODE2_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE2_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE2_1;
	
	//Pulsante Up
	GPIOA->MODER &= ~GPIO_MODER_MODE3_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE3_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE3_1;
	
	//Pulsante Down
	GPIOA->MODER &= ~GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
	GPIOA->PUPDR &= ~GPIO_MODER_MODE5_0;
	GPIOA->PUPDR |= GPIO_MODER_MODE5_1;
}

int SwCxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID0_Msk);
}

int SwSxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID1_Msk);
}

int SwDxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID2_Msk);
}

int SwUpPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID3_Msk);
}

int SwDwPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID5_Msk);
}

int pulseInPA0(void){
	while(SwCxPress()==0){};
	int inizio=micros();
	while(SwCxPress()!=0){};
	int t=micros()-inizio;
	return t;
}

int pulseInPA1(void){
	while(SwSxPress()==0){};
	int inizio=millis();
	while(SwSxPress()!=0){};
	int t=millis()-inizio;
	return t;
}

int pulseInPA2(void){
	while(SwDxPress()==0){};
	int inizio=micros();
	while(SwDxPress()!=0){};
	int t=micros()-inizio;
	return t;
}

int pulseInPA3(void){
	while(SwUpPress()==0){};
	int inizio=micros();
	while(SwUpPress()!=0){};
	int t=micros()-inizio;
	return t;
}

int pulseInPA5(void){
	while(SwDwPress()==0){};
	int inizio=micros();
	while(SwDwPress()!=0){};
	int t=micros()-inizio;
	return t;
}
