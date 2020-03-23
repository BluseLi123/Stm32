/** 
 * @fileName   	 hc_sr04.c
 * @brief         HCSR04 �������������������루4�����ţ�      
 * @author        Bluseli www.bluseli.cn www.bluseli.site �Ӵ��������ͷ��лл��ע��
 * @date          2020-3-2
 */
#include "hc_sr04.h"
#include "usart.h"
#include "delay.h"
#include "timer.h"

u16 sr04Count=0;

/** 
 * @describe	 Ӳ����ʼ��
 * @param		 	 ��
 * 
 * @return		 ��
 */
void SR04_Init(void)
{
  //ʹ�ö�ʱ������
  //IO��һ��Ϊ���һ��Ϊ����
  RCC->APB2ENR |=(1<<2);
  GPIOA->CRL &=~(0xFF<<4*1);
  GPIOA->CRL |=0x34<<4*1;
	
	SR04_TIM_Init();
	
}
/** 
 * @describe	 ��������ඨʱ����ʼ��
 * @param		 	 ��
 * 
 * @return		 ��
 */
void SR04_TIM_Init(void)
{
	Timer1_Init(999, 72-1);
}
/** 
 * @describe	 �򿪶�ʱ��
 * @param		 	 ��
 * 
 * @return		 ��
 */
void SR04_TIM_Open(void)
{
  	TIM_Cmd(TIM1, ENABLE);
}
/** 
 * @describe	 �رն�ʱ��
 * @param		 	 ��
 * 
 * @return		 ��
 */
void SR04_TIM_Close(void)
{
		TIM_Cmd(TIM1, DISABLE);
}
//ǰ������
float SR04_Work(void)
{
	u8 i = 0;
	u32 t = 0;
  u16 cnt=0;
	float lengthTemp = 0;
	float sum = 0;
	while(i!=5)
	{ 
		T1_1;     
		delay_us(30);
		T1_0;
		sr04Count=0;
		while(E1_0);//�ȴ������źţ�     
		SR04_TIM_Open();        
		i = i + 1;
		while(E1_1);//�����źŽ���
		SR04_TIM_Close(); 
//		t=sr04Count*1000;
//		t+=TIM1->CNT;
		lengthTemp = ((float)t/58.0);//cm
		sum = lengthTemp + sum ;   
	}
	lengthTemp = sum/5.0;//��ƽ��ֵ
	return lengthTemp;
}

