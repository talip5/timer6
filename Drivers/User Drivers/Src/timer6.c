/*
 * timer6.c
 *
 *  Created on: Apr 5, 2023
 *      Author: ataha
 */

#include "stm32f0xx_hal.h"


void timer6_init(void){
//RCC->APB1ENR |=RCC_APB1ENR_TIM6EN;
	__HAL_RCC_TIM6_CLK_ENABLE();

//TIM6->CR1 |=(1<<0);
TIM6->CR1 |=TIM_CR1_CEN;
TIM6->PSC=47999;// CLOCK 1 Khz
TIM6->ARR=2499;

TIM6->DIER |=TIM_DIER_UIE;// Enable Timer Update Interrupt
//Enable TIM6 Interrupt on NVIC
NVIC_EnableIRQ(TIM6_IRQn);
NVIC_SetPriority(TIM6_IRQn,2);
}



void led_init(void){
	RCC->AHBENR |=RCC_AHBENR_GPIOCEN;

	GPIOC->MODER |=(1<<16);
	GPIOC->MODER &=~(1<<17);

	GPIOC->OTYPER &=~(1<<8);

	GPIOC->OSPEEDR &=~(1<<16);
	GPIOC->OSPEEDR &=~(1<<17);

}

void ledB5_init(void){
	RCC->AHBENR |=RCC_AHBENR_GPIOBEN;

	GPIOB->MODER |=(1<<10);
	GPIOB->MODER &=~(1<<11);

	GPIOB->OTYPER &=~(1<<5);

	GPIOB->OSPEEDR &=~(1<<10);
	GPIOB->OSPEEDR &=~(1<<11);

}

void led_ON(void){
	GPIOC->ODR |=(1<<8);
}

void led_OFF(void){
	GPIOC->ODR &=~(1<<8);
}

void ledB5_ON(void){
	GPIOB->ODR |=(1<<5);
}

void ledB5_OFF(void){
	GPIOB->ODR &=~(1<<5);
}
