# Java EE Questions

<h3 id="content">Content</h3>

- Java EE

  - [What is Java EE](#wije)
  - [Are EJB/Spring different implementations of Java EE?](#eas)
- Servlet/JSP

  - Basic
    - [What is Servlet](#wis)
    - [Lifecycle of Servlet](#los)
    - [Flow of Request in Servlet](#for)
    - [Servlet Interfaces And Implementation Class](#sic)
  - Core
    - What are Servlet Core Concept
    - Sharing Information like Session & Cookie
    - How to use session when client ban cookie
    - Uploading Files
    - Asynchronous Processing and Nonblocking I/O
- JDBC
  - [Transaction Isolation Levels](#til)
- Tomcat
  - [What is Apache Tomcat](#wit)
  - [Apache HTTP server and Apache Tomcat](#aat)
  - [Web Servers and Servlet Containers](#was)
- HTTP
  - HTTP request
  - HTTP Common request method
  - get vs post
  - Content Type
  - Status Code
- Spring Framework

  - What is Spring
  - What are Configuration files in Spring
  - IOC Implementation Principles
  - AOP Implementation Principles
  - How @transactional work in spring
- Spring Boot

  - What is SpringBoot
  - Spring Boot Features
  - Spring Boot Implementation Principle.
  - Spring Boot Configuration
- Hibernate

  - What is Hibernate
  - What are Configuration files in Hibernate
- Mybatis

  - What is Mybatis
  - What are Configuration files in MyBatis
  - What is differences between Mybatis and Hibernate
  - Why the Dao Interface can mapper its mapper.xml

---



### Main

### Java EE

<h3 id="wije"># What is Java EE</h3>

What is Java EE

- It translates to Java Enterprise Edition.

- **Java EE is a collection of specifications for developing and deploying enterprise applications.** (In general, enterprise applications refer to software hosted on servers that provide the applications that support the enterprise. The specifications (defined by Sun) describe services, application programming interfaces (APIs), and protocols. The Java EE product provider is typically an application-server, web-server, or database-system vendor who provides classes that implement the interfaces defined in the specifications. These vendors compete on implementations of the Java EE specifications.)

- **Java EE is actually a collection of technologies and APIs** for the Java platform designed to support "Enterprise" Applications which can generally be classed as large-scale, distributed, transactional and highly-available applications designed to support mission-critical business requirements. Transactions and distribution are key.

- Java EE is indeed an **abstract** specification. Anybody is open to develop and provide a working implementation of the specification. The *concrete* implementations are the so-called application servers, like [WildFly](http://wildfly.org/), [TomEE](http://tomee.apache.org/), [GlassFish](http://glassfish.org/), [Liberty](http://www-03.ibm.com/software/products/en/appserv-was-liberty-core), [WebLogic](http://www.oracle.com/technetwork/middleware/weblogic/overview/index.html), etc. There are also servlet containers which implement only the JSP/Servlet part of the huge Java EE API, such as [Tomcat](http://tomcat.apache.org/), [Jetty](http://www.eclipse.org/jetty/), etc.

  We, Java EE developers, should write code utilizing the specification (i.e. import *only* `javax.*`classes in our code instead of implementation specific classes such as `org.jboss.wildfly.*`, `com.sun.glassfish.*`, etc) and then we'll be able to run our code on any implementation (thus, on any application server). If you're familiar with JDBC, it's basically the same concept as how JDBC drivers work. See also a.o. [In simplest terms, what is a factory?](https://stackoverflow.com/questions/7550612/in-simplest-terms-what-is-a-factory)

The 13 core technologies that make up Java EE are:

1. JDBC
2. JNDI
3. EJBs
4. RMI
5. JSP
6. Java Servlets
7. XML
8. JMS
9. Java IDL
10. JTS
11. JTA
12. JavaMail
13. JAF

References

- [What is Java EE?](https://stackoverflow.com/questions/106820/what-is-java-ee)

- [What exactly is Java EE?](https://stackoverflow.com/questions/7295096/what-exactly-is-java-ee)

[back to  content](#content)

---



<h3 id="eas"># Are EJB/Spring different implementations of Java EE?</h3>

Are EJB/Spring different implementations of Java EE?

- No. EJB is part of Java EE. Spring is a standalone framework which substitutes and improves many parts of Java EE. Spring doesn't necessarily require Java EE to run. A barebones servletcontainer like Tomcat is already sufficient. Simply put, Spring is a competitor of Java EE. E.g. "Spring" (standalone) competes EJB/JTA, Spring MVC competes JSF/JAX-RS, Spring DI/IoC/AOP competes CDI, Spring Security competes JAAS/JASPIC, etc.
- Back during the old J2EE/EJB2 times, the EJB2 API was terrible to implement and maintain. Spring was then a much better alternative to EJB2. But since EJB3 (Java EE 5), the EJB API was much improved based on lessons learnt from Spring. Since CDI (Java EE 6), there's not really a reason to look at again *another* framework like Spring to make the developers more easy as to developing among others the service layer.
- Only when you're using a barebones servletcontainer such as Tomcat and can't move on to a Java EE server, then Spring is more attractive as it's easier to install Spring on Tomcat. It isn't possible to install e.g. an EJB container om Tomcat without modifying the server itself, you would basically be reinventing TomEE.

References

- [What exactly is Java EE?](https://stackoverflow.com/questions/7295096/what-exactly-is-java-ee)

[back to content](#content)

---



### Servlet/JSP

<h3 id="wis"># What is Servlet</h3>

What is Servlet

- Servlet is a technology i.e. used to create web application.
- Servlet is a web component that is deployed on the server to create dynamic web page. 
- Servlet is an API that provides many interfaces and classes including documentations.
- Servlet is an interface that must be implemented for creating any servlet.
- Servlet is a class that extend the capabilities of the servers and respond to the incoming request. It can respond to any type of requests.
- A servlet is simply a class which responds to a particular type of network request - most commonly an HTTP request. Basically servlets are usually used to implement web applications - but there are also various frameworks which operate on top of servlets (e.g. Struts) to give a higher-level abstraction than the "here's an HTTP request, write to this HTTP response" level which servlets provide.

References

- [What is Java Servlet?](https://stackoverflow.com/questions/7213541/what-is-java-servlet)

[back to content](#content)

---



<h3 id="los"># Lifecycle of Servlet</h3>

Lifecycle of Servlet

- Servlet class loaded.
- Servlet instance created.
- init() method is invoked. Initializes the servlet.
- service() method invoked.
- destroy() method invoked.

**Details of Lifecycle of Servlet**

Servlet class loaded

- Servlet class loaded is on application startup or at the first time when the servlet is invoked.
- The classloader is responsible to load the servlet class. The servlet class is loaded when the first request for the servlet is received by the web container.
- using <load-on-startup>, you can be sure that your servlets will be loaded when the app is starting up and be available.

Servlet instance created

- The web container creates the instance of a servlet after loading the servlet class. The servlet instance is created only once in the servlet life cycle.

init method is invoked

- The web container calls the init method only once after creating the servlet instance. The init method is used to initialize the servlet. 

service method is invoked

- The web container calls the service method each time when request for the servlet is received. If servlet is not initialized, it follows the first three steps as described above then calls the service method. If servlet is initialized, it calls the service method. Notice that servlet is initialized only once.

destory method is invoked

- All the Servlet instances are destroyed when server is shutting down or on application disposal call it destroy() method.
- The web container calls the destroy method before removing the servlet instance from the service. It gives the servlet an opportunity to clean up any resource for example memory, thread etc.
- You can't destroy the Servlet manually and Servlet is just like worker not for data container. 



References

- [Life Cycle of a Servlet](https://www.javatpoint.com/life-cycle-of-a-servlet)

- [When exactly a servlet is destroyed?](https://stackoverflow.com/questions/24832470/when-exactly-a-servlet-is-destroyed)

[back to content](#content)

---



<h3 id="for"># Flow of Request in Servlet</h3>

**Flow of request**

- Client sends HTTP request to Web server
- Web server forwards that HTTP request to web container.
- Since Servlet can not understand HTTP, its a Java program, it only understands objects, so web container converts that request into valid request object
- Web container spins a thread for each request
- All the business logic goes inside doGet() or doPost() callback methods inside the servlets
- Servlet builds a Java response object and sends it to the container. It converts that to HTTP response again to send it to the client

**How does the Container know which Servlet client has requested for?**

- There’s a file called web.xml
- This is the master file for a web container
- You have information about servlet in this file-
  - servlets
    - Servlet-name
    - Servlet-class
  - servlet-mappings \- the path like /Login or /Notifications is mapped here in
    - Servlet-name
    - url-pattern
  - and so on
- Every servlet in the web app should have an entry into this file
- So this lookup happens like- url-pattern -> servlet-name -> servlet-class



[back to content](#content)

---



<h3 id="sic"""># Servlet Interfaces And Implementation Class</h3>

[back to content](#content)

---

### Tomcat

<h3 id="wit"># What is Apache Tomcat</h3>



[`back to content`](#content)

---

<h3 id="aat"># Apache HTTP Server and Apache Tomcat</h3>

Difference between the Apache HTTP Server and Apache Tomcat

[back to content](#content)

---

<h3 id="was"># Web Servers and Servlet Containers</h3>

What are differences between web servers and servlet containers

- Web Server(HTTP Server): A server which is capable of handling HTTP requests, sent by a client and respond back with a HTTP response.
- Web Container or Servlet Container or Servlet Engine : is used to manage the components like Servlets, JSP. It is a part of the web server.

[back to content](#content)

---

### JDBC

<h3 id="til"># Transaction Isolation Levels</h3>



| Level                | **dirty reads** | **non-repeatable reads** | **phantom reads** |
| -------------------- | --------------- | ------------------------ | ----------------- |
| **READ_UNCOMMITTED** | yes             | yes                      | yes               |
| **READ_COMMITTED**   | no              | yes                      | yes               |
| **REPEATABLE_READ**  | no              | no                       | yes               |
| **SERIALIZABLE**     | no              | no                       | no                |

READ_UNCOMMITTED: 读未提交，即能够读取到没有被提交的数据.
READ_COMMITTED: 读已提交，即能够读到那些已经提交的数据.
REPEATABLE_READ: 数据读出来之后加锁,防止别人修改它。
SERLALIZABLE: 串行化，最高的事务隔离级别，不管多少事务，挨个运行完一个事务的所有子事务之后才可以执行另外一个事务里面的所有子事务.

[`back to content`](#content)



### HTTP



### Spring Framework

<h3 id="sta"># Spring Transaction accomplishment principles</h3>

- How @transactional work in spring?

### Spring Boot

### # What is Spring Boot

简化基于spring项目的配置。

### # Spring Boot features or goals

Advantages

- 简化配置，快速开始开发。没有繁琐的配置，专注于业务开发。

- 内置tomcat和jetty容器，可以直接启动。

- 没有代码生成和xml配置

Shortcomings

### # Spring Boot 实现原理

在pom.xml文件中把spring boot 作为parent父项目。

```java
	<!-- Inherit defaults from Spring Boot -->
	<parent>
		<groupId>org.springframework.boot</groupId>
		<artifactId>spring-boot-starter-parent</artifactId>
		<version>1.5.9.RELEASE</version>
		<relativePath/>
	</parent>
	
	<!-- Add typical dependencies for a web application -->
	<dependencies>
		<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-starter-web</artifactId>
		</dependency>
	</dependencies>
	
    <!-- Package as an executable jar -->
	<build>
		<plugins>
			<plugin>
				<groupId>org.springframework.boot</groupId>
				<artifactId>spring-boot-maven-plugin</artifactId>
			</plugin>
		</plugins>
	</build>
```

### # Spring Boot Configuration 

.properties or .yml

1).properties

```
app.user.name = javastack
```

2).yml

```
app:
    user:
        name: javastack
```

主要配置

application.yml:

```java
server:
  session-timeout: 1800
  tomcat:
      uri-encoding: UTF-8

security:
  basic:
    enabled: false
sms:
  isOpen: false
spring:
  thymeleaf:
    mode: LEGACYHTML5
    cache: false
    encoding: UTF-8
    content-type: text/html; charset=utf-8
  jackson:
    time-zone: GMT+8
    date-format: yyyy-MM-dd HH:mm:ss
  profiles: 
    active: dev
  http:
    multipart:
      max-file-size: 30Mb
      max-request-size: 30Mb
    encoding:
      force: true
      charset: utf-8
      enabled: true  
mybatis: 
  configuration:
    map-underscore-to-camel-case: true
  mapper-locations: mybatis/**/*Mapper.xml
  typeAliasesPackage: com.wiiun.training.**.domain


```

application-pro.yml

```java
training:
  uploadPath : C:/Tools/apache-tomcat-8.0.23/files/admin/upload/
  isForTest: true
  prePicture: /files/picture/
  host: http://www.ruixinyingyu.com/admin
  apiHost: http://www.ruixinyingyu.com/api
  sms:
    uri: http://login.qianjingtong.cn/msg/HttpBatchSendSM
logging:
  level:
    com.wiiun.training: debug
spring:
  http:
    multipart:
      max-file-size: 100Mb
      max-request-size: 100Mb
  thymeleaf:
    cache: false
    encoding: UTF-8
    content-type: text/html; charset=utf-8
  datasource:
    type: com.alibaba.druid.pool.DruidDataSource
    driverClassName: com.mysql.jdbc.Driver
    url: jdbc:mysql://127.0.0.1:3306/training?allowMultiQueries=true&useUnicode=true&characterEncoding=utf8
    username: training
    password: 2AvDywXxeyTB8Zab
    initialSize: 1
server:
  port: 80

    # 合并多个DruidDataSource的监控数据
    #useGlobalDataSourceStat: true

```



### Hibernate



### MyBatis

