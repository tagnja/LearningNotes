# Algorithms Common Questions

### Content

<h3 id="content"></h3>

- Data Structure
  - Common
    - [What is Data Structure](#wds)
    - [Abstract Data Type](#adt)
    - [Which Are Common Data Structures](#wcd)
  - List
    - Difference between Singly linked list and Doubly linked list
  - Stack
    - Get Output sequence by input in Stack.
  - Tree
    - [DFS/BFS of Tree](dbt)
    - Nodes and Levels.
  - Graph
    - What differences between Adjacency Matrix and Adjacency List
- Algorithms
  - [What is algorithm](#wia)
  - [Which Are Common Algorithms](#wca)
  - What are Common sorting algorithms
  - What are Common searching algorithms



### Main

### Data Structure

<h3 id="wds"># What is Data Structure</h3>
> Data structure is a data organization, management and storage format that enables efficient access and modification. 
> More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data
> --by Wikipedia

- A Data Structure is a way of organizing the data so that the data can be used efficiently. It contain data type and operation functions.

- A Data Structure is implementation of an Abstract Data Type.

**ADT(Abstract Data Type) vs DS (Data Structure)**

- ADT is a logical description, while a Data Structure is concrete.
- ADT as a  picture of the data and the operations. DS is the concrete thing, and it can be implemented and used within an algorithm.
- ADT is to an Interface (What it does). A Data Structure is to a class (how it does it). For Example ADT(List). and DS(ArrayList, LinkedList)

References:

[Data Structure - Wikipedia](https://en.wikipedia.org/wiki/Data_structure)

[back to content](#content)

---

<h3 id="adt"># Abstract Data Type</h3>
Abstract Data type (ADT) is a type (or class) for objects whose behavior is defined by a set of value and a set of operations.

**List ADT**

A list contains elements of same type arranged in sequential order and following operations can be performed on the list.

get() – Return an element from the list at any given position.

insert() – Insert an element at any position of the list.

remove() – Remove the first occurrence of any element from a non-empty list.

removeAt() – Remove the element at a specified location from a non-empty list.

replace() – Replace an element at any position by another element.

size() – Return the number of elements in the list.

isEmpty() – Return true if the list is empty, otherwise return false.

isFull() – Return true if the list is full, otherwise return false.

**Stack ADT**

A Stack contains elements of same type arranged in sequential order. All operations takes place at a single end that is top of the stack and following operations can be performed:

push() – Insert an element at one end of the stack called top.

pop() – Remove and return the element at the top of the stack, if it is not empty.

peek() – Return the element at the top of the stack without removing it, if the stack is not empty.

size() – Return the number of elements in the stack.

isEmpty() – Return true if the stack is empty, otherwise return false.

isFull() – Return true if the stack is full, otherwise return false.

**Queue ADT**

A Queue contains elements of same type arranged in sequential order. Operations takes place at both ends, insertion is done at end and deletion is done at front. Following operations can be performed:

enqueue() – Insert an element at the end of the queue.

dequeue() – Remove and return the first element of queue, if the queue is not empty.

peek() – Return the element of the queue without removing it, if the queue is not empty.

size() – Return the number of elements in the queue.

isEmpty() – Return true if the queue is empty, otherwise return false.

isFull() – Return true if the queue is full, otherwise return false.

From these definitions, we can clearly see that the definitions do not specify how these ADTs will be represented and how the operations will be carried out. There can be different ways to implement an ADT, for example, the List ADT can be implemented using arrays, or singly linked list or doubly linked list. Similarly, stack ADT and Queue ADT can be implemented using arrays or linked lists.

**Tree ADT**

traverseBFS()

traversePreorder()

tracvrseInorder()

traversePostorder()

**Graph ADT**

traverseBFS()

traverseDFS()



References:

[Abstract Data Types - GeeksforGeeks](https://www.geeksforgeeks.org/abstract-data-types/)

[back to content](#content)

---

<h3 id="wcd"># Which are Common Data Structures</h3>
- Array
- Stack
- Queue
- Binary Tree
- Trie
- Hash Table
- Graph

**Array**

Description:

- Array is a linear data structure consisting of a collection of *elements* each identified by *array index.*

Applications:

- Sorting elements
- Matrix operation
- CPU scheduling

**Stack**

Description:

- Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be *LIFO(Last In First Out).* Insertion in a stack is called *PUSH* while deletion from stack is called *POP*.

Applications:

- Expression evaluation
- Syntax parsing.
- Recursion.
- algorithms like [Tower of Hanoi](http://www.geeksforgeeks.org/recursive-functions/),  DFS

**Queue**

Description:

- Queue is a linear structure which follows a particular order in which the operations are performed. The order is *FIFO(First In First Out).* Insertion in a stack is called *Enqueue* while deletion from stack is called *Dequeue*.

Applications:

- it is used when a resource is shared among multiple consumers like in CPU scheduling, Disk Scheduling.

**Binary Tree**

Description:

- Binary Tree is a [tree](https://en.wikipedia.org/wiki/Tree_structure) [data structure](https://en.wikipedia.org/wiki/Data_structure) in which each node has at most two children, which are referred to as the *left child* and the *right child.*

Applications:

- [Binary Tree](https://en.wikipedia.org/wiki/Binary_tree) applications are Binary Search Tree, Heaps, Binary Tries etc.

**Binary Search Tree**

Description:

- Binary Search Tree is a binary tree where the value of each node is greater than or equal to the value of left subtree & the value of each node is less than or equal to the value of right subtree.

Applications:

- [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree) is used to implement multilevel indexing in database. 
- It is also used in Huffman Coding Algorithm & to implement searching Algorithm.

**Heap**

Description:

- Heap is a specialised tree data structure that satisfies the following property*:* *if P is a parent node of C, then the value of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the value of C.*

Applications:

- [Heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) is used in [Heapsort](https://en.wikipedia.org/wiki/Heapsort)
- Dynamic memory allocation in lisp

**Tire**

Description:

- Trie is an ordered tree data structure that is used to store a dynamic set or associative array where the keys are usually strings.

Applications:

- [Trie](https://en.wikipedia.org/wiki/Trie) is used as dictionary, such as one found on a mobile telephone for autocompletion and spell-checking. 
- Trie is also used in [Aho–Corasick algorithm](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm) & in [KMP algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)

**Hash Table**

Description:

- Hash Table is a data structure that is used to store keys/value pairs. It uses a *hash* function to compute an index into an array in which an element will be inserted or searched.

Applications:

- [Hash Table](https://en.wikipedia.org/wiki/Hash_table) is used for fast data lookup - symbol table for compilers, database indexing, caches,Unique data representation.

**Graph**

Description:

- Graph is a data structure that consists a finite set of vertices called as *Nodes* & a finite set of ordered pair called as *Edge*. Graph can be *Directed* or *Undirected*.

Applications:

- [Graphs](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)) are used to represent networks. Graphs are also used in social networks like linkedIn, facebook. For example, in facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender and locale. 
- They are also used in *Routing Algorithms*.

**Applications of binary trees**

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

References:

[What are the applications of data structures? - Quora](https://www.quora.com/What-are-the-applications-of-data-structures)

[What are the applications of binary trees? - StackOverflow](https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees)

[back to content](#content)

---

### Tree

<h3 id="dbt"># DFS/BFS of Tree</h3>
Binary  Tree Example:

```
        1
     2      3
   4   5   6

Print Result:

DFS
preorderTraverse: 1 2 4 5 3 6
inorderTraverse: 4 2 5 1 6 3 
postorderTraverse: 4 5 2 6 3 1

BFS
levelTraverse: 1 2 3 4 5 6
```



[back to content](#content)

---

### Algorithm

<h3 id="wia"># What is algorithm</h3>
> an algorithm is an unambiguous specification of how to solve a class of problem
> --by Wikipedia

Algorithms is the step to solve the question.

**Algorithm Basic Features**

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

[back to content](#content)

---

<h3 id="wca"># Which Are Common Algorithms</h3>
Common Algorithms

- Sorting
- Searching
- DFS/BFS of Graph
- Linked List
- String / Array
- Number Theory
- BIT Manipulation

Algorithms Paradigms

- Dynamic Programming
- Greedy Algorithm
- Divide and Conquer
- Backtracking
- Branch and Bound

References

[Top 10 algorithms in Interview Questions - GeeksforGeeks](https://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/)

[back to content](#content)

---