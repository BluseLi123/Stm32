#ifndef __HW_H
#define __HW_H 			   
#include "stm32f10x.h"
#include "sys.h"

//����Թ�
//͸��   ����---3.3v �̸�---GND ���Ͷ�
//��͸�� ����---GND  ���ź�--GPIO ���ն�

//�˿ڶ���
#define HW_EN PAout(1)								 	// PC0 ����ʹ�ܣ���1Ϊʹ��
#define HW GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)			// PC1 �����ϼ��

#define HW_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define HW_GPIO_PORT    	GPIOA			              /* �˿� */
#define HW_GPIO_PIN				GPIO_Pin_1			        /* λ */


void HW_Init(void);//�����ʼ��
void EXTI_HW_Init(void);

#endif
