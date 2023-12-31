/**************************************************************************************/
/*************                   正点原子@ALIENTEK                **********************/
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
/* 说明 ：
 * 源码为正点原子@ALIENTEK 编写
 * 本人RNA，只是移植到了MSP432平台
 * 仅作为学习使用
 * 在此也感谢正点原子
 */
/**************************************************************************************/

/******************************************************************************
//MSP432P401R
//2-2 GPIO输入 板载按键
//Bilibili：m-RNA
//E-mail:m-RNA@qq.com
//创建日期:2021/8/12
*******************************************************************************/

#include "key.h"
#include "led.h"
//按键初始化函数
void KEY_Init(bool mode) //IO初始化
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1 | GPIO_PIN4);
	if(mode)
	{
		GPIO_clearInterruptFlag(GPIO_PORT_P1,GPIO_PIN1);
	GPIO_clearInterruptFlag(GPIO_PORT_P1,GPIO_PIN4);
	
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN1,GPIO_HIGH_TO_LOW_TRANSITION);
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN4,GPIO_HIGH_TO_LOW_TRANSITION);
	
	GPIO_enableInterrupt(GPIO_PORT_P1,GPIO_PIN1);
	GPIO_enableInterrupt(GPIO_PORT_P1,GPIO_PIN4);
	
	Interrupt_enableInterrupt(INT_PORT1);
	}
}
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY1按下
//2，KEY2按下
//注意此函数有响应优先级,KEY1>KEY2!!
uint8_t KEY_Scan(uint8_t mode)
{
	uint16_t i;
	static uint8_t key_up = 1; //按键按松开标志
	if (mode)
		key_up = 1; //支持连按
	if (key_up && (KEY2 == 0 || KEY1 == 0))
	{
		for (i = 0; i < 5000; i++)
			; //去抖动
		key_up = 0;
		if (KEY1 == 0)
			return KEY1_PRES;
		else if (KEY2 == 0)
			return KEY2_PRES;
	}
	else if (KEY2 == 1 && KEY1 == 1)
		key_up = 1;
	return 0; // 无按键按下
}

void PORT1_IRQHandler(void) //中断配置
{
	uint16_t status;
	uint16_t i;
	status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
	GPIO_clearInterruptFlag(GPIO_PORT_P1,status);
	for(i = 0; i<5000;i++);
	
	if(status & GPIO_PIN1)
	{		
		if(KEY1 == 0)
		{
			LED_RED_On();
		}
	}

	if(status & GPIO_PIN4)
	{
		if(KEY2 == 0)
		{
			LED_RED_Off();
		}
	}
}
