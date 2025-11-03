#include "header_file.h"

// 定义串口数据数组
uint8_t Serial_Data[20];

// 串口接收标志位
uint8_t Serial_RxFlag = 0;

uint8_t Index = 0;

// 串口初始化---默认波特率是9600
void Serial_Init(void)
{
	HAL_UART_Transmit_DMA(&huart1, NULL , 1);                                // 开启DMA转运模式
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1,Serial_Data,sizeof(Serial_Data));   // 开启接收不定长数据模式
	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);                         // 关闭串口数据传输过半中断
}

// 串口接收数据处理函数
void Serial_Ex(void)
{
	
}

// 获取接收标志位
uint8_t Serial_GetRxFlag(void)
{
	return Serial_RxFlag;
}

// 清除接收标志位
void Serial_ClearRxFlag(void)
{
	Serial_RxFlag = 0;
}

// 清除接收数组的内容
void Serial_ClearData(void)
{
	memset(Serial_Data,0,sizeof(Serial_Data));
}

// 接收不定长函数中断
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	// 在标志位没有被重置的时候是不会再接收数据的
	if(huart == &huart1 && Serial_RxFlag == 0)
	{
		Index = Size;

		Serial_RxFlag = 1;    // 获得接收标志位
		
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1,Serial_Data,sizeof(Serial_Data));

		__HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);
	}
}

//==================================仅作为测试程序==================================
void Serial_Demo(void)
{
	// 判断是否接收到了信息
	if(Serial_GetRxFlag() == 1)
	{
		// 清除接收标志位
		Serial_ClearRxFlag();

		// 向主机发送接收到的信息以及信息的长度
		printf("%s %d\n",Serial_Data,Index);

		// 在LCD屏幕上显示
		char str[20];
	    sprintf(str,"DATA:%s",Serial_Data);
		LCD_DisplayStringLine(Line0,(u8 *)"                    ");      // 清除这一行
		LCD_DisplayStringLine(Line0,(u8 *)str);
		// 清空缓存数组
		Serial_ClearData();
	}
}
//==================================仅作为测试程序==================================

// 重定义printf---要勾选 Use MicrolLIB
int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,0xffff);
	return ch;
}
