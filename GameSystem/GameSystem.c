#include "GameSystem.h"


int Shoot(char field[10][10], int koord[2])
{
	if (field[koord[0]][koord[1]] == '@')
		return 1;
	else
		return 0;
}


void PlaceShip(char field[10][10], int koords[4][2], int count)
{
	for (int i = 0; i < count; i++)
		field[koords[i][0]][koords[i][1]] = '@';
}