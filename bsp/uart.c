/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:23
 * @LastEditTime: 2021-10-19 20:03:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\uart.c
 */

#include "uart.h"

static void open(void * dev_obj);
static int8_t write(void * dev_obj,void *data);
static int8_t read(void * dev_obj,void *data);
static void close(void * dev_obj);

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

void gpio_init(UART_OPR_T *uart_opr)
{
    uart_opr->open = open;
    uart_opr->read = read;
    uart_opr->write = write;
    uart_opr->close = close;
}


static void open(void *dev_obj)
{
	UART_PIN_NAME_T pin_name = TX;
	GPIO_OPR_T gpio_opr;

	/*open clock*/
	RCC_APB2PeriphClockCmd(G_UART_GROUP[(uint32_t)dev_obj].uart_clock, ENABLE);
	/* init uart pins*/
	gpio_init(&gpio_opr);
	while(pin_name <= RX) {
		gpio_opr.open(&(G_UART_GROUP[(uint32_t)dev_obj].uart_gpio[pin_name].pin));
	}
	USART_Init(G_UART_GROUP[(uint32_t)dev_obj].uart_x, &G_UART_GROUP[(uint32_t)dev_obj].uart_arg);
    USART_Cmd(G_UART_GROUP[(uint32_t)dev_obj].uart_x, ENABLE);
}

static int8_t write(void *dev_obj, void *handle)
{
	int8_t result_state = 0;
	
	USART_ClearFlag(G_UART_GROUP[(uint32_t)dev_obj].uart_x,USART_FLAG_TC);
	USART_SendData(G_UART_GROUP[(uint32_t)dev_obj].uart_x,*((uint16_t *)data));
	while(!USART_GetFlagStatus(G_UART_GROUP[(uint32_t)dev_obj].uart_x,USART_FLAG_TC));
	result_state = 1;

	return result_state;
}

static int8_t read(void * dev_obj,void *data)
{
	
}

static void close(void * dev_obj)
{
    USART_Cmd(G_UART_GROUP[(uint32_t)dev_obj].uart_x, DISABLE);

}

static void uart_print(void *data)
{
	
}
