/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:23
 * @LastEditTime: 2021-10-12 20:02:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\uart.c
 */

#include "uart.h"


static void open(void *UART_inf, void *UART_opt);
static int8_t write(void *UART_inf, void *UART_opt);
static int8_t read(void *UART_inf, void *UART_opt);
static void close(void *UART_inf, void *UART_opt);

/**
  * uart1 : tx pa9    rx pa10
  */

static UART_T G_UART_GROUP[UART_GROUP_NUM] = 
{
	UART1,
	{
		{//tx pa9
			PA9,
			0
		},
		{//rx pa10
			PA10,
			0
		},
		
	},
	RCC_APB2Periph_USART1,
	USART1,
	{
		9600,
		USART_WordLength_8b,
		USART_StopBits_1,
		USART_Parity_No,
		USART_Mode_Tx | USART_Mode_Rx,
		USART_HardwareFlowControl_None,
	}
};

void gpio_init(UART_opr *uart_opr)
{
    uart_opr->open = open;
    uart_opr->read = read;
    uart_opr->write = write;
    uart_opr->close = close;
}


static void open(void *dev_obj, void *handle)
{
    
}

static int8_t write(void *inf, void *handle)
{

}

static int8_t read(void *inf, void *handle)
{

}

static void close(void *handle)
{
    
}
