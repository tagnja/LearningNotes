# Algorithms Common Questions

<h3 id="content">Content</h3>

- Data Structure
  - [What is Data Structure](#wds)
  - [Abstract Data Type](#adt)
  - [Which Are Common Data Structures](#wcd)
  - List
    - Difference between Singly linked list and Doubly linked list
  - Stack
    - Get Output sequence by input in Stack.
  - Tree
    - Nodes and Levels.
- Algorithms
  - [What is algorithm](#wia)
  - [Which Are Common Algorithms](#wca)



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


<h3 id="wcd"># Which Are Common Data Structures</h3>

- ArrayList
- LinkedList
- Stack
- Queue
- Binary Tree
- Graph



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