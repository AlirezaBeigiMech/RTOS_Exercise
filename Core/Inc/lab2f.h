#include "main.h"
#include "cmsis_os.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"

extern osMessageQueueId_t myQueue01Handle;


extern osThreadId_t Task1Handle;
/* Definitions for Task2 */
extern osThreadId_t Task2Handle;
extern osThreadId_t Task3Handle;
extern uint8_t x;
extern uint8_t res;

void Sender1_lab2f(void *argument);
void Receiver_lab2f(void *argument);
void Sender2_lab2f(void *argument);
