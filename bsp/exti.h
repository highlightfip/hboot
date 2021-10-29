/*** 
 * @Author       : highlight
 * @Date         : 2021-10-11 18:43:57
 * @LastEditTime : 2021-10-29 18:40:13
 * @LastEditors  : highlight
 * @Description  : 
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\exti.h
 */

#ifndef _EXTI_H
#define _EXTI_H

#include "bsp.h"
#include "stm32f10x_exti.h"

typedef struct 
{
    EXTI_InitTypeDef *exti_arg;
} EXTI_T;

#define EXTI_GROUP_NUM 1

/**
 * @brief GPIO_opr struction definition
 */
typedef struct 
{
	void (*open)(void * dev_obj,void *handle);	/*!< device init */
	int8_t (*write)(void * handle,void *data);	/*!< device write */
	int8_t (*read)(void * handle,void *data);	/*!< device read */
	void (*close)(void * handle);               /*!< device close */
} EXTI_OPR_T;

extern void exti_init(EXTI_OPR_T *exti_opr);

#endif
