#ifndef __LED_H
#define __LED_H

// 定义LED灯对应的GPIO口
#define LED_1    GPIO_PIN_8
#define LED_2    GPIO_PIN_9
#define LED_3    GPIO_PIN_10
#define LED_4    GPIO_PIN_11
#define LED_5    GPIO_PIN_12
#define LED_6    GPIO_PIN_13
#define LED_7    GPIO_PIN_14
#define LED_8    GPIO_PIN_15

// 定义为操作所有LED灯
#define LED_All  0xFF00       // 这个值是16位二进制数对应的高八位的值,与8个LED灯的地址对应

// 定义锁存芯片的HC引脚对应的GPIO口
#define HC GPIO_PIN_2

// LED灯状态宏
#define LED_ON   0x00
#define LED_OFF  0x01

// LED灯初始化 --- 默认为灭
void LED_Init(void);
// LED灯状态设置
void LED_Set(uint16_t LED_Num,uint16_t LED_Flag);

//==================================仅作为测试程序==================================
// LED灯状态读取
uint8_t LED_Read(uint16_t LED_Num);
// LED灯历程测试程序
void LED_Demo(void);
//==================================仅作为测试程序==================================

#endif
