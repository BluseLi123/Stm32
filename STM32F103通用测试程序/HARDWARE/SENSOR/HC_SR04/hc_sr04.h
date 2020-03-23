/** 
 * @fileName   	 hc_sr04.h
 * @brief        HCSR04 �������������������루4�����ţ�
 *							 Trig�ṩһ��10uS �������崥���źţ���ģ���ڲ�������8��40kHz���ڵ�ƽ�����ز���һ����⵽�лز��ź���Echo�����
 *							 �����źŵ�������������ľ�������ȡ��ɴ�ͨ�������źŵ��յ��Ļ����ź�ʱ�������Լ���õ����룻
 *							 ��ʽ��uS/58=���׻���uS/148=Ӣ�磻���ǣ�����=�ߵ�ƽʱ��*���٣�340M/S��/2��
 *							 �����������Ϊ60ms ���ϣ��Է�ֹ�����źŶԻ����źŵ�Ӱ�졣      
 * @author       Bluseli www.bluseli.cn www.bluseli.site �Ӵ��������ͷ��лл��ע��
 * @date         2020-3-2
 */
#ifndef _HC_SR04_H_
#define _HC_SR04_H_

#include "stm32f10x.h"

//��������Echo-------PA1,ǰ�������������
//       Trig-------PA2,ǰ�����������ź�����
//�������պ궨��
#define E1_1      ((GPIOA->IDR &1<<1)!=0)//�����źŽ��룬Ϊ1    
#define T1_1      {(GPIOA->ODR |=1<<2);}

#define E1_0      ((GPIOA->IDR &1<<1)==0)//�����źŽ��룬Ϊ1    
#define T1_0      {(GPIOA->ODR &=~(1<<2));}

void SR04_Init(void);
void SR04_TIM_Init(void);
void SR04_TIM_Open(void);
void SR04_TIM_Close(void);

float SR04_Work(void);

#endif 

