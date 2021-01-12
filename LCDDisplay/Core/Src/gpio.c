


#include "gpio.h"













void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  
  HAL_GPIO_WritePin(LCD_POWER_GPIO_Port, LCD_POWER_Pin, GPIO_PIN_RESET);

  
  HAL_GPIO_WritePin(GPIOC, LCD_WR_RS_Pin|LCD_RESET_Pin, GPIO_PIN_RESET);

  
  GPIO_InitStruct.Pin = LCD_POWER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_POWER_GPIO_Port, &GPIO_InitStruct);

  
  GPIO_InitStruct.Pin = LCD_WR_RS_Pin|LCD_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}






