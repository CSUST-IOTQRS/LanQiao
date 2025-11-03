#ifndef __ADC_READ_H
#define __ADC_READ_H

// 外部调用R37电位器的原始ADC值
extern uint16_t ADC_Num_1;
// 外部调用R38+可编程电阻的ADC值
extern uint16_t ADC_Num_2[2];

// ADC初始化
void ADC_Init(void);

// ADC值转化为电压值
float ADC_GetVac(uint16_t ADC_Num);

//==================================仅作为测试程序==================================
// ADC测试函数
void ADC_Demo(void);
//==================================仅作为测试程序==================================

#endif
