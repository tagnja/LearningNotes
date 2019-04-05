# Top Java Questions You Must Know

<h3 id="content">Content</h3>

- Basics
  - [Differences between JDK, JRE and JVM?](#dbj)
  - Java every version features?
  - [int vs Integer?](#ivi)
  - [equals vs == in String](#ev=)
  - [Function value passing or reference passing](#fvp)
  - [String, StringBuider, StringBuffer](#sss)
- Classes
  - Object-oriented design principles?
  - Java Object Creation Process in run-time memory.
  - [Package access](#pa)
  - [instanceof in Polymorphism](#iip)
  - [Polymorphism function calling](#pfc)
  - [Process of Object instance  in extends](#poo)
  - [Nested Exception Run Sequence](#ner)
- Container
- Library
- Advanced
  - 
- Design Pattern
  - [Common Design Patterns](#cdp)
- JVM
  - [How java works?](#hjw)
  - Java Run-time memory
  - JVM Specification concepts?
  - JVM configurations?
  - JVM Optimizations?
- Concurrency
  - [synchronized](#sync)
  - [Thread Pool](#tp)
  - [Thread Deadlock](#tdk)

### Main

### Basic



<h3 id="dbj"># Differences between JDK, JRE and JVM?</h3>

JVM(Java Virtual Machine)

- Specification, implementation, and instance.

- JVM Tasks: Loads code(class file), Verifies code, Executes code, Provides runtime environment.

JRE(Java Runtime Environment)

- It is a set of software tools.
- It provides the runtime environment.
- It is the implementation of JVM. It physically exists.
- It contains a set of libraries + other files that JVM users at runtime.

JDK(Java Development Kit)

- It contains JRE + development tools(javac, java, jar, javadoc etc)

Reference:

[Difference between JDK, JRE, and JVM](https://www.javatpoint.com/difference-between-jdk-jre-and-jvm)

[`back to content`](#content)



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id="ivi"># int vs Integer</h3>

Java supprots Auto boxing and Auto unboxing.

```java

Integer i = 1; // actual is Integer i = Integer.valueOf(1);
int j = i; // actual is int j = i.intValue();
```
Sources View

```java
Integer.class
public final class Integer extends Number implements Comparable<Integer> {
    private final int value;
    public Integer(int value) {
        this.value = value;
    }
    public static Integer valueOf(int i) {
        if (i >= IntegerCache.low && i <= IntegerCache.high)
            return IntegerCache.cache[i + (-IntegerCache.low)];
        return new Integer(i);
    }
    public int intValue() {
        return value;
    }
}

Integer$IntegerCache.class

private static class IntegerCache {
    static final int low = -128;
    static final int high; // high value may be configured by property, default 127.
    static final Integer cache[];
    static{
        ...
        int h = 127;
    	String integerCacheHighPropValue =
                sun.misc.VM.getSavedProperty("java.lang.Integer.IntegerCache.high");
        for(int k = 0; k < cache.length; k++)
                cache[k] = new Integer(j++);
        assert IntegerCache.high >= 127;
    }
}

```

> cache of Byte, Short, Integer, Long all is between -128~127. Only Integer cache max value can set over 127.


__Interger == Integer  Example__

```java

Integer a1 = 1;
Integer a2 = 1;
Integer b1 = 128;
Integer b2 = 128;

a1 == a2 // true
b1 == b2 // false

```

>  key point : Integer == Integer contrast is reference address. IntegerCache affected the result.



__Integer == int or int == Integer Example__

```java
Integer a1 = 1;
Integer a2 = 128;
int b1 = 1;
int b2 = 128;

a1 == b1 // true
a2 == b2 // true
```

>  key point : int == Integer contrast is numeric value. Integer will auto unbox. It always == is true.

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id="ev="># equals vs == in String</h3>



```java
String a1 = "hello";
String a2 = "he" + "llo";
String b1 = new String("hello");
String b2 = "he" + new String("llo");
String b3 = new String("he") + "llo";
String b4 = new String("hello");
System.out.println(a1 == a2); // true
System.out.println(a1 == b*); // false
System.out.println(b* == b*); // false
System.out.println(b*.equals(*)); // true
/*
	new String("xxx")    // string store in heap.
	"xxx"                // store in String static pool, no repeat string in there.
	new String("xxx") + "xxx"  // 
*/
```

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id="fvp"># Function value passing or reference passing</h3>

Data Type consist of primitive data type and reference type.

Primitive Types: byte, short, int, long, float, double, boolean, char.

Reference Types: array, Object, String. WrapperClass Object

__Value passing: all of primitive types, String, all of wrapperClass Object__

__Reference passing: array, Object (Exclude String, WrapperClass)__

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3 id="sss"># String, StringBuider, StringBuffer</h3>


immutable

- Their accomplishment all are  by char array.
- String is immutable whereas StringBuffer and StringBuilder are mutable classes. 
- String concat operation uses StringBuilder or StringBuffer better than String.

Thread Safety

- StringBuffer is thread safe and synchronized whereas StringBuilder is not. StringBuilder is more faster than StringBuffer.
- non-multi threaded environment uses StringBuilder better than StringBuffer.

References:

<https://www.journaldev.com/538/string-vs-stringbuffer-vs-stringbuilder>



[`back to content`](#content)



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



### Classes


<h3 id="pa"> # Package Access</h3>

Key Wrods | Class | Pacakage | Not Package but Sub | Not Package not sub 
--- | --- | --- | --- | ---
private        | √ | × | × | × | 
default        | √ | √ | × | × | 
protected    | √ | √ | √ | × | 
public         | √ | √ | √ | √ | 

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




<h3 id="iip">#  instanceof in Polymorphism</h3>



```java
class A{}
class B extends A{}
class C extends A{}
class D extends B{}

A obj = new D();
System.out.println(obj instanceof B); // true
System.out.println(obj instanceof C); // false
System.out.println(obj instanceof D); // true
System.out.println(obj instanceof A); // true

```

[`back to content`](#content)



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



<h3 id="pfc"># Polymorphism function calling</h3>

```java
public class A {
    public String show(D obj) {
        return ("A and D");
    }
    public String show(A obj) {
        return ("A and A");
    } 
}

public class B extends A{
    public String show(B obj){
        return ("B and B");
    }
    public String show(A obj){
        return ("B and A");
    } 
}

public class C extends B{
}

public class D extends B{
}

public class Test {
    public static void main(String[] args) {
        A a1 = new A();
        A a2 = new B();
        B b = new B();
        C c = new C();
        D d = new D();
        
        System.out.println("1--" + a1.show(b));
        System.out.println("2--" + a1.show(c));
        System.out.println("3--" + a1.show(d));
        System.out.println("4--" + a2.show(b));
        System.out.println("5--" + a2.show(c));
        System.out.println("6--" + a2.show(d));
        System.out.println("7--" + b.show(b));
        System.out.println("8--" + b.show(c));
        System.out.println("9--" + b.show(d));    
    }
}
运行结果为：
1--A and A
2--A and A
3--A and D
4--B and A
5--B and A
6--A and D
7--B and B
8--B and B
9--A and D
```

Match Sequence

```java
A a1 = new A();
A a2 = new B();
B b = new B();
```

Super type and super Object - a1：(1)Only find in super. (2)call in super

Super type and son Object - a2: (1)only find in super. (2)First call in son.if not exist in son, then call super.

Son type and son object - b: (1)First find in son, then find in super. (2)Find just call.

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



<h3 id="poo">#Process of Object instance  in extends</h3>



```java
public class Parent {
	private String name = "parent";
	public Parent()
	{
		System.out.println("Parent constructor...");
		print();
	}
	
	public void print()
	{
		System.out.println("Parent print...");
		System.out.println("name=" + name);
	}
}

public class Son extends Parent{
	private String name = "son";
	
	public Son()
	{
		System.out.println("Son constructor..");
	}
	
	public void print()
	{
		System.out.println("Son print..");
		System.out.println("name=" + this.name);
	}
}

public static void main(String[] args)
{
    Parent parent = new Son();
}
```

What is the main function print result?

```java
Parent Constructor...

Son print...

name=null   // When son print() execute by Polymorphism, but instance variales are not initialize and the Son contructor not execute. 

Son Constructor...
```







[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



<h3 id="ner"># Nested Exception Run Sequence</h3>

The finally not must run. using System.exit(0) in try or catch block.

```java
 try
 {
     System.out.println("try...");
     System.exit(0);
 }
 finally
 {
     System.out.println("finally...")
 }
```

Nested exception run example

```java
try
{
	try
	{
		System.out.println("try...");
		int i = 1/0;
	}
	catch (NullPointerException e )
	{
		System.out.println("catch...");
	}
	finally
	{
		System.out.println("finally...");
	}
}
catch(Exception e) 
{
	System.out.println("base catch...");
}
finally
{
	System.out.println("base finally...");
}
/* 
	try...
  	finally...
   	base catch..
   	base finally..
 */
```

`try` - `try` execute until the last executable line.

`catch` - It can execute outside `catch` block if inside `catch` can't catch the exception.

`finally` - all `finally` block must execute from inside to outside.

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### Advanced




### JVM



<h3 id="hjw"># How Java Works</h3>

Javac convert source code => bytecode file

JVM Class Loader loading bytecode to memory, Byte Code Verifier verifying bytecode, Execution Engine convert bytecode file => machine code

Most Computer languages use the "compile-link-execute" format.

[`back to content`](#content)



### Design Patterns

<h3 id="cdp"># Common Design Patterns</h3>

(Composite, Strategy, Decorator, Abstract Factory, Bridge, )

- Create Patterns

  - __Abstract Factory__
  - __Builder__
  - __Factory Method__
  - Prototype
  - __Singleton__

- structural Patterns

  - Adapter
  - __Bridge__
  - __Composite__
  - __Decorator__
  - Facade
  - Flyweight
  - __Proxy__

- Behavioral patterns

  - Chain of Responsibility
  - Command
  - Interpreter
  - Iterator
  - Mediator
  - Memento
  - Observer
  - State
  - __Strategy__
  - Template Method
  - Visitor

  

### Concurrency

### 

<h3 id="sync"># synchronized</h3>

synchronized:

- 被synchronized修饰的代码，多个线程使用相同的synchronized锁，只能同时被一个线程执行。
- 同步锁，可以是类级别的（调用一个类的静态方法互斥），可以是对象级别的（调用同一个对象的方法互斥）。

```java
public class Demo{
    // this static method can be executed by one thread execute at a time. The lock is Demo.class.
    public synchronized static void foo(){
        
    }
}

public class Demo {
    // this instatnce method can be executed by one thread execute at a time when multiple thread using same object. The lock is this.
    public synchronized void foo(){
        
    }
}

public class Test implements Runnable{
    @Override
    public void run(){
        synchronized (Demo.class){
            Demo.foo(); // when one thread execute this line, get the lock, Other thread can't enter synchronized block.
        }
    }
} 

public class Test implements Runnable{
    private Demo demo;
    
    public Test(Demo demo)
    {
        this.demo = demo;
    }
    
    @Override
    public void run()
    {
        synchronized (demo){
            demo.foo(); // when one thread execute this line, get the lock, Other thread uses same demo object, can't enter synchronized block.
        }
    }
}

```



<h3 id="tp"># Thread Pool</h3>

What is Thread Pool

- It manages the pool of worker threads.
- It contains a queue that keeps tasks waiting to get executed.

Why use thread pool

- Focus on the tasks. you want the thread to perform instead of thread mechanics.
- Easy to manage tasks to perform.
- Solution for the problem of thread cycle overhead. (Repeating create and destroy thread)
- Solution for the problem of resource thrashing(if every request create a new thread, too many threads cause system to run out of memory).

How to use thread pool

- Java provides the Executor framework which is centered around the Executor interface.

```java
java.lang
		class-Thread
		interface-Runnable
java.util.concurrent
        interface-Executor
            interface-ExecutorService
                *class-AbstractExecutorService
                    class-ThreadPoolExecutor
                        class-ScheduleThreadPoolExecutor
                    class-ForkJoinPool
                interface-ScheduleExecutorService
                        class-ScheduleThreadPoolExecutor
        
        class-Executors
		interface-Future
			*class-ForkJoinTask
				*class-RecursiveTask
		interface-Callable
```

- Executor 

its sub-interface-ExecutorService, class-ThreadPoolExecutor, class-ScheduledThreadPoolExecutor.

- Executors 

It is a utility class that provices useful methods to work with ExecutorService, ScheduleExecutorService, ThreadFactory, and Callable classes through various factory methods.

```java
class-Executors methods
    public static ExecutorService newSingleThreadExecutor() {
        return new FinalizableDelegatedExecutorService
            (new ThreadPoolExecutor(1, 1,
                                    0L, TimeUnit.MILLISECONDS,
                                    new LinkedBlockingQueue<Runnable>()));
    }
    public static ExecutorService newFixedThreadPool(int nThreads) {
        return new ThreadPoolExecutor(nThreads, nThreads,
                                      0L, TimeUnit.MILLISECONDS,
                                      new LinkedBlockingQueue<Runnable>());
    }
    public static ExecutorService newCachedThreadPool() {
        return new ThreadPoolExecutor(0, Integer.MAX_VALUE,
                                      60L, TimeUnit.SECONDS,
                                      new SynchronousQueue<Runnable>());
    }
    public ScheduledThreadPoolExecutor(int corePoolSize) {
        super(corePoolSize, Integer.MAX_VALUE, 0, NANOSECONDS,
              new DelayedWorkQueue());
    }
class-ThreadPoolExecutor
    public ThreadPoolExecutor(int corePoolSize, int maximumPoolSize, 
    	long keepAliveTime, TimeUnit unit, BlockingQueue<Runnable> workQueue)
	{
    	this(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue,
             Executors.defaultThreadFactory(), defaultHandler);
	}
```

- Callable

It java 5 introduced java.util.concurrenct.Callable interface. It is similar to Runnable interface, but it can return any Object and able to throw Exception.

- Future

Java Callable tasks return java.utl.concurrent.Future object. It provide get() method get the Callable task return Object.

Using Example

Single Thread Pool by Executor Example

```java
    Executor executor = Executors.newSingleThreadExecutor();
    executor.execute(() -> System.out.println("Hello World")); // Runnable
	executor.shutdown();
```



Fixed Thread Pool by Executors Example

```java
    ExecutorService executor = Executors.newFixedThreadPool(5);
    for (int i=0; i < 10; i++)
    {
        executor.execute(new Runnable()
        {
            @Override
            public void run(){
                System.out.println(Thread.currentThread().getName() + " start...");
                Thread.sleep(3000);
                System.out.println(Thread.currentThread().getName() + " end");
            }
        });
    }
    executor.shutdown();
    while (! executor.isTerminated()) {
    }
    System.out.println("Finished all threads");
```

Fixed Thread Pool by ThreadPoolExecutor Example

```java
    ThreadPoolExecutor executor = new ThreadPoolExecutor(10, 10,
        0L, TimeUnit.MILLISECONDS,
        new LinkedBlockingQueue<Runnable>());
    for (int i=0; i < 10; i++)
    {
        executor.execute(new Runnable() {
            @Override
            public void run() {
                System.out.println("hh");
            }
        });
    }
    executor.shutdown();
    while (! executor.isTerminated()) {
    }
    System.out.println("Finished all threads");
```

Callable & Future Example

```java
    ExecutorService executor = Executors.newFixedThreadPool(10);
    Callable<String> callable = new Callable<String>(){
        @Override
        public String call() throws Exception {
            Thread.sleep(1000);
            return Thread.currentThread().getName();
        }
    };
    for (int i=0; i < 100; i++){
        Future<String> future = executor.submit(callable);
        System.out.println(future.get());
    }
    executor.shutdown();
    while (! executor.isTerminated()){
    }
    System.out.println("Finished all threads");

 	ExecutorService executorService = Executors.newFixedThreadPool(10);
    Future<String> future = executorService.submit(() -> "Hello World"); //Callable
    String result = future.get();
	executor.shutdown();
```



[`back to content`](#content)



<h3 id="tdk">Thread Deadlock</h3>

What is deadlock

A situation where two or more threads are blocked forever, waiting for each other.

```java
	static Object lock1 = new Object();
	static Object lock2 = new Object();
	public static void main(String[] args) throws InterruptedException, ExecutionException
	{
		new Thread(new Runnable() {
			@Override
			public void run()
			{
				synchronized(lock1)
				{
					System.out.println(Thread.currentThread().getName() + "hold lock1...");
					sleep();
					synchronized(lock2)
					{
						System.out.println(Thread.currentThread().getName() + "hold lock2...");
						sleep();
					}
				}
			}
		}).start();
		new Thread(new Runnable() {
			@Override
			public void run()
			{
				synchronized(lock2)
				{
					System.out.println(Thread.currentThread().getName() + "hold lock2...");
					sleep();
					synchronized(lock1)
					{
						System.out.println(Thread.currentThread().getName() + "hold lock1...");
						sleep();
					}
				}
			}
		}).start();
	}
```



[`back to content`](#content)

--END--