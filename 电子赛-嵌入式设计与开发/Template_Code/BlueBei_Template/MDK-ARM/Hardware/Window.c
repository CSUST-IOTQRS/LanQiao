#include "header_file.h"

// 定义显示字符串数组
char str[20];

// 定义窗口号
uint8_t Window_Num = 1;     // 用于判断处于哪个界面实现对应界面的功能

// 标志位定义
uint8_t Change_Flag = 0;    // 屏幕切换标志位

// 参数定义

// 屏幕显示初始化
void Window_Init(void)
{
	LCD_Init();

	LCD_Clear(Black);
	LCD_SetBackColor(Black);
	LCD_SetTextColor(White);
}

// 示例窗口
void Window_Ex(void)
{
	Window_Num = 1;
	
	// 参数显示等操作
}

// 窗口显示
void Window_Show(void)
{
	// 用作参考对齐
	LCD_DisplayStringLine(Line0,(u8 *)"12345678901234567890");

	// 示例
	if(Change_Flag == 1)         // 窗口切换
	{
		LCD_Clear(Black);
		// 相应操作
	}

	// 对应窗口的对应操作
	if(Window_Num == 1)
	{
		Window_Ex();
	}// ...

	// 其它操作
}

// 实现按键功能
void Window_Key(void)
{
	// 示例
	if(keys[0].keySingle == 1)
	{
		// 操作
		keys[0].keySingle = 0;
	}
	// ...
}

// 其它操作函数

//==================================仅作为测试程序==================================
void Window_Demo(void)
{
	LCD_SetBackColor(Black);
    LCD_SetTextColor(White);
	LCD_Clear(Black);
	HAL_Delay(100);

    LCD_DisplayStringLine(Line4, (unsigned char *)"    Hello,world.   ");
    HAL_Delay(1000);
}
//==================================仅作为测试程序==================================