#include <iostream>
#include <climits>
using namespace std;

int LISLength(int arr[], int n)
{
	int L[n] = {0};
	L[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && L[i] < L[j])
			{
				L[i] = L[j];
			}
		}
		L[i]++;
	}
	
	int lis = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		lis = max(L[i], lis);
	}
	return lis;
}

int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	//Output: Length of LIS is 6
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The length of longest increasing subsequence is " << LISLength(arr, n);
	return 0;
}