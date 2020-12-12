#ifndef __AIRCONDITIONER__
#define __AIRCONDITIONER__
#include "AirConditionerState.h"
#include<iostream>
#include<string>
using namespace std;
//空调类
class AirConditionerState;
class AirConditioner
{
private:
	//空调名称
	string m_strAirName;
 
	//空调当前温度
	int m_nTemperature;
	
	//常温状态
	AirConditionerState * m_pNormalTemperatureState;
	
	//制冷状态
	AirConditionerState * m_pRefrigerateState;
 
	//制热状态
	AirConditionerState * m_pHeatState;
 
	//当前温度状态
	AirConditionerState * m_pCurState;
public:
	//构造函数
	AirConditioner(string strAirName, int nTemperature);
 
	//虚构函数
	virtual ~AirConditioner();
	
	//调节温度
	void SetTemperature(int nTemperature);
 
	//获取温度
	int GetTemperature();
 
	//设置空调状态
	void SetAirConditionerState(AirConditionerState * pAirConditionerState);
 
	
	//获取常温状态
	AirConditionerState * GetNormalTemperatureState();
 
	//获取制冷状态
	AirConditionerState * GetRefrigerateState();
 
	//获取制热状态
	AirConditionerState * GetHeatState();
 
 
	//保持常温
	void KeepNormalTemperature();
 
	//制冷
	void refrigerate();
 
	//制热
	void Heat();
	
};
#endif