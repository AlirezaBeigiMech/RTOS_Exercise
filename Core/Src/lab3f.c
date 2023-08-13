#include "lab3f.h"

void Sender1_lab3f(void *argument)
{
  /* init code for USB_DEVICE */
  //MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Sender1 \r\n";


  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {

	osDelay(2000);
	CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	//osMessagePut(myQueue01Handle, &x, millisec)
	osSemaphoreRelease(myCountingSem01Handle);


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
void Receiver_lab3f(void *argument)
{
  /* USER CODE BEGIN Receiver */
	//MX_USB_DEVICE_Init();

	char *txBuffer = "Receiver \r\n";
  /* Infinite loop */
  for(;;)
  {
	  //osDelay(2000);
	  CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	  osSemaphoreAcquire(myCountingSem01Handle, 1000);
	  osSemaphoreAcquire(myCountingSem01Handle, 1000);


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
void Sender2_lab3f(void *argument)
{
  /* USER CODE BEGIN Sender2 */
	  char *txBuffer = "Sender2 \r\n";

	  /* Infinite loop */
	  for(;;)
	  {

		osDelay(2000);
		CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
		//osMessagePut(myQueue01Handle, &x, millisec)
		osSemaphoreRelease(myCountingSem01Handle);


	  }
	  //osDelay(500);

  /* USER CODE END Sender2 */
}
