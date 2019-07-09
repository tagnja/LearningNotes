# Greedy Algorithm Problems Analysis

### Content

<div id="content"></div>
- Convention
- [Introduction to Greedy Algorithms](#intr)
- Classic Problems
  - [Activity Selection Problem](#aspr)
  - Greedy coloring of graph (Graph coloring)
  - Job Sequencing Problem with Deadlines
  - Shortest Superstring Problem
  - Find minimum number of platforms needed in the station so to avoid any delay in arrival of any train
  - Huffman Coding
  - Dijkstra Shortest path algorithm
  - Kruskal’s Algorithm for finding **Minimum Spanning Tree**
  -  Fractional Knapsack Problem
- Other Problems
  - Bin packing problem
  - Boruvka’s algorithm
  - Connect n ropes with minimum cost
  - Dail’s Algorithm
  - Dijkstra’s Algorithm for Adjacency List Representation
  - Efficient Huffman Coding for Sorted Input
  - Find maximum sum possible equal to sum of three stacks
  - Find minimum time to finish all jobs with given constraints
  - Greedy Algorithm to find Minimum number of Coins
  - K centres problem
  - Minimize Cash Flow among a given set of friends who have borrowed money from each other
  - Minimum Number of Platforms Required for a Railway/Bus Station
  - Prim’s Minimum Spanning Tree Algorithm (Prim’s MST)
  - Prim’s MST for Adjacency List Representation
  - Set cover problem

### Before Start

### Convention

```
#### Description

#### Solutions

#### Exercise

#### References
[`back to content`](#content)

---
```



### Main



### Introduction to Greedy Algorithms

<h3 id="intr"></h3>
**What is it**

Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. So the problems where choosing locally optimal also leads to global solution are best fit for Greedy.

For example consider the Fractional Knapsack Problem. The local optimal strategy is to choose the item that has maximum value vs weight ratio. This strategy also leads to global optimal solution because we allowed to take fractions of an item.

**When to use**

A problem must comprise these two components for a greedy algorithm to work:

1. It has **optimal substructures**. The optimal solution for the problem contains optimal solutions to the sub-problems.
2. It has a **greedy property** (hard to prove its correctness!). If you make a choice that seems the best at the moment and solve the remaining sub-problems later, you still reach an optimal solution. You will never have to reconsider your earlier choices.

**How to use**

References

[Greedy Algorithms - geeks for geeks](https://www.geeksforgeeks.org/greedy-algorithms/)

[Basics of Greedy Algorithms - hackerearth](https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/) 





### Top Problems

<div  id="acpr"></div>


### Activity Selection Problem

#### Description

In Activity Selection Problem, we’re given a set of activities and the starting & finishing time of each activity, we need to find the maximum number of activities that can be performed by a single person assuming that a person can only work on a single activity at a time.

For example,

```
Input:
(1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9), (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)

Output: (1 4), (5 7), (8 11), (12 14)
```

#### Solutions

Earliest finish time priority.

Process:

- Sorts activities in increasing order of their finish time.
- Create a set S to store the selected activities.
- Put the activity in activities list if start time of the activity is greater or equal to the finish time of the last selected activity

```cpp
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
```

Output

```
{1, 4}
{5, 7}
{8, 11}
{12, 14}
```

 Time complexity of problem decided by  time complexity of sort algorithm.

#### Exercise

#### References

[Activity Selection Problem](https://www.techiedelight.com/activity-selection-problem/)

[`back to content`](#content)

---


### References

[1] [Top 7 Greedy Algorithm Problems - medium](https://medium.com/@codingfreak/top-7-greedy-algorithm-problems-3885feaf9430)

[2] [Top 7 Greedy Algorithm Problems - Techie Delight](https://www.techiedelight.com/greedy-algorithm-problems/)

[3] [What are some good Greedy algorithm lists? - Quora](https://www.quora.com/What-are-some-good-Greedy-algorithm-lists)

[4] [Top 20 Greedy Algorithms Interview Questions - geeksforgeeks](https://www.geeksforgeeks.org/top-20-greedy-algorithms-interview-questions/)