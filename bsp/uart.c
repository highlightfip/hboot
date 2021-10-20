/*
 * @Author: highlight
 * @Date: 2021-10-10 19:11:23
 * @LastEditTime: 2021-10-20 16:59:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\uart.c
 */

#include "uart.h"

static void open(void *dev_obj);
static int8_t write(void *dev_obj, void *data);
static int8_t read(void *dev_obj, void *data);
static void close(void *dev_obj);

/**
  * uart1 : tx pa9    rx pa10
  */

static UART_T G_UART_GROUP[UART_GROUP_NUM] = 
{
	UART1,
	{
		{//tx pa9
			PA9,
			0
		},
		{//rx pa10
			PA10,
			0
		},
		
	},
	RCC_APB2Periph_USART1,
	USART1,
	{
		9600,
		USART_WordLength_8b,
		USART_StopBits_1,
		USART_Parity_No,
		USART_Mode_Tx | USART_Mode_Rx,
		USART_HardwareFlowControl_None,
	}
};

void gpio_init(UART_OPR_T *uart_opr)
{
    uart_opr->open = open;
    uart_opr->read = read;
    uart_opr->write = write;
    uart_opr->close = close;
}


static void open(void *dev_obj)
{
	UART_PIN_NAME_T pin_name = TX;
	GPIO_OPR_T gpio_opr;
	void *handle;

	/*open clock*/
	RCC_APB2PeriphClockCmd(G_UART_GROUP[(uint32_t)dev_obj].uart_clock, ENABLE);
	/* init uart pins*/
	gpio_init(&gpio_opr);
	for(; pin_name <= RX; pin_name++)
	{
		gpio_opr.open(&(G_UART_GROUP[(uint32_t)dev_obj].uart_gpio[pin_name].pin), handle);
	}
	USART_Init(G_UART_GROUP[(uint32_t)dev_obj].uart_x, &G_UART_GROUP[(uint32_t)dev_obj].uart_arg);
    USART_Cmd(G_UART_GROUP[(uint32_t)dev_obj].uart_x, ENABLE);
}

static int8_t write(void *dev_obj, void *data)
{
	int8_t result_state = 0;
	
#if 0
	USART_ClearFlag(G_UART_GROUP[(uint32_t)dev_obj].uart_x,USART_FLAG_TC);
	USART_SendData(G_UART_GROUP[(uint32_t)dev_obj].uart_x,*((uint16_t *)data));
	while(!USART_GetFlagStatus(G_UART_GROUP[(uint32_t)dev_obj].uart_x,USART_FLAG_TC));
	result_state = 1;
#else
	uart_print((char *)data);
#endif

	return result_state;
}

static int8_t read(void * dev_obj,void *data)
{
	
}

static void close(void *dev_obj)
{
    USART_Cmd(G_UART_GROUP[(uint32_t)dev_obj].uart_x, DISABLE);
	
}

static void uart_send(char *string)
{
    u32 i = 0;
    //USART_ClearFlag(USART1, USART_FLAG_TC);
    while(string[i])
    {
        delay_us(5);    
        //确定reset再发送数据
        PUTC(string[i]);
        i++;
    }
    return ;
}

static u32 output_num(u32 n, u32 digit)
{
    u32 cnt = 0;
    while (digit--) {
        PUTC(n % 10 + '0');
        ++cnt;
        n /= 10;    
    }
    return cnt;
}

static void uart_print(const char *frm , ...)
{
    u32 cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (u32 i = 0; frm[i]; i++)
	{
        switch (frm[i])
		{
            case '%':
			{
                switch (frm[++i])
				{
                    case '%':
					{
						PUTC(frm[i]);
						break;
					}
                    case 'd':
					{
                        int x = va_arg(arg, u32);
                        u32 xx = 0;
                        if (x < 0)
                        {
                            PUTC('-');
                            xx = -x;
                        }
                        else
                        {
                            xx = x;
                        }
                        u32 x1 = xx / 100000, x2 = xx % 100000;
                        u32 temp1 = 0, temp2 = 0;
                        u32 digit1 = reverse_num(x1, &temp1);
                        u32 digit2 = reverse_num(x2, &temp2);
                        u32 digit3 = 0;
                        if (x1) digit3 = 5 - digit2;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(0, digit3);
                        cnt += output_num(temp2, digit2);
						break;
                    }
                    case 's':
					{
                        char *str = va_arg(arg, char *);
                        uart_send(str);
						break;
                    }
                    case 'c':
					{
                        char str = va_arg(arg, char);
    					PUTC(str);
						break;
                    } 
                }
				break;
            }
			case '\\':
			{
				switch (frm[++i])
				{
					case '\\':
					{
						PUTC(frm[i]);
						break;
					}
				}
			}
            default: 
			{
				PUTC(frm[i]);
				break;
			}
        }
    }
    va_end(arg);
    return cnt;
}
