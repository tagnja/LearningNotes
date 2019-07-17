# Note of Data Structure and Algorithms 

### Content

- Introduction to Data Structure
- Basic Data Structure 
  - Array
  - Linked List
  - Stack
  - Queue
  - Tree (Binary Tree)
  - Graph
- Advanced Data Structure 
  - Binary Search Tree, AVL Tree
  - B-Tree, Red–black Tree	
  - Heap
  - Trie
  - Dictionary
  - Hashing (Hash Table)
  - Priority Queue
  - String
  - Matrix
- Data Structures Contrast
- Introduction to Algorithms
- Algorithm Analysis
- Common Algorithms
  - Sort
  - Search
  - Bit Algorithms
  - Mathematical Algorithms
- Algorithm Paradigms
  - Dynamic programming
  - Divide and Conquer
  - Greedy
  - Backtracking
  - DFS/BFS
  - Randomized
  - Algorithms Paradigms Summary
- References

### Main

### Introduction to Data Structure

What is Data Structure?

> Data structure is a data organization, management and storage format that enables efficient access and modification. 
> More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data
> --by Wikipedia

- A Data Structure is a way of organizing the data so that the data can be used efficiently. It contain data type and operation functions.
- A Data Structure is implementation of an Abstract Data Type.\

ADT(Abstract Data Type) vs DS (Data Structure)

- ADT is a logical description, while a Data Structure is concrete.
- ADT as a  picture of the data and the operations. DS is the concrete thing, and it can be implemented and used within an algorithm.
- ADT is to an Interface (What it does). A Data Structure is to a class (how it does it). For Example ADT(List). and DS(ArrayList, LinkedList)
- Abstract Data type (ADT) is a type (or class) for objects whose behavior is defined by a set of value and a set of operations.
- From these definitions, we can clearly see that the definitions do not specify how these ADTs will be represented and how the operations will be carried out. There can be different ways to implement an ADT, for example, the List ADT can be implemented using arrays, or singly linked list or doubly linked list. Similarly, stack ADT and Queue ADT can be implemented using arrays or linked lists.

References:

[Data Structure - Wikipedia](https://en.wikipedia.org/wiki/Data_structure)

[back to content](#content)

---



### Basic Data Structure 

### Array

Description:

- Array is a linear data structure consisting of a collection of *elements* each identified by array index.



List ADT

A list contains elements of same type arranged in sequential order and following operations can be performed on the list.

get() – Return an element from the list at any given position.

insert() – Insert an element at any position of the list.

remove() – Remove the first occurrence of any element from a non-empty list.

removeAt() – Remove the element at a specified location from a non-empty list.

replace() – Replace an element at any position by another element.

size() – Return the number of elements in the list.

isEmpty() – Return true if the list is empty, otherwise return false.

isFull() – Return true if the list is full, otherwise return false.



Applications:

- Sorting elements
- Matrix operation
- CPU scheduling

### Stack 

Description:

- Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be *LIFO(Last In First Out).* Insertion in a stack is called *PUSH* while deletion from stack is called *POP*.

Stack ADT

A Stack contains elements of same type arranged in sequential order. All operations takes place at a single end that is top of the stack and following operations can be performed:

push() – Insert an element at one end of the stack called top.

pop() – Remove and return the element at the top of the stack, if it is not empty.

peek() – Return the element at the top of the stack without removing it, if the stack is not empty.

size() – Return the number of elements in the stack.

isEmpty() – Return true if the stack is empty, otherwise return false.

isFull() – Return true if the stack is full, otherwise return false.

Applications:

- Expression evaluation
- Syntax parsing.
- Recursion.
- algorithms like [Tower of Hanoi](http://www.geeksforgeeks.org/recursive-functions/),  DFS

### Queue

Description:

- Queue is a linear structure which follows a particular order in which the operations are performed. The order is *FIFO(First In First Out).* Insertion in a stack is called *Enqueue* while deletion from stack is called *Dequeue*.

Queue ADT

A Queue contains elements of same type arranged in sequential order. Operations takes place at both ends, insertion is done at end and deletion is done at front. Following operations can be performed:

enqueue() – Insert an element at the end of the queue.

dequeue() – Remove and return the first element of queue, if the queue is not empty.

peek() – Return the element of the queue without removing it, if the queue is not empty.

size() – Return the number of elements in the queue.

isEmpty() – Return true if the queue is empty, otherwise return false.

isFull() – Return true if the queue is full, otherwise return false.

Applications:

- it is used when a resource is shared among multiple consumers like in CPU scheduling, Disk Scheduling.

### Tree

Tree ADT

traverseBFS()

traversePreorder()

tracvrseInorder()

traversePostorder()

Binary Tree

Description:

- Binary Tree is a [tree](https://en.wikipedia.org/wiki/Tree_structure) [data structure](https://en.wikipedia.org/wiki/Data_structure) in which each node has at most two children, which are referred to as the *left child* and the *right child.*

Applications:

- [Binary Tree](https://en.wikipedia.org/wiki/Binary_tree) applications are Binary Search Tree, Heaps, Binary Tries etc.

Applications of binary trees

- [Binary Search Tree](http://en.wikipedia.org/wiki/Binary_search_tree) - Used in *many* search applications where data is constantly entering/leaving, such as the `map` and `set` objects in many languages' libraries.
- [Binary Space Partition](http://en.wikipedia.org/wiki/Binary_space_partitioning) - Used in almost every 3D video game to determine what objects need to be rendered.
- [Binary Tries](http://en.wikipedia.org/wiki/Radix_tree) - Used in almost every high-bandwidth router for storing router-tables.
- [Hash Trees](http://en.wikipedia.org/wiki/Hash_tree) - used in p2p programs and specialized image-signatures in which a hash needs to be verified, but the whole file is not available.
- [Heaps](http://en.wikipedia.org/wiki/Heap_(data_structure)) - Used in implementing efficient priority-queues, which in turn are used for scheduling processes in many operating systems, Quality-of-Service in routers, and A* *(path-finding algorithm used in AI applications, including robotics and video games)*. Also used in heap-sort.
- [Huffman Coding Tree](http://en.wikipedia.org/wiki/Huffman_coding) ([Chip Uni](https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees/2174096#2174096)) - used in compression algorithms, such as those used by the .jpeg and .mp3 file-formats.
- [GGM Trees](http://www.wisdom.weizmann.ac.il/~/oded/ggm.html) - Used in cryptographic applications to generate a tree of pseudo-random numbers.
- [Syntax Tree](http://en.wikipedia.org/wiki/Abstract_syntax_tree) - Constructed by compilers and (implicitly) calculators to parse expressions.
- [Treap](http://en.wikipedia.org/wiki/Treap) - Randomized data structure used in wireless networking and memory allocation.
- [T-tree](http://en.wikipedia.org/wiki/T-tree) - Though most databases use some form of B-tree to store data on the drive, databases which keep all (most) their data in memory often use T-trees to do so.

### Graph

Description:

- Graph is a data structure that consists a finite set of vertices called as *Nodes* & a finite set of ordered pair called as *Edge*. Graph can be *Directed* or *Undirected*.

Graph ADT

traverseBFS()

traverseDFS()

Applications:

- [Graphs](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)) are used to represent networks. Graphs are also used in social networks like linkedIn, facebook. For example, in facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender and locale. 
- They are also used in *Routing Algorithms*.

### Advanced Data Structure 

### Binary Search Tree

Description:

- Binary Search Tree is a binary tree where the value of each node is greater than or equal to the value of left subtree & the value of each node is less than or equal to the value of right subtree.

Applications:

- [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree) is used to implement multilevel indexing in database. 
- It is also used in Huffman Coding Algorithm & to implement searching Algorithm.

### Heap

Description:

- Heap is a specialised tree data structure that satisfies the following property*:* *if P is a parent node of C, then the value of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the value of C.*

Applications:

- [Heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) is used in [Heapsort](https://en.wikipedia.org/wiki/Heapsort)
- Dynamic memory allocation in lisp

### Tire

Description:

- Trie is an ordered tree data structure that is used to store a dynamic set or associative array where the keys are usually strings.

Applications:

- [Trie](https://en.wikipedia.org/wiki/Trie) is used as dictionary, such as one found on a mobile telephone for autocompletion and spell-checking. 
- Trie is also used in [Aho–Corasick algorithm](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm) & in [KMP algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)

### Hash Table

Description:

- Hash Table is a data structure that is used to store keys/value pairs. It uses a *hash* function to compute an index into an array in which an element will be inserted or searched.

Applications:

- [Hash Table](https://en.wikipedia.org/wiki/Hash_table) is used for fast data lookup - symbol table for compilers, database indexing, caches,Unique data representation.

### Data Structures Contrast

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

### Introduction to Algorithms

What is algorithm

> an algorithm is an unambiguous specification of how to solve a class of problem
> --by Wikipedia

Algorithms is the step to solve the question.

Algorithm Basic Features

- Finiteness(有穷性). The algorithm stops after a finite number of steps.
- Definiteness(确定性). Every statement of the algorithm should be clear and unambiguous. Same input get same output.
- Effectiveness(可行性). An algorithm can implement by basic exist algorithms.
- Input. An algorithm have zero or multiple input.
- Output. An algorithm have one or more output.

好的算法应考虑的目标：

- Correctness正确性
- Precision 可读性
- Robustness 健壮性
- Efficient 效率

### Algorithm Paradigms

### Dynamic Programming

Process

- How to judge a problem is a DP problem
  - 能够转换为若干个更小规模的子问题 T(n) = m * ( O(n-x)+y )。
  - 有大量重复的子问题。

- Deciding the State
  - 能决定问题的参数。如背包问题的（石头个数，石头重量）

- Formulating a Relation Among the States

- Adding Memoization or Tabulation for the State



Feature Classify

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



Summary

- 动态规划问题特征总结
  - 问题规模 1, 2, 3 .. n 是独立的子问题。1）问题规模 n 与问题规模 n-1 之间有递推关系，可以通过问题规模 n-1 的解求规模 n 的解。如 。。2）n 与 n-1 之间没关联，但子问题独立，每个规模有自己的规则，最后合并所有子问题的解可以得到规模 n 的最终解。如。。
- **动态规划问题，核心的思路就是，找到一种递归求解的方法，然后通过减少重复子问题优化算法。**
- (1)有的动态规划问题，他的规模缩减比较明显，关系简单，如Fibonacci斐波那契数，Min-Cost-Path表格最小花费路径等。 (2)有的问题能看出缩减关系，但是缩减的关系很复杂。如COINS-Bytelandian-glod-coins金币换美元等。 (3)有的问题则看不出缩减关系，甚至不知道它是不是动态规划问题，如ACODE数字解码字母，Longest-Increase-Sequence最长递增子序列等。(4) 确实需要靠一点直觉，接触多了就有感觉。
- 找到一种递归求解的方法，通过减少重复子问题来优化递归方法。
- 当问题规模为n时有最优解，n-1时也有自己的最优解，隔离问题规模 。在试图用递归来找到从小规模最优解来得到大规模最优解。

[back to content](#content)

----

### Greedy Algorithms

Find a greedy principle.



### References

[What are the applications of data structures? - Quora](https://www.quora.com/What-are-the-applications-of-data-structures)

[What are the applications of binary trees? - StackOverflow](https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees)

[Abstract Data Types - GeeksforGeeks](https://www.geeksforgeeks.org/abstract-data-types/)

