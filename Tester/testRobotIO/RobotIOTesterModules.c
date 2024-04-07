#include "..\..\RobotIO\RobotIO.h"
#include "RobotIOTesterModules.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>


int testGetRobotShipKoords()
{
	srand(time(0));
	int expectedSpawnRow = rand() % 10;		//��������� ������ ���������� �������
	int decks = rand() % 4 + 1;		//���������� �������
	int ship[4][2];
	char field[10][10];
	for (int i = 0; i < 10; i++)	//��������� ���� � ������������ ���������� ��� ���������� ������� �������
	{
		if ((i - 1 == expectedSpawnRow) || (i == expectedSpawnRow) || (i + 1 == expectedSpawnRow))
			for (int j = 0; j < 10; j++)
				field[i][j] = '#';
		else
			for (int j = 0; j < 10; j++)
				field[i][j] = '@';
	}
	GetRobotShipKoords(field, ship, decks);		//����� ����������� �������
	for (int i = 0; i < decks; i++)		//�������� �� ��������� ������� � ���� � � ��������� ������
		for (int j = 0; j < 2; j++)
		{
			if (!(-1 < ship[i][j] < 10))
				return -1;
			if ((j == 0) && ((ship[i][j] != expectedSpawnRow) || (expectedSpawnRow == 1 && ship[i][j] == 0) || (expectedSpawnRow == 8 && ship[i][j] == 9)))
				return -1;
		}
	return 0;
}


int testGetRobotTarget()
{
	srand(time(0));
	int sankShip = rand() % 2;	//����� �� ������� �������� ������� ��� ���
	//���������� ����������� ������
	int sankDeckRow = rand() % 10;
	int sankDeckColumn = rand() % 10;
	char field[10][10];
	int target[2];
	for (int i = 0; i < 10; i++)	//��������� ���� c ����������� ������� (��� �������)
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
	GetRobotTarget(field, target);	//����� ����������� �������
	if (((0 > target[0]) || (target[0] > 11)) || ((0 > target[1]) || (target[1] > 11)))
		return -1;
	if ((field[target[0]][target[1]] == '0') || (field[target[0]][target[1]] == '*'))
		return -1;
	return 0;
}