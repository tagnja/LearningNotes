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

[Details](_knowledge-os-details.md#intr)



#### Computer-System Organization

Computer-System Operation

Storage Structure

I/O Structure

[Details](_knowledge-os-details.md#intr)



#### Computer-System Architecture

Multiprocessor Systems

Clustered Systems

[Details](_knowledge-os-details.md#intr)



#### Operating-System Structure

[Details](_knowledge-os-details.md#intr)



#### Operating-System Operations

[Details](_knowledge-os-details.md#intr)



#### Resource Management

Process Management

Memory Management

Storage Management

[Details](_knowledge-os-details.md#intr)



#### Protection and Security

[Details](_knowledge-os-details.md#intr)



#### Distributed Systems

[Details](_knowledge-os-details.md#intr)



#### Special-Purpose Systems

Real-Time Systems

Multimedia Systems

Handheld Systems

[Details](_knowledge-os-details.md#intr)



#### Computing Environments

Traditional Computing

Client-Server Computing

Peer-to-Peer Computing

Web-Based Computing

[Details](_knowledge-os-details.md#intr)

[`back to content`](#content)



<h3 id="osst">2. Operating System Structures</h3>



#### Operating-System Services

[Details](_knowledge-os-details.md#osst)



#### User Operating-System Interface

[Details](_knowledge-os-details.md#osst)



#### System Calls

[Details](_knowledge-os-details.md#osst)



#### Types of System Calls

[Details](_knowledge-os-details.md#osst)



#### System Programs

[Details](_knowledge-os-details.md#osst)



#### Operating-System Design and Implementation

[Details](_knowledge-os-details.md#osst)



#### Operating-System Structure

Simple Structure

Layered Approach

Microkernels

Modules

[Details](_knowledge-os-details.md#osst)



#### Virtual Machines

[Details](_knowledge-os-details.md#osst)



#### Operating-System Generation

[Details](_knowledge-os-details.md#osst)



#### System Boot

[Details](_knowledge-os-details.md#osst)

[`back to content`](#content)



---



### II. Process Management



<h3 id="proc">3. Process</h3>



#### Basic Concept

What is Process

Process in Memory

Process States

Process Control Block

What is Threads

[Details](_knowledge-os-details.md#proc)



#### Process Scheduling

Scheduling Queues

Schedulers

Context Switch Algorithms

[Details](_knowledge-os-details.md#proc)



#### Operations Of Processes

Process Creation

Process Termination

[Details](_knowledge-os-details.md#proc)



#### Interprocess Communication

Shared Memory

Message Passing

[Details](_knowledge-os-details.md#proc)



#### Communication in System

Sockets

Remote Procedure Calls

Remote Method Invocation

[Details](_knowledge-os-details.md#proc)

[`back to content`](#content)



<h3 id="thre">4. Threads</h3>



#### Basic Concepts

What is Thread. 

Its Benefits

[Details](_knowledge-os-details.md#thre)



#### Multithreading Models

Many-to-one

one-to-one

many-to-many

two-level model

[Details](_knowledge-os-details.md#thre)



#### Thread Libraries

POSIX PThreads

Win 32

Java

[Details](_knowledge-os-details.md#thre)



#### Thread Issues

Creating sub Process

Thread Cancellation

Signal Handling

Thread Pools

Thread-special Data

Scheduler Activation

[Details](_knowledge-os-details.md#thre)



#### Thread Implementation

Implementation in Windows and Linux

[Details](_knowledge-os-details.md#thre)

[`back to content`](#content)



<h3 id="csch">5. CPU Scheduling</h3>



#### Basic Concepts

CPU-I/O Burst Cycle

CPU Scheduler

Preemptive Scheduling

Dispatcher

[Details](_knowledge-os-details.md#csch)



#### Scheduling Criteria

[Details](_knowledge-os-details.md#csch)



#### Scheduling Algorithms

First-Come First-Served (FCFS) Scheduling

Shortest-Job-First (SJF) Scheduling

Priority Scheduling

Round-Robin (RR) Scheduling

Multilevel Queue Scheduling

Multilevel Feedback-Queue Scheduling

[Details](_knowledge-os-details.md#csch)



#### Multiple-Processor Scheduling

Approaches to Multiple-Processor Scheduling

Processor Affinity

Load Balancing

Symmetric Multithreading

[Details](_knowledge-os-details.md#csch)



#### Thread Scheduling

[Details](_knowledge-os-details.md#csch)



#### Algorithm Evaluation

[Details](_knowledge-os-details.md#csch)

[`back to content`](#content)



<h3 id="psyn">6. Process Synchronization</h3>



#### Background

[Details](_knowledge-os-details.md#psyn)



#### The Critical-Section Problem

[Details](_knowledge-os-details.md#psyn)



#### Peterson's Solution

[Details](_knowledge-os-details.md#psyn)



#### Synchronization Hardware

[Details](_knowledge-os-details.md#psyn)



#### Semaphores

[Details](_knowledge-os-details.md#psyn)



#### Classic Problems of Synchronizaiton

The Bounded-Buffer Problem

The Dining-Philosophers Problem

[Details](_knowledge-os-details.md#psyn)



#### Monitors

[Details](_knowledge-os-details.md#psyn)



#### Atomic Transaction

System Model

Log-Based Recovery

Checkpoints

Concurrent Atomic Transactions

[Details](_knowledge-os-details.md#psyn)



[`back to content`](#content)



<h3 id="dead">7. Deadlocks</h3>



#### System Model

[Details](_knowledge-os-details.md#dead)



#### Deadlock Characterization

[Details](_knowledge-os-details.md#dead)



#### Methods for Handling Deadlocks

[Details](_knowledge-os-details.md#dead)



#### Deadlock Prevention

Mutual Exclusion

Hold and Wait

No Preemption

Circular Wait

[Details](_knowledge-os-details.md#dead)



#### Deadlock Avoidance

[Details](_knowledge-os-details.md#dead)



#### Deadlock Detection

[Details](_knowledge-os-details.md#dead)



#### Recovery From Deadlock

[Details](_knowledge-os-details.md#dead)



[`back to content`](#content)



---



### III. Memory Management



<h3 id="mmem">8. Main Memory</h3>



#### Background

Basic Hardware

Address Binding

Logical Versus Physical Address Space

Dynamic Loading

Dynamic Linking and Shared Libraries

[Details](_knowledge-os-details.md#mmem)



#### Swapping

What is it?

Why is it?

How does it accomplish?

[Details](_knowledge-os-details.md#mmem)



#### Contiguous Memory Allocation

Memory Mapping and Protection

Memory Allocation

Fragmentation

[Details](_knowledge-os-details.md#mmem)



#### Paging 

What is it? (noncontiguous)

Basic Method of Accomplishment

Hardware Support

Protection

Shared Pages

[Details](_knowledge-os-details.md#mmem)



#### Structure of the Page Table

Hierarchical Paging

Hashed Page Tables

Inverted Page Tables

[Details](_knowledge-os-details.md#mmem)



#### Segmentation

Basic Method

Hardware

[Details](_knowledge-os-details.md#mmem)



#### Example Memory Management

Pentium Segmentation

Pentium Paging

Linux on Pentium Systems

[Details](_knowledge-os-details.md#mmem)



#### Summary

[Details](_knowledge-os-details.md#mmem)



[`back to content`](#content)



<h3 id="vmem">9. Virtual Memory</h3>



#### Background

What is it

Virtual Address Space

[Details](_knowledge-os-details.md#vmem)



#### Demand Paging

Basic Concept

Performance of Demand Paging

[Details](_knowledge-os-details.md#vmem)



#### Copy-on-Write

What is it

[Details](_knowledge-os-details.md#vmem)



#### Page Replacement

Basic Page Replacement

FIFO Page Replacement Algorithm

Optimal Page Replacement Algorithm

LRU Page Replacement Algorithm

LRU-Approximation page Replacement Algorithm

Counting-Based Page Replacement Algorithm

Page-Buffering Algorithms

Application and Page Replacement

[Details](_knowledge-os-details.md#vmem)



#### Allocation of Frames

Minimum Number of Frames

Allocation Algorithms

Global versus Local Allocation

[Details](_knowledge-os-details.md#vmem)



#### Thrashing

Cause of Thrashing

Working-Set Model

Page-Fault Frequency

[Details](_knowledge-os-details.md#vmem)



#### Memory-Mapped Files

Basic Mechanism

Shared Memory in the Win32 API

Memory-Mapped I/O

[Details](_knowledge-os-details.md#vmem)



#### Allocating Kernel Memory

Buddy System

Slab Allocation

[Details](_knowledge-os-details.md#vmem)



#### Other Considerations

Prepaging

Page Size

TLB Reach

Inverted Page Tables

Program Structure

I/O Interlock

[Details](_knowledge-os-details.md#vmem)



#### Operating-System Example of Virtual Memory

[Details](_knowledge-os-details.md#vmem)



#### Summary

[Details](_knowledge-os-details.md#vmem)



[`back to content`](#content)



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

[Details](_knowledge-os-details.md#fsin)



#### Access Methods

Sequential Access

Direct Access

Other Access Methods

[Details](_knowledge-os-details.md#fsin)



#### Directory Structure

Directory Storage Structure

Directory Overview

Single-Level Directory of Logical Structure

Two-Level Directory

Tree-Structured Directoires

Acyclic-Graph Directories

General Graph Directory

[Details](_knowledge-os-details.md#fsin)



#### File-System Mounting

What is it?

[Details](_knowledge-os-details.md#fsin)



#### File Sharing

Multiple Users

Remote File Systems

Consistency Semantics

[Details](_knowledge-os-details.md#fsin)



#### Protection

Types of Access

Access Control

Other Protection Approaches

[Details](_knowledge-os-details.md#fsin)



#### Summary

[Details](_knowledge-os-details.md#fsin)



[`back to content`](#content)



<h3 id="fsim">11. File-System Implementation</h3>



#### File-System Structure

Layered File System

[Details](_knowledge-os-details.md#fsim)



#### File-System Implementation

Overview

Partitions and Mounting

Virtual File Systems

[Details](_knowledge-os-details.md#fsim)



#### Directory Implementation

Data Structure of a directory

[Details](_knowledge-os-details.md#fsim)



#### Allocation Methods

Contiguous Allocation

Linked Allocation

Indexed Allocation

Performance

[Details](_knowledge-os-details.md#fsim)



#### Free-Space Management

Bit Vector

Linked List

Grouping

Counting

[Details](_knowledge-os-details.md#fsim)



#### Efficiency and Performance

Efficiency and performance of secondary storage

[Details](_knowledge-os-details.md#fsim)



#### Recovery

Consistency Checking

Backup and Restore

Log-Structured File Systems

[Details](_knowledge-os-details.md#fsim)



#### NFS

[Details](_knowledge-os-details.md#fsim)



[`back to content`](#content)



<h3 id="msst">12. Mass-Storage Structure</h3>



#### Overview of Mass-Storage Structure

Hard Disk Drives (Magnetic Disks)

Nonvolatile Memory Devices

Volatile Memory

Secondary Storage Connection Methods

Address Mapping

[Details](_knowledge-os-details.md#msst)



#### HDD Scheduling

FCFS Scheduling

SCAN Scheduling

C-SCAN Scheduling

Selection of a Disk-Scheduling Algorithm

[Details](_knowledge-os-details.md#msst)



#### NVM Scheduling

What is it

[Details](_knowledge-os-details.md#msst)



#### Error Detection and Correction

What is it

[Details](_knowledge-os-details.md#msst)



#### Storage Device management

Device Formatting, Partitions, and Volumes

Boot Block

Bad Block

[Details](_knowledge-os-details.md#msst)



#### Swap-Space Management

Swap-Space Use

Swap-Space Location

[Details](_knowledge-os-details.md#msst)



#### Storage Attachment

What is it

Host-Attached Storage

Network-Attached Storage

Cloud Storage

Storage-Area Networks and Storage Arrays

[Details](_knowledge-os-details.md#msst)



#### RAID Structure

What is it

Improvement of Reliability via Redundancy

RAID Levels

Selecting a RAID Level

Extensions

Problems with RAID

Object Storage

[Details](_knowledge-os-details.md#msst)



#### Summary

[Details](_knowledge-os-details.md#msst)



[`back to content`](#content)



<h3 id="iosy">13. I/O Systems</h3>



#### Overview

What is it

[Details](_knowledge-os-details.md#iosy)



#### I/O Hardware

I/O hardware

Memory-Mapped I/O

Polling

Interrupts

Direct Memory Access

[Details](_knowledge-os-details.md#iosy)



#### Application I/O Interface

I/O Structure and I/O Devices

Block and Character Devices

Network Devices

Clocks and Timers

Nonblocking and Asynchronous I/O

Vectored I/O

[Details](_knowledge-os-details.md#iosy)



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

[Details](_knowledge-os-details.md#iosy)



#### Transforming I/O Requests to Hardware Operations

What is it

[Details](_knowledge-os-details.md#iosy)



#### STRRAMS

What is it

[Details](_knowledge-os-details.md#iosy)



#### Performance

What is it

[Details](_knowledge-os-details.md#iosy)



#### Summary

[Details](_knowledge-os-details.md#iosy)



[`back to content`](#content)



---



### V. Protection and Security



<h3 id="prot">Protection</h3>

[Details](_knowledge-os-details.md#prot)



<h3 id="secu">Security</h3>

[Details](_knowledge-os-details.md#secu)





---



### VI. Distributed Systems



<h3 id="dsst">Distributed System Structures</h3>



<h3 id="dfsy">Distributed File System</h3>



<h3 id="dcoo">Distributed Coordination</h3>



--END--