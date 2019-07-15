#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Job {
	int taskId, deadline, profit;
};

int solution(vector<Job> jobs)
{
	int slot[jobs.size()];
	memset(slot, 0, sizeof slot);
	
	int maxProfit = 0;
	for (Job &job : jobs)
	{
		for (int i = job.deadline - 1; i >= 0; i--)
		{
			if (slot[i] == 0)
			{
				slot[i] = job.profit;
				maxProfit += job.profit;
				break;
			}
		}
	}
	return maxProfit;
}

int main()
{
	vector<Job> jobs = 
	{
		{ 1, 9, 15 }, { 2, 2, 2 }, { 3, 5, 18 }, { 4, 7, 1 }, { 5, 4, 25 },
        { 6, 2, 20 }, { 7, 5, 8 }, { 8, 7, 10 }, { 9, 4, 12 }, { 10, 3, 5 }
	};
	sort(jobs.begin(), jobs.end(), [](Job &a, Job &b)
	{
		return a.profit > b.profit; // using C++11 lambda comparison
	});
	cout << "Total Profit is " << solution(jobs);
	
	return 0;
}