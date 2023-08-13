#include "main.h"
#include "cmsis_os.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"


extern osSemaphoreId_t myCountingSem01Handle;

extern osMessageQueueId_t myQueue01Handle;


extern osThreadId_t Task1Handle;
/* Definitions for Task2 */
extern osThreadId_t Task2Handle;
extern osThreadId_t Task3Handle;





void Sender1_lab3f(void *argument);
void Receiver_lab3f(void *argument);
void Sender2_lab3f(void *argument);


