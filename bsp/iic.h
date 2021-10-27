/*
 * @Author: your name
 * @Date: 2021-10-11 18:47:22
 * @LastEditTime: 2021-10-26 22:01:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\iic.h
 */

#ifndef _IIC_H
#define _IIC_H

#include "stm32f10x_i2c.h"
#include "bsp.h"

typedef enum{
    I2C_1
}I2C_NAME_T;

typedef struct  
{
	I2C_NAME_T	      uart_name;        /*!< uart name */
	GPIO_PIN_T        uart_gpio[RX+1];  /*!< uart pins */
	uint32_t          uart_clock;       /*!< RCC clock */
	I2C_TypeDef*      uart_x;           /*!< uart x */
	I2C_InitTypeDef   uart_arg;         /*!< uart config */
}I2C_T;

typedef struct {
	void (*open)(void * dev_obj);			    /*!< device init */
	int8_t (*write)(void * dev_obj,void *data);	/*!< device write */
	int8_t (*read)(void * dev_obj,void *data);	/*!< device read */
	void (*close)(void * dev_obj);		        /*!< device close */
}I2C_OPR_T;


#endif
