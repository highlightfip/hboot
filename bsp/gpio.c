/*
 * @Author: highlight
 * @Date: 2021-10-10 19:08:45
 * @LastEditTime: 2021-10-20 16:27:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\gpio.c
 */

#include "bsp.h"

static void open(void *dev_obj, void *handle);
static int8_t write(void * handle,void * data);
static int8_t read(void * handle,void * data);
static void close(void *handle);

void gpio_opr_init(void *dev_obj_opr)
{
    ((GPIO_OPR_T *)dev_obj_opr)->open = open;
    ((GPIO_OPR_T *)dev_obj_opr)->read = read;
    ((GPIO_OPR_T *)dev_obj_opr)->write = write;
    ((GPIO_OPR_T *)dev_obj_opr)->close = close;
}
/**
 * @description: 
 * @param {void} *dev_obj
 * @param {void} *handle
 * @return {*}
 */
static void open(void *dev_obj, void *handle)
{
    BSP_BASE_T *bsp_base = (BSP_BASE_T *)dev_obj;
	GPIO_INFO_T *gpio_info = (GPIO_INFO_T *)handle;
    uint8_t pin_flag = 0;
    
    for(pin_flag = 0; pin_flag < bsp_base->dev_pin_num; pin_flag++)
    {
        gpio_info->gpio_clock = GPIO_RCC_CLOCK(bsp_base->dev_pins[pin_flag].pin/GPIO_GROUP_NUM); 
        gpio_info->gpiox = GPIO_GROUP(bsp_base->dev_pins[pin_flag].pin/GPIO_GROUP_NUM);
        
        gpio_info->gpio_arg.GPIO_Speed = GPIO_Speed_MAX;
        gpio_info->gpio_arg.GPIO_Pin = GPIO_PIN(bsp_base->dev_pins[pin_flag].pin%GPIO_GROUP_NUM);
        gpio_info->gpio_arg.GPIO_Mode = bsp_base->dev_type;

		/* open the clock */
        RCC_APB1PeriphClockCmd(gpio_info->gpio_clock, ENABLE);
		/* init gpio*/
        GPIO_Init(gpio_info->gpiox, &(gpio_info->gpio_arg));
    }
}

/**
 * @description: write the device
 * @param {void *} handle = gpio info
 * @param {void *} data
 * @return operate state
 */
static int8_t write(void *handle,void *data)
{
	GPIO_INFO_T *gpio_obj = &(((GPIO_HANDLE_T *)handle)->gpio_info);
	BitAction gpio_opr =  (BitAction)((uint32_t)(data));
	int8_t result_state = 0;

	if(GPIO_MODE_IS(gpio_obj->gpio_arg.GPIO_Mode) == GPIO_OUT)
	{
		GPIO_WriteBit(gpio_obj->gpiox,gpio_obj->gpio_arg.GPIO_Pin,gpio_opr);
		result_state = 0;
	}
	else
	{
		result_state = -1;
	}

	return result_state;
}

/**
 * @description: read the portion
 * @param {void *} handle
 * @param {void *} data
 * @return {*}
 */
static int8_t read(void * handle,void * data)
{
	GPIO_INFO_T *gpio_obj = &(((GPIO_HANDLE_T *)handle)->gpio_info);
	int8_t result_state = 0;

	if(GPIO_MODE_IS(gpio_obj->gpio_arg.GPIO_Mode) == GPIO_IN )
	{
		result_state =  GPIO_ReadInputDataBit(gpio_obj->gpiox,gpio_obj->gpio_arg.GPIO_Pin);
		*(uint8_t *)data = result_state;
	}
	else if(GPIO_MODE_IS(gpio_obj->gpio_arg.GPIO_Mode) == GPIO_OUT )
	{
		result_state =  GPIO_ReadOutputDataBit(gpio_obj->gpiox,gpio_obj->gpio_arg.GPIO_Pin);
		*(uint8_t *)data = result_state;
	}
	else
	{
		result_state = -1;
	}

	return result_state;
}

static void close(void *handle)
{
	// GPIO_INFO_T *gpio_obj = &(((GPIO_HANDLE_T *)handle)->gpio_info);
	/* 暂时想不到必（怎）要（么）性（做） */
}
