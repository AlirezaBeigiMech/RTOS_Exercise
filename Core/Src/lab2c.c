#include "lab2c.h"

/* USER CODE END Header_Sender */

void Sender_lab2c(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Sender \r\n";

  x = 0;
  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {
	CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	//osMessagePut(myQueue01Handle, &x, millisec)
	osMessageQueuePut(myQueue01Handle, (uint8_t *)&x, 1, 2000);

	if (++x>9){
		x = 0;
	}
	osDelay(1500);

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
uint8_t res;
void Receiver_lab2c(void *argument)
{
  /* USER CODE BEGIN Receiver */
	MX_USB_DEVICE_Init();

	char *txBuffer = "Receiver \r\n";
  /* Infinite loop */
  for(;;)
  {
	  CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	  osMessageQueueGet(myQueue01Handle, (uint8_t *)&res, NULL, 2000);
	  //osMessageQueueGet(mq_id, msg_ptr, msg_prio, timeout)
	  //osMessageQueueGet(mq_id, msg_ptr, msg_prio, timeout)
	  //char *txBuffer1 = (char *)(res+48);
	  osDelay(100);
	  res = res + 49;
	  CDC_Transmit_FS((uint8_t *)&res, strlen((char *)&res));


	  osDelay(1500);
  }
  /* USER CODE END Receiver */
}
