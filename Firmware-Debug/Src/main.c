#include "UART.h"

void init() {
  HAL_Init();
  SystemClock_Config();
}

void TxTask(void *argument) {
  while (1) {
    // Send UART here
  }
}

StaticTask_t txTaskBuffer;
StackType_t txTaskStack[configMINIMAL_STACK_SIZE];

int main() {
  init();

  xTaskCreateStatic(TxTask, "TX", configMINIMAL_STACK_SIZE, NULL,
                    tskIDLE_PRIORITY + 2, txTaskStack, &txTaskBuffer);

  vTaskStartScheduler();

  while (1) {
  }
}
