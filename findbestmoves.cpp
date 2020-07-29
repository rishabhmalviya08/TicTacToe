#include<iostream>
#include "minimax.cpp"

using namespace std;

struct Move {
	int row, col;
};

Move findbestMove(char b[3][3])
{
	Move bestMove;
	bestMove.row = 110;
	bestMove.col = 110;
	int bestVal = 1000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == '_')
			{
				b[i][j] = '0';

				int move = minimax(b, 0,INT_MIN, INT_MAX, true);

				b[i][j] = '_';

				if (move < bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = move;
				}
			}
		}
	}
	return bestMove;
}