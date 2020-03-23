#include "math.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "timer.h"
#include "usart.h"
#include "pwm.h"
#include "sys.h"
#include "hc_sr04.h" //������

/**************************************************************************************/
unsigned char usart1Buf[64];
unsigned char usart1Len;
unsigned char usart2Buf[64];
unsigned char usart2Len;
/**************************************************************************************/
const u8 *COMPILED_DATE=__DATE__;//��ñ�������
const u8 *COMPILED_TIME=__TIME__;//��ñ���ʱ��

const u8 *Week[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
/**************************************************************************************/
/**************************************************************************************/
extern u16 sr04Count;
/**************************************************************************************/
/**************************************************************************************/
void Board_Init(void);
short MPU6050_Get_Angle(float x,float y,float z,u8 dir);
/**************************************************************************************/
void LED_Iest(void);
void KEY_Test(void);

int main(void)
{
	float pitch,roll,yaw; 		//ŷ����
	short aacx,aacy,aacz;		//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;	//������ԭʼ����
	short temp;					//�¶�	
	
	int statue=0;
	
	Board_Init();
	while(1)
	{
		LED_Iest();
		//KEY_Test();

//		temp=MPU_Get_Temperature();	//�õ��¶�ֵ
//		MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
//		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
//		UsartPrintf(USART1, "MPU6050\r\n");
//		UsartPrintf(USART1, "%f\r\n", temp/100.0);
//		UsartPrintf(USART1, "%d %d %d\r\n", aacx, aacy, aacz);
//		UsartPrintf(USART1, "%d %d %d\r\n", gyrox, gyroy, gyroz);
		
		//dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,&more);
		
//	  UsartPrintf(USART1, "������\r\n");
//		UsartPrintf(USART1, "%f\r\n", SR04_Work());
//		UsartPrintf(USART1, "%d\r\n", sr04Count);
//		UsartPrintf(USART1, "%d\r\n",HC_SR501_Read());
//		if(HC_SR501_Read()==ON)
//		{
//			LED1ON;
//		}else
//		{
//			LED1OFF;
//		}

		delay_ms(1000);
	}	 
}

void Board_Init(void)
{
	Delay_Init(72);
	NVIC_Configuration();
	//Timer1_Init(5000,7199);				   //��ʱ��TIM1
	Usart1_Init(115200);						 //���ڳ�ʼ��
	//SR04_Init();
//	MPU_Init();
//	mpu_dmp_init();
//	UsartPrintf(USART1, "11111\r\n");
	LED_Init();//led��ʼ��
	//KEY_Init();//������ʼ��
	//Timer6_Init(999, 71);
	//Timer3_Init(10000,7199);//10Khz�ļ���Ƶ�ʣ�������10000Ϊ1s 
	//Timer4_Init(50000,7199);//10Khz�ļ���Ƶ�ʣ�������50000Ϊ5s 
	//EXTIX_KEY_Init();
	//TIM2_PWM_Init(10000,7199);
	
	//HC_SR501_Init();//��ʼ��

}

void LED_Iest(void)
{
	LED1TURN;
	LED2TURN;
	LED3TURN;
	LED4TURN;
}
void KEY_Test(void)
{
	if(KEY_Scan(GPIOC,GPIO_Pin_1) == KEY_DOWN)
	{
		LED1=!LED1;
	}
}

