# include<iostream>
# include<string>
using namespace std;

int SCSLength(string X, string Y, int m, int n)
{
	if (n == 0)
	{
		return m;
	}
	if (m == 0)
	{
		return n;
	}
	int result = SCSLength(X, Y, n-1, m-1);
	if (X[n-1] == Y[m-1])
	{
		result += 1;
	}
	else
	{
		if (((n-2 >= 0 && X[n-1] != X[n-2]) || n-2 < 0) && m-2 >= 0 && X[n-1] == Y[m-2])
		{
			
		}
		else
		{
			result += 1;
		}
		
		if (((m-2 >= 0 && Y[m-1] != Y[m-2]) || m-2 < 0) && n-2 >= 0 && Y[m-1] == X[n-2])
		{
			
		}
		else
		{
			result += 1;
		}
		return result;
	}
}
int main()
{
	string s1 = "ABC", s2 = "ACB";
	int m = 3, n = 3;
	std::cout << "The length of SCS is " << SCSLength(s1, s2, m, n) << std::endl;
	return 0;
}

