#include "RobotIOTesterModules.h"
#include "RobotTester.h"


int testRobotIO()
{
	int code1 = testGetRobotShipKoords();
	int code2 = testGetRobotTarget();
	if (code1 == -1)
		return -1;
	if (code2 == -1)
		return -2;
	return 0;
}