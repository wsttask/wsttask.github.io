#include "stm32f10x.h"
#include "led.h"

static void Delay(uint16_t n)
{	
	uint16_t i,j;
	for(i=0;i<n;i++)
		for(j=0;j<8888;j++);
}

int main(void)
{
	LED_Init();
	while(1)
	{
		LED_ON_OFF();
	}
}
