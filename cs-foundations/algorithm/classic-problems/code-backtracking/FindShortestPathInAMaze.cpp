#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

// M x N matrix
#define M 10
#define N 10

int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};

bool isValid(int maze[M][N], int visited[M][N], int x, int y)
{
	if (maze[x][y] == 0 || visited[x][y] || x < 0 || x >= M|| y < 0 || y >= N)
	{
		return false;
	}
	return true;
}

void findShortestPath(int mat[M][N], int visited[M][N], 
	int i, int j, int x, int y, int& min_dist, int dist)
{	
	if (i == x && j == y)
	{
		min_dist = min(dist, min_dist);
		return;
	}
	visited[i][j] = 1;
	
	for (int k = 0; k < 4; k++)
	{
		int newI = i + row[k];
		int newJ = j + col[k];
		if (isValid(mat, visited, newI, newJ))
		{
			findShortestPath(mat, visited, newI, newJ, x, y, min_dist, dist + 1);
		}
	}
	visited[i][j] = 0;
	return;
}

int main()
{
    int mat[M][N] = 
    {
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
    };
 
    // construct a matrix to keep track of visited cells
    int visited[M][N];
 
    // initially all cells are unvisited
    memset(visited, 0, sizeof visited);
    
    int min_dist = INT_MAX;
    findShortestPath(mat, visited, 0, 0, 7, 5, min_dist, 0);
 
    if(min_dist != INT_MAX)
        cout << "The shortest path from source to destination "
                "has length " << min_dist;
    else 
        cout << "Destination can't be reached from given source";
    
    return 0;
}