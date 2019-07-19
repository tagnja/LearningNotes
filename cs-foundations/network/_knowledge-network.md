# Knowledge of Network

- [Introduction](#intr)
- The Application Layer
  - Principles of Network Applications
  - The Web and HTTP
  - Electronic Mail 
  - DNS - The Internet's Directory Service
  - Peer-to-peer Applications
  - Video Streaming and Content Distribution Networks
  - Socket Programming: Creating Network Applications
- The Transport Layer
  - Introduction Transport-Layer Services
  - Multiplexing and Demultiplexing
  - Connectionless Transport: UDP
  - Principles of Reliable Data Transfer
  - Connection-oriented Transport: TCP
  - Principles of Congestion Control
  - TCP Congestion Control
- The Network Layer: Data Plane
- The Network Layer: Control Plane
- The Data Link Layer
- The Physical Layer
- Network Security

### Main

<h3 id="intr"></h3>
### Introduction

#### Uses of Computer Networks

Business Applications

Home Applications

Mobile Users

Social Issues



#### Network Hardware

Transmission technology 

- Broadcast links 
- Point-to-point links

Scale

- PAN (Personal Area Networks)
  - Bluetooth
- LAN (Local Area Networks)
  - Wi-Fi
  - Ethernet (IEEE 802.3)
- MAN (Metropolitan Area Networks)
- WAN (Wide Area Networks)
  - Subnet
    - Transmission Line
    - Switching Element, named Router
  - VPN
  - ISP network
  - wireless technology. Satellite system, cellular telephone network.

#### Network Software

- Protocol Hierarchies

#### Reference Models

- OSI (Open Systems Interconnection) Reference Model 
- TCP/IP Reference Model
- Five Layers Model



---



### Application Layer



#### Principles of Network Applications

Application Architecture

Processes Communicating

Transport Services Available to Applications

Transport Services Provided by Internet

Application-Layer Protocols

Network Applications and Application-layer protocols

#### The Web and HTTP

Overview of HTTP

Non-persistent and Persistent Connections

HTTP Message Format

User-Server Interaction: Cookies

Web Caching

#### Electronic Mail 

#### DNS - The Internet's Directory Service

Services of Provided by DNS

Overview of How DNS Works

DNS Records and Messages

#### Peer-to-peer Applications

Bit Torrent Protocol

#### Video Streaming and Content Distribution Networks

Dynamic Adaptive Streaming over HTTP (DASH).

Content Distribution Networks (CDN)

#### Socket Programming: Creating Network Applications



---



### Transport Layer

#### Introduction Transport-Layer Services

Basic Concepts

- Logical Communication

- Segments

Relationship Between Transport and Network Layers

Overview of the Transport Layer

- UDP
- Best-effort delivery service
- Unreliable service
- TCP
- transport-layer multiplexing and demultiplexing
- Reliable data transfer
- Congestion control

#### Multiplexing and Demultiplexing

How TCP and Socket Connection works.

#### Connectionless Transport: UDP

UDP Concepts

UDP Segment Structure

UDP Checksum

#### Principles of Reliable Data Transfer

Basic Concepts

- Finite-state-machine (FSM)
- Automatic Repeat Request (ARQ) protocol
- Stop-and-wait protocols
- Positive Acknowledgement (ACK), Negative Acknowledge (NAK)
- Duplicate Packets, Duplicate ACKs
- Sequence Number
- NAK-free reliable data
- Countdown Timer

Capabilities Required

- Error detection
- Receiver feedback
- Retransmission

Problems and Solutions

- Data Corrupted, Bit Errors, Duplicate Packets
  - ACK
  - Checksum
  - Sequence number
- Data loss delay
  - Timer

Pipelined Reliable Data Transfer Protocols

Go-Back-N (GBN)

- Cumulative Acknowledgement

Selective Repeat (SR)

- Window Size

#### Connection-oriented Transport: TCP

TCP Connection

(A TCP Connection consist of buffers, variables, and a socket connection to a process.)

- Connection-oriented
- Full-duplex service
- Point-to-point
- Three-way handshake
- Send buffer
- Maximum segment size (MSS)

TCP Segment Structure

- Header fields and a data field

Round-Trip Time Estimation and Timeout

- Round-trip time (RTT)
- SampleRTT, EstimatedRTT, DevRTT
- TimeoutInterval

Reliable Data Transfer

- Fast Retransmit

Flow Control

- Receive window

TCP Connection Management

- Process of Connection
- TCP States

#### Principles of Congestion Control

The Causes and the Costs of Congestion

- Large queuing delays
- Unneeded Retransmissions
- Dropping a packet

Approaches to Congestion Control

- End-to-end congestion control
- Network-assisted congestion control. ATM Available Bite Rate (ABR) congestion control.

#### TCP Congestion Control

- What is it.
- How a TCP sender limits its send rate? Congestion Window (cwnd)
- How a TCP sender perceives that there is congestion? Loss event.
- How to change its send rate. Congestion-control algorithms.

TCP Congestion-control Algorithm

- Slow Start
- Congestion Avoidance
- Fast Recovery. 
- Additive-increase, multiplicative-decrease (AIMD)

Fairness

Explicit Congestion Notification (ECN) Network-assisted Congestion Control

---



### The Network Layer: Data Plane



### The Network Layer: Control Plane



### The Link Layer and LANs



### Security in Computer Networks

