/** 
* @projectName   ��ʱ��
* @brief         ��ʱ�� 
* @author        Bluseli
* @date          2020-3-2
*/
#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

//������ʱ��
void Timer6_Init(u16 arr,u16 psc);
//ͨ�ö�ʱ��
void Timer3_Init(u16 arr,u16 psc); 
void Timer4_Init(u16 arr,u16 psc);
//�߼���ʱ��
void Timer1_Init(u16 arr,u16 psc);
#endif
