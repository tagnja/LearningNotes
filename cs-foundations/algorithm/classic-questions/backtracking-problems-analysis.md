# Backtracking Problems Analysis

<h3 id="content"></h3>
### Content

- Convention
- [Introduction to Backtracking Programming](#intr)
- Top Problems
  - [Knight’s Tour Problem](#ktpr)
  - Rat In A Maze Puzzle
  - N Queens Problem
  - The Word Break Problem
  - Print All The Permutations Of a String
  - Search a Word In a Matrix
  - N Queens Problem — Better Solution
  - SUDOKU Solver
- Problems
  - Crptarithmetic puzzle
  - Find if there is a path of more than k length from a source
  - Find Path from corner cell to middle cell in a maze
  - Hamiltonian cycle
  - Knight’s Tour Problem
  - longest possible route in a matrix with hurdles
  - M Coloring Problem
  - Match a pattern and string using regular expression
  - N Queens Problem
  - Partition of a set into k subsets with equal sum
  - Print all permutations of a given string
  - Print all possible paths from top left to bottom right of a mXn matrix
  - Print palindromic partitions string
  - Rat in a Maze
  - Remove Invalid Parenthesis
  - Search a Word In a Matrix
  - Shortest safe route in a path with landmines
  - Subset sum
  - Sudoku solver
  - Tug of war
  - Warnsdorff’s Algorithm
  - Word Break Problem

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

<h3 id="intr"></h3>
### Introduction to Backtracking Programming

**Backtracking** can be defined as a general algorithmic technique that considers searching every possible combination in order to solve a computational problem.

Backtracking is an algorithmic paradigm that tries different solutions until finds a solution that “works”.  A Naive solution for these problems is to try all configurations and output a configuration that follows given problem constraints. Backtracking works in incremental way and is an optimization over the Naive solution where all possible configurations are generated and tried.

Types of problems in backtracking

1. Decision Problem – In this, we search for a feasible solution.
2. Optimization Problem – In this, we search for the best solution.
3. Enumeration Problem – In this, we find all feasible solutions.

Backtracking algorithms are generally exponential in both time and space complexity. It don't like *Dynamic Programming* or *Greedy Algorithms* in logarithmic, linear, linear-logarithmic time complexity. However, a few  problems still remain, that only have backtracking algorithms to solve them until now.

Consider a situation that you have three boxes in front of you and only one of them has a gold coin in it but you do not know which one. So, in order to get the coin, you will have to open all of the boxes one by one. You will first check the first box, if it does not contain the coin, you will have to close it and check the second box and so on until you find the coin. This is what backtracking is, that is solving all sub-problems one by one in order to reach the best possible solution.

Process of Backtracking

```
Pick a starting point.
   while(Problem is not solved)
      For each path from the starting point.
         check if selected path is safe, if yes select it
         and make recursive call to rest of the problem
         If recursive calls returns true, 
           then return true.
         else 
           undo the current move and return false.
      End For
 If none of the move works out, return false, NO SOLUTON.
```



References

[Backtracking | Introduction - geeksforgeeks](https://www.geeksforgeeks.org/backtracking-introduction/)

[Introduction To Backtracking Programming - algorithms](https://algorithms.tutorialhorizon.com/introduction-to-backtracking-programming/)



[`back to content`](#content)

---



### Top Problems

<h3 id="ktpr"></h3>
### Knight’s Tour Problem

#### Description

A [knight's tour](https://en.wikipedia.org/wiki/Knight%27s_tour) is a sequence of moves of a knight on a chessboard such that the knight visits every square only once. If the knight ends on a square that is one knight's move from the beginning square (so that it could tour the board again immediately, following the same path), the tour is closed, otherwise it is open

#### Solutions

Knight can move in 8 possible directions from a given square.

Using arrays stores the relative position of Knight movement from any location. If current location is (x, y), Knight can move to (x+row[k], y+col[k]) for 0 <= k <= 7 using below array.

row[] = [ 2, 1, -1, -2, -2, -1, 1, 2, 2 ]
col[] = [ 1, 2, 2, 1, -1, -2, -2, -1, 1 ]

```cpp
#include <iostream>
#include <string>
using namespace std;

// N*N chessboard
#define N 5

// 8 possible movements for a knight
// It is important to avoid changing sequence of below arrays
int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };

int count = 0;

bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
	{
		return false;
	}
	return true;
}

void KnightTour(int visited[N][N], int x, int y, int pos)
{
	// mark current square is visited
	visited[x][y] = pos;
	
	// if all square are visited, print the solution
	if (pos >= N*N)
	{
		cout << ++count << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// backtrack before returning
		visited[x][y] = 0;
		return;
	}
	
	// check for all 8 possible movements for a knight and recur for each valid movement
	for (int k = 0; k < 8; k++)
	{
		int newX = x + row[k];
		int newY = y + col[k];
		if (isValid(newX, newY) && !visited[newX][newY])
		{
			KnightTour(visited, newX, newY, pos+1);
		}
	}
	// backtrack from current square  and remove it from current path
	visited[x][y] = 0;
}

int main()
{
	// visited[][] serves two purpose -
    // 1. It keep track of squares involved the Knight's tour.
    // 2. It stores the order in which the squares are visited
	int visited[N][N] = {0};

	int pos = 1;
	
	// start knight tour from corner square (0, 0)
	KnightTour(visited, 0, 0, pos); // 5*5, has 304 knight's tour.
	return 0;
}
```



#### Exercise

#### References

[1] [Knight's tour - wikipedia]([https://en.wikipedia.org/wiki/Knight%27s_tour](https://en.wikipedia.org/wiki/Knight's_tour))
[2] [Print all Possible Knight’s Tours in a chessboard - Techie Delight](https://www.techiedelight.com/print-possible-knights-tours-chessboard/)
[3] [Chess Knight Problem | Find Shortest path from source to destination - Techie Delight](https://www.techiedelight.com/chess-knight-problem-find-shortest-path-source-destination/)
[4] [The Knight’s tour problem | Backtracking-1 - geeksforgeeks](https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/)

[`back to content`](#content)

---





### References

[1] [Top 20 Backtracking Algorithm Interview Questions - geeksforgeeks](https://www.geeksforgeeks.org/top-20-backtracking-algorithm-interview-questions/)
[2] [TOP 10 INTERVIEW PROBLEMS ON BACKTRACKING - algorithms](https://algorithms.tutorialhorizon.com/top-10-problems-on-backtracking/)
[3] [backtracking problems - techiedelight](https://www.techiedelight.com/Category/backtracking/)
[4] [Backtracking Algorithms - geeksforgeeks](https://www.geeksforgeeks.org/backtracking-algorithms/)