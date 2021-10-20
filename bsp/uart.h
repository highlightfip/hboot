/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:17
 * @LastEditTime: 2021-10-16 19:58:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\uart.h
 */

#ifndef _UART_H
#define _UART_H

#include "stm32f10x_usart.h"
#include "bsp.h"

/** 
  * @brief  UART pin name definition  
  */
typedef enum  
{
	TX,RX
}UART_PIN_NAME_T;

/** 
  * @brief  UART dev name definition  
  */
typedef enum  
{
	UART1,UART2
}UART_NAME_T;

/** 
  * @brief  UART Init structure definition  
  */

typedef struct  
{
	UART_NAME_T	      uart_name;        /*!< uart name */
  GPIO_PIN_T      	uart_gpio[RX+1];  /*!< uart pins */
  uint32_t          uart_clock;       /*!< RCC clock */
  USART_TypeDef*    uart_x;           /*!< uart x */
  USART_InitTypeDef uart_arg;         /*!< uart config */
}UART_T;

/** 
  * @brief  UART opr structure definition  
  */
typedef struct  
{
	void (*open)(void * dev_obj);			    /*!< device init */
	int8_t (*write)(void * dev_obj,void *data);	/*!< device write */
	int8_t (*read)(void * dev_obj,void *data);	/*!< device read */
	void (*close)(void * dev_obj);		        /*!< device close */
}UART_OPR_T;

/** @defgroup UART_Exported_Constants
  * @{
  */
#define UART_GROUP_NUM 1

 /**
  * @}
  */

 /** @defgroup UART_Exported_Functions
  * @{
  */
extern void uart_init(void *dev_obj);
static void uart_print(void *data);
/**
  * @}
  */

#endif
