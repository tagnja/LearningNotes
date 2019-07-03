# include<iostream>
# include<string>
using namespace std;

int LCSLength(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}
	if (X[m-1] == Y[n-1])
	{
		return LCSLength(X, Y, m-1, n-1) + 1;
	}
	else
	{
		int l1 = LCSLength(X, Y, m-1, n);
		int l2 = LCSLength(X, Y, m, n-1);
		return l1 > l2 ? l1 : l2;
	}
}

int main()
{
	string s1 = "ABCBDAB", s2 = "BDCABA";
	int m = 7, n = 6;
	cout << "The length of LCS is " << LCSLength(s1, s2, m, n) << endl;
	
	string s11 = "AAAAAAAAAAAAAAAA", s22 = "BBBBBBBBBBBBBBBA";
	int m1 = 16, n1 = 16;
	cout << "The length of LCS is " << LCSLength(s11, s22, m1, n1) << endl;
	return 0;
}