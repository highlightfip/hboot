/*** 
 * @Author       : highlight
 * @Date         : 2021-10-12 23:19:34
 * @LastEditTime : 2021-10-29 22:59:34
 * @LastEditors  : highlight
 * @Description  : 
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\iic.h
 */

#ifndef _IIC_H
#define _IIC_H

#include "stm32f10x_i2c.h"
#include "bsp.h"

typedef enum{
    I2C_1
}I2C_NAME_T;


#define I2C_GROUP_NUM 1


typedef struct  
{
	I2C_NAME_T	    i2c_name;
	GPIO_PIN_T      i2c_gpio[I2C_GROUP_NUM+1];
	uint32_t        i2c_clock;
	I2C_TypeDef*    i2c_x;
	I2C_InitTypeDef i2c_arg;
} I2C_T;

typedef struct {
	void (*open)(void * dev_obj);			    /*!< device init */
	int8_t (*write)(void * dev_obj,void *data);	/*!< device write */
	int8_t (*read)(void * dev_obj,void *data);	/*!< device read */
	void (*close)(void * dev_obj);		        /*!< device close */
}I2C_OPR_T;


#endif
