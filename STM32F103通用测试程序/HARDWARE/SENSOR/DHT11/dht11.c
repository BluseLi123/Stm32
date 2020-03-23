#include "dht11.h"

/** 
* @describe DHT-11���ų�ʼ�� ͷ�ļ�����������
* @param		��
* 
* @return		��
*/
void DHT11_Init(void)
{	 
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(DHT_GPIO_CLK, ENABLE);	 
	
 	GPIO_InitStructure.GPIO_Pin 	= DHT_GPIO_PIN;				 
 	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP; 		 
 	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
 	GPIO_Init(DHT_GPIO_PORT, &GPIO_InitStructure);				  
	
	DHT11_Reset();
} 

/** 
* @describe ��λDHT-11
* @param		��
* 
* @return		��
*/
void DHT11_Reset(void)	   
{   
	//�ı�GPIO���� ׼����������
	DHT_Direction_O;
	GPIO_ResetBits(DHT_GPIO_PORT,DHT_GPIO_PIN);
	delay_ms(20);    	
	GPIO_SetBits(DHT_GPIO_PORT,DHT_GPIO_PIN);
	delay_us(30);     
}

/** 
* @describe �ȴ�DHT11��Ӧ
* @param		��
* 
* @return		0 OK 1 δ��⵽
*/
uint8_t DHT11_IsOnline(void) 	   
{   
	uint8_t retry = 0;
	//�ı�GPIO���� ׼����ȡ����
	DHT_Direction_I;
	while (GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	
	if(retry >= 100)
	{
		return 1;
	}
	else
	{
		retry = 0;
	}
	
	while (!GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	
	if(retry >= 100)
	{
		return 1;
	}	    
	return 0;
}
/** 
* @describe ��ȡһ��Bit
* @param		��
* 
* @return		0uint8_t
*/
uint8_t DHT11_ReadBit(void) 			 
{
 	uint8_t retry = 0;
	while(GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	retry = 0;
	while(!GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN) && retry < 100)
	{
		retry ++;
		delay_us(1);
	}
	
	delay_us(40);
	
	if(GPIO_ReadInputDataBit(DHT_GPIO_PORT,DHT_GPIO_PIN))
	{
		return 1;
	}
	else 
	{
		return 0;	
	}		
}

/** 
* @describe ��ȡһ���ֽ�
* @param		��
* 
* @return		0uint8_t
*/
uint8_t DHT11_ReadByte(void)    
{        
	uint8_t i,dat;
	dat = 0;
	for (i = 0; i < 8; i ++) 
	{
   		dat <<= 1; 
	    dat |= DHT11_ReadBit();
    }						    
    return dat;
}

/** 
* @describe ��ȡһ������
* @param		temp �¶�ֵ humi ʪ��ֵ
* 
* @return		0 ���� 1 ʧ��
*/
uint8_t DHT11_Read_Data(float *temp,float *humi)
{
	uint8_t buf[5];
	uint8_t i;
	
	DHT11_Reset();
	
	if(DHT11_IsOnline() == 0)
	{
		//��λ����λ 1λУ��λ
		//��һλΪʪ������λ���ڶ�λΪʪ��С��λ
		//����λΪ�¶�����λ������λλ�¶�С��λ
		for(i = 0; i < 5; i ++)
		{
			buf[i] = DHT11_ReadByte();
		}
		if((buf[0] + buf[1] + buf[2] + buf[3]) == buf[4])
		{
			*humi = (float)buf[0];
			*temp = (float)buf[2];
		}
	}
	else 
	{
		return 1;
	}
	
	return 0;	    
}

