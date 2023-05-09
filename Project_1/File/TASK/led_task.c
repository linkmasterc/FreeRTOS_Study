#include "led_task.h"
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
void PinkLEDON(void)
{
	while(1)
  {
		GPIO_ToggleBits(GPIOE, GPIO_Pin_15);
		vTaskDelay(1000);
	}
	
}

void BlueLEDON(void)
{
	while(1)
	{
	GPIO_ToggleBits(GPIOE, GPIO_Pin_14);
		vTaskDelay(500);
	}
}
