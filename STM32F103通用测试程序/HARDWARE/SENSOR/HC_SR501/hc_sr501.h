/******************************************************************************
* @fileName hc_sr501.h
* @author  	Bluseli  www.Bluseli.cn
* @date    	2020/3/7
* @brief   	���͵��������� 
*******************************************************************************/
#ifndef __HC_SR501_H
#define __HC_SR501_H	 

#include "sys.h"

#define ON	1
#define OFF	0

//λ������
//LED����
#define HC_SR501_BIT   0
//LED�˿ڶ��� 
#define HC_SR501 PAin(HC_SR501_BIT)// PA0

//���д������ ��� ������ֲ
//LED1
#define HC_SR501_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define HC_SR501_GPIO_PORT    	GPIOA			              /* �˿� */
#define HC_SR501_GPIO_PIN				GPIO_Pin_0	        /* λ */

void HC_SR501_Init(void);//��ʼ��
int  HC_SR501_Read(void); //��ȡ���͵�״̬
		 				    
#endif
