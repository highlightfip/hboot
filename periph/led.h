/*
 * @Author: your name
 * @Date: 2021-10-11 18:43:57
 * @LastEditTime: 2021-10-20 15:06:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \kbootd:\github workshop\hboot\periph\led.h
 */

#include "bsp.h"


typedef uint32_t * LED_NAME_T;
typedef uint32_t * LED_ACTION_T;

typedef enum
{
    LV0,LV1,LV2,LV3,LV4
}LED_STATE_T;


typedef struct
{
    BSP_BASE_T led_bsp;
    LED_NAME_T led_name;
    LED_STATE_T led_state;
}LED_INFO_T;

typedef struct 
{
    void (*open)(void *dev_obj, void *handle);
    int8_t (*write)(void *handle, void *data);
    int8_t (*read)(void *handle, void *data);
    void (*close)(void *handle);
}LED_OPR_T;

typedef struct
{
    LED_INFO_T led_info;
    GPIO_HANDLE_T gpio_handle;
    LED_OPR_T led_opr;
}LED_HANDLE_T;

#define LED_GROUP_NUM 1

#define LED1 (uint32_t *)0

#define OFF (uint8_t *)0
#define ON  !OFF

extern void led_opr_init(void *dev_obj);

#endif
