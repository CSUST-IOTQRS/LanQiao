/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED6_Pin GPIO_PIN_13
#define LED6_GPIO_Port GPIOC
#define LED7_Pin GPIO_PIN_14
#define LED7_GPIO_Port GPIOC
#define LED8_Pin GPIO_PIN_15
#define LED8_GPIO_Port GPIOC
#define B4_Pin GPIO_PIN_0
#define B4_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOB
#define B2_Pin GPIO_PIN_1
#define B2_GPIO_Port GPIOB
#define B3_Pin GPIO_PIN_2
#define B3_GPIO_Port GPIOB
#define R38_Pin GPIO_PIN_12
#define R38_GPIO_Port GPIOB
#define MC_Pin GPIO_PIN_14
#define MC_GPIO_Port GPIOB
#define R37_Pin GPIO_PIN_15
#define R37_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_8
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOC
#define R40_Pin GPIO_PIN_15
#define R40_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_10
#define LED3_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_11
#define LED4_GPIO_Port GPIOC
#define LED5_Pin GPIO_PIN_12
#define LED5_GPIO_Port GPIOC
#define HC_Pin GPIO_PIN_2
#define HC_GPIO_Port GPIOD
#define R39_Pin GPIO_PIN_4
#define R39_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
