#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

int SCSLength(string X, string Y, int m, int n, auto &lookup)
{
	if (m == 0 || n == 0)
	{
		return m + n;
	}
	
	string key = to_string(m) + "|" + to_string(n);
	if (lookup.find(key) == lookup.end())
	{
		if (X[m-1] == Y[n-1])
		{
			lookup[key] = SCSLength(X, Y, m-1, n-1, lookup) + 1;
		}
		else
		{
			lookup[key] = min(SCSLength(X, Y, m, n-1, lookup) + 1, SCSLength(X, Y, m-1, n, lookup) + 1);
		}
	}
	return lookup[key];
}

int main()
{
	string X = "ABCBDAB", Y = "BDCABA"; 
	// Output: The length of shortest Common supersequence is 9
	int m = X.length(), n = Y.length();
	// create a map to store solutions of subproblems
    // we can also use array instead of map
    unordered_map<string, int> lookup;
	cout << "The length of SCS is " << SCSLength(X, Y, m, n, lookup);
	return 0;
}