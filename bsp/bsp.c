/*
 * @Author: your name
 * @Date: 2021-10-12 12:43:28
 * @LastEditTime: 2021-10-20 19:26:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \hboot\bsp\bsp.c
 */

#include "bsp.h"

//each 10us range 0.4us
extern void delay_us(u32 x)
{
	u32 j = 0;
    while(x--)
		{
			  j = 23;
			  while(j--);
		}
}

//each 1ms range 0.0004ms
extern void delay_ms(u32 x)
{
    u32 i = 0;
    while(x--)
    {
        i = 2498;
        while(i--);
    }
}
