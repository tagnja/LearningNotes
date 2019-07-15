#include <iostream>
#include <cstring>

using namespace std;

#define ROW 5
#define COL 5


void DFS(int mat[][COL], bool visited[][COL], int i, int j)
{
	if (i >= 0 && i < ROW && j >= 0 && j < COL && ! visited[i][j] && mat[i][j] == 1)
	{
		visited[i][j] = true;
		DFS(mat, visited, i-1, j);
		DFS(mat, visited, i+1, j);
		DFS(mat, visited, i, j-1);
		DFS(mat, visited, i, j+1);
		DFS(mat, visited, i-1, j-1);
		DFS(mat, visited, i-1, j+1);
		DFS(mat, visited, i+1, j+1);
		DFS(mat, visited, i+1, j-1);
	}
	
	return;
}

int solution(int mat[][COL])
{
	bool visited[ROW][COL];
	memset(visited, 0, sizeof visited);
	
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (mat[i][j] && ! visited[i][j])
			{
				count++;
				DFS(mat, visited, i, j);
			}
		}
	}
	return count;
}

int main()
{
	int mat[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };
	
	cout << "Number of islands is: " << solution(mat); // Number of islands is: 5 
	return 0;
}