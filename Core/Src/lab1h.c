
#include "lab1h.h"


void StartDefaultTask_lab1h(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Task 01\r\n";

  osThreadId_t Task2Handle;
  const osThreadAttr_t Task2_attributes = {
    .name = "Task2",
    .stack_size = 256 * 4,
    .priority = (osPriority_t) osPriorityNormal2,
  };

  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {
	Task2Handle = osThreadNew(StartTask02_lab1h, NULL, &Task2_attributes);
	CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	osDelay(1500);

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
void StartTask02_lab1h(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
	char *txBuffer = "Task 02\r\n";

  /* Infinite loop */
  for(;;)
  {

    osDelay(1500);
    CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));

  }

  /* USER CODE END StartTask02 */
}
