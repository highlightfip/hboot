/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:23
 * @LastEditTime: 2021-10-11 13:24:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\uart.c
 */

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "uart.h"

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

static void write(void *inf, void *handle)
{

}

static void read(void *inf, void *handle)
{

}

static void close(void *handle)
{
    
}
