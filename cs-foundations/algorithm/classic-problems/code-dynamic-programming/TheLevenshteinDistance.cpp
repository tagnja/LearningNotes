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

int dist(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return m + n;
	}
	
	if (X[m-1] == Y[n-1])
	{
		return dist(X, Y, m - 1, n -1);
	}
	else
	{
		return 1 + min(dist(X, Y, m, n - 1), dist(X, Y, m-1, n-1), dist(X, Y, m-1, n-1));
	}
}

int main()
{
	string X = "kitten", Y = "sitting";  // result is 3
	cout << "The Levenshtein distance is " << dist(X, Y, X.length(), Y.length());
	return 0;
}