#include "main.h"
#include "cmsis_os.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"

void StartDefaultTask1(void *argument);
void StartTask021(void *argument);


osThreadId_t Task1Handle;
/* Definitions for Task2 */
osThreadId_t Task2Handle;


void StartDefaultTask_lab1a(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  char *txBuffer = "Task 01\r\n";
  osPriority_t Priority;


  //uint8_t message[8] = "hello \n";
  /* Infinite loop */
  for(;;)
  {
	  //Task_action('1');
	  Priority = uxTaskPriorityGet(Task2Handle);
	 //osDelay(1500);
	CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
	osThreadSetPriority(Task2Handle, Priority + 1 );
	HAL_Delay(1500);

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
void StartTask02_lab1a(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
	char *txBuffer = "Task 02\r\n";
	osPriority_t Priority;
  /* Infinite loop */
  for(;;)
  {
	 Priority = uxTaskPriorityGet(Task2Handle);
    //Task_action('2');
    osDelay(1500);
    CDC_Transmit_FS((uint8_t *)txBuffer, strlen(txBuffer));
    osThreadSetPriority(Task2Handle, Priority - 2 );

  }

  /* USER CODE END StartTask02 */
}
