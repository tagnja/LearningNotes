# Dynamic Programming Problems Analysis

<h3 id="content">Content</h3>

- [Before Start](#first)
- I. Classic Problems
  - [x] [Longest Common Subsequence (LCS)](#lcs)
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
- Solutions

**Problem Class Summary**

- using assisted mark array tab

  >  Longest Increase Sequence

**Solution Methods**

- Top-down approach: recursion and memorized.

  > 1\. Sub-problem result store to Array, or sub-problem index value to map). If this sub-problem exist in memorized container, bypass it and don't calculate it.
  >
  > 2\. The memorized container can be global variable(array, map) or parameter of function(map).

- Bottom-up approach: for iterator and relational calculate. 

  > Iterate Impose sub-problem result to calculate bigger scale sub-problem.



### I. Classic Problems



<h3 id="lcs">Longest Common Subsequence</h3>

#### Description

The longest common subsequence (LCS) problem is the problem of finding the longest subsequence that is present in given two sequences in the same order. i.e. find a longest sequence which can be obtained from the first original sequence by deleting some items, and from the second original sequence by deleting other items.

The problem differs from problem of finding common substrings. Unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.
For example, consider the two following sequences X and Y

X: ABCBDAB
Y: BDCABA

The length of LCS is 4
LCS are BDAB, BCAB and BCBA

#### Solutions

##### 1\. Find the relation by Top to Buttom

if X[m] = Y[n], 

​	LCS(X[1..m], Y[1..n]) = LCS(X[1..m-1], Y[1..n-1]) + X[m]

else, 

​	LCS[X[1..m], Y[1..n]] = max( LCS(X[1..m-1], Y[1..n]), LCS(X[1..m], Y[1..n-1]) )

```
             | 0                              (i == 0 or j == 0)
LCS[i][j] =  | LCS[i-1][j-1] + 1              (X[i-1] = Y[j-1])
             | max(LCS[i-1][j], LCS[i][j-1])  (X[i-1] != Y[j-1])
```

Implementation

```cpp
#include <iostream>
#include <string>
using namespace std;
 
// Function to find length of Longest Common Subsequence of
// sequences X[0..m-1] and Y[0..n-1]
int LCSLength(string X, string Y, int m, int n)
{
    // return if we have reached the end of either sequence
    if (m == 0 || n == 0)
        return 0;
 
    // if last character of X and Y matches
    if (X[m - 1] == Y[n - 1])
        return LCSLength(X, Y, m - 1, n - 1) + 1;
 
    // else if last character of X and Y don't match
    return max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}
 
// Longest Common Subsequence
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
 
    cout << "The length of LCS is " <<
            LCSLength(X, Y, X.length(), Y.length());
 
    return 0;
}
```

T(n) = O(2^(n+m))

##### 2\. Remove Repeated subproblems

​                              (n, m)

​         (n-1, m)                          (n, m-1)

(n-2, m)   **(n-1, m-1)**        **(n-1, m-1)**  (n, m-2)

Implementation

```java
class LCS
{
    // Function to find length of Longest Common Subsequence of substring
    // X[0..m-1] and Y[0..n-1]
    public static int LCSLength(String X, String Y, int m, int n,
                                Map<String, Integer> lookup)
    {
        // return if we have reached the end of either string
        if (m == 0 || n == 0)
            return 0;
 
        // construct a unique map key from dynamic elements of the input
        String key = m + "|" + n;
 
        // if sub-problem is seen for the first time, solve it and
        // store its result in a map
        if (!lookup.containsKey(key))
        {
            // if last character of X and Y matches
            if (X.charAt(m - 1) == Y.charAt(n - 1)) {
                lookup.put(key, LCSLength(X, Y, m - 1, n - 1, lookup) + 1);
 
            }
            else {
                // else if last character of X and Y don't match
                lookup.put(key, Integer.max(LCSLength(X, Y, m, n-1, lookup),
                        LCSLength(X, Y, m-1, n, lookup)));
            }
        }
 
        // return the subproblem solution from the map
        return lookup.get(key);
    }
 
    // main function
    public static void main(String[] args)
    {
        String X = "ABCBDAB", Y = "BDCABA";
 
        // create a map to store solutions of subproblems
        Map<String, Integer> lookup = new HashMap<>();
 
        System.out.print("The length of LCS is "
                + LCSLength(X, Y, X.length(), Y.length(), lookup));
    }
}

```



References

[Longest Common Subsequence | Introduction & LCS Length - Techie Delight](https://www.techiedelight.com/longest-common-subsequence/)



### II. Other Problems



### References

[1] [Top 10 Dynamic programming problems for interviews - medium](https://medium.com/@codingfreak/top-10-dynamic-programming-problems-5da486eeb360)
[2] [What are the top 10 most popular dynamic programming problems among interviewers? - quora](https://www.quora.com/What-are-the-top-10-most-popular-dynamic-programming-problems-among-interviewers)
[3] [Top 20 Dynamic Programming Interview Questions](https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/)