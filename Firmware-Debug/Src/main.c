#include "UART.h"

void init() {
  HAL_Init();
  SystemClock_Config();
}

void TxTask(void *argument) {
  husart2->Instance = USART2;
  husart2->Init.BaudRate = 115200;
  husart2->Init.WordLength = UART_WORDLENGTH_8B;
  husart2->Init.StopBits = UART_STOPBITS_1;
  husart2->Init.Parity = UART_PARITY_NONE;
  husart2->Init.Mode = UART_MODE_TX_RX;
  husart2->Init.HwFlowCtl = UART_HWCONTROL_NONE;
  husart2->Init.OverSampling = UART_OVERSAMPLING_16;

  uart_init(husart2);

  while (1) {
    // Send UART here
    uart_send(husart2, (const uint8_t *)"Hello World!", 13, portMAX_DELAY);
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
