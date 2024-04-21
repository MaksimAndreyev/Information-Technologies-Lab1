#include "RobotIOTesterModules.h"
#include "RobotTester.h"
#include <stdio.h>


enum { TEST_SUCCESS, TEST_FAILURE };


int testRobotIO()
{
	int code1 = testGetRobotShipKoords();
	int code2 = testGetRobotTarget();
	FILE* testResults;
	testResults = fopen("TestRobotIO.log", "w");
	if (code1 == -1)
		fprintf(testResults, "GetRobotShipKoords failure\n");
	if (code2 == -1)
		fprintf(testResults, "GetRobotTarget failure\n");
	if (code1 == -1 || code2 == -2)
	{
		fclose(testResults);
		return TEST_FAILURE;
	}
	fprintf(testResults, "RobotIO successful\n");
	fclose(testResults);
	return TEST_SUCCESS;
}
