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

### Sort & Search

### Dynamic Programming

### Backtracking

### Divide and Conquer

### Greedy Algorithm

## Summary

习惯性思维

- Sorted List 要想到 Binary Search
- Reverse Sequence 要想到 Stack or Recursion

注意事项

- 递归可能导致函数调用栈溢出。
- 算术表达式的数值可能溢出，集合下标的是否超过范围，链表的指针是否是空指针。

## References

[1] 剑指Offer 第二版 by 何海涛

[2] [剑指Offer 第二版源代码](https://github.com/zhedahht/CodingInterviewChinese2)