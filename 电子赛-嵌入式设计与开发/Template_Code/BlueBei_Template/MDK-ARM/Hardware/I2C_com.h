#ifndef __I2C_COM_H
#define __I2C_COM_H

// I2C通信初始化
void I2C_Init(void);

// e2prom写函数
void E2prom_write(uint8_t Address , uint8_t Data);
// e2prom读函数
uint8_t E2prom_read(uint8_t Address);
// 可编程电阻写函数
void MCP4017_write(uint8_t Data);
// 在加一个电阻计算
// 可编程电阻读函数
uint8_t MCP4017_read(void);

//==================================仅作为测试程序==================================
void E2prom_Demo(void);
//==================================仅作为测试程序==================================

#endif
