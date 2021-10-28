/*
 * @Author: your name
 * @Date: 2021-10-11 18:43:57
 * @LastEditTime: 2021-10-20 15:36:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \kbootd:\github workshop\hboot\periph\led.c
 */

#include "led.h"

static void open(void * dev_obj,void *handle);
static int8_t write(void * hanled,void * data);
static int8_t read(void * hanled,void * data);
static void close(void * hanled);

static LED_INFO_T G_LED_INFO_GROUP[LED_GROUP_NUM] =
{
    {
        {                                //BSP_BASE_T
            (PIN_DEV | PIN_OUT | PIN_PP),   //GPIOMode_TypeDef
            {
                {
                    PC13,
                    0
                },                          //GPIO_PIN_T[0]
            },                              //GPIO_PIN_T[]
            1,
        },
        LED1,                            //LED_NAME_T
        LV0                              //LED_STATE_T
    }
};

void led_opr_init(void *dev_obj_opr)
{
    ((LED_OPR_T *)dev_obj_opr)->open = open;
    ((LED_OPR_T *)dev_obj_opr)->write = write;
    ((LED_OPR_T *)dev_obj_opr)->read = read;
    ((LED_OPR_T *)dev_obj_opr)->close = close;
}

static void open(void *dev_obj,void *handle)
{
    LED_HANDLE_T *lh = (LED_HANDLE_T *)handle;

    memcpy(&lh->led_info, &G_LED_INFO_GROUP[(uint32_t)dev_obj], sizeof(LED_INFO_T));
    gpio_opr_init(&lh->gpio_handle.gpio_opr);
    lh->gpio_handle.gpio_opr.open(&(lh->led_info.led_bsp), &(lh->gpio_handle.gpio_opr));
    write(lh, OFF);
}

static int8_t write(void * handle,void * data)
{
    LED_HANDLE_T *lh = (LED_HANDLE_T *)handle;
    int8_t result_state = 0;
    uint32_t *opr;

    if(!lh->led_info.led_bsp.dev_pins[0].effe_level)
    {
        opr = (uint32_t *)(!(uint32_t)((uint32_t *)(data)));
    }
    else
    {
        opr = (uint32_t *)(data);
    }
    result_state = lh->gpio_handle.gpio_opr.write(&(lh->gpio_handle), opr);

    return result_state;
}

static int8_t read(void * handle,void * data)
{
    LED_HANDLE_T *lh = (LED_HANDLE_T *)handle;
    int8_t result_state = 0;

    result_state = lh->gpio_handle.gpio_opr.read(&lh->gpio_handle, data);
    return result_state;
}

static void close(void * handle)
{
    LED_HANDLE_T *lh = (LED_HANDLE_T *)handle;
    lh->gpio_handle.gpio_opr.close(&lh->gpio_handle);
    
}
