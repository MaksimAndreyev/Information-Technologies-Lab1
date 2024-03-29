#include "GameSysTester.h"
#include "GameSysTesterModules.h"


int testGameSystem()
{
	int code1 = testShoot();
	int code2 = testPlaceShip();
	if (code1 == -1)
		return -1;
	if (code2 == -1)
		return -2;
	return 0;
}