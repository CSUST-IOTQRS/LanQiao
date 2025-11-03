#include "header_file.h"

// I2C通信初始化
void I2C_Init(void)
{
	I2CInit();
}

// e2prom写函数
void E2prom_write(uint8_t Address , uint8_t Data)
{
	I2CStart();
	
	I2CSendByte(0xA0);
	I2CWaitAck();
	
	I2CSendByte(Address);
	I2CWaitAck();
	
	I2CSendByte(Data);
	I2CWaitAck();
	
	I2CStop();
}

// e2prom读函数
uint8_t E2prom_read(uint8_t Address)
{
	uint8_t Data;
	
	I2CStart();
	
	I2CSendByte(0xA0);
	I2CWaitAck();
	
	I2CSendByte(Address);
	I2CWaitAck();
	
	I2CStop();
	
	I2CStart();
	
	I2CSendByte(0xA1);
	I2CWaitAck();
	
	Data = I2CReceiveByte();
	I2CSendNotAck();
	
	I2CStop();
	
	return Data;
}

// 可编程电阻写函数
void MCP4017_write(uint8_t Data)
{
	I2CStart();
	
	I2CSendByte(0x5E);
	I2CWaitAck();
	
	I2CSendByte(Data);
	while(I2CWaitAck());
	
	I2CStop();
}

// 可编程电阻读函数
uint8_t MCP4017_read(void)
{
	uint8_t Data;
	
	I2CStart();
	
	I2CSendByte(0x5F);
	I2CWaitAck();
	
	Data = I2CReceiveByte();

	I2CSendNotAck();
	I2CStop();
	
	return Data;
}

//==================================仅作为测试程序==================================
// E2prom测试函数
void E2prom_Demo(void)
{
	// ASCll码表写入和读出
	uint8_t str[20];
	uint8_t i = 0;
    uint8_t Address = 0x00;      // 起始地址
    uint8_t Data    = 0x20;      // 起始数据
    uint8_t Line    = Line0;     // 起始行
	
	while(1)
	{
		E2prom_write(Address,Data);

		HAL_Delay(200);

		str[i] = E2prom_read(Address);

		LCD_DisplayStringLine(Line,(u8 *)str);

		// 循环自增
		Address++;
		i++;
		Data++;

		// 换行
		if(i >= 19)
		{
			Line += 24;
			i = 0;
			memset(str,0,sizeof(str));
		}
		
		if(Data == 127)
		{
			LCD_Clear(Black);
			break;
		}
	}
}
//==================================仅作为测试程序==================================
