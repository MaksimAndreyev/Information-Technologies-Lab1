#include "GameSystem.h"


void checkNeighbours(int a, int b, char field[10][10], int* res);
void sinkShip(int a, int b, char field[10][10]);
int Shoot(char field[10][10], int koord[2], int ships);
void PlaceShip(char field[10][10], int koords[4][2], int count);


void checkNeighbours(int a, int b, char field[10][10], int* res)
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
				*res = 1;
		if (edge1 != 1)
			if (field[a+1][b-1] == '@')
				*res = 1;
		if (field[a][b-1] == '@')
			*res = 1;
	}
	if (edge2 != 1)
	{
		if (edge1 != 1)
			if (field[a+1][b+1] == '@')
				*res = 1;
		if (edge1 != -1)
			if (field[a-1][b+1] == '@')
				*res = 1;
		if (field[a][b+1] == '@')
			*res = 1;
	}
	if (edge1 != -1)
	{
		if (field[a-1][b] == '@')
			*res = 1;
	}
	if (edge1 != 1)
	{
		if (field[a+1][b] == '@')
		*res = 1;
	}
}


void sinkShip(int a, int b, char field[10][10])
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
			if (field[a-1][b-1] == '#')
				field[a-1][b-1] = '0';
		if (edge1 != 1)
			if (field[a+1][b-1] == '#')
				field[a+1][b-1] = '0';
		if (field[a][b-1] == '#')
			field[a][b-1] = '0';
	}
	if (edge2 != 1)
	{
		if (edge1 != 1)
			if (field[a+1][b+1] == '#')
				field[a+1][b+1] = '0';
		if (edge1 != -1)
			if (field[a-1][b+1] == '#')
				field[a-1][b+1] = '0';
		if (field[a][b+1] == '#')
			field[a][b+1] = '0';
	}
	if (edge1 != -1)
	{
		if (field[a-1][b] == '#')
			field[a-1][b] = '0';
	}
	if (edge1 != 1)
	{
		if (field[a+1][b] == '#')
			field[a+1][b] = '0';
	}
}


int Shoot(char field[10][10], int koord[2], int ships)
{
	switch (field[koord[0]][koord[1]])
	{
	case '@':
		break;
	default:
		return 0;
	}
	field[koord[0]][koord[1]] = '*';
	int shipDestroyed = 0;		//потоплен ли корабль целиком (по умолчанию нет)
	checkNeighbours(koord[0], koord[1], field, &shipDestroyed);
	if (shipDestroyed)		//если корабль был потоплен целиком
	{
		ships--;
		sinkShip(koord[0], koord[1], field);
		if (ships == 0)		//кораблей больше не осталось
			return 3;
		else
			return 2;
	}
	else	//если корабль был подбит
		return 1;
}


void PlaceShip(char field[10][10], int koords[4][2], int count)
{
	for (int i = 0; i < count; i++)
		field[koords[i][0]][koords[i][1]] = '@';
}