/*
 * @Author: your name
 * @Date: 2021-10-11 18:43:57
 * @LastEditTime : 2021-10-29 19:02:26
 * @LastEditors  : highlight
 * @Description: In User Settings Edit
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\adc.c
 */

#include "adc.h"

static void open(void *dev_obj, void *handle);
static int8_t write(void * handle,void * data);
static int8_t read(void * handle,void * data);
static void close(void *handle);

/**
 * @brief: init adc
 * @param {ADC_OPR_T} *adc_opr
 * @retval: none
 */
void adc_init(ADC_OPR_T *adc_opr)
{
    ((ADC_OPR_T *)adc_opr)->open = open;
    ((ADC_OPR_T *)adc_opr)->read = read;
    ((ADC_OPR_T *)adc_opr)->write = write;
    ((ADC_OPR_T *)adc_opr)->close = close;
}

static void open(void *dev_obj, void *handle)
{

}

static int8_t write(void * handle,void * data)
{
    uint8_t result_state = 0;
    
    return result_state;
}

static int8_t read(void * handle,void * data)
{
    uint8_t result_state = 0;
    
    return result_state;
}

static void close(void *handle)
{

}
