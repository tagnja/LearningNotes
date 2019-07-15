# Graph Problems Analysis

### Content

- Top Problems
  - Counting the number of connected components in an undirected graph
  - [Find the number of islands (DFS)](#Find the number of islands (DFS))
- Problems
  - 2-Edge Connectivity in the graph
  - 2-Vertex Connectivity in the graph
  - All-Pairs Shortest Paths – Floyd Warshall Algorithm
  - Application of DFS
  - Arrival and Departure Time of Vertices in DFS
  - Bipartite Graph
  - Breadth First Search (BFS) | Iterative & Recursive Implementation
  - Check if an undirected graph contains cycle or not
  - Check if given digraph is a DAG (Directed Acyclic Graph) or not
  - Check if given Graph is Strongly Connected or not
  - Check if given Graph is Strongly Connected or not using one DFS Traversal
  - Chess Knight Problem – Find Shortest path from source to destination
  - Depth First Search (DFS) | Iterative & Recursive Implementation
  - Detect cycle in an undirected graph
  - Determine if a given graph is Bipartite Graph using DFS
  - Determine if an undirected graph is a Tree (Acyclic Connected Graph)
  - Determine negative-weight cycle in a graph
  - Disjoint-Set Data Structure (Union-Find Algorithm)
  - Find a mother vertex in a graph
  - Find Cost of Shortest Path in DAG using one pass of Bellman-Ford
  - Find maximum cost path in graph from given source to destination
  - Find number of islands
  - Graph Implementation in C
  - Graph Implementation in C++ without using STL
  - Graph Implementation in Java using Collections
  - Graph Implementation using STL
  - Greedy coloring of graph
  - Iterative Depth first traversal
  - Kahn’s Topological Sort Algorithm
  - Kruskal’s Algorithm for finding Minimum Spanning Tree
  - Least cost path in given digraph from given source to destination having exactly m edges
  - Least Cost Path in Weighted Digraph using BFS
  - Longest path between any pair of vertices
  - Maximum product of two non- intersecting paths in a tree
  - Minimum number of throws required to win Snake and Ladder game
  - Print All Hamiltonian Path present in a graph
  - Print all k-colorable configurations of the graph (Vertex coloring of graph)
  - Print all path from a given source to a destination
  - Single-Source Shortest Paths – Bellman Ford Algorithm
  - Single-Source Shortest Paths – Dijkstra’s Algorithm
  - Stepping Number
  - Terminology and Representations of Graphs
  - Topological Sorting in a DAG
  - Total paths in given digraph from given source to destination having exactly m edges
  - Transitive Closure of a Graph
  - Types of edges involved in DFS and relation between them
  - Union-Find Algorithm for Cycle Detection in undirected graph

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

### Introduction to Graph Algorithms

### Top Problems

### Find the number of islands (DFS)

#### Description

Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

**Example:**

```
Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1} 
Output : 5
```

This is a variation of the standard problem: “Counting the number of connected components in an undirected graph”.

#### Solutions

```cpp
#include <iostream>
#include <cstring>

using namespace std;

#define ROW 5
#define COL 5

void DFS(int mat[][COL], bool visited[][COL], int i, int j)
{
	if (i >= 0 && i < ROW && j >= 0 && j < COL && ! visited[i][j] && mat[i][j] == 1)
	{
		visited[i][j] = true;
		DFS(mat, visited, i-1, j);
		DFS(mat, visited, i+1, j);
		DFS(mat, visited, i, j-1);
		DFS(mat, visited, i, j+1);
		DFS(mat, visited, i-1, j-1);
		DFS(mat, visited, i-1, j+1);
		DFS(mat, visited, i+1, j+1);
		DFS(mat, visited, i+1, j-1);
	}
	
	return;
}

int solution(int mat[][COL])
{
	bool visited[ROW][COL];
	memset(visited, 0, sizeof visited);
	
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (mat[i][j] && ! visited[i][j])
			{
				count++;
				DFS(mat, visited, i, j);
			}
		}
	}
	return count;
}

int main()
{
	int mat[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };
	
	cout << "Number of islands is: " << solution(mat); // Number of islands is: 5 
	return 0;
}
```



#### Exercise

#### References

[Find the number of islands | Set 1 (Using DFS) - geeksforgeeks](https://www.geeksforgeeks.org/find-number-of-islands/)

[`back to content`](#content)

---

### References

[1] [Graphs Interview Questions and Practice Problems - Thchie Delight](https://www.techiedelight.com/graphs-interview-questions/)
[2] [Graph Data Structure And Algorithms - geeksforgeeks](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
[3] [Top 10 Interview Questions on Depth First Search (DFS) - geeksforgeeks](https://www.geeksforgeeks.org/top-10-interview-question-depth-first-search-dfs/)