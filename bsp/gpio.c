/*
 * @Author: highlight
 * @Date: 2021-10-10 19:08:45
 * @LastEditTime: 2021-10-11 13:23:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\gpio.c
 */
#include "gpio.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void gpio_init(GPIO_opr *gpio_opr)
{
    gpio_opr->open = open;
    gpio_opr->read = read;
    gpio_opr->write = write;
    gpio_opr->close = close;
}

static void open(void *dev_obj, void *handle)
{
    GPIO_InitTypeDef *gpio_def;

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

