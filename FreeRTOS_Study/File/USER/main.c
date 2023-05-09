#include "stm32f4xx.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
/*--------------------------------------
任务功能：主函数
--------------------------------------*/

int main(void)
{
  BSP_Init(); //外设初始化
	xTaskCreate((TaskFunction_t)TaskCreat,
							(const char*   )"TaskCreat",
							(uint16_t      )(CreatTask_STK_SIZE),
							(void*         )NULL,
							(UBaseType_t   )CreatTask_TASK_PRIO,
							(TaskHandle_t* )&CreatTask_Handler);		
	vTaskStartScheduler();
}

void TaskCreat(void)
{
	taskENTER_CRITICAL();
	xTaskCreate((TaskFunction_t)PinkLEDON,
							(const char*   )"PinkLEDON",
							(uint16_t      )PinkLED_STK_SIZE,
							(void*         )NULL,
							(UBaseType_t   )PinkLED_TASK_PRIO,
							(TaskHandle_t* )&PinkLEDTask_Handler);
							
	xTaskCreate((TaskFunction_t)BlueLEDON,
							(const char*   )"BlueLEDON",
							(uint16_t      )BlueLED_STK_SIZE,
							(void*         )NULL,
							(UBaseType_t   )BlueLED_TASK_PRIO,
							(TaskHandle_t* )&BlueLEDTask_Handler);
	vTaskDelete(CreatTask_Handler);
	taskEXIT_CRITICAL();

}



