#include <iostream>
using namespace std;

int solution(int values[], int weights[], int W, int n)
{
	if (n == 0)
	{
		return 0;
	}
	
	if (weights[n-1] > W)
	{
		return solution(values, weights, W, n-1);
	}
	else
	{
		int result1, result2;
		result1 = solution(values, weights, W, n-1);
		result2 = values[n-1] + solution(values, weights, W - weights[n-1], n-1);

		return max(result1, result2);
	}
}

int main()
{
	int values[] = {20, 5, 10, 40, 15, 25};
	int weights[] = {1, 2, 3, 8, 7, 4};
	int W = 10, n = 6;
	cout << "0-1 knapsack value is " << solution(values, weights, W, n); // Knapsack value is 60
	return 0;
}