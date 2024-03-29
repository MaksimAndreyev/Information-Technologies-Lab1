#include <stdio.h>
#include "testRobotIO\RobotTester.h"
#include "testGameSystem\GameSysTester.h"


int main()
{
	int code1 = testRobotIO();
	int code2 = testGameSystem();
	switch (code1)
	{
	case -1:
		printf("GetRobotShipKoords: error\n");
		break;
	case -2:
		printf("GetRobotTarget: error\n");
		break;
	case 0:
		printf("GetRobotShipKoords: ok\nGetRobotTarget: ok\n");
		break;
	default:
		printf("RobotIO test failure\n");
		break;
	}
	switch (code2)
	{
	case -1:
		printf("Shoot: error\n");
		break;
	case -2:
		printf("PlaceShip: error\n");
		break;
	case 0:
		printf("Shoot: ok\nPlaceShip: ok\n");
		break;
	default:
		printf("GameSystem test failure\n");
		break;
	}
	return 0;
}