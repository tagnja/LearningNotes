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
    - Servlet Collaboration
    - Sharing Information like Session & Cookie
    - Session Tracking
    - Filter and Listener
    - How to use session when client ban cookie
    - Uploading Files
    - Asynchronous Processing and Nonblocking I/O
  - JSP
    - include(), forward(), redirect
- JDBC
  - [Transaction Isolation Levels](#til)
- Apache Tomcat
  - [What is Apache Tomcat](#wit)
  - [Apache HTTP server and Apache Tomcat](#aat)
  - [Web Servers and Servlet Containers](#was)
- Web Server
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
- ORM Framework
- Hibernate
  - What is Hibernate
    - What are Configuration files in Hibernate
  - MyBatis
  
    - What is MyBatis
    - What are Configuration files in MyBatis
    - What is differences between MyBatis and Hibernate
    - Why the Dao Interface can mapper its mapper.xml
- Restful
- Web Service
- Cache
- Web Security
  - OAuth
  - Shiro
  - Spring Security

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

**Lifecycle of Servlet**

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

**Advantage of load-on-startup element**

- As you know well, servlet is loaded at first request. That means it consumes more time at first request. If you specify the load-on-startup in web.xml, servlet will be loaded at project deployment time or server start. So, it will take less time for responding to first request.
- If you pass the positive value, the lower integer value servlet will be loaded before the higher integer value servlet. In other words, container loads the servlets in ascending integer value. The 0 value will be loaded first then 1, 2, 3 and so on.

```java
  <servlet>  
     <servlet-name>servlet1</servlet-name>  
     <servlet-class>com.javatpoint.FirstServlet</servlet-class>  
     <load-on-startup>0</load-on-startup>  
  </servlet> 
```



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

**Server-side Java stack**

- Hardware
  - Firmware
    - Operating System
      - Java Virtual Machine
        - Java Server
          - Your Java Application
          - Servlet API

References

- [What is a Java servlet? Request handling for Java web applications - JavaWorld](https://www.javaworld.com/article/3313114/what-is-a-java-servlet-request-handling-for-java-web-applications.html)



[back to content](#content)

---



<h3 id="sic"""># Servlet Interfaces And Abstract Classes</h3>

Servlet Interfaces

```java
I-Servlet
	*-GenericSevlet implements Servlet, ServletConfig
		*-HttpServlet extends HttpServlet
I-ServletRequest
	I-HttpServletRequest extends ServletRequest
		HttpServletRequestWrapper implements HttpServletRequest
I-ServletResponse
	I-HttpServletResponse 
I-RequestDispatcher
I-ServletConfig
I-HttpSession
I-ServletContext
I-java.util.EventListener
	I-javax.servlet.ServletContextListener
	I-HttpSessionListener
	I-ServletRequestListener
I-Filter
I-FilterChain
I-FilterConfig
```

**Servlet Interface**

- Servlet interface needs to be implemented for creating any servlet (either directly or indirectly). It provides 3 life cycle methods that are used to initialize the servlet, to service the requests, and to destroy the servlet and 2 non-life cycle methods.

- ```java
  void init(ServletConfig config);
  void service(ServletRequest request, ServletResponse response);
  void destory();
  ServletConfig getServletConfig();
  String getServletInfo();
  ```

**GenericServlet Abstract class**

- GenericServlet class implements Servlet, ServletConfig and Serializable interfaces. It provides the implementation of all the methods of these interfaces except the service method. GenericServlet provides simple versions of the life-cycle methods init and destroy and of the methods in the ServletConfig interface.
- GenericServlet class can handle any type of request so it is protocol-independent.
- You may create a generic servlet by inheriting the GenericServlet class and providing the implementation of the service method. To write a generic servlet, it is sufficient to override the abstract service() method.

**HttpServlet Abstract class**

- The HttpServlet class extends the GenericServlet class and implements Serializable interface. It provides http specific methods such as doGet, doPost, doHead, doTrace etc.\

**GenericServet VS HttpServlet**

- the Servlet class doesn't know about any protocols. It is the HttpServlet that understands the HTTP protocol. A SMTPServlet would override the service() method of Servlet to handle, for example, the MAIL, RCPT, and DATA SMTP "verbs" - maybe with a doMail(), doRecipient(), and doData(). There would likely be other methods to handle the protocol. But the interaction would be protocol specific - thus the generic base class and protocol specific child class.

**ServletRequest Interface**

- An object of ServletRequest is used to provide the client request information to a servlet such as content type, content length, parameter names and values, header informations, attributes etc.

**ServletResponse**

**ServletConfig**

- An object of ServletConfig is created by the web container for each servlet. This object can be used to get configuration information from web.xml file.

- If the configuration information is modified from the web.xml file, we don't need to change the servlet. So it is easier to manage the web application if any specific content is modified from time to time.

- The core advantage of ServletConfig is that you don't need to edit the servlet file if information is modified from the web.xml file.

- ```
    <servlet> 
    	......  
      <init-param>  
        <param-name>parametername</param-name>  
        <param-value>parametervalue</param-value>  
      </init-param>  
      ......  
    </servlet>  
  ```

**HttpSession**

- Session simply means a particular interval of time.
- Session Tracking is a way to maintain state (data) of an user. It is also known as session management in servlet.
- Http protocol is a stateless so we need to maintain state using session tracking techniques. Each time user requests to the server, server treats the request as the new request. So we need to maintain the state of an user to recognize to particular user.

**ServletContext**

- An object of ServletContext is created by the web container at time of deploying the project. This object can be used to get configuration information from web.xml file. There is only one ServletContext object per web application.

- If any information is shared to many servlet, it is better to provide it from the web.xml file using the **<context-param>** element.

- Easy to maintain if any information is shared to all the servlet, it is better to make it available for all the servlet. We provide this information from the web.xml file, so if the information is changed, we don't need to modify the servlet. Thus it removes maintenance problem.

- ```java
  <web-app>  
   ......  
    <context-param>  
      <param-name>parametername</param-name>  
      <param-value>parametervalue</param-value>  
    </context-param>  
   ......  
  </web-app>  
  ```

- ```java
  ServletContext application=getServletConfig().getServletContext();  
  ```

**ServletContextListener**

- Events are basically occurrence of something. Changing the state of an object is known as an event.

- We can perform some important tasks at the occurrence of these exceptions, such as counting total and current logged-in users, creating tables of the database at time of deploying the project, creating database connection object etc.

- There are many Event classes and Listener interfaces in the javax.servlet and javax.servlet.http packages.

- ```java
  <web-app>
  	<listener>
  		<listener-class>com.wiiun.petkit.web.listener.MyServletContextListener</listener-class>
  	</listener>
  </web-app>  
  ```

**Filter**

- A filter is an object that is invoked at the preprocessing and postprocessing of a request.

- It is mainly used to perform filtering tasks such as conversion, logging, compression, encryption and decryption, input validation etc.

- The servlet filter is pluggable, i.e. its entry is defined in the web.xml file, if we remove the entry of filter from the web.xml file, filter will be removed automatically and we don't need to change the servlet.

- ```java
  <web-app>  
    
  <filter>  
  <filter-name>...</filter-name>  
  <filter-class>...</filter-class>  
  </filter>  
     
  <filter-mapping>  
  <filter-name>...</filter-name>  
  <url-pattern>...</url-pattern>  
  </filter-mapping>  
    
  </web-app>  
  ```

****

References

- [Servlet Interface - javaTpoint](https://www.javatpoint.com/Servlet-interface)

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
