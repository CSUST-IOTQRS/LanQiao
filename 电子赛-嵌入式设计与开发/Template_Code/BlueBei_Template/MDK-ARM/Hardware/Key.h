#ifndef __KEY_H
#define __KEY_H

// 定义按键对应的GPIO口
#define B1  GPIO_PIN_0
#define B2	GPIO_PIN_1
#define B3  GPIO_PIN_2
#define B4  GPIO_PIN_0

// 按键状态机结构体
typedef struct
{
	uint8_t keySingle;      // 单击
	uint8_t keyDouble;      // 双击
	uint8_t keyLong;        // 长按

	uint8_t keyJudge;       // 按键状态机的状态,用于消抖和判断
	uint8_t keyState;       // 按键电平状态
	uint8_t keyTim;         // 用于长按按键的计时判定

	uint8_t doubleTime;     // 用于双击按键的计时判定
	uint8_t doubleEn;       // 双击计时使能
}KEY;

extern KEY keys[4];         // 用于外部调用

// 按键初始化
void Key_Init(void);

// 按键扫描
void Key_Scan(void);

//==================================仅作为测试程序==================================
// B4按键测试函数
void Key_Demo(void);
//==================================仅作为测试程序==================================

#endif
