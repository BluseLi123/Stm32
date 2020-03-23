#include "led.h"
	   
/** 
* @describe LED���ų�ʼ��  �޸�ͷ�ļ��еĺ������������
* @param		��
* 
* @return		��
*/
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;

 RCC_APB2PeriphClockCmd(LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK | LED4_GPIO_CLK, ENABLE);	 //ʹ��PA�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;				 //LED1-->PA1 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
 GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);
 //GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);			 //PA1 �����
 GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);			 //PA1 �����
	
 GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;				 //LED2-->PA2 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
 //GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);			 //PA2�����
 GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);			 //PA2 �����
}
