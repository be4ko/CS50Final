#include<bits/stdc++.h>

using namespace std;
char arr[3][3] = {'0','1','2','3','4','5','6','7','8'};
char player = 'X';

bool isWinner(void)
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if ((arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]))
		{
			return true;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
	{
		return true;
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
	{
		return true;
	}
	return false;
}

bool isTie(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 ; j++)
		{
			if (arr[i][j] != 'X' && arr[i][j] != 'O')
				return false;
		}
	}
	return true;
}

void print(void)
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "|";
		}
		cout << endl;
	}
}

int main()
{

	while (true)
	{
		print();
		int x;
		cin >> x;
		if (arr[ x/3 ][ x%3 ] == 'X' || arr[x / 3][x % 3] == 'O')
		{
			continue;
			cout << "tryagain";
		}
		arr[x/3][x % 3] = player;
		if (isWinner() == true)
		{
			cout << player << " is the winner" << endl;
			break;
		}
		if (isTie() == true)
		{
			cout << "Game Over";
			break;
		}
		player = (player == 'X') ? 'O' : 'X';
	}
}
