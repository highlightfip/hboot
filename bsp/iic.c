/*
 * @Author       : highlight
 * @Date         : 2021-10-12 23:19:34
 * @LastEditTime : 2021-10-31 12:35:23
 * @LastEditors  : highlight
 * @Description  : 
 * @FilePath     : \kbootd:\github workshop\hboot\bsp\iic.c
 */

#include "iic.h"

static void open(void * dev_obj, void *handle);
static int8_t write(void * dev_obj,void * data);
static int8_t read(void * dev_obj,void * data);
static void close(void * dev_obj);

static I2C_T G_I2C_GROUP[I2C_GROUP_NUM] =
{
    I2C_1,
    {
        {
            PB12,
            0
        }
    },
    RCC_APB1Periph_I2C1,
    I2C1,
    {
        /*I2C_ClockSpeed*/
        I2C_Mode_I2C,
        I2C_DutyCycle_16_9,
        I2C_Ack_Disable,
        I2C_AcknowledgedAddress_10bit
    }
};

void i2c_init(I2C_OPR_T *i2c_opr)
{
    i2c_opr->open = open;
    i2c_opr->read = read;
    i2c_opr->write = write;
    i2c_opr->close = close;
}

static void open(void * dev_obj, void *handle)
{
	GPIO_OPR_T gpio_opr;

	/*open clock*/
	RCC_APB2PeriphClockCmd(G_I2C_GROUP[(uint32_t)dev_obj].i2c_clock, ENABLE);
	/* init i2c pins*/
	gpio_init(&gpio_opr);
    for(; dev_obj <= I2C_GROUP_NUM; dev_obj++)
    {
        gpio_opr.open(&(G_I2C_GROUP[(uint32_t)dev_obj].i2c_gpio[i2c_num].pin), handle);
        USART_Init(G_I2C_GROUP[(uint32_t)dev_obj].i2c_x, &G_I2C_GROUP[(uint32_t)dev_obj].i2c_arg);
        USART_Cmd(G_I2C_GROUP[(uint32_t)dev_obj].i2c_x, ENABLE);
    }
}

static int8_t write(void * dev_obj,void * data)
{
    uint8_t result_state = 0;

    return result_state;
}

static int8_t read(void * dev_obj,void * data)
{
    uint8_t result_state = 0;
    
    return result_state;
}

static void close(void * dev_obj)
{

}
