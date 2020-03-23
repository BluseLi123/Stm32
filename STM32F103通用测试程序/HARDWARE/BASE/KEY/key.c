#include "key.h"
#include "led.h"
#include "delay.h"
#include "sys.h"

/** 
* @describe KEY���ų�ʼ��  �޸�ͷ�ļ��еĺ������������
* @param		��
* 
* @return		��
*/
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
	
	
 	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK | KEY2_GPIO_CLK,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = KEY2_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = KEY3_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = KEY4_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStructure);
	
	/*
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK ,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	*/
}

/*******************************************************************
 *
 *          @describe ����ɨ��
 *
 *******************************************************************/
/** 
* @describe ����ɨ��  �޸�ͷ�ļ��еĺ������������
* @param		��
* 
* @return		KEY_DOWN KEY1���� KEY_UP KEY1�ް���
*/
uint8_t KEY_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN);   
		return 	KEY_DOWN;	 
	}
	else
		return KEY_UP;
}


/*******************************************************************
 *
 *          @describe ����--�ⲿ�ж�
 *
 *******************************************************************/
/** 
* @describe �����ⲿ�ж� �ڼ������Ŷ�Ӧ�ڼ����ж���
* @param		��
* 
* @return		��
*/
void EXTIX_KEY_Init(void)
{
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;

	  //RCC_APB2Periph_AFIO  ����IOʱ�� ��Ҫ�õ��������ӳ�书��ʱ����Ҫʹ��AFIO��ʱ��
  	//�ⲿ�жϣ�EXTI������AFIO�йصļĴ�����AFIO-EXTICR1��2��3������������ѡ��EXTIx�ⲿ�жϵ������֮�á�
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO,ENABLE);

	  /* ѡ��EXTI���ź�Դ */
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource3);
		//�ж�/�¼��� EXTI_Line0-15 ����GPIIO
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
		//ģʽѡ�� EXTI_Mode_Interrupt = 0x00 �����ж�   EXTI_Mode_Event = 0x04 �����¼�
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
		//���ش����¼�   EXTI_Trigger_Rising = 0x08, �����ش���  EXTI_Trigger_Falling = 0x0C, �½��ش���  EXTI_Trigger_Rising_Falling = 0x10 �����½�������
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	  //�ж�ʹ��
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);
		//�����ж����ȼ�
		
		//�����ж�Դ
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  	//��ռ���ȼ�
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
  	//�����ȼ�
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  	//ʹ��
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure); 
}
/** 
* @describe �жϷ����� ����������ļ��еĺ�������ͬ
* @param		��
* 
* @return		��
*/
void EXTI3_IRQHandler(void)
{
	//PA0��PB0 ͬʱʹ�õĻ�������Ķ���ͬһ���жϷ���������ô��ô���� 
	//����ͨ����ȡPB0 ���� PA0 �������ݼĴ���IDR��ֵ���жϡ�
	//delay_ms(10);    //����			 

	if(EXTI_GetITStatus(EXTI_Line3) != RESET)
	{
		LED4=!LED4;
	}
	//���EXTI0��·����λ
	EXTI_ClearITPendingBit(EXTI_Line3);  
}
