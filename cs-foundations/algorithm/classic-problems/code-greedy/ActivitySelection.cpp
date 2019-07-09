#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

void sort(int act[][2], int n)
{
	int temp[n][2];
	for (int i = 0; i < n; i++)
	{
		int j, index = -1, flag = INT_MAX;
		for (j = 0; j < n; j++)
		{
			if (act[j][1] < flag)
			{
				index = j;
				flag = act[j][1];
			}
		}
		temp[i][0] = act[j][0];
		temp[i][1] = act[j][1];
	}
	act = temp;
}
void solution(int act[][2], int n)
{
	sort(act, n);
	int result[n][2];
	memset(result, 0, sizeof result);
	result[0][0] = act[0][0];
	result[0][1] = act[0][1];
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (act[i][0] > result[index][1])
		{
			result[i][0] = act[i][0];
			result[i][1] = act[i][1];
			index = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (result[i][0] != 0 && result[i][1] != 0)
		cout << "{" << result[i][0] << "," << result[i][1] << "}" << endl;
	}
	return;
}

int main()
{
	int a[11][2] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, 
		{6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
	solution(a, 11);
	return 0;
}