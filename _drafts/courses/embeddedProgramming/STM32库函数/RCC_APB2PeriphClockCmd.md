```c
函数原型：
void RCC_APB2PeriphClockCmd（u32 RCC_APB2Periph, FunctionalState NewState）
    
    
    其中，RCC_APB2Periph参数是一个32位的值，用于表示要操作的外设时钟，可以使用逻辑或运算符“|”将多个时钟标志组合在一起。
    NewState参数是一个枚举类型，用于指示要使能或禁用指定的外设时钟。可选值为：ENABLE和DISABLE。
    
```

```c
以下代码片段用于使能GPIOA和USART1外设的时钟：
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
```

```c
在stm32f10x_rcc.h中，有APB2_peripheral的宏定义。
/** @defgroup APB2_peripheral 
  * @{
  */
 
#define RCC_APB2Periph_AFIO              ((uint32_t)0x00000001)
#define RCC_APB2Periph_GPIOA             ((uint32_t)0x00000004)
#define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOC             ((uint32_t)0x00000010)
#define RCC_APB2Periph_GPIOD             ((uint32_t)0x00000020)
#define RCC_APB2Periph_GPIOE             ((uint32_t)0x00000040)
#define RCC_APB2Periph_GPIOF             ((uint32_t)0x00000080)
#define RCC_APB2Periph_GPIOG             ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1              ((uint32_t)0x00000200)
#define RCC_APB2Periph_ADC2              ((uint32_t)0x00000400)
#define RCC_APB2Periph_TIM1              ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1              ((uint32_t)0x00001000)
#define RCC_APB2Periph_TIM8              ((uint32_t)0x00002000)
#define RCC_APB2Periph_USART1            ((uint32_t)0x00004000)
#define RCC_APB2Periph_ADC3              ((uint32_t)0x00008000)
#define RCC_APB2Periph_TIM15             ((uint32_t)0x00010000)
#define RCC_APB2Periph_TIM16             ((uint32_t)0x00020000)
#define RCC_APB2Periph_TIM17             ((uint32_t)0x00040000)
#define RCC_APB2Periph_TIM9              ((uint32_t)0x00080000)
#define RCC_APB2Periph_TIM10             ((uint32_t)0x00100000)
#define RCC_APB2Periph_TIM11             ((uint32_t)0x00200000)
 
#define IS_RCC_APB2_PERIPH(PERIPH) ((((PERIPH) & 0xFFC00002) == 0x00) && ((PERIPH) != 0x00))
```

STM32的时钟控制模块因MCU芯片不同，各有差异，但原理都类似，功能也相当丰富。主要的目的就是给相对独立的外设模块提供时钟，也是为了降低整个芯片的功能。

降低功耗是主要原因，还有一个原因，就是为了兼容不同速度的设备，有些高速，有些低速，如果都用高速时钟，势必造成浪费。

RCC给外设提供时钟是一个主要目的，那么为什么要提供时钟呢？ 原因在于外围设备的寄存器需要时钟才能工作。你可以把外设当做一个设备，而这个设备需要给它提供电源（时钟）才能工作。

你在STM32参考手册的“RCC”章节可能会看到这么一句话：当外设时钟没有启用时，软件不能读出外设寄存器的数值，返回的数值始终是0x0。
