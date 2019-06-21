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



#### What Operating System Do

User View

System View

Defining Operating Systems

[details](_knowledge-os-details#intr)



#### Computer-System Organization

Computer-System Operation

Storage Structure

I/O Structure

[details](_knowledge-os-details#intr)



#### Computer-System Architecture

Multiprocessor Systems

Clustered Systems

[details](_knowledge-os-details#intr)



#### Operating-System Structure

[details](_knowledge-os-details#intr)



#### Operating-System Operations

[details](_knowledge-os-details#intr)



#### Resource Management

Process Management

Memory Management

Storage Management

[details](_knowledge-os-details#intr)



#### Protection and Security

[details](_knowledge-os-details#intr)



#### Distributed Systems

[details](_knowledge-os-details#intr)



#### Special-Purpose Systems

Real-Time Systems

Multimedia Systems

Handheld Systems

[details](_knowledge-os-details#intr)



#### Computing Environments

Traditional Computing

Client-Server Computing

Peer-to-Peer Computing

Web-Based Computing

[details](_knowledge-os-details#intr)



<h3 id="osst">2. Operating System Structures</h3>



#### Operating-System Services

#### User Operating-System Interface

#### System Calls

#### Types of System Calls

#### System Programs

#### Operating-System Design and Implementation

#### Operating-System Structure

Simple Structure

Layered Approach

Microkernels

Modules

#### Virtual Machines

#### Operating-System Generation

#### System Boot



---



### II. Process Management



<h3 id="proc">3. Process</h3>



#### Basic Concept

What is Process

Process in Memory

Process States

Process Control Block

What is Threads



#### Process Scheduling

Scheduling Queues

Schedulers

Context Switch Algorithms



#### Operations Of Processes

Process Creation

Process Termination



#### Interprocess Communication

Shared Memory

Message Passing



#### Communication in System

Sockets

Remote Procedure Calls

Remote Method Invocation



<h3 id="thre">4. Threads</h3>



#### Basic Concepts

What is Thread. 

Its Benefits



#### Multithreading Models

Many-to-one

one-to-one

many-to-many

two-level model



#### Thread Libraries

POSIX PThreads

Win 32

Java



#### Thread Issues

Creating sub Process

Thread Cancellation

Signal Handling

Thread Pools

Thread-special Data

Scheduler Activation



#### Thread Implementation

Implementation in Windows and Linux



<h3 id="csch">5. CPU Scheduling</h3>



#### Basic Concepts

CPU-I/O Burst Cycle

CPU Scheduler

Preemptive Scheduling

Dispatcher



#### Scheduling Criteria



#### Scheduling Algorithms

First-Come First-Served (FCFS) Scheduling

Shortest-Job-First (SJF) Scheduling

Priority Scheduling

Round-Robin (RR) Scheduling

Multilevel Queue Scheduling

Multilevel Feedback-Queue Scheduling



#### Multiple-Processor Scheduling

Approaches to Multiple-Processor Scheduling

Processor Affinity

Load Balancing

Symmetric Multithreading



#### Thread Scheduling

#### Algorithm Evaluation



<h3 id="psyn">6. Process Synchronization</h3>



#### Background

#### The Critical-Section Problem

#### Peterson's Solution

#### Synchronization Hardware

#### Semaphores



#### Classic Problems of Synchronizaiton

The Bounded-Buffer Problem

The Dining-Philosophers Problem

#### Monitors



#### Atomic Transaction

System Model

Log-Based Recovery

Checkpoints

Concurrent Atomic Transactions



<h3 id="dead">7. Deadlocks</h3>



#### System Model

#### Deadlock Characterization

#### Methods for Handling Deadlocks

#### Deadlock Prevention

Mutual Exclusion

Hold and Wait

No Preemption

Circular Wait

#### Deadlock Avoidance

#### Deadlock Detection

#### Recovery From Deadlock



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

Performance of Demand Paging



#### Copy-on-Write

What is it



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





-----



### IV. Storage Management



<h3 id="fsin">10. File-System Interface</h3>



#### File Concept

What is a File

File Attributes

File Operations

File Types

What is File Structure 

Internal File Structure



#### Access Methods

Sequential Access

Direct Access

Other Access Methods



#### Directory Structure

Directory Storage Structure

Directory Overview

Single-Level Directory of Logical Structure

Two-Level Directory

Tree-Structured Directoires

Acyclic-Graph Directories

General Graph Directory



#### File-System Mounting

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



<h3 id="fsim">11. File-System Implementation</h3>



#### File-System Structure

Layered File System



#### File-System Implementation

Overview

Partitions and Mounting

Virtual File Systems



#### Directory Implementation

Data Structure of a directory



#### Allocation Methods

Contiguous Allocation

Linked Allocation

Indexed Allocation

Performance



#### Free-Space Management

Bit Vector

Linked List

Grouping

Counting



#### Efficiency and Performance

Efficiency and performance of secondary storage



#### Recovery

Consistency Checking

Backup and Restore

Log-Structured File Systems



#### NFS



<h3 id="msst">12. Mass-Storage Structure</h3>



#### Overview of Mass-Storage Structure

Hard Disk Drives (Magnetic Disks)

Nonvolatile Memory Devices

Volatile Memory

Secondary Storage Connection Methods

Address Mapping



#### HDD Scheduling

FCFS Scheduling

SCAN Scheduling

C-SCAN Scheduling

Selection of a Disk-Scheduling Algorithm



#### NVM Scheduling

What is it



#### Error Detection and Correction

What is it



#### Storage Device management

Device Formatting, Partitions, and Volumes

Boot Block

Bad Block



#### Swap-Space Management

Swap-Space Use

Swap-Space Location



#### Storage Attachment

What is it

Host-Attached Storage

Network-Attached Storage

Cloud Storage

Storage-Area Networks and Storage Arrays



#### RAID Structure

What is it

Improvement of Reliability via Redundancy

RAID Levels

Selecting a RAID Level

Extensions

Problems with RAID

Object Storage



#### Summary



<h3 id="iosy">13. I/O Systems</h3>



#### Overview

What is it



#### I/O Hardware

I/O hardware

Memory-Mapped I/O

Polling

Interrupts

Direct Memory Access



#### Application I/O Interface

I/O Structure and I/O Devices

Block and Character Devices

Network Devices

Clocks and Timers

Nonblocking and Asynchronous I/O

Vectored I/O



#### Kernel I/O Subsystem

I/O Scheduling

Buffering

Cacheing

Spooling and Device Reservation

Error Handling

I/O Protection

Kernel Data Structures

Power management

Kernel I/O Subsystem Summary



#### Transforming I/O Requests to Hardware Operations

What is it



#### STRRAMS

What is it



#### Performance

What is it



#### Summary





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