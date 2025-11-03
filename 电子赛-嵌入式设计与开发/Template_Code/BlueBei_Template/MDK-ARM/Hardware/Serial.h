#ifndef __SERIAL_H
#define __SERIAL_H

// 这两个句柄只在usart.c中进行了定义，要在此处外部调用才可以使用这个句柄
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

// 外部调用
extern uint8_t Serial_Data[20];

// 串口初始化---默认波特率是9600
void Serial_Init(void);

// 串口接收数据处理函数
void Serial_Ex(void);

// 获取接收标志位
uint8_t Serial_GetRxFlag(void);

// 清除接收标志位
void Serial_ClearRxFlag(void);

// 清除接收数组的内容
void Serial_ClearData(void);

//==================================仅作为测试程序==================================
void Serial_Demo(void);
//==================================仅作为测试程序==================================

#endif
