# Knowledge Details of Operating System 


<h3 id="content">Content</h3>

- I. Overview
  - [1. Introduction](#intr)
    - What Operating System Do ~
    - Computer-System Organization ~
    - Computer-System Architecture 
    - Operating-System Structure ~
    - Operating-System Operations ~
    - Resource Management
    - Protection and Security
    - Distributed Systems
    - Special-Purpose Systems
    - Computing Environments ~
  - [2. Operating System Structure](#osst)
    - Operating-System Services ~
    - User Operating-System Interface
    - System Calls ~
    - Types of System Calls
    - System Programs
    - Operating-System Design and Implementation
    - Operating-System Structure
    - Virtual Machines
    - Operating-System Generation
    - System Boot
- II. Process Management
  - [3. Process](#proc)
    - Basic Concept
    - Process Scheduling
    - Operations Of Processes
    - Interprocess Communication
    - Communication in System
  - [4. Threads](#thre)
    - Basic Concepts
    - Multithreading Models
    - Thread Libraries
    - Thread Issues
    - Operating System Examples 
  - [5. CPU Scheduling](#csch)
    - Basic Concepts
    - Scheduling Criteria
    - Scheduling Algorithms
    - Multiple-Processor Scheduling
    - Thread Scheduling
    - Operating System Examples
    - Algorithm Evaluation 
  - [6. Process Synchronization](#psyn)
    - Background
    - The Critical-Section Problem
    - Peterson's Solution
    - Synchronization Hardware
    - Semaphores
    - Classic Problems of Synchronizaiton
    - Monitors
    - Synchronization Examples
    - Atomic Transaction
  - [7. Deadlocks](#dead)
    - System Model
    - Deadlock Characterization
    - Methods for Handling Deadlocks
    - Deadlock Prevention
    - Deadlock Avoidance
    - Deadlock Detection
    - Recovery From Deadlock 
- III. Memory Management
  - [8. Main Memory](#mmem)
    - Background
    - Swapping
    - Contiguous Memory Allocation
    - Paging
    - Structure of the Page Table
    - Segmentation
    - Example Memory Management
  - [9. Virtual Memory](#vmem)
    - Background
    - Demand Paging
    - Copy-on-Write
    - Page Replacement
    - Allocation of Frames
    - Thrashing
    - Memory-Mapped Files
    - Allocating Kernel Memory
    - Other Considerations
    - Operating-System Example of Virtual Memory
- IV. Storage Management
  - [10. File-System Interface](#fsin)
    - File Concept
    - Access Methods
    - Directory Structure
    - File-System Mounting
    - File Sharing
    - Protection
  - [11. File-System Implementation](#fsim)
    - File-System Structure
    - File-System Implementation
    - Directory Implementation
    - Allocation Methods
    - Free-Space Management
    - Efficiency and Performance
    - Recovery
    - NFS (Network File System)
  - [12. Mass-Storage Structure](#msst)
    - Overview of Mass-Storage Structure
    - HDD Scheduling
    - NVM Scheduling
    - Error Detection and Correction
    - Storage Device management
    - Swap-Space Management
    - Storage Attachment
    - RAID Structure
  - [13. I/O Systems](#iosy)
    - Overview
    - I/O Hardware
    - Application I/O Interface
    - Kernel I/O Subsystem
    - Transforming I/O Requests to Hardware Operations
    - STRRAMS
    - Performance
- V. Protection and Security
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
> Computer System vs Operating System
>
> Computer System: Hardware and software perspective for computer. Mainly in hardware organization.
>
> Operating System: Hardware and software perspective for operating system. Mainly in operating system functions.

#### What Operating System Do ~

> Computer System divided component: hardware, operating system, application programs, users.



User View

- The user's view is  according to the interface. Like GUI, terminal.
- For a PC of single-user, the operating system is designed for ease of use. The goal is to maximize the work (or play). performance is important rather than resource utilization.
- For mainframe, It is designed to maximize resource utilization.
- For workstation, it is designed to compromise between individual usability and resource utilization.



System View

- An operating system as a resource allocator. Managing CPU time, memory space, file-storage space, I/O device, and so on.
- How to allocate resource efficiently and fairly to specific programs and users
- A slightly view of an operating system is a control program. It manages the execution of user programs to prevent errors and improper use of the computer.



Defining Operating Systems

- An operating system is the one program running at all times on the computer (usually called the kernel), with all else being systems programs and application programs.
- An operating system like a government, it performs no useful function by itself. It simply provides an environment within which other programs can do useful work. 



#### Computer-System Organization ~



##### Computer System Organization

- A computer system consist of one or more CPUs and a number of device controllers connected through a common bus that provides access to shared memory.

- How a computer to start running? An initial program bootstrap program. It is stored in read-only memory (ROM). It locate and load operating system into memory. 

- A modern computer system

  ```
                   disks           mouse  keyboard  printer         monitor
                    |                  \     |     /                   |   
  CPU         disk controller          USE controller           graphics adapter
  |_________________|________________________|_________________________|
                                |
                              memory
  ```

  

##### Computer-System Operation - interrupt

- What is it? When the CPU is interrupted, it stops what it is doing and immediately transfer execution to a fixed location. Example, CPU is waiting I/O operation, when I/O data transfer done, need to interrupt the CPU to continue execute next instruction of program.
- Trigger an interrupt. Hardware by sending a signal to the CPU by way of system bus. Software by executing a system call.



##### Storage Structure

- Storage-device hierarchy

  ```
  # Speed, cost, size top-down
  
  register
  cache
  main memory
  ----------------------------------
  electronic disk    (nonvolatile)
  magnetic disk 
  optical disk
  magnetic tapes
  ```

- cache (RAM memory)



##### I/O Structure

- system bus

  - The system bus is a pathway composed of cables and connectors used to carry data between a computer microprocessor and the main memory.
  - The bus provides a communication path for the data and control signals moving between the major components of computer system.
  - Three main buses: data, address and control bus.
  - computer system consists of CUPs and multiple device controllers that are connected through a common bus.

- device driver

  - it understands device controller.
  - It presents a uniform  interface to the device to the operating system.

- device controller

  - it's in charge of a specific type of device. 
  - Devices attached to specific controller.
  - It maintains some local buffer storage (in RAM) and a set of special-purpose registers.
  - It is responsible for moving data between peripheral devices that it controls and its local buffer storage.

- buffer (buffer storage)

  - A part of RAM used for temporary storage of data that is waiting to be sent to a device (or read from device).
  - it is a data area shared by hardware devices or program processes.

- interrupt-driven I/O

  - device driver loads registers within device controller
  - device controller execute appropriate task by contents of these registers.
  - controller transfer of data from device to its local buffer (in RAM).
  - controller informs device driver via an interrupt that it has finished its operation.
  - device driver return control to OS. returning data pointer(read) or status information(write).

- DMA(direct memory access)

  - device controller transfer an entire block of data directly to or from its buffer storage to memory, with no intervention by CPU.
  - interrupt is generated per block.

- How a modern computer system works

  ```
  -------------------------------                            --------------------
  | Thread of execution |       |  <----instruction ----->   |   instructions   |
  |                     | cache |     execution cycle        |       and        | 
  |   CPU(*N)           |       |  <----data movement---->   |      data        |
  -------------------------------                            |                  |
     |          ^         ^                            /     |                  |
     |          |         |                       /          |      memory      |
  IO REQUEST   data    interrupt             /                --------------------
     |          |         |             DMA
     V          V         |           /
  --------------------------       /
  |                        |    /
  |       device(*M)       | /
  --------------------------
  ```

  

#### Computer-System Architecture

Single-Processor Systems

Multiprocessor Systems

Clustered Systems



#### Operating-System Structure ~

Operating system structure

- Multiprogramming
  - increasing CPU utilization by organization jobs.
  - keeps several jobs in memory simultaneously.
  - CPU is switched executing jobs in job pool.
- Time sharing
  - It is a logical extension of multiprogramming.
  - It allows many users to share the computer simultaneously.
- Process
  - a program loaded into memory and executing is called a process.
- Job scheduling, job pool.
- CPU scheduling
- Memory swapping
- Virtual memory



#### Operating-System Operations ~

##### trap

- a trap (or an exception) is a signal like an interrupt.
- It is a software-generated interrupt caused by an error (for example, division by zero or invalid memory access) or by a specific request from a user program.



##### Dual-Mode Operation

- Ensure proper execution of the operating system, must to distinguish between execution of operating system code and user program code.
- A bit called mode bit is added to the hardware of the computer indicate the current mode: kernel(0) or user(1).
- privileged instructions
  - Privileged instructions executed only in kernel mode. If an attempt execute a privileged instruction in user mode, the hardware does not execute rather treats it as illegal and traps it to operating system.
  - Privileged instruction: I/O control, timer management, interrupt management.
  - user program execute privileged instructions by send a system call to operating system.
- Life cycle of instruction execution
  - initial control is within operating system, where instructions are executed in kernel mode.
  - when control is given to a user application, mode is set to user mode.
  - control is switched back to operating system, when an interrupt, a trap, or a system call is occurred.

##### Timer

- Using a timer to prevent a user program from getting stuck in an infinite loop or never returning control to the operating system.
- A timer can be set to interrupt the computer after a specified period.



#### Resource Management 

Process Management

Memory Management

Storage Management



#### Protection and Security 



#### Distributed Systems



#### Special-Purpose Systems

Real-Time Systems

Multimedia Systems

Handheld Systems



#### Computing Environments ~

Traditional Computing

- Batch System
  - Processing jobs in bulk, with predetermined input from files.
- Interactive System
  - Waiting for input from users.
  - To optimize the use of the computing resources.
  - multiple users shared time on system.
- Time Shared System
  - Using a timer and scheduling algorithms to rapidly cycle processes through the CPU, giving each user a share of the resources.



Client-Server Computing

- Multiple client systems request to server system.
- Server System Class
  - Compute-server system: A client send a request to perform an action, in response, the server executes the action and sends back results to client.
  - File-server system: provides a file-system interface where clients can create, update, read, and delete files.



Peer-to-Peer Computing

- What
  - Not distinguish clients and servers. Each may act as either a client or a server, depending on whether it is requesting or providing a service.
- Advantages
  - In a client-server system, the server is a bottleneck, but in a peer-to-peer system, service can be provided by several nodes distributed throughout the network.
- Two way accomplished peer-to-peer system
  - 1)A node joins a network, it register its service with a centralized lookup service on the network. 2)Any node desiring a specific service first contacts this centralized lookup service to determine which node provides the service.
  - 1) a client node broadcasting a request for service to all other nodes in the network. 2) The node providing that service responds to peer.



Web-Based Computing

- The implementation of web-based computing has a load balancers which distribute network connections among a pool of similar servers.

[`back to content`](#content)



<h3 id="osst">2. Operating System Structures</h3>
#### Operating-System Services ~

Operating System Services - helpful to user

- user interface
- Program execution
- I/O operations
- File-system manipulation
- Communications
- Error detection

Operating System functions for itself

- Resource allocation
- Accounting
- Protection and security



#### User Operating-System Interface

Command Interpreter

Graphical User Interfaces



#### System Calls ~

System Calls

- System calls provide an interface to the services made available by an operating system.

- These system calls generally written in C and C++ language. Certain low-level tasks may need to be written using assembly language.

System-call interface 

- Most programming languages provides a system-call interface. These API invokes the  necessary system call within the operating system.



#### Types of System Calls 

Process Control

File Management

Device Management

Information Maintenance

Communication



#### System Programs



#### Operating-System Design and Implementation

Design Goals

Mechanisms and Policies

Implementation



#### Operating-System Structure ~

Simple Structure

Layered Approach

Microkernels

Modules



#### Virtual Machines

Implementation

Benefits

Examples: VMware, Java Virtual Machine



#### Operating-System Generation



#### System Boot



[`back to content`](#content)



---



### II. Process Management



<h3 id="proc">3. Process</h3>
#### Basic Concept ~

What is Process

Process in Memory

Process States

Process Control Block

What is Threads



#### Process Scheduling ~

Scheduling Queues

Schedulers

Context Switch Algorithms



#### Operations Of Processes ~

Process Creation

Process Termination



#### Interprocess Communication ~

Shared Memory

Message Passing



#### Communication in System ~

Sockets

Remote Procedure Calls

Remote Method Invocation

[`back to content`](#content)



<h3 id="thre">4. Threads</h3>
#### Basic Concepts ~

What is Thread. 

Its Benefits



#### Multithreading Models ~

user threads and kernel threads

Many-to-one

one-to-one

many-to-many

two-level model



#### Thread Libraries

POSIX PThreads

Win 32

Java



#### Thread Issues

The fork() and exec() system calls

Thread Cancellation

Signal Handling

Thread Pools

Thread-special Data

Scheduler Activation



#### Operating System Examples

threads Implementation in Windows and Linux

[`back to content`](#content)



<h3 id="csch">5. CPU Scheduling</h3>
#### Basic Concepts ~

CPU-I/O Burst Cycle

CPU Scheduler

Preemptive Scheduling

Dispatcher



#### Scheduling Criteria ~



#### Scheduling Algorithms ~

First-Come First-Served (FCFS) Scheduling

Gantt Chart

Shortest-Job-First (SJF) Scheduling

Priority Scheduling

Round-Robin (RR) Scheduling

Multilevel Queue Scheduling

Multilevel Feedback-Queue Scheduling



#### Multiple-Processor Scheduling ~

Approaches to Multiple-Processor Scheduling

Processor Affinity

Load Balancing

Symmetric Multithreading



#### Thread Scheduling



#### Operating System Examples

Scheduling Policies in Solaris, Windows XP, and Linux.



#### Algorithm Evaluation



[`back to content`](#content)



<h3 id="psyn">6. Process Synchronization</h3>
#### Background ~ 



#### The Critical-Section Problem ~



#### Peterson's Solution ~



#### Synchronization Hardware ~



#### Semaphores ~



#### Classic Problems of Synchronization ~

The Bounded-Buffer Problem

The Readers-Writers Problem

The Dining-Philosophers Problem



#### Monitors ~



#### Synchronization Examples

Synchronization mechanisms in Solaris, Windows XP, Linux operating system. 



#### Atomic Transaction ~

System Model

Log-Based Recovery

Checkpoints

Concurrent Atomic Transactions



[`back to content`](#content)



<h3 id="dead">7. Deadlocks</h3>
#### System Model ~



#### Deadlock Characterization ~

Necessary Conditions

Resource-Allocation Graph



#### Methods for Handling Deadlocks ~



#### Deadlock Prevention ~

Mutual Exclusion

Hold and Wait

No Preemption

Circular Wait



#### Deadlock Avoidance ~



#### Deadlock Detection ~



#### Recovery From Deadlock ~



[`back to content`](#content)



---



### III. Memory Management



<h3 id="mmem">8. Main Memory</h3>
#### Background ~

Basic Hardware

Address Binding

Logical Versus Physical Address Space

Dynamic Loading

Dynamic Linking and Shared Libraries



#### Swapping ~

What is it?

Why is it?

How does it accomplish?



#### Contiguous Memory Allocation ~

Memory Mapping and Protection

Memory Allocation

Fragmentation



#### Paging  ~

What is it? (noncontiguous)

Basic Method of Accomplishment

Hardware Support

Protection

Shared Pages



#### Structure of the Page Table ~

Hierarchical Paging

Hashed Page Tables

Inverted Page Tables



#### Segmentation ~

Basic Method

Hardware



#### Example Memory Management

Pentium Segmentation

Pentium Paging

Linux on Pentium Systems



#### Summary



[`back to content`](#content)



<h3 id="vmem">9. Virtual Memory</h3>
#### Background ~

What is it

Virtual Address Space



#### Demand Paging ~

Basic Concept

- memory resident
- page-fault trap
- Implement demand paging major problems: a frame-allocation algorithm and a page-replacement algorithm.

Performance of Demand Paging

- effective access time
- page fault rate



#### Copy-on-Write ~

What is it

- rapid process creation.
- minimizes the number of new pages



#### Page Replacement ~

Basic Page Replacement

FIFO Page Replacement Algorithm

Optimal Page Replacement Algorithm

LRU Page Replacement Algorithm

LRU-Approximation page Replacement Algorithm

Counting-Based Page Replacement Algorithm

Page-Buffering Algorithms

Application and Page Replacement



#### Allocation of Frames ~

Minimum Number of Frames

Allocation Algorithms

Global versus Local Allocation



#### Thrashing

Cause of Thrashing

Working-Set Model

Page-Fault Frequency



#### Memory-Mapped Files

Basic Mechanism

Shared Memory in the Win32 API

Memory-Mapped I/O



#### Allocating Kernel Memory

Buddy System

Slab Allocation



#### Other Considerations

Prepaging

Page Size

TLB Reach

Inverted Page Tables

Program Structure

I/O Interlock



#### Operating-System Example of Virtual Memory

#### Summary



[`back to content`](#content)



-----



### IV. Storage Management



<h3 id="fsin">10. File-System Interface</h3>
#### File Concept ~

What is a File

File Attributes

File Operations

File Types

What is File Structure 

Internal File Structure



#### Access Methods ~

Sequential Access

Direct Access

Other Access Methods



#### Directory Structure ~

Directory Storage Structure

Directory Overview

Single-Level Directory of Logical Structure

Two-Level Directory

Tree-Structured Directoires

Acyclic-Graph Directories

General Graph Directory



#### File-System Mounting ~

What is it?



#### File Sharing

Multiple Users

Remote File Systems

Consistency Semantics



#### Protection

Types of Access

Access Control

Other Protection Approaches



#### Summary



[`back to content`](#content)



<h3 id="fsim">11. File-System Implementation</h3>
#### File-System Structure ~

Layered File System



#### File-System Implementation ~

Overview

Partitions and Mounting

Virtual File Systems



#### Directory Implementation ~

Data Structure of a directory



#### Allocation Methods ~

Contiguous Allocation

Linked Allocation

Indexed Allocation

Performance



#### Free-Space Management ~

Bit Vector

Linked List

Grouping

Counting



#### Efficiency and Performance

Efficiency and performance of secondary storage



#### Recovery ~

Consistency Checking

Backup and Restore

Log-Structured File Systems



#### NFS (Network File System)



[`back to content`](#content)



<h3 id="msst">12. Mass-Storage Structure</h3>
#### Overview of Mass-Storage Structure ~

Hard Disk Drives (Magnetic Disks)

Nonvolatile Memory Devices

Volatile Memory

Secondary Storage Connection Methods

Address Mapping



#### HDD Scheduling ~

FCFS Scheduling

SCAN Scheduling

C-SCAN Scheduling

Selection of a Disk-Scheduling Algorithm



#### NVM Scheduling

What is it



#### Error Detection and Correction

What is it



#### Storage Device management ~

Device Formatting, Partitions, and Volumes

Boot Block

Bad Block



#### Swap-Space Management ~

Swap-Space Use

Swap-Space Location



#### Storage Attachment

What is it

Host-Attached Storage

Network-Attached Storage

Cloud Storage

Storage-Area Networks and Storage Arrays



#### RAID Structure ~

What is it

Improvement of Reliability via Redundancy

RAID Levels

Selecting a RAID Level

Extensions

Problems with RAID

Object Storage



#### Summary



[`back to content`](#content)



<h3 id="iosy">13. I/O Systems</h3>
#### Overview ~

What is it



#### I/O Hardware ~

I/O hardware

Memory-Mapped I/O

Polling

Interrupts

Direct Memory Access



#### Application I/O Interface ~

I/O Structure and I/O Devices

Block and Character Devices

Network Devices

Clocks and Timers

Nonblocking and Asynchronous I/O

Vectored I/O



#### Kernel I/O Subsystem ~

I/O Scheduling

Buffering

Cacheing

Spooling and Device Reservation

Error Handling

I/O Protection

Kernel Data Structures

Power management

Kernel I/O Subsystem Summary



#### Transforming I/O Requests to Hardware Operations ~

What is it



#### STRRAMS

What is it



#### Performance

What is it



#### Summary



[`back to content`](#content)



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
