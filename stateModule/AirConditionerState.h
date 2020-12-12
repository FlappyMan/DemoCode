#ifndef __AIRCONTITIONERSTATE__
#define __AIRCONTITIONERSTATE__
#include "AirConditioner.h"
using namespace std;
//空调抽象状态类
class AirConditioner;
class AirConditionerState
{
public:	
	//保持常温
	virtual void KeepNormalTemperature(AirConditioner * pAirConditioner) = 0;
 
	//制冷
	virtual void refrigerate(AirConditioner * pAirConditioner) = 0;
	
	//制热
	virtual void Heat(AirConditioner * pAirConditioner) = 0;
};
//常温状态
class NormalTemperatureState : public AirConditionerState
{
public:	
	//保持常温
	void KeepNormalTemperature(AirConditioner * pAirConditioner);
 
	//制冷
	void refrigerate(AirConditioner * pAirConditioner);
	
	//制热
	void Heat(AirConditioner * pAirConditioner);
};

//制冷状态
class RefrigerateState : public AirConditionerState
{
public:	
	//保持常温
	void KeepNormalTemperature(AirConditioner * pAirConditioner);
	
	
	//制冷
	void refrigerate(AirConditioner * pAirConditioner);
	
	//制热
	void Heat(AirConditioner * pAirConditioner);
};
//制热状态
class HeatState : public AirConditionerState
{
public:	
	//保持常温
	void KeepNormalTemperature(AirConditioner * pAirConditioner);
	
	//制冷
	void refrigerate(AirConditioner * pAirConditioner);
	
	//制热
	void Heat(AirConditioner * pAirConditioner);
};
#endif