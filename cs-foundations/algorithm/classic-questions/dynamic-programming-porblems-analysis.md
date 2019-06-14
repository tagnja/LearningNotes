# Dynamic Programming Problems Analysis

<h3 id="content">Content</h3>

- [Introduction](#intr)
- I. Classic Problems
  - [x] [Longest Common Subsequence (LCS)](#lcs)
  - [Shortest Common Supersequence](#scsu)
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

### Before Start

**Convention**

- Description
- Solutions
- References

**Problem Class Summary**

- using assisted mark array tab

  > Longest Increase Sequence

**Solution Methods**

- Top-down approach (Memoization): recursion and memorized.

  > 1\. Sub-problem result store to Array, or sub-problem index value to map). If this sub-problem exist in memorized container, bypass it and don't calculate it.
  >
  > 2\. The memorized container can be global variable or parameter of function. Variable can using Map or Array. Map memorized multiple composed key, Array memorized single key.

- Bottom-up approach  (Tabulation): for iterator and relational calculate. 

  > Iterate Impose sub-problem result to calculate bigger scale sub-problem.

<h3 id="intr">Introduction</h3>

#### Dynamic Programming

**Dynamic programming** is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions using a memory-based data structure (array, map,etc). Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup. So the next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time. This technique of storing solutions to subproblems instead of recomputing them is called **memoization**.

There are two key attributes that a problem must have in order for dynamic programming to be applicable: 

- optimal substructure

- overlapping sub-problems.

##### Optimal substructure

Dynamic programming simplify a complicated problem by breaking it down into simpler sub-problems in a recursive manner. A problem that can be solved optimally by breaking it into sub-problems and then recursively finding the optimal solutions to the sub-problems is said to have optimal substructure. In other words, solution to a given optimization problem can be obtained by the combination of optimal solutions to its sub-problems.

##### Overlapping sub-problems

A problem is said to have **overlapping subproblems** if the problem can be broken down into subproblems which are reused several times or a recursive algorithm for the problem solves the same subproblem over and over rather than always generating new subproblems.

**Top-down approach (Memoization):** This is the direct fall-out of the recursive formulation of any problem. If the solution to any problem can be formulated recursively using the solution to its sub-problems, and if its sub-problems are overlapping, then one can easily memoize or store the solutions to the sub-problems in a table. Whenever we attempt to solve a new sub-problem, we first check the table to see if it is already solved. If the sub-problem is already solved, we can use it’s solution directly, otherwise we solve the sub-problem and add its solution to the table.

**Bottom-up approach (Tabulation):** Once we formulate the solution to a problem recursively as in terms of its sub-problems, we can try reformulating the problem in a bottom-up fashion: try solving the sub-problems first and use their solutions to build-on and arrive at solutions to bigger sub-problems. This is also usually done in a tabular form by iteratively generating solutions to bigger and bigger sub-problems by using the solutions to small sub-problems. For example, if we already know the values of *F*(*i* – 1) and *F*(*i* – 2), we can directly calculate the value of *F*(*i*).

If a problem can be solved by combining optimal solutions to non-overlapping sub-problems, the strategy is called “divide and conquer” instead. This is why merge sort and quick sort are not classified as dynamic programming problems.

#### Example of Fibonacci

A Native Implementation, T(n) = O(2^n)

```
// Function to find n'th Fibonacci number
int fib(int n)
{
    if (n <= 1)
        return n;
 
    return fib(n - 1) + fib(n - 2);
}
```

Top-down Approach, T(n) = O(n)

```java
import java.util.HashMap;
import java.util.Map;
 
class Main
{
    // Function to find nth Fibonacci number
    public static int fib(int n, Map<Integer, Integer> lookup)
    {
        if (n <= 1) {
            return n;
        }
 
        // if sub-problem is seen for the first time
        if (!lookup.containsKey(n)) {
            int val = fib(n - 1, lookup) + fib(n - 2, lookup);
            lookup.put(n, val);
        }
 
        return lookup.get(n);
    }
 
    public static void main(String[] args)
    {
        int n = 8;
        Map<Integer, Integer> lookup = new HashMap<>();
 
        System.out.println(fib(n, lookup));
 
    }
}
```

Bottom-up Approach, T(n) = O(n)

```java
class Main
{
    // Function to find n'th fibonacci number
    public static int fib(int n)
    {
        if (n <= 1) {
            return n;
        }
 
        int previousFib = 0, currentFib = 1;
        for (int i = 0; i < n - 1; i++) {
            int newFib = previousFib + currentFib;
            previousFib = currentFib;
            currentFib = newFib;
        }
 
        return currentFib;
    }
 
    public static void main(String[] args)
    {
        System.out.print(fib(8));
    }
}
```



References

[Introduction to Dynamic Programming](https://www.techiedelight.com/introduction-dynamic-programming/?v=1#optimal-substructure)

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

The LCS problem has an [optimal substructure](https://www.techiedelight.com/introduction-dynamic-programming/?v=1#optimal-substructure). That means the problem can be broken down into smaller, simple “subproblems”, which can be broken down into yet simpler subproblems, and so on, until, finally, the solution becomes trivial.

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

```
                      (n, m)

       (n-1, m)                     (n, m-1)

(n-2, m)   *(n-1, m-1)        *(n-1, m-1)    (n, m-2)
```

Above \* is repeated sub-problems

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
// The length of LCS is 4
```

**Print Optimal Result**

(TODO)



References

[Longest Common Subsequence | Introduction & LCS Length - Techie Delight](https://www.techiedelight.com/longest-common-subsequence/)

[`back to content`](#content)

---



<h3 id="scsu">Shortest Common Supersequence</h3>



#### Description

The shortest common supersequence (SCS) is the problem of finding the shortest supersequence Z of given sequences X and Y such that both X & Y are subsequences of Z.

For example, consider the two following sequences X and Y

X: ABCBDAB
Y: BDCABA

The length of SCS is 9
SCS are ABCBDCABA, ABDCABDAB and ABDCBDABA



#### Solutions







References

[Shortest Common Supersequence | Introduction & SCS Length - Techie Delight](https://www.techiedelight.com/shortest-common-supersequence-introduction-scs-length/)

[`back to content`](#content)

---





### II. Other Problems



### References

[1] [Top 10 Dynamic programming problems for interviews - medium](https://medium.com/@codingfreak/top-10-dynamic-programming-problems-5da486eeb360)
[2] [What are the top 10 most popular dynamic programming problems among interviewers? - quora](https://www.quora.com/What-are-the-top-10-most-popular-dynamic-programming-problems-among-interviewers)
[3] [Top 20 Dynamic Programming Interview Questions](https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/)