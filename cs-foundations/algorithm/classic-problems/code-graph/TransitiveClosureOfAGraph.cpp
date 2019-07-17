#include <iostream>
#include <cstring>
using namespace std;

#define V 4

void DFS(int mat[][V], int visited[][V], int curr, int X)
{
	for (int j = 0; j < V; j++)
	{
		visited[curr][j] = 1;
		if (j != curr && j != X && mat[curr][j] == 1)
		{
			mat[X][j] = 1;
			if (! visited[j][0])
			{
				DFS(mat, visited, j, X);
			}
		}
	}
}

void solution(int mat[][V])
{
	int visited[V][V];
	
	for (int i = 0; i < V; i++)
	{
		memset(visited, 0, sizeof visited);
		DFS(mat, visited, i, i);
	}
	return;
}

int main()
{
	int mat[V][V] = { { 1, 1, 1, 0}, 
					{ 0, 1, 1, 0}, 
					{ 1, 0, 1, 1}, 
					{ 0, 0, 0, 1}};
	/*
	
	Output:
		Transitive closure matrix is 
		1 1 1 1 
		1 1 1 1 
		1 1 1 1 
		0 0 0 1 
	*/
	
	solution(mat);
	
	cout << "Transitive closure matrix is " << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

// T(n) = O(n^3), S(n) = O(n^2)