```c
#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"

#define LED2_GPIO 	GPIOB		//LED2端口宏定义
#define LED2_Pin	GPIO_Pin_3	//LED2引脚宏定义
#define LED2_ON		LED2_GPIO->BRR	=	LED2_Pin	//点亮LED操作


void LED_Init(void)
{
    GPIO_InitTypedef GPIO_Structure;
   	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//开启时钟
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);//复用使能
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, EnABLE);
    GPIO_Structure.GPIO_Pin = LED2_Pin;//配置管脚
    GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;//翻转速度
    GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP;//输出模式
    GPIO_Init(LED2_GPIO, &GPIO_Structure);
}
```

