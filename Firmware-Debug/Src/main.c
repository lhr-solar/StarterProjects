#include "UART.h"
#include <string.h>

void init() {
  HAL_Init();
  SystemClock_Config();
  
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

void TxTask(void *argument) {
    while (1) {
     uart_send(husart2, (const uint8_t *)"hi\n", strlen("hi\n"), portMAX_DELAY);
     HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
     HAL_Delay(500);
  }
}

StaticTask_t txTaskBuffer;
StackType_t txTaskStack[configMINIMAL_STACK_SIZE];

void HAL_UART_MspGPIOInit(UART_HandleTypeDef *huart) {
  GPIO_InitTypeDef led_init = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();
  led_init.Pin = GPIO_PIN_5;
  led_init.Mode = GPIO_MODE_OUTPUT_PP;
  led_init.Pull = GPIO_NOPULL;
  led_init.Alternate = 0;
  HAL_GPIO_Init(GPIOA, &led_init);

  // __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_USART2_CLK_ENABLE();
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
  husart2->Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  husart2->AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  uart_init(husart2);

  xTaskCreateStatic(TxTask, "TX", configMINIMAL_STACK_SIZE, NULL,
                    tskIDLE_PRIORITY + 2, txTaskStack, &txTaskBuffer);
  vTaskStartScheduler();

   /* USER CODE BEGIN USART2_Init 0 */
  

  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
