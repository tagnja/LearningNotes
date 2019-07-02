#include <iostream>
using namespace std;

int min(int x, int y, int z)
{
	if (x < y)
	{
		return x < z ? x : z;
	}
	else
	{
		return y < z ? y : z;
	}
}

int dist(string X, string Y)
{
	int m = X.length(), n = Y.length();
	int dist[m+1][n+1] = {0};
	
	for (int i = 0; i < m+1; i++)
	{
		dist[i][0] = i;
	}
	
	for (int j = 0; j < n+1; j++)
	{
		dist[0][j] = j;
	}
	
	for (int i = 1; i < m+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				dist[i][j] = dist[i-1][j-1];
			}
			else
			{
				dist[i][j] = 1 + min(dist[i-1][j], dist[i-1][j-1], dist[i][j-1]);
			}
		}
	}
	return dist[m][n];
}

int main()
{
	string X = "kitten", Y = "sitting";  // result is 3
	cout << "The Levenshtein distance is " << dist(X, Y);
	return 0;
}