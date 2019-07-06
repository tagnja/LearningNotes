#include <iostream>
#include <cstring>
using namespace std;

#define N 8

int count = 0;
int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };

bool isSafe(char mat[][N], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (mat[i][col] == 'Q')
		{
			return false;
		}
	}
	
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (mat[i][j] == 'Q')
		{
			return false;
		}
	}
	
	for (int i = row, j = col; i >= 0 && j < N; i--, j++)
	{
		if (mat[i][j] == 'Q')
		{
			return false;
		}
	}
	
	return true;
}

void NQueen(char mat[][N], int row)
{	
	if (row == N)
	{
		cout << ++count << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	
	// place Queen at every square in current row r
    // and recur for each valid movement 
	for (int k = 0; k < N; k++)
	{
		if (isSafe(mat, row, k))
		{
			// place queen on current square
			mat[row][k] = 'Q';
			// recur for next row
			NQueen(mat, row+1);
			// backtrack and remove queen from current square ??? TODO
			mat[row][k] = '-';
		}
	}
	return;
}

int main()
{
	// mat[][] keeps track of position of Queens in current configuration
	char mat[N][N];
	
	// initalize mat[][] by '-'
    memset(mat, '-', sizeof mat);
	
	int row = 0;
	NQueen(mat, row); // N=8 has 92 possible N-Queen result 
	return 0;
}

// T(n) = O(N^N), S(n) = O(N^2)
