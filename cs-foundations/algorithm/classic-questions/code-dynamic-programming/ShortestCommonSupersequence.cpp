# include<iostream>
using namespace std;

int SCSLength(string X, string Y, int m, int n)
{
	if (m == 0 || n ==0)
	{
		return m + n;
	}

	if (X[m-1] == Y[n-1])
	{
		return SCSLength(X, Y, m-1, n-1) + 1;
	}
	else
	{
		int i = SCSLength(X, Y, m-1, n) + 1;
		int j = SCSLength(X, Y, m, n-1) + 1;
		return min(i, j);
	}
}
int main()
{
	string X = "ABCBDAB", Y = "BDCABA";
	int m = X.length(), n = Y.length();
	cout << "The length of SCS is " << SCSLength(X, Y, m, n) << endl;
	return 0;
}

