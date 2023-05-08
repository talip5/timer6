/*
 * timer6.h
 *
 *  Created on: Apr 5, 2023
 *      Author: ataha
 */

#ifndef USER_DRIVERS_INC_TIMER6_H_
#define USER_DRIVERS_INC_TIMER6_H_

void timer6_init(void);
void led_init(void);
void TIM6_IRQHandler(void);
void led_ON(void);
void led_OFF(void);
int start=1;

void ledB5_init(void);
void ledB5_ON(void);
void ledB5_OFF(void);

#endif /* USER_DRIVERS_INC_TIMER6_H_ */
