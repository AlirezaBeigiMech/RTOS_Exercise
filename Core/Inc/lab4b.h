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

extern osEventFlagsId_t myEvent01Handle;


char *txBuffer1_lab4b = "Sender1 \r\n";
char *txBuffer2_lab4b = "Receiver \r\n";
char *txBuffer3_lab4b = "Sender2 \r\n";
char *txBuffer4_lab4b = "Sender Int \r\n";

extern uint32_t messageSender1;
extern uint32_t messageSender2;
extern uint32_t messageReceiver;


void Sender1_lab4b(void *argument);
void Receiver_lab4b(void *argument);
void Sender2_lab4b(void *argument);


