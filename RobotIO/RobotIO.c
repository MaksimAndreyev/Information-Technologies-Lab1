#include "RobotIO.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"


void checkNeighbours(int a, int b, char field[10][10], bool* res);
void GetRobotShipKoords(char field[10][10], int koords[4][2], int count);
void GetRobotTarget(char field[10][10], int koord[2]);


void checkNeighbours(int a, int b, char field[10][10], bool* res)
{
	int edge1 = 0, edge2 = 0;
	if (a == 0)
		edge1 = -1;
	else if (a == 9)
		edge1 = 1;
	if (b == 0)
		edge2 = -1;
	else if (b == 9)
		edge2 = 1;
	if (edge2 != -1)
	{
		if (edge1 != -1)
			if (field[a-1][b-1] == '@')
				*res = false;
		if (edge1 != 1)
			if (field[a+1][b-1] == '@')
				*res = false;
		if (field[a][b-1] == '@')
			*res = false;
	}
	if (edge2 != 1)
	{
		if (edge1 != 1)
			if (field[a+1][b+1] == '@')
				*res = false;
		if (edge1 != -1)
			if (field[a-1][b+1] == '@')
				*res = false;
		if (field[a][b+1] == '@')
			*res = false;
	}
	if (edge1 != -1)
	{
		if (field[a-1][b] == '@')
			*res = false;
	}
	if (edge1 != 1)
	{
		if (field[a+1][b] == '@')
		*res = false;
	}
}


void GetRobotShipKoords(char field[10][10], int koords[4][2], int count)
{
	srand(time(0));
	bool shipIsPlaced = false;	//размещён ли корабль
	int place[4];	//массив для записи координат столбцов при горизонтальном размещении и наоборот
	int j;	//количество найденных подходящих для размещения полей
	bool cellIsGood;	//подходит ли текущая клетка
	while (!shipIsPlaced)
	{
		j = 0;
		int orientation = rand() % 2;	//ориентация корабля: 0 - вертикально, 1 - горизонтально
		int line = rand() % 10;		//генерация линии размещения (столбца или строки)
		for (int i = 0; i < 10; i++)
		{
			cellIsGood = false;		//по умолчанию клетка не подходит
			if (orientation)	//если размещаем горизонтально
			{
				if (field[line][i] == '#')		//если клетка пустая
				{
					cellIsGood = true;
					checkNeighbours(line, i, field, &cellIsGood);	//проверяем соседние клетки
				}
			}
			else	//если размещаем вертикально
			{
				if (field[i][line] == '#')		//если клетка пустая
				{
					cellIsGood = true;
					checkNeighbours(i, line, field, &cellIsGood);	//проверяем соседние клетки
				}
			}
			if (cellIsGood)		//если клетка подходит для размещения
			{
				place[j] = i;
				j++;
				if (j == count)		//если нашли нужное число клеток для размещения
					break;
			}
			else
				j = 0;
		}
		if (j == count)		//если нашли нужное число клеток для размещения
		{
			for (int i = 0; i < count; i++)		//заполняем массив koords
			{
				if (orientation)
				{
					koords[i][0] = line;
					koords[i][1] = place[i];
				}
				else
				{
					koords[i][0] = place[i];
					koords[i][1] = line;
				}
			}
			shipIsPlaced = true;	//корабль размещён
		}
	}
}


void GetRobotTarget(char field[10][10], int koord[2])
{
	bool targetFound = false;	//найдена ли цель
	for (int i = 0; i < 10; i++)	//ищем, есть ли недобитые корабли
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == '#')
			{
				if ((j != 0 && field[i][j-1] == '*') || (j != 9 && field[i][j+1] == '*') || (i != 0 && field[i-1][j] == '*') || (i != 9 && field[i+1][j] == '*'))
				{
					targetFound = true;
				}
			}
			if (targetFound)
			{
				koord[0] = i;
				koord[1] = j;
				break;
			}
		}
		if (targetFound)
			break;
	}
	if (!targetFound)	//если прошлый выстрел потопил корабль или был промахом
	{
		//ищем четырёхпалубник
		int start = 3;
		for (int i = 0; i < 10; i++)
		{
			for (int j = start; j < 10; j += 4)
			{
				if (field[i][j] == '#')
				{
					koord[0] = i;
					koord[1] = j;
					targetFound = true;
					break;
				}
			}
			if (targetFound)
				break;
			else 
			{
				if (start != 0)
					start--;
				else
					start = 3;
			}	
		}
		if (!targetFound)
		{
			//ищем 3-ёх- и 2-ухпалубники
			int start = 1;
			for (int i = 0; i < 10; i++)
			{
				for (int j = start; j < 10; j += 4)
				{
					if (field[i][j] == '#')
					{
						koord[0] = i;
						koord[1] = j;
						targetFound = true;
						break;
					}
				}
				if (targetFound)
					break;
				else 
				{
					if (start != 0)
						start--;
					else
						start = 3;
				}	
			}
		}
		if (!targetFound)
		{
			//ищем просто свободное поле
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (field[i][j] == '#')
					{
						koord[0] = i;
						koord[1] = j;
						targetFound = true;
						break;
					}
				}
				if (targetFound)
					break;
			}
		}
	}
}