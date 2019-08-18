# Knowledge of Network



### Content



- [Introduction](#intr)
- Computer Networks and the Internet
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
  - Basic
  - Inside a  Router
  - The Internet Protocol: IPv4, Addressing, IPv6, and More
  - Generalized Forwarding and SDN
- The Network Layer: Control Plane
  - Introduction
  - Routing Algorithms
  - Internet Routing Protocols
  	- Intra-AS Routing in the Internet: OSPF
  	- Routing Among the ISPs: BGP
  - The SDN Control Plane
  - Managing an IP network
  	- ICMP: The Internet Control Message Protocol
  	- Network Manage and SNMP
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



### Computer Network and the Internet



#### What is the Internet

A Nuts-and-Bolts Description

- hosts, end systems
- communication links, packet switches
- routers, link-layer switches
- Internet Service Providers (ISPs)
- protocols

A Service Description

- Distributed Applications
- Socket interfaces

What is a Protocol



#### The Network Edge

Access Networks

- Home Access: DSL, FTTH, Dial-Up, and Satelllite
- Access in the Enterprise (and home): Ethernet and WiFi
- Wide-Area Wireless Access: 3G and LTE

Physical Media

- Twisted-Pair Copper Wire
- Coaxial Cable
- Fiber Optics
- Terrestrial Radio Channels
- Satellite Radio Channels



#### The Network Core

Packet Switching

- Store-and-forward transmission
- Queuing Delays and Packet loss
- Forwarding Tables and Routing Protocols

Circuit Switching



#### A Network of Networks

ISP

Points of presence (PoPs)

Internet Exchange Point (IXP)

Content-provider networks



#### Delay, Loss, and Throughput in Packet-Switched Network

Delay

- Processing Delay
- Queuing delay
- Transmission delay
- propagation delay

Queuing Delay and Packet Loss

End-to-End Delay

Throughput in Computer Network



#### Protocol Layers and Their Service Models

Layered Architecture

- Protocol Layering
- Application layer
- Transport Layer
- Network Layer
- Link Layer
- Physical Layer
- The OSI model

Encapsulation



#### Network Under Attack

Malware. Put Malware into your host via the Internet

- Viruses
- Worms

Denial-of-service (DoS) Attack, Distributed DoS (DDoS)

- Vulnerability attack
- Bandwidth flooding
- connection flooding

Packet Sniffer

IP Spoofing



![](mind-map/Network-Introduction.png)



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

#### Basic

##### Forwarding and Routing

Forwarding Table

Routing Algorithms

Control Plane: The Traditional Approach. (Destination-based forwarding)

Control Plane: The SDN (software-defined networking) Approach (Generalized forwarding)

#### Network Service Model

A single service: best-effort service.

#### Inside a  Router

Four router components: Input ports, Switching fabric, Output ports, Routing processor

##### Input Port Processing and Destination-Based Forwarding

##### Switching

##### Output Port Processing

##### Input and Output Queue

##### Packet Scheduling

First-in-First-Out (FIFO)

Priority Queuing

Round Robin and Weighted Fair Queuing (WFQ)

#### The Internet Protocol: IPv4, Addressing, IPv6, and More

##### IPv4 Datagram Format 

##### IPv4 Datagram Fragmentation

Maximum transmission unit (MTU)

##### IPv4 Addressing

subnet

subnet mask

Classless Interdomain Routing

IP broadcast address

Obtaining a block of address

Obtaining a host address: Dynamic host configuration protocol (DHCP)

Network Address Translation (NAT)

##### IPv6

IPv6 Datagram Format. (40 bytes)

Transitioning from IPv4 to IPv6

Tunnel

#### Generalized Forwarding and SDN

Flow table

Match

Action



### The Network Layer: Control Plane

How Network -layer components and services are configured and managed.

#### Introduction

per-router control

software-defined networking (**SDN**) control (Logically centralized control)



#### Routing Algorithms

least-cost path

link-state (LS) routing (centralized routing algorithm)

distance-vector routing (decentralized routing algorithm)



#### Internet Routing Protocols



##### Intra-AS Routing in the Internet: OSPF

interconnected routers

autonomous systems (**ASs**)

autonomous system number (**ASN**)

Intra-autonomous system routing protocol

Open Shortest Path First (**OSPF**) is a link-state protocol



##### Routing Among the ISPs: BGP

Inter-autonomous system routing protocol

Border Gateway Protocol (**BGP**)

CIDRized prefixes, a subnet

The Role of BGP

- Obtain prefix reachability information from neighboring ASs.
- Determine the "best" routes to the prefixes.

Advertising BGP Route Information

- Gateway router, internal router
- BGP connection, external BGP (eBGP), internal BGP (iBGP)

Determining the Best Routes

- one of the simplest routing algorithms: Hot Potato Routing
- Route-Selection Algorithm

IP-Anycast

- How a CDN use IP-anycast.

Routing Policy

- Not advertised to a ISP.

Putting the Pieces Together: Obtaining Internet Presenece



#### The SDN Control Plane

Characters of an SDN architecture



The SDN Control Plane: SDN Controller and SDN Network-control Applications

The SDN Control Plane Layers

- A Communication Layer
  - OpenFlow
- A network-wide state-management layer
  - State of the networks hosts, links, switches, and other SDN-controlled devices.
- The interface to the network-control application layer
  - Routing
  - Access Control
  - Load Balancer

OpenFlow Protocol

- Operates between an SDN controller and an SDN-controlled switch.

Data and Control Plane Interaction



#### Managing an IP network

##### ICMP: The Internet Control Message Protocol

It is used by hosts and routers to communicate network-layer information.

ICMP messages are carried as IP payload

ICMP messages types and code fields.



##### Network Manage and SNMP

To keep the network "up and running"

Network Management Framework

- Managing server
- Managed device
- Management Information Base (**MIB**)
- Network management agent
- Network management protocol

The Simple Network Management Protocol (SNMP)

- Carried in the payload of a UDP datagram



### The Link Layer and LANs

#### Introduction to the Link Layer

Basic

- a Node: hosts, routers, switches, and WiFi access points.

- links

- link-layer frame

The services provided by the Link Layer

- Framing
- Link access
- Reliable delivery
- Error detection and correction

Where is the Link Layer Implemented

- network adapter (as a network interface card (NIC))
- Link-layer controller in adapter



#### Error-Detection and -Correction Techniques

(**TODO**)



#### Multiple Access Link and Protocols

(**TODO**)



#### Switched Local Area Networks

##### Link-layer Addressing and ARP

MAC address

- MAC Address (LAN address, physical address)

- MAC address its function, format and features

ARP

- Address Resolution Protocol (ARP)
- ARP module
- ARP table
- ARP packet
- MAC broadcast address

Sending a Datagram off the Subnet

##### Ethernet

Ethernet is the most prevalent wired LAN technology.

Ethernet Frame Structure

Ethernet technologies

##### Link-layer Switches

Forwarding and Filtering

- Forwarding
- Filtering
- Switch table

Self-Learning

Properties of Link-Layer Switching

- Elimination of collisions
- Heterogeneous links
- Management

Switch Versus Routers

- store-and-forward packet
- Switch pros and cons
- Router pros and cons
- Typical features
  - Traffic isolation
  - plug and play
  - Optimal routing

##### Virtual Local Area Networks (VLANs)

A single switch configured VLANs



#### Link Virtualization: A Network as a Link Layer

Multiprotocol Label Switching (MPLS)

Label-switched router

MPLS label in forwarding table



#### Data Center Networking

A data center network with a hierarchical topology

Hierarchical Architecture

Trends in Data Center Networking



#### Retrospective: A Day in the Life of a Web Page Request

Get Basic IP - DHCP, UDP, IP, and Ethernet

Get Website IP -  DNS and ARP

Get Website IP - Intra-Domain Routing to DNS Server

Get Website Page - Web Client-Server Interaction: TCP and HTTP



### Security in Computer Networks

