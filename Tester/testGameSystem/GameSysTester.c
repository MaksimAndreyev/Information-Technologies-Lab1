#include "GameSysTester.h"
#include "GameSysTesterModules.h"
#include <stdio.h>


enum { TEST_SUCCESS, TEST_FAILURE };


int testGameSystem()
{
	int code1 = testShoot();
	int code2 = testPlaceShip();
	FILE* testResults;
	testResults = fopen("TestGameSystem.log", "w");
	if (code1 == -1)
		fprintf(testResults, "Shoot failure\n");
	if (code2 == -1)
		fprintf(testResults, "PlaceShip failure\n");
	if (code1 == -1 || code2 == -2)
	{
		fclose(testResults);
		return TEST_FAILURE;
	}
	fprintf(testResults, "GameSystem successful\n");
	fclose(testResults);
	return TEST_SUCCESS;
}
