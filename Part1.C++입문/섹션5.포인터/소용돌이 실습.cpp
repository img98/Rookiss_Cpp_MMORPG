#include <iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N) //보드판 위를 벗어나거나
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0) //이미 간적이 있다면
		return false;
	return true;
}
void SetBoard()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	while (true)
	{
		board[y][x] = num;
		
		if (num == N * N)
			break;

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			dir++;
			dir %= 4;
		}
	}
}

int main()
{
	cout << "Input Number : ";
	cin >> N;
	SetBoard();
	PrintBoard();
	return 0;
}
