/*
 * @Author: your name
 * @Date: 2021-10-20 22:57:06
 * @LastEditTime: 2021-10-20 22:57:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \kbootd:\github workshop\hboot\periph\port.c
 */

#include "uart.h"
#include "iic.h"


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

static void print(void *dev_obj, const char *frm , ...)
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
