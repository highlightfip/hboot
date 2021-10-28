/*
 * @Author: highlight
 * @Date: 2021-10-10 19:09:34
 * @LastEditTime: 2021-10-13 20:54:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\gpio.h
 */

#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stdint.h"


#define GPIO_GROUP_NUM                 16
#define GPIO_GROUP(x)                  (GPIO_TypeDef*)(APB2PERIPH_BASE + (0x0800+0x400*(x)))
#define GPIO_PIN(x)                    GPIO_Pin_0<<(x)
#define GPIO_RCC_CLOCK(x)              RCC_APB2Periph_GPIOA<<(x)
#define GPIO_Speed_MAX                 GPIO_Speed_50MHz
#define GPIO_MODE_IS(mode)             ((mode) == GPIO_Mode_Out_OD ||  (mode) == GPIO_Mode_Out_PP)?GPIO_OUT:\
                                       (((mode) == GPIO_Mode_IPU ||  (mode) == GPIO_Mode_IPD)?GPIO_IN:-1) 

/**
 * @brief GPIO 
 */
typedef enum
{
  PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15,
  PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB11,PB12,PB13,PB14,PB15,
  PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,PC8,PC9,PC10,PC11,PC12,PC13,PC14,PC15,
  PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,PD8,PD9,PD10,PD11,PD12,PD13,PD14,PD15,
  PE0,PE1,PE2,PE3,PE4,PE5,PE6,PE7,PE8,PE9,PE10,PE11,PE12,PE13,PE14,PE15,
  PF0,PF1,PF2,PF3,PF4,PF5,PF6,PF7,PF8,PF9,PF10,PF11,PF12,PF13,PF14,PF15,
  PG0,PG1,PG2,PG3,PG4,PG5,PG6,PG7,PG8,PG9,PG10,PG11,PG12,PG13,PG14,PG15,
} GPIO_PIN_NAME_T;

/** 
  * @brief  GPIO dir definition  
  */
typedef enum  
{
  GPIO_IN,GPIO_OUT
} GPIO_DIR_T;

/** 
  * @brief  GPIO pin info structure definition  
  */
typedef struct  
{
  GPIO_PIN_NAME_T  pin;     /*!< led pin */
  BitAction effe_level;		  /*!< Effective level */
} GPIO_PIN_T;

/** 
  * @brief  GPIO info structure definition && handle
  */
typedef struct  
{
	uint32_t gpio_clock;				/*!< RCC clock */
	GPIO_TypeDef* gpiox;				/*!< GPIO group */
	GPIO_InitTypeDef  gpio_arg;	/*!< GPIO config */
} GPIO_INFO_T;

/**
 * @brief GPIO_opr struction definition
 */
typedef struct 
{
	void (*open)(void * dev_obj,void *handle);	/*!< device init */
	int8_t (*write)(void * handle,void *data);	/*!< device write */
	int8_t (*read)(void * handle,void *data);	/*!< device read */
	void (*close)(void * handle);               /*!< device close */
} GPIO_OPR_T;

/** 
  * @brief  GPIO handle structure definition  
  */
typedef struct  
{
	GPIO_INFO_T gpio_info;    /*!< gpio info */
	GPIO_OPR_T  gpio_opr;     /*!< gpio opr */
}GPIO_HANDLE_T;

/**
 * @description: init dev_obj_opr to operate
 * @param {void} *dev_obj_opr
 * @return {none}
 */
extern void gpio_opr_init(void *dev_obj_opr);

#endif
