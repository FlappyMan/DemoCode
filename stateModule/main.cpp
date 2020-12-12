#include <iostream>
#include "AirConditioner.h"
 
using namespace std;
 
int main()
{
 
	AirConditioner * pAirConditioner = new AirConditioner("海尔空调", 25);
 
	/****************常温状态*************************/
	pAirConditioner->KeepNormalTemperature();
 
	cout << endl;
	
	/****************制冷状态*************************/
	pAirConditioner->SetTemperature(33);
	pAirConditioner->refrigerate();
 
	cout << endl;
 
	/****************制热状态*************************/
	pAirConditioner->SetTemperature(15);
	pAirConditioner->Heat();
 
	/****************销毁操作*************************/
	delete pAirConditioner;
	pAirConditioner = NULL;
 
	return 0;
}