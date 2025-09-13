#include "UART.h"
#include "stm32f4xx_hal_rcc.h"

void init() {
  HAL_Init();
  SystemClock_Config();
}

void HAL_UART_MspGPIOInit(UART_HandleTypeDef *huart) {
  GPIO_InitTypeDef GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
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

  GPIO_InitTypeDef led_init = {.Pin = GPIO_PIN_5,
                               .Mode = GPIO_MODE_OUTPUT_PP,
                               .Pull = GPIO_NOPULL,
                               .Alternate = 0};

  __HAL_RCC_GPIOA_CLK_ENABLE();

  HAL_GPIO_Init(GPIOA, &led_init);

  uart_init(husart2);

  while (1) {
    // Send UART here
    uart_send(husart2, (const uint8_t *)"Hello World!", 13, portMAX_DELAY);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    vTaskDelay(1000);
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
