#include <iostream>
#include <vector>
using namespace std;

void LISPrint(int arr[], int n)
{
	vector<int> LIS[n];
	LIS[0].push_back(arr[0]);
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && LIS[i].size() < LIS[j].size())
			{
				LIS[i] = LIS[j];
			}
		}
		LIS[i].push_back(arr[i]);
	}
	
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (LIS[i].size() > LIS[j].size())
		{
			j = i;
		}
	}
	cout << "LIS is ";
	for (int x : LIS[j])
	{
		cout << x << " ";
	}
	
	return;
}

int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	//Length of LIS is 6
	int n = sizeof(arr) / sizeof(arr[0]);
	LISPrint(arr, n);
	// LIS print: 0 4 6 9 13 15
	return 0;
}