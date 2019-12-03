Content

Data Structures

- Array List
- String
- Stack & Queue
- Linked List & Binary Tree
- Graph

Algorithms

- Number & Binary
- Sort & Search
- Dynamic Programming
- Backtracking
- Divide and Conquer
- Greedy Algorithm

## Data Structures

### Array List

#### 题3：数组中的重复的数字

- 解法一：简单法。将数组排序后，前后对比即可。T(n) = O(nlogn), S(n) = O(1)
- 解法二：哈希表法。如果数组中的数字的取值范围是已知的，可以利用一个标记数组来记录源数组中数字出现的次数，将元素的值映射到数组的下标。T(n) = O(n), S(n) = O(n)
- 解法三：将数值为 i 的元素放到第 i 个位置中。从头到尾扫描，如果当前元素的数值 i 为当前遍历的下标不相等则，当前下标元素与下标为 i 的元素交换；如果数值与下标相等，则遍历下一个元素。直到找到要交换的元素与被交换的元素相等为止。T(n) = O(n), S(n) = O(1)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/03_01_DuplicationInArray/FindDuplication.cpp)

#### 题4：二维数组中的查找

二维数组从左到右、从上到下递增的顺序。判断数组中是否包含一个整数。

- 解法一：简单法。遍历每个元素，判断数组中是否包含目标数字。（但没有利用到递增排序的特点）。T(n) = O(n), S(n) = O(1)
- 解法二：每次排除一行或一列。每次去右上角的元素，如果该数字目标数字，则查找结束；如果该数字大于目标数字，剔除这个数字所在的列；如果该数字小于要目标数字，则剔除这个是最所在的行。T(n) = O(n), S(n) = O(1)。 [code]( https://github.com/zhedahht/CodingInterviewChinese2/blob/master/04_FindInPartiallySortedMatrix/FindInPartiallySortedMatrix.cpp )



### String

#### 题5：替换空格

把字符串中的空格替换成“%20”。

- 解法一：从前往后遍历，遇到一个空格插入 “%20”，并且当前位置后面的所有的元素移动两个位置。T(n) = O(n^2), S(n) = O(n)
- 解法二：先算出空格的数量，然后增加字符串的大小，记录最后一个元素的指针和最后一个空位的指针，从最后一个元素开始往后移动，遇到空格插入 “%20”。T(n) = O(n), S(n) = O(n)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/05_ReplaceSpaces/ReplaceSpaces.cpp)



### Stack & Queue

#### 题9：用两个栈实现队列

分别完成在队列尾部插入和在头部删除的功能。

- 解法一：两个栈两次顺序反转之后刚好时队列的顺序。每个元素都要经历两次入栈和一次出栈。具体操作是：（1）入栈操作，把元素压入 stack1 即可。（2）出栈操作，若 stack2 中有元素，把 stack2 栈顶元素弹出即可；若 stack2 为空，将 stack1 的元素压入 stack2 中，再执行弹出；若两个栈都为空，则弹出空。T(n) = O(1), S(n) = O(1) [code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/09_QueueWithTwoStacks/QueueWithTwoStacks.cpp)

相关题目：用两个队列实现一个栈

- 解法一：为了满足后进先出，移除队尾前面的所有元素，然后弹出队尾元素，即为后进先出。具体操作是：（1）入队操作，把元素插入不为空的队列尾部。两个队列必定一个为空一个不为空。（2）出队操作，把不为空的队列的尾部元素之前的元素移到另一个队列，把队尾元素弹出。



### Linked List & Binary Tree

#### 题6：从尾到头打印链表

- 解法一：用栈来实现反向打印。T(n) = O(n), S(n) = O(n)。 [code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/06_PrintListInReversedOrder/PrintListInReversedOrder.cpp)
- 解法二：类似栈实现的方式，用递归来实现。T(n) = O(n), S(n) = O(1) 

注意：递归的方式看气来更简洁，但是，当链表非常长时，递归可能会导致函数调用栈溢出。用栈实现的代码鲁棒性更好，但需要额外的内存消耗。

#### 题7：重建二叉树

输入某个二叉树的前序遍历和中序遍历的结果，请重建该二叉树。

- 解法一：由前序遍历的第一元素直到根节点，根据中序遍历知道左子树和右子树。用递归的方式依次找到所有的子树的根节点，并建立根节点与左右子树的指针。 [code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/07_ConstructBinaryTree/ConstructBinaryTree.cpp)

#### 题8：二叉树的下一个节点

给定一个二叉树的节点，找出中序遍历序列的下一个节点。树中右指向左右子节点的指针，还有指向父节点的指针。

- 解法一：分类处理。（1）如果一个节点有右子树，那么它的下一个节点是它的右子树的最左节点。（2）如果一个节点没有右子树，该节点是它父节点的左子节点，那么它的下一个节点就是它的父节点。（3）如果一个节点没有右子树，且它是它的父节点的右子节点。一直向上遍历，直到找到一个是它父节点的左子节点的节点。如果这样的节点存在，那么这个节点的父节点就是我们要找的下一个节点。T(n) = O(n), S(n) = O(1)。 [code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/08_NextNodeInBinaryTrees/NextNodeInBinaryTrees.cpp)

二叉树的下一个节点情况比较复杂。需要分析归类清晰。

### Graph





## Algorithms



### Number & Binary

#### 题15：二进制中的1的个数





### Sort & Search

#### 题11：旋转数组的最小数字

把一个数组最开始的若干个元素移动到数组的末尾，称之为数组的旋转。题为输入一个递增排序的数组的一个旋转，输入旋转数组中的最小元素。

- 解法一：使用二分查找处理。（1）特例：若第一个元素是数组中最小元素，第一个数字小于最后一个数字，则直接返回第一个元素。（2）旋转之后的数组可以划分为两个排序的子数组，前面子数组的元素都大于或等于后面子数组的元素。可以使用二分查找缩小范围，找到中间那个最小的元素。使用两个指针，第一个指针 P1 指向前面子数组的元素，第二指针 P2 指向后面子数组的元素，刚开始 P1 指向第一个元素，P2 指向最后一个元素，如果 P1 和 P2 中间的元素大于 P1 则，P1 指向中间的元素，小于P1则 P2 指向中间的元素。通过不断缩短范围，最后 P1 指向前面子数组的最大的元素，P2 指向后面子数组最小的元素。最后结果返回 P2 指向的元素即可。（3）若步骤二出现特例情况，即当中间元素等于 P1 也等于 P2 时，不知道该如何缩小范围，我们则采用顺序查找，从 P1 位置到 P2 位置顺序查找，找到它们之间的最小值。T(n) = O(nlogn), S(n) = O(1)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/11_MinNumberInRotatedArray/MinNumberInRotatedArray.cpp)



### Dynamic Programming & Greedy Algorithm

#### 题10：斐波那契数列

求斐波那契数列的第n项。

- 解法一：根据斐波那契的函数，写出简单的递归。T(n) = O(n^2), S(n)=O(1)
- 解法二：利用动态规划自底向上的方法。它去除了递归中的重复计算。T(n) = O(n), S(n) = O(1)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/10_Fibonacci/Fibonacci.cpp)

#### 题14：减绳子

一根长度为 n 的绳子，把绳子剪成 m 段（m、n都是整数，n>1，m>1），每段绳子最小长度为1，求所有绳子段长度可能的最大乘积是多少。当长度为8时，最大的乘积为 18 = 2\*3\*3.

- 解法一：动态规划。由等式 `f(n)=max(f(i) * f(n-i))`，手动算出 f(0) = 0, f(1)=1,f(2)=2, f(3) = 3，然后自定向上求解所有的 f(i)。最后返回 f(n)。T(n) = O(n), S(n) = O(1)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/14_CuttingRope/CuttingRope.cpp)
- 解法二：贪婪算法。当 n>=5 时，尽可能多剪长度为3的绳子段，当剩下的绳子长度为4时，把绳子剪成长度为2的绳子段。 [code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/14_CuttingRope/CuttingRope.cpp)



### Backtracking

经典问题：

- N-Queen: O(n!)
- Graph Coloring: O(nm^n)
- Hamilton Cycle: O(N!)
- WordBreak and StringSegment: O(2^N)
- Subset Sum: O(nW)

#### 题12：矩阵中的路径

判断一个矩阵中的字符是否存在一条包含字符串所有字符的路径。每一步可以上下左右移动一格，每个格子只能走一次。

- 解法一：典型的回溯问题。（1）任意一个格子作为起点。（2）如果路径上的第 i 个字符不是字符串中的第 i 个字符则回溯到上一个位置。（3）如果路径上的第 i 个字符时字符串中的第 i 个字符则寻找路径上的第 i+1 个字符。（4）重复第二步和第三步过程，直到路径上的所有字符都在矩阵上找到响应的位置。T(n) = O(3^n), S(n) = O(1)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/12_StringPathInMatrix/StringPathInMatrix.cpp)

#### 题13：机器人的运动范围

有一个m行n列的方格。一个机器人从坐标(0, 0) 的格子开始移动，每次可以向上下左右移动一格，但不能进入坐标的数位之和大于 k 的格子。如 k = 18时，机器人可以进入方格 (35, 37)，因为 3+5+3+7=18 <= k，求机器人一共能够达到多少个格子。

- 解法一：类似回溯的题目，但没有回溯，只是递归求解。递归判断下一个方格是否能进入，若能则结果加1。T(n) = O(3^(mn)), S(n) = O(1)。[code](https://github.com/zhedahht/CodingInterviewChinese2/blob/master/13_RobotMove/RobotMove.cpp) 



### Divide and Conquer 



## Summary

习惯性思维

- Data Structures Thinking Habits
  - Reverse Sequence 要想到 Stack or Recursion
  - Graph 要想到 DFS or BFS
- Algorithms Thinking Habits
  - Path in matrix 要想到 backtracking
  - Sorted List 要想到 Binary Search

注意事项

- 递归可能导致函数调用栈溢出。
- 算术表达式的数值可能溢出，集合下标的是否超过范围，链表的指针是否是空指针。

## References

[1] 剑指Offer 第二版 by 何海涛

[2] [剑指Offer 第二版源代码](https://github.com/zhedahht/CodingInterviewChinese2)