#include "lab3c.h"



void Sender1_lab3c(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Sender \r\n";


  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {
	 osDelay(1000);
	 CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	//osMessagePut(myQueue01Handle, &x, millisec)
	osSemaphoreRelease(myBinarySem01Handle);


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
void Receiver_lab3c(void *argument)
{
  /* USER CODE BEGIN Receiver */
	//MX_USB_DEVICE_Init();
	char *txBuffer = "Receiver \r\n";
  /* Infinite loop */
  for(;;)
  {

	  osSemaphoreAcquire(myBinarySem01Handle, 4000);
	  CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	  //osDelay(50);


  }
  /* USER CODE END Receiver */
}

