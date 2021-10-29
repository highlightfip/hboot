/*** 
 * @Author       : highlight
 * @Date         : 2021-10-11 18:43:57
 * @LastEditTime : 2021-10-29 19:16:37
 * @LastEditors  : highlight
 * @Description  : 
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\adc.h
 */

#ifndef _ADC_H
#define _ADC_H

#include "bsp.h"
#include "stm32f10x_adc.h"

#define adc_num     1

/*** 
 * @brief: adc name
 */
typedef enum
{
	ADC_1,ADC_2
} ADC_NAME_T;

/** 
  * @brief  ADC Init structure definition  
  */
typedef struct
{
	ADC_NAME_T	    adc_name;
	GPIO_PIN_T      adc_gpio[adc_num+1];
	uint32_t        adc_clock;
	ADC_TypeDef*    adc_x;
	ADC_InitTypeDef adc_arg;
} ADC_INFO_T;

/*** 
 * @brief: init adc
 */
typedef struct 
{
	void (*open)(void * dev_obj,void *handle);	/*!< device init */
	int8_t (*write)(void * handle,void *data);	/*!< device write */
	int8_t (*read)(void * handle,void *data);	/*!< device read */
	void (*close)(void * handle);               /*!< device close */
} ADC_OPR_T;

/** 
  * @brief  ADC handle structure definition  
  */
typedef struct  
{
	ADC_INFO_T gpio_info;    /*!< gpio info */
	ADC_OPR_T  gpio_opr;     /*!< gpio opr */
}ADC_HANDLE_T;

extern void adc_init(ADC_OPR_T *adc_opr);

#endif
