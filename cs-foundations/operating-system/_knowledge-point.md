# Knowledge of Operating System



<h3 id="content">Content</h3>

- Overview
  - [1. Introduction](#intr)
  - [2. Operating System Structure](#osst)
- Process Management
  - [3. Process](#proc)
  - [4. Threads](#thre)
  - [5. CPU Scheduling](#csch)
  - [6. Process Synchronization](#psyn)
  - [7. Deadlocks](#dead)
- Memory Management
  - [8. Main Memory](#mmem)
  - [9. Virtual Memory](#vmem)
- Storage Management
  - [10. File-System Interface](#fsin)
  - [11. File-System Implementation](#fsim)
  - [12. Mass-Storage Structure](#msst)
  - [13. I/O Systems](#iosy)
- Protection and Security
  - [14. Protection](#prot)
  - [15. Security](#secu)
- Distributed Systems
  - [16. Distributed System Structures](#dsst)
  - [17. Distributed File System](#dfsy)
  - [18. Distributed Coordination](#dcoo)
- \* *Special-Purpose Systems*
  - *Real-Time Systems*
  - *Multimedia Systems*



### Main



### I. Overview



<h3 id="intr">1. Introduction</h3>



<h3 id="osst">2. Operating System Structures</h3>



---



### II. Process Management



<h3 id="proc">3. Process</h3>

Basic Concept
- What is Process
- Process in Memory
- Process States
- Process Control Block
- What is Threads

Process Scheduling
- Scheduling Queues
- Schedulers
- Context Switch Algorithms

Operations Of Processes
- Process Creation
- Process Termination

Interprocess Communication
- Shared Memory
- Message Passing

Communication in System
- Sockets
- Remote Procedure Calls
- Remote Method Invocation

<h3 id="thre">4. Threads</h3>

Basic Concepts
- What is Thread. 
- Its Benefits

Multithreading Models
- Many-to-one
- one-to-one
- many-to-many
- two-level model

Thread Libraries
- POSIX PThreads
- Win 32
- Java

Thread Issues
- Creating sub Process
- Thread Cancellation
- Signal Handling
- Thread Pools
- Thread-special Data
- Scheduler Activation

Thread Implementation

- Implementation in Windows and Linux

<h3 id="csch">5. CPU Scheduling</h3>

<h3 id="psyn">6. Process Synchronization</h3>

<h3 id="dead">7. Deadlocks</h3>





---



### III. Memory Management



<h3 id="mmem">8. Main Memory</h3>

#### Background

Basic Hardware

Address Binding

Logical Versus Physical Address Space

Dynamic Loading

Dynamic Linking and Shared Libraries

#### Swapping

What is it?

Why is it?

How does it accomplish?

#### Contiguous Memory Allocation

Memory Mapping and Protection

Memory Allocation

Fragmentation

#### Paging 

What is it? (noncontiguous)

Basic Method of Accomplishment

Hardware Support

Protection

Shared Pages

#### Structure of the Page Table

Hierarchical Paging

Hashed Page Tables

Inverted Page Tables

#### Segmentation

Basic Method

Hardware

#### Example Memory Management

Pentium Segmentation

Pentium Paging

Linux on Pentium Systems

#### Summary



<h3 id="vmem">9. Virtual Memory</h3>

#### Background

What is it

Virtual Address Space

#### Demand Paging

Basic Concept

- memory resident
- page-fault trap

Performance of Demand Paging

- effective access time
- page fault rate

Others

- Implement demand paging major problems: a frame-allocation algorithm and a page-replacement algorithm.

#### Copy-on-Write

What is it? 

- rapid process creation.
- minimizes the number of new pages

#### Page Replacement

Basic Page Replacement

FIFO Page Replacement Algorithm

Optimal Page Replacement Algorithm

LRU Page Replacement Algorithm

LRU-Approximation page Replacement Algorithm

Counting-Based Page Replacement Algorithm

Page-Buffering Algorithms

Application and Page Replacement

#### Allocation of Frames

Minimum Number of Frames

Allocation Algorithms

Global versus Local Allocation

#### Thrashing

Cause of Thrashing

Working-Set Model

Page-Fault Frequency

#### Memory-Mapped Files



#### Allocating Kernel Memory

#### Other Considerations

#### Operating-System Example of Virtual Memory

#### Summary





-----









### IV. Storage Management

<h3 id="fsin">File-System Interface</h3>

<h3 id="fsim">File-System Implementation</h3>

<h3 id="msst">Mass-Storage Structure</h3>

<h3 id="iosy">I/O Systems</h3>



---



### V. Protection and Security

<h3 id="prot">Protection</h3>

<h3 id="secu">Security</h3>



---



### VI. Distributed Systems

<h3 id="dsst">Distributed System Structures</h3>

<h3 id="dfsy">Distributed File System</h3>

<h3 id="dcoo">Distributed Coordination</h3>



--END--