#include "main.h"
#include "stm32f1xx_hal.h"

UART_HandleTypeDef huart2;

uint8_t txData[] = "Hello ESP32!\n";
uint8_t rxData[20];

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    while (1)
    {
        // Transmit data to ESP
        if (HAL_UART_Transmit(&huart2, txData, sizeof(txData), HAL_MAX_DELAY) != HAL_OK)
        {
            Error_Handler();
        }

        // Receive data from ESP
        if (HAL_UART_Receive(&huart2, rxData, sizeof(rxData), HAL_MAX_DELAY) == HAL_OK)
        {
            // Process received data
        }

        HAL_Delay(1000);  // Delay between transmissions
    }
}

static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

void Error_Handler(void)
{
    while(1)
    {
        // Stay in this loop if there's an error
    }
}
