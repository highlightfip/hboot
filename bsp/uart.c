/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:23
 * @LastEditTime : 2021-10-29 18:57:18
 * @LastEditors  : highlight
 * @Description: In User Settings Edit
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\uart.c
 */

#include "uart.h"

static void open(void *dev_obj);
static int8_t write(void *dev_obj, void *data);
static int8_t read(void *dev_obj, void *data);
static void close(void *dev_obj);

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


extern void uart_init(void *uart_opr)
{
    ((UART_OPR_T *)uart_opr)->open = open;
    ((UART_OPR_T *)uart_opr)->read = read;
    ((UART_OPR_T *)uart_opr)->write = write;
    ((UART_OPR_T *)uart_opr)->close = close;
}


static void open(void *dev_obj)
{
	UART_PIN_NAME_T pin_name = TX;
	GPIO_OPR_T gpio_opr;
	void *handle;

	/*open clock*/
	RCC_APB2PeriphClockCmd(G_UART_GROUP[(uint32_t)dev_obj].uart_clock, ENABLE);
	/* init uart pins*/
	gpio_init(&gpio_opr);
	for(; pin_name <= RX; pin_name++)
	{
		gpio_opr.open(&(G_UART_GROUP[(uint32_t)dev_obj].uart_gpio[pin_name].pin), handle);
	}
	USART_Init(G_UART_GROUP[(uint32_t)dev_obj].uart_x, &G_UART_GROUP[(uint32_t)dev_obj].uart_arg);
    USART_Cmd(G_UART_GROUP[(uint32_t)dev_obj].uart_x, ENABLE);
}

static int8_t write(void *dev_obj, void *data)
{
	int8_t result_state = 0;
	
	USART_ClearFlag(G_UART_GROUP[(uint32_t)dev_obj].uart_x, USART_FLAG_TC);
	USART_SendData(G_UART_GROUP[(uint32_t)dev_obj].uart_x, *((uint16_t *)data));
	while(!USART_GetFlagStatus(G_UART_GROUP[(uint32_t)dev_obj].uart_x, USART_FLAG_TC));
	result_state = 1;

	return result_state;
}

static int8_t read(void * dev_obj,void *data)
{
	int8_t result_state = 0;

	/* working */

	return result_state;
}

static void close(void *dev_obj)
{
    USART_Cmd(G_UART_GROUP[(uint32_t)dev_obj].uart_x, DISABLE);
	
}
