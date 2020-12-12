#include "AirConditionerState.h"
/******************************正常温度状态******************************************/
 
//保持常温
void NormalTemperatureState::KeepNormalTemperature(AirConditioner * pAirConditioner)
{
 
	int nTemperature = pAirConditioner->GetTemperature();
 
	if( nTemperature > 20 && nTemperature <= 30 )
	{
		cout << "已经是常温状态，不能调节为常温" << endl;
	}
}
 
 
 
//制冷
void NormalTemperatureState::refrigerate(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature > 30 && nTemperature <= 45 )
	{
		pAirConditioner->SetAirConditionerState(pAirConditioner->GetRefrigerateState());
 
		cout << "切换到制冷状态" << endl;
	}
}
	
 
 
//制热
void NormalTemperatureState::Heat(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature <= 20 )
	{
		pAirConditioner->SetAirConditionerState(pAirConditioner->GetHeatState());
 
		cout << "切换到制热状态" << endl;
	}
}
 
 
 
/******************************制冷状态******************************************/
 
//保持常温
void RefrigerateState::KeepNormalTemperature(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature > 20 && nTemperature <= 30 )
	{
		pAirConditioner->SetAirConditionerState(pAirConditioner->GetNormalTemperatureState());
 
		cout << "切换到常温状态" << endl;
	}
}
	
 
 
//制冷
void RefrigerateState::refrigerate(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature > 30 && nTemperature <= 45 )
	{
		cout << "已经是制冷状态，不能调节为制冷状态" << endl;
	}
}
	
 
 
//制热
void RefrigerateState::Heat(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature <= 20 )
	{
		pAirConditioner->SetAirConditionerState(pAirConditioner->GetHeatState());
 
		cout << "切换到制热状态" << endl;
	}
}
 
 
 
/******************************制热状态******************************************/
 
 
//保持常温
void HeatState::KeepNormalTemperature(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature > 20 && nTemperature <= 30 )
	{
		pAirConditioner->SetAirConditionerState(pAirConditioner->GetNormalTemperatureState());
 
		cout << "切换到常温状态" << endl;
	}
}
	
	
 
//制冷
void HeatState::refrigerate(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature > 30 && nTemperature <= 45 )
	{
		pAirConditioner->SetAirConditionerState(pAirConditioner->GetRefrigerateState());
 
		cout << "切换到制冷状态" << endl;
	}
}
 
 
	
//制热
void HeatState::Heat(AirConditioner * pAirConditioner)
{
	int nTemperature = pAirConditioner->GetTemperature();
	
	if( nTemperature <= 20 )
	{
		cout << "已经是制热状态，不能调节为制热状态" << endl;
	}
}