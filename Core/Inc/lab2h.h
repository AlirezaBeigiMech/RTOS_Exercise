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
extern uint16_t res2;
extern uint16_t res1;

typedef struct  {
    uint8_t source;
    uint16_t value;
} Data_lab2h;



void Sender1_lab2h(void *argument);
void Receiver_lab2h(void *argument);
void Sender2_lab2h(void *argument);
