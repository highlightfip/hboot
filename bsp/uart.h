/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:17
 * @LastEditTime: 2021-10-11 13:24:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\uart.h
 */

#ifndef _UART_H
#define _UART_H

#include "stm32f10x.h"
#include "stm32f10x_usart.h"


typedef struct {
    void (*open)(void *dev_obj, void *handle);
    void (*write)(void *inf, void *handle);
    void (*read)(void *inf, void *handle);
    void (*close)(void *handle);
} UART_opr;

static void open(void *UART_inf, void *UART_opt);
static void write(void *UART_inf, void *UART_opt);
static void read(void *UART_inf, void *UART_opt);
static void close(void *UART_inf, void *UART_opt);

#endif
