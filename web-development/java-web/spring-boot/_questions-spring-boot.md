# Questions of Spring Boot

### Content

- What does spring-boot-starter-parent exactly do in pom file
- What is the function of spring-boot-starter-web  dependency



### Main



### What does spring-boot-starter-parent exactly do in pom file

Such as

```xml
<parent>
	<groupId>org.springframework.boot</groupId>
	<artifactId>spring-boot-starter-parent</artifactId>
	<version>2.1.6.RELEASE</version>
</parent>
```

or

```xml
<dependency>
	<groupId>org.springframework.boot</groupId>
	<artifactId>spring-boot-dependencies</artifactId>
	<version>2.1.6.RELEASE</version>
	<type>pom</type>
	<scope>import</scope>
</dependency>
```

- It provides place for common configuration for `CHILD POM`s.
- The `spring-boot-starter-parent` as parent or dependency is the parent POM providing dependency and plugin management for Spring Boot-based applications. It contains the default versions of Java to use, the default versions of dependencies that Spring Boot uses, and the default configuration of the Maven plugins. 
- complete configuration of spring-boot-starter-parent  refer to [spring-boot-starter-parent/pom.xml](https://github.com/spring-projects/spring-boot/blob/master/spring-boot-project/spring-boot-starters/spring-boot-starter-parent/pom.xml)

References

[What does spring-boot-starter-parent exactly do in pom file? - stack overflow](https://stackoverflow.com/questions/43305016/what-does-spring-boot-starter-parent-exactly-do-in-pom-file)]

[Spring-boot-starter-parent Example](https://howtodoinjava.com/spring-boot2/spring-boot-starter-parent-dependency/)

Spring boot reference documentation

---

### What is the function of spring-boot-starter-web  dependency

It provides common configuration and dependencies for current project.

complete configuration of spring-boot-starter-web  refer to [spring-boot-starter-web/pom.xml](https://github.com/spring-projects/spring-boot/blob/master/spring-boot-project/spring-boot-starters/spring-boot-starter-web/pom.xml)