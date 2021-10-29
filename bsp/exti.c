/*
 * @Author: your name
 * @Date: 2021-10-11 18:43:57
 * @LastEditTime : 2021-10-29 18:52:11
 * @LastEditors  : highlight
 * @Description: In User Settings Edit
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\exti.c
 */

#include "exti.h"

static void open(void *dev_obj, void *handle);
static int8_t write(void * handle,void * data);
static int8_t read(void * handle,void * data);
static void close(void *handle);

static EXTI_T G_EXTI_GROUP[EXTI_GROUP_NUM] =
{
    {
        EXTI_Line1,
        EXTI_Mode_Interrupt,
        EXTI_Trigger_Rising,
        ENABLE
    }
};

void adc_init(EXTI_OPR_T *exti_opr)
{
    ((EXTI_OPR_T *)exti_opr)->open = open;
    ((EXTI_OPR_T *)exti_opr)->read = read;
    ((EXTI_OPR_T *)exti_opr)->write = write;
    ((EXTI_OPR_T *)exti_opr)->close = close;
}

static void open(void *dev_obj, void *handle)
{
    EXTI_InitTypeDef *exti_inf;
    EXTI_Init(exti_inf);
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
