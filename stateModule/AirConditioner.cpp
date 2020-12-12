#include "AirConditioner.h"
//构造函数
AirConditioner::AirConditioner(string strAirName, int nTemperature)
{
	m_strAirName = strAirName;
	m_nTemperature = nTemperature;
 
	m_pNormalTemperatureState = new NormalTemperatureState();
	m_pRefrigerateState = new RefrigerateState();
	m_pHeatState = new HeatState();
 
	m_pCurState = m_pNormalTemperatureState;
}

//虚构函数
AirConditioner::~AirConditioner()
{
	delete m_pNormalTemperatureState;
	m_pNormalTemperatureState = NULL;
 
	delete m_pRefrigerateState;
	m_pRefrigerateState = NULL;
 
	delete m_pHeatState;
	m_pHeatState = NULL;
}
	
//调节温度
void AirConditioner::SetTemperature(int nTemperature)
{
	m_nTemperature = nTemperature;
}
 
//获取温度
int AirConditioner::GetTemperature()
{
	return m_nTemperature;
}
 
//设置空调状态
void AirConditioner::SetAirConditionerState(AirConditionerState * pAirConditionerState)
{
	m_pCurState = pAirConditionerState;
}
 

//获取常温状态
AirConditionerState * AirConditioner::GetNormalTemperatureState()
{
	return m_pNormalTemperatureState;
}
 

//获取制冷状态
AirConditionerState * AirConditioner::GetRefrigerateState()
{
	return m_pRefrigerateState;
}
 

//获取制热状态
AirConditionerState * AirConditioner::GetHeatState()
{
	return m_pHeatState;
}
 
 
//保持常温
void AirConditioner::KeepNormalTemperature()
{
	m_pCurState->KeepNormalTemperature(this);
	
}
  
 
//制冷
void AirConditioner::refrigerate()
{
	m_pCurState->refrigerate(this);
}
  
//制热
void AirConditioner::Heat()
{
	m_pCurState->Heat(this);
}