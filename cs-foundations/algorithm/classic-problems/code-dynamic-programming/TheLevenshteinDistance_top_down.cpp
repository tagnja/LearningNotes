#include <iostream>
#include <unordered_map>
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

int dist(string X, string Y, int m, int n, auto &lookup)
{
	if (m == 0 || n == 0)
	{
		return m + n;
	}
	string key = m + "|" + n;
	if (lookup.find(key) == lookup.end())
	{
		if (X[m-1] == Y[n-1])
		{
			lookup[key] = dist(X, Y, m - 1, n -1, lookup);
		}
		else
		{
			lookup[key] = 1 + min(dist(X, Y, m, n - 1, lookup), dist(X, Y, m-1, n-1, lookup), dist(X, Y, m-1, n-1, lookup));
		}
	}
	return lookup[key];
}

int main()
{
	string X = "kitten", Y = "sitting";  // result is 3
	unordered_map<string, int> lookup;
	cout << "The Levenshtein distance is " << dist(X, Y, X.length(), Y.length(), lookup);
	return 0;
}