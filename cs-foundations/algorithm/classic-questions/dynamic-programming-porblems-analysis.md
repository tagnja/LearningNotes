# Dynamic Programming Problems Analysis

<h3 id="content">Content</h3>

- [Before Start](#first)
- I. Classic Problems
  - [Longest Common Subsequence (LCS)](#lcs)
  - Shortest Common Supersequence
  - Longest Increasing Subsequence problem
  - The Levenshtein distance (Edit distance) problem
  - Matrix Chain Multiplication
  - 0–1 Knapsack problem
  - Partition problem
  - Rod Cutting
  - Coin change problem
  - Word Break Problem
- II. Other Problems
  - Balanced Partition
  - Box Stacking
  - Count All Palindrome Sub-Strings in a String
  - Count ways to reach the n’th stair
  - Counting Boolean Parenthesizations
  - Dice Throw Problem
  - Edit Distance
  - Egg Dropping Puzzle
  - Interleaved Strings
  - Longest Common Substring
  - Longest **Substring** Without Repeating Characters
  - Longest Palindromic Subsequence
  - Longest Path In Matrix
  - Maximal Product when Cutting Rope
  - Maximum Value Contiguous Subsequence
  - Min Cost Path
  - Minimum edit distance
  - Minimum number of jumps to reach end
  - Minimum Partition
  - Number of Coins
  - Optimal strategy for the game
  - String interleaving problem
  - Subset sum problem
  - Text justification problem
  - The Fibonacci Problem
  - Total Decoding Messages
  - Two-Person Traversal of a Sequence of Cities
  - Unbounded Knapsack Problem
  - Ways to Cover a Distance
  - Wildcard Pattern Matching
- References

### Main

<h3 id="first">Before Start</h3>

**Convention**

- Description
- Analysis
- Solution

**Method Summary**

- using assisted mark array tab

  >  Longest Increase Sequence



### I. Classic Problems



<h3 id="lcs">Longest Common Subsequence</h3>

**Description**

The longest common subsequence (LCS) problem is the problem of finding the longest subsequence that is present in given two sequences in the same order. i.e. find a longest sequence which can be obtained from the first original sequence by deleting some items, and from the second original sequence by deleting other items.

The problem differs from problem of finding common substrings. Unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.
For example, consider the two following sequences X and Y

X: ABCBDAB
Y: BDCABA

The length of LCS is 4
LCS are BDAB, BCAB and BCBA

**Analysis**

1\. Find the relation by Top to Buttom

if X[m] = Y[n], 

​	LCS(X[1..m], Y[1..n]) = LCS(X[1..m-1], Y[1..n-1]) + X[m]

else, 

​	LCS[X[1..m], Y[1..n]] = max( LCS(X[1..m-1], Y[1..n]), LCS(X[1..m], Y[1..n-1]) )

2\. Remove Repeated subproblems



**Solution**



References

[Longest Common Subsequence | Introduction & LCS Length - Techie Delight](https://www.techiedelight.com/longest-common-subsequence/)



### II. Other Problems



### References

[1] [Top 10 Dynamic programming problems for interviews - medium](https://medium.com/@codingfreak/top-10-dynamic-programming-problems-5da486eeb360)
[2] [What are the top 10 most popular dynamic programming problems among interviewers? - quora](https://www.quora.com/What-are-the-top-10-most-popular-dynamic-programming-problems-among-interviewers)
[3] [Top 20 Dynamic Programming Interview Questions](https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/)