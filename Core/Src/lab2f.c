#include "lab2f.h"

void Sender1_lab2f(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Sender \r\n";


  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {
	CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	//osMessagePut(myQueue01Handle, &x, millisec)
	x = 1;
	osMessageQueuePut(myQueue01Handle, (uint8_t *)&x, 1, 4000);


	osDelay(2000);

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

void Receiver_lab2f(void *argument)
{
  /* USER CODE BEGIN Receiver */
	MX_USB_DEVICE_Init();

	char *txBuffer = "Receiver \r\n";
  /* Infinite loop */
  for(;;)
  {
	  CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	  osMessageQueueGet(myQueue01Handle, (uint8_t *)&res, NULL, 4000);
	  //osMessageQueueGet(mq_id, msg_ptr, msg_prio, timeout)
	  //osMessageQueueGet(mq_id, msg_ptr, msg_prio, timeout)
	  //char *txBuffer1 = (char *)(res+48);
	  osDelay(100);
	  res = res + 49;
	  CDC_Transmit_FS((uint8_t *)&res, strlen((char *)&res));


	  osDelay(2000);
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
void Sender2_lab2f(void *argument)
{
  /* USER CODE BEGIN Sender2 */
  /* Infinite loop */
	  MX_USB_DEVICE_Init();
	  /* USER CODE BEGIN 5 */
	  char *txBuffer = "Sender \r\n";


	  //uint8_t message[8] = "hello \n";
	  /* Infinite loop */
	  for(;;)
	  {
		CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
		//osMessagePut(myQueue01Handle, &x, millisec)
		x = 2;
		osMessageQueuePut(myQueue01Handle, (uint8_t *)&x, 1, 4000);


		osDelay(2000);

	  }
  /* USER CODE END Sender2 */
}
