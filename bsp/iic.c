/*
 * @Author: your name
 * @Date: 2021-10-12 23:19:34
 * @LastEditTime: 2021-10-26 21:57:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\iic.c
 */

#include "iic.h"

static void open(void * dev_obj);
static int8_t write(void * dev_obj,void * data);
static int8_t read(void * dev_obj,void * data);
static void close(void * dev_obj);

void gpio_init(I2C_OPR_T *uart_opr)
{
    uart_opr->open = open;
    uart_opr->read = read;
    uart_opr->write = write;
    uart_opr->close = close;
}

static void open(void * dev_obj)
{

    I2C_Init();
    I2C_Cmd();
}

static int8_t write(void * dev_obj,void * data)
{

}

static int8_t read(void * dev_obj,void * data)
{

}

static void close(void * dev_obj)
{

}
