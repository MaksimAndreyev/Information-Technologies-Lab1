#include "RobotIO.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"


void GetRobotShipKoords(char field[10][10], int koords[4][2], int count)
{
	srand(time(0));
	bool shipIsPlaced = false;	//размещён ли корабль
	int kds = new int[count];
	/*while (!shipIsPlaced)
	{
		int orientaion = rand() % 2;	//генерация ориентации корабля: 0 - горизонтально, 1 - вертикально
		int line = rand() % 10 + 1;		//генерация линии размещения корабля (вертикали или горизонтали)

	}*/
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