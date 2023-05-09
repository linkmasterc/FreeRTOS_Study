#ifndef __RM_ROBOT_H__
#define __RM_ROBOT_H__

#include "stm32f4xx.h"

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

//ϵͳ֡�ʼ����
typedef struct
{
  u16 LedTask_cnt;
	u16 TestTask_cnt;
	
	u16 LedTask_fps;
	u16 TestTask_fps;
}SYSTEM_MONITOR;

#endif
