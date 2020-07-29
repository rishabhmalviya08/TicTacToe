#include<iostream>

using namespace std;

int evaluate(char b[3][3])
{
	for (int i = 0; i < 3; i++)// checking for rows
	{
		if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
		{
			if (b[i][0] == 'x')
				return +1;
			else if (b[i][0] == '0')
				return -1;
		}
	}
	for (int i = 0; i < 3; i++)// checking for columns;
	{
		if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
		{
			if (b[0][i] == 'x')
				return +1;
			else if(b[0][i] == '0')
				return -1;
		}
	}

	//checking for diagonals
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == 'x')
			return +1;
		else if (b[0][0] == '0')
			return -1;
	}
	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == 'x')
			return +1;
		else if (b[0][2] == '0')
			return -1;
	}

	return 0;// if draw
}

bool isMoves(char b[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == '_')
				return true;
		}
	}
	return false;
}

void printBoard(char b[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << b[i][j] << " | ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}

	
