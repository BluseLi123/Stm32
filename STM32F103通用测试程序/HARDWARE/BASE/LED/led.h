/******************************************************************************
* @fileName led.h
* @author  	Bluseli  www.Bluseli.cn
* @date    	2020/1/14
* @brief   	LED�������� 
*******************************************************************************/
#ifndef __LED_H
#define __LED_H	 

#include "sys.h"

#define LED_ON	1
#define LED_OFF	0

//λ������
// LED 4 5 6 7 ==��  PA4 PA5 PA6 PA7
//LED����
#define LED1_BIT   11
#define LED2_BIT   12
#define LED3_BIT   6
#define LED4_BIT   7
//LED�˿ڶ��� 
#define LED1 PAout(LED1_BIT)// PA1
#define LED2 PAout(LED2_BIT)// PA2
#define LED3 PAout(LED3_BIT)// PA3
#define LED4 PAout(LED4_BIT)// PA4

//���д������ ��� ������ֲ
//LED1
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define LED1_GPIO_PORT    	GPIOA			              /* �˿� */
#define LED1_GPIO_PIN				GPIO_Pin_11			        /* λ */
//LED2
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define LED2_GPIO_PORT    	GPIOA			              /* �˿� */
#define LED2_GPIO_PIN				GPIO_Pin_12			        /* λ */
//LED3
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define LED3_GPIO_PORT    	GPIOA			              /* �˿� */
#define LED3_GPIO_PIN				GPIO_Pin_6			        /* λ */
//LED4
#define LED4_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define LED4_GPIO_PORT    	GPIOA			              /* �˿� */
#define LED4_GPIO_PIN				GPIO_Pin_7			        /* λ */


#define LED1ON		GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1OFF		GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1TURN	GPIO_WriteBit(LED1_GPIO_PORT, LED1_GPIO_PIN,!GPIO_ReadOutputDataBit(LED1_GPIO_PORT,LED1_GPIO_PIN))

#define LED2ON		GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2OFF		GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2TURN	GPIO_WriteBit(LED2_GPIO_PORT, LED2_GPIO_PIN,!GPIO_ReadOutputDataBit(LED2_GPIO_PORT,LED2_GPIO_PIN))

#define LED3ON		GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3OFF		GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3TURN	GPIO_WriteBit(LED3_GPIO_PORT, LED3_GPIO_PIN, !GPIO_ReadOutputDataBit(LED3_GPIO_PORT,LED3_GPIO_PIN))

#define LED4ON		GPIO_SetBits(LED4_GPIO_PORT,LED4_GPIO_PIN)
#define LED4OFF		GPIO_ResetBits(LED4_GPIO_PORT,LED4_GPIO_PIN)
#define LED4TURN	GPIO_WriteBit(LED4_GPIO_PORT, LED4_GPIO_PIN, !GPIO_ReadOutputDataBit(LED4_GPIO_PORT,LED4_GPIO_PIN))

void LED_Init(void);//��ʼ��
		 				    
#endif
