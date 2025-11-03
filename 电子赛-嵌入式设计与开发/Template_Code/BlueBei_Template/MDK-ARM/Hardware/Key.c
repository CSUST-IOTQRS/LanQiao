#include "header_file.h"

// 双击按键使能宏定义
#define DOUBLE 1

// 按键状态结构体变量定义
KEY keys[4];

// 按键初始化
void Key_Init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);
}

// 按键扫描
void Key_Scan(void)
{
	// 读取按键电平
	keys[0].keyState = HAL_GPIO_ReadPin(GPIOB,B1);
	keys[1].keyState = HAL_GPIO_ReadPin(GPIOB,B2);
	keys[2].keyState = HAL_GPIO_ReadPin(GPIOB,B3);
	keys[3].keyState = HAL_GPIO_ReadPin(GPIOA,B4);

	for(uint8_t i = 0;i < 4;i++)
	{
		if(keys[i].keyJudge == 0)
		{
			keys[i].keyTim = 0;
#if DOUBLE
			if(keys[i].doubleEn == 1)
			{
				keys[i].doubleTime++;
					
				if (keys[i].doubleTime >= 20)
				{
					keys[i].keySingle = 1;
					keys[i].doubleTime = 0;
					keys[i].doubleEn = 0;
				}
			}
#endif 
			if(keys[i].keyState == GPIO_PIN_RESET)
			{
				keys[i].keyJudge = 1;
			}
		}

		if(keys[i].keyJudge == 1)
		{
#if DOUBLE
			if (keys[i].doubleEn == 1 && keys[i].keyState == 0 && keys[i].doubleTime < 30)
			{
				keys[i].doubleEn = 0;
				keys[i].doubleTime = 0;
				
				keys[i].keyDouble = 1;

				keys[i].keyJudge = 3;              // 等待双击按键松手
				break;                  
			}
#endif
			if(keys[i].keyState == GPIO_PIN_RESET)
			{
				keys[i].keyJudge = 2;
			}
			else
			{
				keys[i].keyJudge = 0;
			}
		}

		if(keys[i].keyJudge == 2)
		{
			if(keys[i].keyState == GPIO_PIN_RESET)
			{
				keys[i].keyTim++;
		
				if(keys[i].keyTim >= 100)      // 10ms *100 = 1s 长按按键
				{
					keys[i].keyLong = 1;
					keys[i].keyJudge = 3;      // 等待长按按键的松手
				}
			}
			else                               // 在这期间松手则判定为单击
			{
#if DOUBLE
				keys[i].doubleEn = 1;
#else
				keys[i].keySingle = 1;
#endif
				keys[i].keyJudge = 0;
			}
		}

		if(keys[i].keyJudge == 3)
		{
			if (keys[i].keyState == GPIO_PIN_SET)
			{
				keys[i].keyJudge = 0;       // 按键松手重新开始检测
			}
		}
	}
}

// 定时中断
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim6)
	{
		Key_Scan();       // 按键扫描
	}
}

//==================================仅作为测试程序==================================
// B4按键的测试函数
uint8_t sum1 = 0;
uint8_t sum2 = 0;
uint8_t sum3 = 0;

uint8_t Show_Key_Long(void)
{
	if (keys[3].keyLong != 0)
	{
		sum1++;
		keys[3].keyLong = 0;
	}
	return sum1;
}

uint8_t Show_Key_Double(void)
{
	if (keys[3].keyDouble!= 0)
	{
		sum2++;
		keys[3].keyDouble = 0;
	}
	return sum2;
}

uint8_t Show_Key_Single(void)
{
	if (keys[3].keySingle != 0)
	{
		sum3++;
		keys[3].keySingle = 0;
	}
	return sum3;
}

void Key_Demo(void)
{
	char str[20];
	
	sprintf(str,"    Key_4_S=%d",Show_Key_Single());
	
	LCD_DisplayStringLine(Line2,(unsigned char *)str);
	
	sprintf(str,"    Key_4_D=%d",Show_Key_Double());
	
	LCD_DisplayStringLine(Line3,(unsigned char *)str);
	
	sprintf(str,"    Key_4_L=%d",Show_Key_Long());
	
	LCD_DisplayStringLine(Line4,(unsigned char *)str);
}
//==================================仅作为测试程序==================================

