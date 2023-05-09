//#include "stm32f4xx_it.h"
//#include "rm_data_types.h"
//#include "main.h"
//#include "string.h"
//USHORT16 Clear_IT = 0;
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
///*************************************************************************
//中断处理函数名称：SysTick_Handler
//中断产生机制：1ms进入一次中断。
//函数功能：将SysTick（系统滴答定时器）作为操作系统的时钟
//*************************************************************************/
extern void xPortSysTickHandler(void);
void SysTick_Handler(void)
{	
    if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//系统已经运行
    {
        xPortSysTickHandler();	
    }

//      pitch_kf.raw_value=Visionrx_freq_data_p;
//		  Kalman_Filter(&pitch_kf);		//模拟噪声信号滤波
}

///*************************************************************************
//中断处理函数名称：USART1_IRQHandler
//中断产生机制：DR16每隔14ms通过DBus发送一帧数据（18字节）,USART1每接收一帧数据
//             进入一次中断
//函数功能：遥控器传输数据接收
//*************************************************************************/
//extern USART_RX_TypeDef USART1_Rcr;
//extern EventGroupHandle_t IRQHandler;
//void USART1_IRQHandler(void)
//{
//	BaseType_t Result,xHigherPriorityTaskWoken;
//  if(USART_GetITStatus(USART1, USART_IT_IDLE)!= RESET)
//	{
//		Clear_IT = USART1->SR;
//		Clear_IT = USART1->DR;//先读SR后读DR清楚中断标志位
//		
//    if(USART_Receive(&USART1_Rcr)==USART1_RXMB_LEN)
//	  {
//			 if(IRQHandler!=NULL)		
//		 {
//			Result = xEventGroupSetBitsFromISR(IRQHandler,0x01,&xHigherPriorityTaskWoken);
//			if(Result!=pdFAIL)
//		  {
//				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//		  }
//		}
//			system_monitor.USART1_cnt++;
//			system_monitor.USART1_cnt_100ms++;
//		} 
//	}		
//}

///*************************************************************************
//中断处理函数名称：USART2_IRQHandler
//中断产生机制：USART2接收到一个空字节后触发中断
//函数功能：裁判系统通讯
//*************************************************************************/
//void USART2_IRQHandler(void)
//{ 	
//	BaseType_t Result,xHigherPriorityTaskWoken;
//  if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
//  {   		 	
//		Clear_IT = USART2->SR;
//		Clear_IT = USART2->DR;                   //先读SR后读DR清楚中断标志位
//    
//     USART_Receive(&USART2_Rcr);	
//     if(IRQHandler!=NULL)		
//		 {
//	     Result = xEventGroupSetBitsFromISR(IRQHandler,0x02,&xHigherPriorityTaskWoken);
//		   if(Result!=pdFAIL)
//		   {
//			   portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//		   }
//		 }
//		   system_monitor.USART2rx_cnt++;
//	} 
//}

///***********************************************************************************
//中断处理函数名称：DMA1_Stream6_IRQHandler
//中断产生机制：串口2发送完成中断
//函数功能：
//************************************************************************************/
//void DMA1_Stream6_IRQHandler(void)
//{
//    if(DMA_GetITStatus(DMA1_Stream6, DMA_IT_TCIF6))
//    {
//        DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_TCIF6);//清除标志位
//    	  DMA_Cmd(DMA1_Stream6, DISABLE);             //关闭DMA传输 
//    }
//}
///***********************************************************************************
//中断处理函数名称：UART4_IRQHandler
//中断产生机制：视觉通讯
//函数功能：
//************************************************************************************/
//void UART4_IRQHandler(void)
//{
//	BaseType_t Result,xHigherPriorityTaskWoken;
//	if(USART_GetITStatus(UART4, USART_IT_IDLE)!= RESET)
//	{
//		Clear_IT = UART4->SR;
//		Clear_IT = UART4->DR;//先读SR后读DR清楚中断标志位
//		
//		if(USART_Receive(&UART4_Rcr)==UART4_RXMB_LEN)
//		{
//			 if(IRQHandler!=NULL)		
//		 {
//			Result = xEventGroupSetBitsFromISR(IRQHandler,0x03,&xHigherPriorityTaskWoken);
//		  if(Result!=pdFAIL)
//		  {
//				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//		  }	
//		 }
//     system_monitor.USART4rx_cnt++;		 
//		}		
//	}
//}

//extern USART_RX_TypeDef USART6_Rcr;
//void USART6_IRQHandler(void)
//{
//	BaseType_t Result,xHigherPriorityTaskWoken;
//	if(USART_GetITStatus(USART6, USART_IT_IDLE)!= RESET)
//	{
//		Clear_IT = USART6->SR;
//		Clear_IT = USART6->DR;//先读SR后读DR清楚中断标志位
//		
//		if(USART_Receive(&USART6_Rcr)==USART6_RXMB_LEN)
//		{
//		 if(IRQHandler!=NULL)		
//		 {
//			Result = xEventGroupSetBitsFromISR(IRQHandler,0x04,&xHigherPriorityTaskWoken);
//		  if(Result!=pdFAIL)
//		  {
//				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//		  }	
//		 }	 
//	   system_monitor.USART6rx_cnt++; 	
//	 }		 
//	}
//}
///*************************************************************************
//中断处理函数名称：void TIM5_IRQHandler(void)
//中断产生机制：
//函数功能：提供4000帧帧率
//*************************************************************************/
//extern TaskHandle_t FWheelSampleTask_Handler; 
//void TIM1_UP_TIM10_IRQHandler(void)
//{
//	BaseType_t Result,xHigherPriorityTaskWoken;
//  if(TIM_GetITStatus(TIM10,TIM_IT_Update) != RESET) 
//	{
//		TIM_ClearITPendingBit(TIM10,TIM_IT_Update);
//		if(FWheelSampleTask_Handler!=NULL)
//		{
//		  vTaskNotifyGiveFromISR(FWheelSampleTask_Handler,&xHigherPriorityTaskWoken);
//	   	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//		}
//	}
//}
///*************************************************************************
//中断处理函数名称：void TIM1_BRK_TIM9_IRQHandler(void)
//中断产生机制：
//函数功能：提供4000帧帧率
//*************************************************************************/
//extern TaskHandle_t IMUSampleTask_Handler; 
//void TIM1_BRK_TIM9_IRQHandler(void)
//{
//	BaseType_t Result,xHigherPriorityTaskWoken;
//  if(TIM_GetITStatus(TIM9,TIM_IT_Update) != RESET) 
//	{
//		TIM_ClearITPendingBit(TIM9,TIM_IT_Update);
//		if(IMUSampleTask_Handler!=NULL)
//		{
//		  vTaskNotifyGiveFromISR(IMUSampleTask_Handler,&xHigherPriorityTaskWoken);
//	   	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//		}
//	}
//}

////模拟视觉帧率发数并增加噪声
////void TIM7_IRQHandler(void)
////{
////   if(TIM_GetITStatus(TIM7,TIM_IT_Update) != RESET)
////	 {
////     TIM_ClearITPendingBit(TIM7,TIM_IT_Update);
////       static s8 a;
////		   static u8 Flag=0;
////		 if(!Flag){
////       a = rand() % 100;
////			 Flag=1;}
////		 else {a = -rand() % 100;
////			 Flag=0;}
////       static bool UpPitchDir 			= TRUE;
////	     static bool UpYawDir			= FALSE;
////       if(UpPitchDir)
////				 Visionrx_freq_data_p=Visionrx_freq_data_p+0.01f+a*0.005;
////			 else 
////				 Visionrx_freq_data_p=Visionrx_freq_data_p-0.01f-a*0.005;
////			 if(Visionrx_freq_data_p>15.0f) UpPitchDir=FALSE;
////			 if(Visionrx_freq_data_p<-30.0f) UpPitchDir=TRUE;
////       
////	 }
////}
///*************************************************************************
//中断处理函数名称：CAN1_TX_IRQHandler
//中断产生机制：
//函数功能：
//*************************************************************************/
//void CAN1_TX_IRQHandler(void)
//{
//    if (CAN_GetITStatus(CAN1,CAN_IT_TME)!= RESET) 
//	{
//		CAN_ClearITPendingBit(CAN1,CAN_IT_TME);
//  }
//}
///***********************************************************
//中断处理函数名称：CAN1_RX0_IRQHandler
//中断产生机制：
//函数功能：
//*************************************************************************/
//CanRxMsg CAN1_RxMsg;
//void CAN1_RX0_IRQHandler(void)
//{   
//  if (CAN_GetITStatus(CAN1,CAN_IT_FMP0)!= RESET)
//	{
//    CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);		
//		CAN_Receive(CAN1, CAN_FIFO0, &CAN1_RxMsg);
//		switch(CAN1_RxMsg.StdId)
//		{
//			case 0x201:
////				Abs_Encoder_Process(&g_stShooterEncoder,Get_Encoder_Number(&CAN1_RxMsg));
////	      g_stShooterPosPID.fpFB = g_stShooterEncoder.siSumValue;
////			  g_stShooterSpeedPID.fpFB = Get_Speed(&CAN1_RxMsg)/36.0f;
//			break;
//			
//			case 0x207:
//							
//			break;
//			
//			default:				
//			break;
//		}	
//		system_monitor.CAN1_cnt++;
//    }
//}
///*************************************************************************
//中断处理函数名称：CAN2_TX_IRQHandler
//中断产生机制：
//函数功能：
//*************************************************************************/
//void CAN2_TX_IRQHandler(void)
//{
//  if (CAN_GetITStatus(CAN2,CAN_IT_TME)!= RESET)
//  {
//	  CAN_ClearITPendingBit(CAN2,CAN_IT_TME);   
//  }
//}
///*************************************************************************
//中断处理函数名称：CAN2_RX0_IRQHandler
//中断产生机制：
//函数功能：
//*************************************************************************/
//#define Pitch_ZERO 120.717773
//#define Pitch_ZERO1  -5.38330078
//#define Yaw_ZERO     55.2392578
//void CAN2_RX0_IRQHandler(void)
//{
//	CanRxMsg CAN2_RxMsg;
//	
//  if (CAN_GetITStatus(CAN2,CAN_IT_FMP0)!= RESET)
//	{
//    CAN_ClearITPendingBit(CAN2, CAN_IT_FMP0);		

//		CAN_Receive(CAN2, CAN_FIFO0, &CAN2_RxMsg);
//		switch(CAN2_RxMsg.StdId)
//		{
//			case 0x203:   //拨弹电机的ID为3
//					
//			  Abs_Encoder_Process(&g_stShooterEncoder,Get_Encoder_Number(&CAN2_RxMsg));
//	      g_stShooterPosPID.fpFB = g_stShooterEncoder.siSumValue;
//			  g_stShooterSpeedPID.fpFB = Get_Speed(&CAN2_RxMsg)/36.0f;
//			// 拨盘转一圈 点击平均转295527.8转  共八格，每格步进码数=36941
//			break;
//			
//			case 0x205://yaw
//        Yaw_encode  = -Angle_Inf_To_180(-Get_Encoder_Number(&CAN2_RxMsg)*360.0/8192.0+Yaw_ZERO);	
//			  Yaw_Limit_Up_imu = -Receive_Angle_Data.Angle_Data.Yaw_Angle - Yaw_encode + Yaw_Limit_Up;
//			  Yaw_Limit_Down_imu = -Receive_Angle_Data.Angle_Data.Yaw_Angle - Yaw_encode + Yaw_Limit_Down;
//			break;
//			
//			case 0x206://pitch
//				Pitch_encode =Angle_Inf_To_180(-Get_Encoder_Number(&CAN2_RxMsg)*360.0/8192.0-Pitch_ZERO);
//			  Pitch_Limit_Up_imu = Receive_Angle_Data.Angle_Data.Pitch_Angle - Pitch_encode + Pitch_Limit_Up;
//			  Pitch_Limit_Down_imu = Receive_Angle_Data.Angle_Data.Pitch_Angle - Pitch_encode + Pitch_Limit_Down;
//			break;
//			
//			default:				
//			break;
//		}	
//		system_monitor.CAN2_cnt++;
//  }
//	
//}

//void HardFault_Handler(void)
//{
//	while(1);
//}

