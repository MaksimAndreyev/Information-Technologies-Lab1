#include "C:\projects2\RobotIO\RobotIO.h"
#include "RobotIOTesterModules.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>


int testGetRobotShipKoords()
{
	srand(time(0));
	int expectedSpawnRow = 5;		//ожидаема€ строка размещени€ корабл€
	int decks = rand() % 4 + 1;		//палубность корабл€
	int ship[4][2];
	char field[10][10];
	for (int i = 0; i < 10; i++)	//генераци€ пол€ с единственной подход€щей дл€ размещени€ корабл€ строкой
	{
		if ((i - 1 == expectedSpawnRow) || (i == expectedSpawnRow) || (i + 1 == expectedSpawnRow))
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					field[j][k] = '#';
		else
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					field[j][k] = '@';
	}
	GetRobotShipKoords(field, ship, decks);		//вызов тестируемой функции
	for (int i = 0; i < decks; i++)		//проверка на попадание корабл€ в поле и в требуемую строку
		for (int j = 0; j < 2; j++)
		{
			if (!(0 < ship[i][j] < 11))
				return -1;
			if ((j == 0) && (ship[i][j] != expectedSpawnRow))
				return -1;
		}
	return 0;
}


int testGetRobotTarget()
{
	srand(time(0));
	int sankShip = rand() % 2;	//будет ли корабль затоплен целиком или нет
	//координаты затопленной палубы
	int sankDeckRow = rand() % 10;
	int sankDeckColumn = rand() % 10;
	char field[10][10];
	int target[2];
	for (int i = 0; i < 10; i++)	//генераци€ пол€ c затопленной палубой (или кораблЄм)
		for (int j = 0; j < 10; j++)
		{
			bool flag1 = (i == sankDeckRow);
			bool flag2 = (j == sankDeckColumn);
			if (flag1 && flag2)
				field[i][j] = '*';
			else
			{
				if (sankShip && ((flag1 && !flag2) || (!flag1 && flag2)))
					field[i][j] = '0';
				else
				{
					if (flag1 && ((j - 1 == sankDeckColumn) || (j + 1 == sankDeckColumn)))
						field[i][j] = '0';
					else
						field[i][j] = '#';
				}
			}
		}
	GetRobotTarget(field, target);	//вызов тестируемой функции
	if (((0 > target[0]) || (target[0] > 11)) || ((0 > target[1]) || (target[1] > 11)))
		return -1;
	if ((field[target[0]][target[1]] == '0') || (field[target[0]][target[1]] == '*'))
		return -1;
	return 0;
}