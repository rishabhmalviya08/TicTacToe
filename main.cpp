#include<iostream>
#include<locale>
#include "findbestmoves.cpp"

using namespace std;

Move playerTurn(char board[3][3])
{
	Move m;
	cout << "Your Turn : " << endl;
	int x, y;
	printBoard(board);
	cout << "Enter row coordinate : " << endl;

	while (1)
	{
		cin >> x;
		if ((x < 0 || x > 2) || !(cin))
		{
			cin.clear(); cin.ignore(512, '\n');
			cout << "Enter a numerical value between 0 and 2" << endl;
		}
		else
			break;
	}

	cout << "Enter col coordinate : " << endl;
	while (1)
	{
		cin >> y;
		if ((y < 0 || y > 2) || !(cin))
		{
			cin.clear(); cin.ignore(512, '\n');
			cout << "Enter a numerical value between 0 and 2" << endl;
		}
		else
			break;
	}
	if (board[x][y] == '_')
	{
		m.row = x;
		m.col = y;
		return m;
	}
	else
	{
		cout << "Enter an empty place" << endl;
		return playerTurn(board);
	}
}


int main()
{
	char board[3][3] = { {'_','_','_'}, {'_','_','_'}, {'_','_','_'} };

	bool isPlayer = true;
	while (isMoves(board))
	{
		if (isPlayer)
		{
			Move m = playerTurn(board);
			
			board[m.row][m.col] = 'x';
			if (evaluate(board) == 1)
			{
				cout << "You win";
				break;
			}
		}
		else
		{
			cout << "AI's Turn : " << endl;
			printBoard(board);
			Move findmove = findbestMove(board);
			board[findmove.row][findmove.col] = '0';
			if (evaluate(board) == -1)
			{
				cout << "AI wins";
				break;
			}
		}
		isPlayer = !isPlayer;
	}
	cout << endl;
	printBoard(board);
	int res = evaluate(board);		
	if (res == 0)
		cout << "Draw";
	return 0;
}
