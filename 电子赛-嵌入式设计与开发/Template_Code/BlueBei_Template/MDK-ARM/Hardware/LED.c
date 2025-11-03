#include "header_file.h"

// 存储LED灯的状态。状态的改变不受程序控制以外的因素影响
uint16_t LED_IO = 0x0000;

// LED灯初始化 --- 默认为灭
void LED_Init(void)
{
	LED_Set(LED_All,LED_OFF);
}

// LED灯状态设置
void LED_Set(uint16_t LED_Num,uint16_t LED_Flag)
{
	// 预先全部置LED_OFF状态
	HAL_GPIO_WritePin(GPIOC,LED_All,GPIO_PIN_SET);

	// 解析LED要被设置成的状态
	if(LED_Flag == LED_ON)
	{
		LED_IO |= LED_Num;
	}
	else
	{
		LED_IO &= ~LED_Num ;
	}

	// 对要亮的LED灯置低电平
	HAL_GPIO_WritePin(GPIOC,LED_IO,GPIO_PIN_RESET);

	// 锁存器开启和关闭
	HAL_GPIO_WritePin(GPIOD,HC,GPIO_PIN_SET);      

	HAL_GPIO_WritePin(GPIOD,HC,GPIO_PIN_RESET);
}

//==================================仅作为测试程序==================================
// LED灯状态读取
uint8_t LED_Read(uint16_t LED_Num)
{
	return (LED_Num & LED_IO) ? 1 : 0;
}

// LED灯历程测试程序
void LED_Demo(void)
{
	char str[20];

	// LED_1亮起，同时读取LED_1的状态并且显示在屏幕上
	LED_Set(LED_1,LED_ON);
	sprintf(str,"  LED_1_FLAG = %d",LED_Read(LED_1));
	LCD_DisplayStringLine(Line0,(u8 *)str);

	HAL_Delay(1000);

	// 延时后LED_2、LED_3亮起
	LED_Set(LED_2| LED_3, LED_ON);

	HAL_Delay(1000);

	// 延时后LED_4、LED_5、LED_6亮起
	LED_Set(LED_4 | LED_5 | LED_6, LED_ON);

	HAL_Delay(1000);

	// 延时后LED_7、LED_8亮起
	LED_Set(LED_7 | LED_8, LED_ON);

	HAL_Delay(1000);

	// LED_1熄灭，同时读取LED_1的状态并且显示在屏幕上
	LED_Set(LED_1, LED_OFF);
	sprintf(str,"  LED_1_FLAG = %d",LED_Read(LED_1));
	LCD_DisplayStringLine(Line0,(u8 *)str);

	HAL_Delay(1000);

	// 延时后LED_2、LED_3熄灭
	LED_Set( LED_2| LED_3,LED_OFF);

	HAL_Delay(1000);

	// 延时后LED_4、LED_5、LED_6熄灭
	LED_Set( LED_4 | LED_5 | LED_6, LED_OFF);

	HAL_Delay(1000);

	// 延时后LED_7、LED_8熄灭
	LED_Set(LED_7 | LED_8,LED_OFF);

	HAL_Delay(1000);

	// LED全亮，同时读取LED_1的状态并且显示在屏幕上
	LED_Set(LED_All, LED_ON);
	sprintf(str,"  LED_1_FLAG = %d",LED_Read(LED_1));
	LCD_DisplayStringLine(Line0,(u8 *)str);

	HAL_Delay(1000);

	// LED全灭，同时读取LED_1的状态并且显示在屏幕上
	LED_Set(LED_All, LED_OFF);
	sprintf(str,"  LED_1_FLAG = %d",LED_Read(LED_1));
	LCD_DisplayStringLine(Line0,(u8 *)str);

	HAL_Delay(1000);
}
//==================================仅作为测试程序==================================
