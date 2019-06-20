#include <iostream>
#include <climits>
using namespace std;

int LISLength(int arr[], int i, int n, int prev)
{
	if (i == n)
	{
		return 0;
	}
	
	int excl = LISLength(arr, i+1, n, prev);
	int incl = 0;
	if (arr[i] > prev)
	{
		incl = LISLength(arr, i+1, n, arr[i]) + 1;
	}
	return max(excl, incl);
}

int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	//Output: Length of LIS is 6
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The length of longest increasing subsequence is " << LISLength(arr, 0, n, INT_MIN);
	return 0;
}