#include "lab4b.h"




/* USER CODE END 4 */

/* USER CODE BEGIN Header_Sender1 */

/**
  * @brief  Function implementing the Task1 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Sender1 */

void Sender1_lab4b(void *argument)
{
  /* init code for USB_DEVICE */
  //MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */




  /* Infinite loop */
  for(;;)
  {

	  messageSender1 = osEventFlagsWait(myEvent01Handle, 0x51, osFlagsWaitAll, osWaitForever);
	  CDC_Transmit_FS((uint8_t *)txBuffer1_lab4b, strlen(txBuffer1_lab4b));
	  //CDC_Transmit_FS(Buf, Len)
	  osDelay(1000);
	//osMessagePut(myQueue01Handle, &x, millisec)
	//osSemaphoreRelease(myCountingSem01Handle);


  }
  //osDelay(500);
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_Receiver */
/**
* @brief Function implementing the Task2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Receiver */
void Receiver_lab4b(void *argument)
{
  /* USER CODE BEGIN Receiver */
	//MX_USB_DEVICE_Init();

	//char *txBuffer = "Receiver \r\n";
  /* Infinite loop */
  for(;;)
  {
	  //osDelay(2000);
	  messageReceiver = osEventFlagsSet(myEvent01Handle,  0x42);

	  CDC_Transmit_FS((uint8_t *)txBuffer2_lab4b, strlen(txBuffer2_lab4b));

	  osDelay(3000);
	  //osSemaphoreAcquire(myCountingSem01Handle, 1000);
	  //osSemaphoreAcquire(myCountingSem01Handle, 1000);


  }
  /* USER CODE END Receiver */
}

/* USER CODE BEGIN Header_Sender2 */
/**
* @brief Function implementing the Task3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Sender2 */
void Sender2_lab4b(void *argument)
{
  /* USER CODE BEGIN Sender2 */
	  //char *txBuffer = "Sender2 \r\n";

	  /* Infinite loop */
	  for(;;)
	  {

		  messageSender2 = osEventFlagsWait(myEvent01Handle, 0x53, osFlagsWaitAll, osWaitForever);
		  CDC_Transmit_FS((uint8_t *)txBuffer3_lab4b, strlen(txBuffer3_lab4b));
		  osDelay(1000);
		//osMessagePut(myQueue01Handle, &x, millisec)
		//osSemaphoreRelease(myCountingSem01Handle);


	  }
	  //osDelay(500);

  /* USER CODE END Sender2 */
}
