
#include "lab1e.h"



void StartDefaultTask_lab1e(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Task 01\r\n";

  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {

	CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	//HAL_Delay(1500);

  }
  //osDelay(500);
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the Task2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02_lab1e(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
	char *txBuffer = "Task 02\r\n";

  /* Infinite loop */
  for(;;)
  {

    //osDelay(1500);
    CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
    osThreadYield();

  }

  /* USER CODE END StartTask02 */
}
