#include<iostream>
#include<string>
using namespace std;

// Function to find length of shortest Common supersequence of
// sequences X[0..m-1] and Y[0..n-1]
int SCSLength(string X, string Y)
{
	int m = X.length(), n = Y.length();
	// lookup table stores solution to already computed sub-problems
    // i.e. lookup[i][j] stores the length of SCS of substring
    // X[0..i-1] and Y[0..j-1]
	int lookup[m+1][n+1];
	
	for (int i = 0; i <= m; i++)
	{
		lookup[i][0] = i;
	}
	
	for (int j = 0; j <= n; j++)
	{
		lookup[0][j] = j;
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(X[i-1] == Y[j-1])
			{
				lookup[i][j] = lookup[i-1][j-1] + 1;
			}
			else
			{
				lookup[i][j] = min(lookup[i][j-1] + 1, 
								lookup[i-1][j] + 1);
			}
		}
	}
	return lookup[m][n];
}

int main()
{
	string X = "ABCBDAB", Y = "BDCABA";
	// Output: The length of shortest Common supersequence is 9
	cout << "The length of Shortest Common Supersequence is " 
			<< SCSLength(X, Y) << endl;
	return 0;
}