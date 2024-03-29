#include "C:\projects2\GameSystem\GameSystem.h"
#include "GameSysTesterModules.h"
#include <stdlib.h>
#include <time.h>


int testShoot()
{
	srand(time(0));
	//координаты корабля
	int shipRow = rand() % 10 + 1;
	int shipColumn = rand() % 10 + 1;
	int hit = rand() % 2;	//должно ли быть попадание
	int res;
	char field[10][10];
	int target[2] = { 5, 5 };	//координаты выстрела
	//генерация поля
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if ((shipRow == i) && (shipColumn == j))
				field[i][j] = '@';
			else
				field[i][j] = '#';
		}
	if (hit)
	{
		target[0] = shipRow;
		target[1] = shipColumn;
	}
	res = Shoot(field, target);		//вызов тестируемой функции
	if (hit == res)		//проверка соответствия результата
		return 0;
	return -1;
}


int testPlaceShip()
{
	srand(time(0));
	int decks = rand() % 4 + 1;		//палубность корабля
	int column = rand() % 10 + 1;	//столбец в котором будет корабль
	int ship[4][2];		//корабль
	char field[10][10];
	for (int i = 0; i < decks; i++)
	{
		ship[i][0] = i;
		ship[i][1] = column;
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			field[i][j] = '#';
	PlaceShip(field, ship, decks);	//вызов тестируемой функции
	int k = 0;	//количество размещённых палуб
	//проверка результа работы функции
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (field[i][j] == '@')
			{
				if ((i == ship[k][0]) && (j == ship[k][1]))
					k += 1;
				else
					return -1;
			}
	if (k != decks)
		return -1;
	return 0;
}