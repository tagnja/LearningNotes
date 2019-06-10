# Data Structure & Algorithms Notes



<h3 id="content">Content</h3>

- Data Structure
  - [Efficiency and Application](#effi)
- Algorithms Paradigms
  - [Greedy Algorithm](#gam)
  - [Dynamic Programming](#dpg)
  - [Backtracking](#btg)
  - [Divide and Conquer](#bac)
- Searching Algorithms 
  - [Binary Search](#bsh)
- Sorting Algorithms 
- Graph Algorithms
  - [DFS and BFS](#dab)

### Main

### Data Structure

<h3 id="effi"># Efficiency and Application</h3>

Random Access

- Array List, T(n) = O(1)

Insert and Remove: 

- Linked List, T(n) = O(1)

Search

- Hash Table, T(n) = O(1)
- Binary Search Tree, T(n) = O(log n)

FIFO

- Queue

LIFO

- Stack

### Algorithms Paradigms



<h3 id="gam"># Greedy Algorithm</h3>



- Find a greedy principle.



[back to content](#content)



----



<h3 id="dpg"># Dynamic Programming</h3>



**Process**



- How to judge a problem is a DP problem
  - 能够转换为若干个更小规模的子问题 T(n) = m * ( O(n-x)+y )。
  - 有大量重复的子问题。

- Deciding the State
  - 能决定问题的参数。如背包问题的（石头个数，石头重量）

- Formulating a Relation Among the States

- Adding Memoization or Tabulation for the State



**Feature Classify**



(1) 最优解问题。从小规模的最优解中得到大规模的最优解。

- 问题的规模就是问题的n
- 判断元素n是否有效
  - 无效的话OPT(n)=OPT(n-1)
  - 有效的话OPT(n) <- OPT(n-1)<-OPT(i)。

>  如，最长递增子序列OPT(n)<-OPT(i)， 最小花费路劲问题OPT(n) <- OPT(n-1)。



(2) 递推关系问题。

- 问题的规模就是问题的n。
- 可以看出明显的递推关系。T(n) = a\*T(n-x) + b\*T(n-y)+...直接根据公式递推求解，再去除重复子结果。

> 如斐波那契数 T(n) = T(n-2) + T(n-1)



(3) 组合问题。多少种可能问题。

- 构造出问题的n。
- 从规模n去推算，它由几种n-1规模问题组成。

> 如3个数有多少种可能通过加法得到指定一个数。



(4)可能性问题。能不能成立问题。

- 问题的规模就是问题的n。
- 判断元素n是否有效
  - 无效的话，这个数就忽略。
  - 有效的话，这个元素就是组成答案的一个关键因素。

> 如数组N是否是数组的子集和



View -> [Classic DP Questions Analysis](classic-questions/dp-questions-analysis.md)



**Summary**

- 动态规划问题特征总结
  - 问题规模 1, 2, 3 .. n 是独立的子问题。1）问题规模 n 与问题规模 n-1 之间有递推关系，可以通过问题规模 n-1 的解求规模 n 的解。如 。。2）n 与 n-1 之间没关联，但子问题独立，每个规模有自己的规则，最后合并所有子问题的解可以得到规模 n 的最终解。如。。
- **动态规划问题，核心的思路就是，找到一种递归求解的方法，然后通过减少重复子问题优化算法。**
- (1)有的动态规划问题，他的规模缩减比较明显，关系简单，如Fibonacci斐波那契数，Min-Cost-Path表格最小花费路径等。 (2)有的问题能看出缩减关系，但是缩减的关系很复杂。如COINS-Bytelandian-glod-coins金币换美元等。 (3)有的问题则看不出缩减关系，甚至不知道它是不是动态规划问题，如ACODE数字解码字母，Longest-Increase-Sequence最长递增子序列等。(4) 确实需要靠一点直觉，接触多了就有感觉。
- 找到一种递归求解的方法，通过减少重复子问题来优化递归方法。
- 当问题规模为n时有最优解，n-1时也有自己的最优解，隔离问题规模 。在试图用递归来找到从小规模最优解来得到大规模最优解。



[back to content](#content)



----



<h3 id="btg">Backtracking</h3>



**Classic Questions**

- N queens problem
- Knight's Tour Problem
- Flight itinerary problem

[back to content](#content)



----



<h3 id="bac">Divide and Conquer</h3>

`

[back to content](#content)



----






# Top 10 Dynamic programming problems for interviews

Below are the top 10 popular problems that can easily be solved using Dynamic programming and commonly asked in technical interviews –

1. [Longest Common Subsequence](https://www.techiedelight.com/longest-common-subsequence/)
2. [Shortest Common Supersequence](https://www.techiedelight.com/shortest-common-supersequence-introduction-scs-length/)
3. [Longest Increasing Subsequence problem](https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/)
4. [The Levenshtein distance (Edit distance) problem](https://www.techiedelight.com/levenshtein-distance-edit-distance-problem/)
5. [Matrix Chain Multiplication](https://www.techiedelight.com/matrix-chain-multiplication/)
6. [0–1 Knapsack problem](https://www.techiedelight.com/0-1-knapsack-problem/)
7. [Partition problem](https://www.techiedelight.com/partition-problem/)
8. [Rod Cutting](https://www.techiedelight.com/rot-cutting/)
9. [Coin change problem](https://www.techiedelight.com/coin-change-making-problem-unlimited-supply-coins/)
10. [Word Break Problem](https://www.techiedelight.com/word-break-problem/)

**Longest Increase sequence**

- 借助 “当前元素最大子序列长度数组” 进行标识，数组都初始化为1
- 第n个元素与前n-1个元素，比较大小，以及比较当前最大子序列长度。如果a[n]比任意的a[i] (0 < i < n) 大，且a[i] 的 LIS值+1 大于a[n] 的历史记录的LIS值，a[n] 的LIS值=a[i] 的 LIS值+1 。遍历从第二个元素开始，遍历n-1次。

常见问题

- 求最大递减、递增子序列的长度？
- 打印最大子序列长度？
- 最少有几组子序列？

Implementation1

T(n)=?

```java
	static int max_ref = 1;
	static int solution(int arr[], int n)
	{
		if (n == 1)
		{
			return 1;
		}
		int res, max_temp = 1;
		for (int i = 1; i < n; i++)
		{
			res = solution(arr, i);
			if (arr[i-1] >= arr[n-1] && res + 1 > max_temp)
			{
				max_temp = res + 1;
			}
		}
		
		if (max_temp > max_ref)
		{
			max_ref = max_temp;
		}
		
		return max_temp;
	}
```

Implementation2

T(n) = O(n^2)

```java
	static int solution(int arr[], int n)
	{
		int LIS[] = new int[n];
		int max_ref = 0, i, j;
		for (i = 0; i < n; i++)
		{
			LIS[i] = 1;
		}
		
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < i; j ++)
			{
				if (arr[i] >= arr[j] && LIS[j] + 1 > LIS[i])
				{
					LIS[i] = LIS[j] + 1;
				}
			}
			if (LIS[i] > max_ref)
			{
				max_ref = LIS[i];
			}
		}
		return max_ref;
	}
```



[back to content](#content)

----

### Searching Algorithms


<h3 id="bsh"># Binary Searching</h3>



[back to content](#content)

----

### Graph Algorithms

<h3 id="dab"># DFS and BFS</h3>



[back to content](#content)

----


可参考类似题型：

 

贪心
<http://codevs.cn/problem/1098/>
<http://codevs.cn/problem/1214/>

动态规划(DP)
<http://codevs.cn/problem/1044/>
<http://codevs.cn/problem/1166/>
<http://codevs.cn/problem/1039/>

DFS/BFS，尤其是图的DFS，BFS遍历
<http://codevs.cn/problem/1004/>
<http://codevs.cn/problem/1018/>
<http://poj.org/problem?id=2251>

二分查找
<http://poj.org/problem?id=3579>