#include "header_file.h"

// 定义R37电位器的原始ADC值
uint16_t ADC_Num_1;

// 定义R38+可编程电阻的ADC值
uint16_t ADC_Num_2[2];

// ADC初始化
void ADC_Init(void)
{
	// ADC校准
	HAL_ADCEx_Calibration_Start(&hadc2,ADC_SINGLE_ENDED);
	HAL_ADCEx_Calibration_Start(&hadc1,ADC_SINGLE_ENDED);
	
	// 开启DMA转运
	if(!HAL_ADC_Start_DMA(&hadc2,(uint32_t*)&ADC_Num_1, 1))
	{
		ADC_Num_1 = 0;      // R37
	}

	if(!HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_Num_2, 2))
	{
		ADC_Num_2[0] = 0;   // R38
		ADC_Num_2[1] = 0;   // 可编程电阻
	}
}

// ADC值转化为电压值
float ADC_GetVac(uint16_t ADC_Num)
{
	float vac = 3.3 * (1.0 * ADC_Num / (4095 + 1) );

	return vac;
}

//==================================仅作为测试程序==================================
// ADC测试函数
void ADC_Demo(void)
{
	// R38电位器电压值
	double vac = 3.3 * (1.0 * ADC_Num_2[0] / (4095 + 1) );
	
	char str[20];
	
	sprintf(str,"    V_R38=%.2lf",vac);
	
	LCD_DisplayStringLine(Line2,(unsigned char *)str);
	
	// 可编程带你组件电阻电压值
	double vac1 = 3.3 * (1.0 * ADC_Num_2[1] / (4095 + 1) );
	
	sprintf(str,"    V_MCP=%.2lf",vac1);
	
	LCD_DisplayStringLine(Line3,(unsigned char *)str);
	
	// R37电位器电压值
	double vac2 = 3.3 * (1.0 * ADC_Num_1 / (4095 + 1) );
	
	sprintf(str,"    V_R37=%.2lf",vac2);
	
	LCD_DisplayStringLine(Line4,(unsigned char *)str);
}
//==================================仅作为测试程序==================================

