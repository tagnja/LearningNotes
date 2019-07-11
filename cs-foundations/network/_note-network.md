# Note of Computer Network

### Content

- Introduction to Computer Network
- Application Layer
- Transport Layer
- The Network Layer: Data Plane
- The Network Layer: Control Plane
- The Link Layer and LANs
- Security in Computer Networks
- Multimedia Networking



### Main



### Introduction to Computer Network



### Application Layer

There are many useful network applications promote the development of the network. Such as, before 2000, World Wide Web, Instant messaging, P2P file sharing. After 2000,  voice over IP, video conferencing, online games, social networking applications and location based mobile apps.

Key application-layer concepts, including required network services, clients and servers, processes communication, and transport layer interfaces (Socket interface). In addition, applications and protocols of application-layer.

#### Principles of Network Applications

##### Application Architecture

Develop a application need select a architecture and provides set of services. There are two architecture: the client-server architecture and the peer-to-peer (P2P) architecture. Some application may use hybrid architecture of two.

Client-server architecture. many hosts called clients request an always-on host called server.

- security, performance, and reliability.

P2P architecture. Each host called a peer. Peers direct communication between pairs of connected hosts. 

- There is no reliance on dedicate servers. Peers direct communication. Low consume in the network bandwidth.
- Self-scalability.
- highly decentralized structure. May face challenges of security, performance, and reliability. 

##### Processes Communicating

Client and Server Process

How the programs running in multiple end systems, communicates with each other. In operating system, it is actually **processes** communicate. A process is a program that is running within a operating system. In network, two processes communicate with each other by passing message.

The Interface Between the Process and the Computer Network

A process sends messages into, and receives messages from. the network through a software interface called a **socket**. A socket is the interface between the application layer and the transport layer within a host. An analogy, a process like a house and its socket like its door.

Addressing Processes

the address of the host is identified by its **IP address**. specifies the receiving process in the destination host by **port number**.



##### Transport Services Available to Applications

- Reliable data transfer. Application don't need reliable data transfer call loss-tolerant applications.
- Throughput. Application have throughput requirements called bandwidth-sensitive application.
- Timing.
- Security



##### Transport Services Provided by Internet

TCP Services

- Connection-oriented service. The client and server exchange information with each other before the application-level message begin to flow. This procedure for establish TCP connection called handshaking. The connection is a full-duplex connection.
- Reliable data transfer service. Deliver all data sent without error and in the proper order.

Secure Socket Layer (SSL)

Neither TCP nor UDP provides any encryption. The data that the sending process passes into its socket is the same data that travels over the network to the destination process. The Internet community developed an enhancement for TCP called **Secure Sockets Layer (SSL)**. SSL is not a Internet transport protocol, is an enhancement of TCP, with the enhancements being implemented in the application layer. SSL has it own socket API that is similar to the traditional TCP socket API. 

Process of using SSL

- When an application uses SSL, the sending process passes cleartext data to the SSL socket; 
- SSL in the sending host then encrypts the data and passes the encrypted data to the TCP socket.
- The encrypted data travels over the Internet to then TCP socket in the receiving process. 
- The Receiving socket passes the encrypted data to SSL, which decrypts data. 
- Finally, SSL passes the cleartext data through its SSL socket to the receiving process. 

UDP Services

- Connectionless. There is no handshaking.
- Unreliable data transfer service. No guarantee message reach the receiving process.
- Don't include a congestion-control mechanism. Just pump data into the layer blow at any rate it pleases.



Service Not Provided by Internet Transport Protocols

- Throughput.
- Timing.



##### Application-Layer Protocols

Application-layer protocol defines:

- The types of messages exchanged.
- The syntax of the various message types. 
- The semantics of the fields.
- Rules for determining when how a process sends messages and responds to messages.

##### Network Applications and Application-layer protocols

- Web. Hyper Text Transfer Protocol (HTTP)
- Electronic mail. Simple Mail Transfer Protocol (SMTP)
- Directory Service. 
- Video streaming. 
- P2P applications.

#### The Web and HTTP

##### Overview of HTTP

Hyper Text Transfer Protocol (HTTP)

- Stateless protocol

Web browsers, Web servers.

##### Non-persistent and Persistent Connections

##### HTTP Message Format

Request Message Format

```
GET /somedir/page.html HTTP/1.1
Host: www.someschool.edu
Connection: close
User-agent: Mozilla/5.0
Accept-language: en

(form data...)
```

- Request line
- Header lines
- Blank line
- Entity body

Response Message Format

```
HTTP/1.1 200 OK
Conncection: close
Server: Apache/2.2.3 (CentOS)
Last-Modified: Tue, 18 Aug 2018 15:11:03 GMTs
Content-Length: 6821
Content-type: text/html

(response data...)
```

- Status line
- Header lines
- Blank line
- Entity body

Common Status Codes

```
200 OK
301 Moved permanently
400 Bad Request
404 Not Found
505 HTTP Version Not Supproted
```

##### User-Server Interaction: Cookies

##### Web Caching

#### Electronic Mail 

Alice's agent --(SMTP)-->Alice's mail server--(SMTP)-->Bob's mail server--(POP3, IMAP, or HTTP)--> Bob's agent

#### DNS - The Internet's Directory Service

#### Peer-to-peer Applications

#### Video Streaming and Content Distribution Networks

#### Socket Programming: Creating Network Applications