#ifndef __MAIN_H__
#define __MAIN_H__
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
/*--------------Types--------------*/
/*--------------BSP--------------*/
#include "bsp_init.h"
#include "delay.h"
//#include "stm32f4xx_it.h"

/*--------------API--------------*/


/*--------------TASK--------------*/
#include "led_task.h"


void LedTask(void);
void TestTask(void);
void SystemMonitorTask(void);

#define CreatTask_TASK_PRIO 1
#define CreatTask_STK_SIZE 500
TaskHandle_t CreatTask_Handler;
void TaskCreat(void);

#define PinkLED_TASK_PRIO 2
#define PinkLED_STK_SIZE 128
TaskHandle_t PinkLEDTask_Handler;

#define BlueLED_TASK_PRIO 3
#define BlueLED_STK_SIZE 128
TaskHandle_t BlueLEDTask_Handler;

#endif


