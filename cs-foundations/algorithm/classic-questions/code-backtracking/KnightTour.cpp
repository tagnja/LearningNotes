#include <iostream>
#include <cstring>
using namespace std;

// N*N chessboard
#define N 5

// 8 possible movements for a knight
// It is important to avoid changing sequence of below arrays
int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };

int count = 0;

bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
	{
		return false;
	}
	return true;
}

void KnightTour(int visited[N][N], int x, int y, int pos)
{
	// mark current square is visited
	visited[x][y] = pos;
	
	// if all square are visited, print the solution
	if (pos >= N*N)
	{
		cout << ++count << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// backtrack before returning
		visited[x][y] = 0;
		return;
	}
	
	// check for all 8 possible movements for a knight and recur for each valid movement
	for (int k = 0; k < 8; k++)
	{
		int newX = x + row[k];
		int newY = y + col[k];
		if (isValid(newX, newY) && !visited[newX][newY])
		{
			KnightTour(visited, newX, newY, pos+1);
		}
	}
	// backtrack from current square  and remove it from current path
	visited[x][y] = 0;
}

int main()
{
	// visited[][] serves two purpose -
    // 1. It keep track of squares involved the Knight's tour.
    // 2. It stores the order in which the squares are visited
	int visited[N][N];
	
	// initialize visited[][] by 0 (unvisited)
	memset(visited, 0, sizeof visited);
	
	int pos = 1;
	
	// start knight tour from corner square (0, 0)
	KnightTour(visited, 0, 0, pos); // 5*5, has 304 knight's tour.
	return 0;
}

// T(n) = O(8^(N^2)), S(n) = O(N^2)