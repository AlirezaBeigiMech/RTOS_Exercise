#include "lab2h.h"


Data_lab2h Data2Send1_lab2h = {'a',1};
Data_lab2h Data2Send2_lab2h = {'b',2};
/* USER CODE END Header_Sender1 */
void Sender1_lab2h(void *argument)
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
	osMessageQueuePut(myQueue01Handle, (uint8_t *)&Data2Send1_lab2h, 1, 4000);


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

void Receiver_lab2h(void *argument)
{
  /* USER CODE BEGIN Receiver */
	MX_USB_DEVICE_Init();
	Data_lab2h retvalue;

	char *txBuffer = "Receiver \r\n";
  /* Infinite loop */
  for(;;)
  {
	  CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	  osMessageQueueGet(myQueue01Handle, &retvalue, NULL, 4000);

	  //osMessageQueueGet(mq_id, msg_ptr, msg_prio, timeout)
	  //osMessageQueueGet(mq_id, msg_ptr, msg_prio, timeout)
	  //char *txBuffer1 = (char *)(res+48);
	  osDelay(100);
	  res1 = retvalue.source;
	  CDC_Transmit_FS((uint8_t *)&res1, strlen((char *)&res1));
	  res2 = retvalue.value;
	  res2 = res2 + 49;
	  CDC_Transmit_FS((uint8_t *)&res2, strlen((char *)&res2));


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
void Sender2_lab2h(void *argument)
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
		//x = 2;
		osMessageQueuePut(myQueue01Handle, (uint8_t *)&Data2Send2_lab2h, 1, 4000);


		osDelay(2000);

	  }
  /* USER CODE END Sender2 */
}
