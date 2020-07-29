#include<iostream>
#include "board.cpp"

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}
int max(int a, int b)
{
	return a > b ? a : b;
}

int minimax(char b[3][3], int depth,int alpha, int beta, bool isMax)
{
	int score = evaluate(b);

	if (score == 1)
		return score;
	if (score == -1)
		return score;

	if (!isMoves(b))
		return 0;

	if (isMax)
	{
		int best = -1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (b[i][j] == '_')
				{
					b[i][j] = 'x';
					best = max(minimax(b, depth + 1, alpha, beta, !isMax), best);
					alpha = max(best, alpha);
					b[i][j] = '_';
					if (beta <= alpha)
						break;
				}
			}
		}
		return best;
	}
	if (!isMax)
	{
		
		int best = +1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (b[i][j] == '_')
				{
					b[i][j] = '0';
					best = min(minimax(b, depth + 1, alpha, beta, !isMax), best);
					beta = min(beta, best);
					b[i][j] = '_';
					if (beta <= alpha)
						break;
				}
			}
		}
		return best;
	}
}