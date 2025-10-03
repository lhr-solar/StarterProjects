#include "UART.h"
#include <string.h>
UART_HandleTypeDef husart2_instance;
UART_HandleTypeDef *husart2 = &husart2_instance;

void init() {
  HAL_Init();
  SystemClock_Config();
  
}

void TxTask(void *argument) {
  
  while (1) {
    // Send UART here
   

  GPIO_InitTypeDef led_init = {0};
  if(husart2->Instance == USART2)
  {
    /* USER CODE BEGIN USART2_MspInit 0 */

    /* USER CODE END USART2_MspInit 0 */
    /* Peripheral clock enable */

    led_init.Pin = GPIO_PIN_5;
    led_init.Mode = GPIO_MODE_OUTPUT_PP;
    led_init.Pull = GPIO_NOPULL;
    led_init.Alternate = 0;


    __HAL_RCC_USART2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_Init(GPIOA, &led_init);
     // enable periph clock
   

    /* USER CODE BEGIN USART2_MspInit 1 */

    /* USER CODE END USART2_MspInit 1 */

  }

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */

  }
  while (1) {
     uart_send(husart2, (const uint8_t *)"hi\n", strlen("hi\n"), portMAX_DELAY);
     HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
     HAL_Delay(500);
  }
}

StaticTask_t txTaskBuffer;
StackType_t txTaskStack[configMINIMAL_STACK_SIZE];

void HAL_UART_MspGPIOInit(UART_HandleTypeDef *huart) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

int main() {
  init();
  husart2->Instance = USART2;
  husart2->Init.BaudRate = 115200;
  husart2->Init.WordLength = UART_WORDLENGTH_8B;
  husart2->Init.StopBits = UART_STOPBITS_1;
  husart2->Init.Parity = UART_PARITY_NONE;
  husart2->Init.Mode = UART_MODE_TX_RX;
  husart2->Init.HwFlowCtl = UART_HWCONTROL_NONE;
  husart2->Init.OverSampling = UART_OVERSAMPLING_16;
  uart_init(husart2);

  xTaskCreateStatic(TxTask, "TX", configMINIMAL_STACK_SIZE, NULL,
                    tskIDLE_PRIORITY + 2, txTaskStack, &txTaskBuffer);
  vTaskStartScheduler();

   /* USER CODE BEGIN USART2_Init 0 */
  

  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
