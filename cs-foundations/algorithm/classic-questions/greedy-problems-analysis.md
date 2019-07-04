# Greedy Algorithm Problems Analysis

<h3 id="content">Content</h3>
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
  - Kruskal’s Algorithm for finding Minimum Spanning Tree
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
  - Prim’s Minimum Spanning Tree Algorithm
  - Prim’s MST
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

<h3 id="intr"> </h3><br>

### Introduction to Greedy Algorithms

**What is it**

Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. So the problems where choosing locally optimal also leads to global solution are best fit for Greedy.

For example consider the Fractional Knapsack Problem. The local optimal strategy is to choose the item that has maximum value vs weight ratio. This strategy also leads to global optimal solution because we allowed to take fractions of an item.

**When to use**

**How to use**

References

[Greedy Algorithms - geeks for geeks](https://www.geeksforgeeks.org/greedy-algorithms/)

[Basics of Greedy Algorithms - hackerearth](https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/) //TODO





### Top Problems

<h3 id="acpr"> </h3><br>

### Activity Selection Problem

#### Description

In Activity Selection Problem, we’re given a set of activities and the starting & finishing time of each activity, we need to find the maximum number of activities that can be performed by a single person assuming that a person can only work on a single activity at a time.

For example,

```
Input:
(1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9), (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)

Output: (1 4), (5 7), (8 11), (12 14)
```



**Output:** (1 4), (5 7), (8 11), (12 14)

#### Solutions

#### Exercise

#### References
[`back to content`](#content)

---


### References

[1] [Top 7 Greedy Algorithm Problems - medium](https://medium.com/@codingfreak/top-7-greedy-algorithm-problems-3885feaf9430)

[2] [Top 7 Greedy Algorithm Problems - Techie Delight](https://www.techiedelight.com/greedy-algorithm-problems/)

[3] [What are some good Greedy algorithm lists? - Quora](https://www.quora.com/What-are-some-good-Greedy-algorithm-lists)

[4] [Top 20 Greedy Algorithms Interview Questions - geeksforgeeks](https://www.geeksforgeeks.org/top-20-greedy-algorithms-interview-questions/)