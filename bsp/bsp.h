/*
 * @Author: your name
 * @Date: 2021-10-12 12:43:34
 * @LastEditTime: 2021-10-13 20:48:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\bsp.h
 */

#ifndef _BSP_H
#define _BSP_H

#include "gpio.h"
#include "stm32f10x.h"
#include "stdint.h"

#define BSP_PIN_NUM_MAX 1
/** 
 * @brief  BSP type
 * 00000000
 * 0-3bit  description properties

	0,1bit:out-driver
		1bit: od 
			0:dis 1:en
		1bit: pp 
			0:dis 1:en
	2,3bit:
		3bit: up 
			0:dis 1:en
		4bit: down 
			0:dis 1:en

	4-7bit:device type
			0000:PIN_DEV
					PIN_OD    0001  0x01
					PIN_PP    0010  0x02
					PIN_UP    0100  0x04
					PIN_DOWN  1000  0x08
			0001:UART_DEV
			0002:IIC_DEV
			0003:SPI_DEV
 */
typedef enum  
{
	PIN_DEV = 0x00, 
					PIN_OUT = 0x00,PIN_OD = 0x01,PIN_PP = 0x02,PIN_INPUT = 0x03,
					PIN_UP = 0x04, PIN_DOWN = 0x08,
		UART_DEV = 0x10,
		IIC_DEV = 0x20,
		SPI_DEV = 0x30,
} BSP_TYPE_T;

/** 
	* @brief  LED Init structure definition  
	*/
typedef struct  
{
	GPIOMode_TypeDef	dev_type;			        /*!< device type */
	GPIO_PIN_T          dev_pins[BSP_PIN_NUM_MAX];  /*!< device pin */
	uint8_t             dev_pin_num;                /*!< device pin num */
	// uint8_t     _RESERVE_[3];
} BSP_BASE_T;

#endif
