#include "header_file.h"

// 定义输入端的频率
uint16_t Freq;
uint16_t R39_Freq;
uint16_t R40_Freq;

// 定义输入端口的占空比
uint16_t Duty;
uint16_t R39_Duty;  // 一般来说不需要知道这两个的占空比，这里仅作计算占空比的演示
uint16_t R40_Duty;

// PWM初始化 --- 兼顾输出比较和输入捕获
void PWM_Init(void)
{
	// 开启输入捕获模式---双通道输入捕获
	HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_2);  // R38

	HAL_TIM_IC_Start_IT(&htim3,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim3,TIM_CHANNEL_2);  // R39

	HAL_TIM_IC_Start_IT(&htim4,TIM_CHANNEL_1);  
	HAL_TIM_IC_Start_IT(&htim4,TIM_CHANNEL_2);  // 用PA11作为输入捕获测输出比较的频率和占空比参数
                                                // 用的时候记得接一根杜邦线连接
	// 开启输出比较
	HAL_TIM_PWM_Start(&htim15,TIM_CHANNEL_1);   // 用PA2作为输出比较,设置:Freq = 1e6Hz | Duty = 60%
}

// 输入比较中断
// 添加标志位控制
volatile uint8_t capture_processing = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    // 防止中断嵌套处理
    if(capture_processing)
	{
		return;
	}
	else
	{
		capture_processing = 1;
    
		if(htim == &htim3)
		{
			uint16_t c1 = __HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1) + 1;
			uint16_t c2 = __HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_2) + 1;

			R39_Freq = 1e6 / c1;
			R39_Duty = 100 * c2 / c1;
		}
		else if(htim == &htim2)  // 使用else if减少判断次数
		{
			uint16_t c1 = __HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_1) + 1;
			uint16_t c2 = __HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_2) + 1;

			R40_Freq = 1e6 / c1;
			R40_Duty = 100 * c2 / c1;
		}
		else if(htim == &htim4)
		{
			uint16_t c1 = __HAL_TIM_GET_COMPARE(&htim4,TIM_CHANNEL_1) + 1;
			uint16_t c2 = __HAL_TIM_GET_COMPARE(&htim4,TIM_CHANNEL_2) + 1;

			Freq = 1e6 / c1;
			Duty = 100 * c2 / c1;
		}
		
		capture_processing = 0;
	}
}
//==================================仅作为测试程序==================================
// 测试函数
void PWM_Demo(void)
{
	char pwm_str[20];
	
	sprintf(pwm_str,"    F=%d ",R39_Freq);
	
	LCD_DisplayStringLine(Line2,(unsigned char *)pwm_str);

	sprintf(pwm_str,"    F=%d ",R40_Freq);
	
	LCD_DisplayStringLine(Line3,(unsigned char *)pwm_str);
	
	sprintf(pwm_str,"    F=%d  D=%d  ",Freq,Duty);

	LCD_DisplayStringLine(Line4,(unsigned char *)pwm_str);
}
//==================================仅作为测试程序==================================
