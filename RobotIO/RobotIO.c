#include "RobotIO.h"


void GetRobotShipKoords(char field[10][10], int koords[4][2], int count)
{
	for (int i = 0; i < count; i++)
	{
		koords[i][0] = 5;
		koords[i][1] = i;
	}
}


void GetRobotTarget(char field[10][10], int koord[2])
{
	int targetFound = 0;	//флаг, найдена ли цель
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == '#')
			{
				koord[0] = i;
				koord[1] = j;
				targetFound = 1;
				break;
			}
		}
		if (targetFound)
			break;
	}
}