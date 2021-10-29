/*** 
 * @Author       : highlight
 * @Date         : 2021-10-12 23:19:34
 * @LastEditTime : 2021-10-29 19:10:20
 * @LastEditors  : highlight
 * @Description  : usart oprate
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\uart.h
 */

#ifndef _UART_H
#define _UART_H

#include "stm32f10x_usart.h"
#include "bsp.h"
#include "stdarg.h"

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

#define PUTC(a) {\
    while(RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC));\
    USART_SendData(USART1, a);\
}

 /**
  * @}
  */

 /** @defgroup UART_Exported_Functions
  * @{
  */
extern void uart_init(void *dev_obj);
/**
  * @}
  */

#endif
