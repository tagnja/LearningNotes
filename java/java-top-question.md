# Java Top Questions You Must Know

<h3 id="content">Content</h3>

- I. Basics
  - [Differences between JDK, JRE and JVM?](#dbj)
  - [ ] Java every version features?
  - [int vs Integer?](#ivi)
  - [equals vs == in String](#ev=)
  - [Function value passing or reference passing](#fvp)
  - [String, StringBuider, StringBuffer](#sss)
- II. Classes
  - [ ] Object-oriented design principles?
  - [Package access](#pa)
  - [instanceof in Polymorphism](#iip)
  - [Function Calling in Polymorphism](#pfc)
  - [Object Instantiating in Polymorphism](#poo)
- III. Library & Advanced
  - [ ] [Common Exceptions](#ces)
  - [Nested Exception Run Sequence](#ner)
  - [ ] [Common IO Stream](#cis)
  - [ ] IO Common Operations
  - [ ] Common Container Class
  - [ ] Thread Safe Container  and Thread-Safe 
- IV. JVM
  - [How java works?](#hjw)
  - [Class Loading Process](#clp)
  - [Java Object Creation Process](#joc)
  - [Java Run-time memory](#jrm)
  - [JVM Configurations](#jcs)
  - [ ] [JVM Optimizations](#jos)
- V. Concurrency
  - [synchronized](#sync)
  - [Thread Pool](#tp)
  - [ ] Thread Class Common Methods
  - [Thread Deadlock](#tdk)
- VI. Design Pattern
  - [ ] [Common Design Patterns](#cdp)

### Main



### I. Basic



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

---



### II. Classes




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
System.out.println(obj instanceof B); 
System.out.println(obj instanceof C); 
System.out.println(obj instanceof D); 
System.out.println(obj instanceof A); 

/* 
result:
    true
    false
    true
    true
*/
```

[`back to content`](#content)



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



<h3 id="pfc"># Function Calling in Polymorphism </h3>

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

__Consequences__

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



<h3 id="poo"># Object Instantiating in Polymorphism</h3>



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

---



### III. Library & Advanced


<h3 id="ces"># Common Exceptions</h3>


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

__Consequences__

`try` - `try` execute until the last executable line.

`catch` - It can execute outside `catch` block if inside `catch` can't catch the exception.

`finally` - all `finally` block must execute from inside to outside.

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




<h3 id="cis"># Common IO Stream</h3>

| classify | function       | byte input           | byte output          | char reader         | char writer         |
| -------- | -------------- | -------------------- | -------------------- | ------------------- | ------------------- |
|          | 抽象基类       | InputStream          | OutputStream         | Reader              | Writer              |
| 节点流   | 访问文件       | FileInputSream       | FileOutputStream     | FileReader          | FileWriter          |
|          | 访问数值       | ByteArrayInputStream | ByteArrayOutStream   | **CharArrayReader** | **CharArrayWriter** |
|          | 访问管道       | PipedInputStream     | **PipedOutStream**   | **PipedReader**     | **PipedWriter**     |
|          | 访问字符串     |                      |                      | **StringReader**    | **StringWriter**    |
| 处理流   | 缓冲流         | BufferedInputStream  | BufferedOutputStream | BufferedReader      | BufferedWriter      |
|          | 转换流         |                      |                      | InputStreamReader   | OutputStreamWriter  |
|          | 对象流         | ObjectInputStream    | ObjectOutputStream   |                     |                     |
|          | (过滤)抽象基类 | FilterInputStream    | *FilterOutputStream* | *FilterReader*      | *FilterWriter*      |
|          | 打印流         |                      | PrintStream          |                     | PrintWriter         |
|          | 退回输入流     | PushBackInputStream  |                      | PushbackReader      |                     |
|          | 特殊流         | DataInputStream      | DataOutputStream     |                     |                     |

__Consequences__

1. Java IO是采用的是装饰模式，即采用**处理流**来包装**节点流**的方式，来达到代码通用性。

2. 处理流和节点流的区分方法，**节点流**在新建时需要一个数据源（文件、网络）作为参数，而**处理流**需要一个节点流作为参数。

3. **处理流**的作用就是提高代码通用性，编写代码的便捷性，提高性能。

4. **节点流**都是对应抽象基类的实现类，它们都实现了抽象基类的基础读写方法。其中read（）方法如果返回-1，代表已经读到数据源末尾。

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



<h3 id=""># IO Common Operations</h3>

read byte/char from stream

write byte[]/char to stream

```java
try (
	BufferedInputStream bis = new BufferedInputStream(new FileInputStream("D:/test.txt"));
	BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream("D:/test2.txt"));
)
{
	StringBuilder sb = new StringBuilder();
	
	// byte[] IO
	byte[] buf = new byte[20];
	int len = -1;
	while ((len = bis.read(buf)) != -1)
	{
		bos.write(buf, 0, len);
		bos.flush();
		sb.append(new String(buf, 0, len, StandardCharsets.UTF_8));
	}
	
	
	// char IO
	/*int ch = -1;
	char[] c = new char[1];
	while ((ch = bis.read()) != -1)
	{
		bos.write(ch);
		bos.flush();
		c[0] = (char)ch;
		sb.append(c);
	}*/
	
	System.out.println(sb.toString());
} catch (FileNotFoundException e) {
	e.printStackTrace();
} catch (IOException e) {
	e.printStackTrace();
}
```

read char from stream 

write char to stream

```java
try (
	BufferedReader br = new BufferedReader(new FileReader("D:/test.txt"));
	BufferedWriter bw = new BufferedWriter(new FileWriter("D:/test2.txt"));
)
{
	StringBuilder sb = new StringBuilder();
	
	// string io
	/*String buf = null;
	while ((buf = br.readLine()) != null)
	{
		buf += "\r\n";
		bw.write(buf);
		sb.append(buf);
	}*/
	
	// char[] IO
	char[] buf = new char[1024];
	int len = 0;
	while ((len = br.read(buf)) != -1)
	{
		bw.write(buf, 0, len);
		sb.append(buf, 0, len);
	}
	
	// char IO
	/*int c = -1;
	char[] str = new char[1];
	while ((c = br.read()) != -1)
	{
		bw.write(c);
		str[0] = (char) c;
		sb.append(str);
	}*/
	
	System.out.println(sb.toString());
} catch (FileNotFoundException e) {
	e.printStackTrace();
} catch (IOException e) {
	e.printStackTrace();
}
```

read object from stream

write object to stream

```java
try (
	ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("D:/object.txt"));
	ObjectInputStream ois = new ObjectInputStream(new FileInputStream("D:/object.txt"));
)
{
	oos.writeObject(new Draft());
	Draft obj = (Draft) ois.readObject();
} catch (ClassNotFoundException e) {
	e.printStackTrace();
}
```



[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id=""># Common Container Class</h3>



[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id=""># Thread Safe Container  and Thread-Safe</h3>



[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

---


### IV. JVM



<h3 id="hjw"># How Java Works</h3>

Javac convert source code => bytecode file

JVM Class Loader loading bytecode to memory, `Byte Code Verifier` verifying bytecode, `Execution Engine` convert bytecode file => machine code

Most Computer languages use the "compile-link-execute" format.

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3 id="clg"># Class Loading Process</h3>

Process of Class Loading

- JVM Loading

- JVM Linking

- JVM Initialization

__类加载过程__

①加载阶段。是指把类的.class文件中的二进制数据读入内存中，把它存放在运行时数据区的方法区内，然后在堆区创建一个java.lang.Class对象，用来封装类在方法区内的数据结构。

②连接阶段。包括验证、准备和解析类的二进制

③初始化阶段。给类的静态变量赋予正确的初始值，若有显示赋值，则把值赋给变量，若没有，则取默认值，然后，执行静态代码块。

__类加载的时机__

java虚拟机只有在程序首次主动使用一个类和接口时才会初始化它。

下例6种程序对类或接口的主动使用

①创建类的实例：用new语句创建实例，或者通过反射、克隆及反序列化手段来创建实例。

②调用类的静态方法。

③访问类和接口的静态变量或者为该静态变量赋值。

④调用java API中某些反射方法，Class.forName("Worker");

⑤初始化一个类的子类。

⑥java虚拟机启动时被标明为启动类的类。

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3 id="joc"># Java Object Creation Process in run-time memory</h3>

__对象创建过程__

①为对象在堆中分配内存空间

②将对象的实例变量自动初始化为默认值。若实例变量在声明时被显式的初始化，则把相应的值赋给变量。然后，运行构造代码块

③调用构造方法

④返回对象的引用（Sample s=new Sample（）表示将对象的引用赋给s引用变量）

（注：若该类有父类，则先初始化父类的实例变量、执行父类构造代码块，调用父类的构造方法。再初始化该类的实例变量，执行构造代码块，调用构造方法）



[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id="jrm">Java Run-time memory</h3>

java运行时内存分配

①程序计数器

程序计数器是一块较小的区域，它的作用可以看做是当前线程所执行的字节码的行号指示器。在虚拟机的模型里，字节码指示器就是通过改变程序计数器的值来指定下一条需要执行的指令。分支，循环等基础功能就是依赖程序计数器来完成的。

②堆

堆是Java虚拟机所管理的内存中最大的一块。堆是所有线程共享的一块区域，在虚拟机启动时创建。堆的唯一目的是存放对象实例，几乎所有的对象实例都在这里分配

③方法区

法区也是线程共享的区域，用于存储已经被虚拟机加载的类信息，常量，静态变量和即时编译器（JIT）编译后的代码等数据。

④运行时常量池

运行时常量池是方法区的一部分，Class文件中除了有类的版本，字段，方法，接口等信息以外，还有一项信息是常量池用于存储编译器生成的各种字面量和符号引用，这部分信息将在类加载后存放到方法区的运行时常量池中。

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id="jcs">JVM Configurations</h3>

- Heap Memory
- Garbage Collection (choosing of right Garbage Collection algorithm is critical)
- GC Logging  (Checking  the JVM’s *Garbage Collection* performance by logging the *GC* activity in human readable format)
- Handling Out of Memory (dump heap memory into a physical file)
- 32/64 bit
- Misc

__Heap__

`-Xms<heap size>[unit]`

`-Xmx<heap size>[unit]`

unit g for GB, m for MB and k for KB.

For Example, assign minimum 2 GB and maximum 5 GB to JVM.

`Xms2GB -Xmx5G`

__Garbage Collection__

```java
-XX:+UseSerialGC
-XX:+UseParallelGC
-XX:+USeParNewGC
-XX:+UseG1GC
```

__GC Logging__

```
-XX:+UseGCLogFileRotation  
-XX:NumberOfGCLogFiles=10
-XX:GCLogFileSize=50M 
-Xloggc:/home/user/log/gc.log
```

__Handling Out of Memory__

```java
-XX:+HeapDumpOnOutOfMemoryError 
-XX:HeapDumpPath=./java_pid<pid>.hprof
-XX:OnOutOfMemoryError="< cmd args >;< cmd args >" 
-XX:+UseGCOverheadLimit
```

__32/64 bit__
In the OS environment where both 32 and 64-bit packages are installed, the JVM automatically chooses 32-bit environmental packages.
If we want to set the environment to 64 bit manually, we can do so using below parameter:

`-d<OS bit>`





[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


<h3 id="jos">JVM Optimizations</h3>



[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------








### V. Concurrency






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

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



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

```

- ThreadPoolExecutor

```java
class-ThreadPoolExecutor
	public ThreadPoolExecutor(int corePoolSize, int maximumPoolSize, 
    	long keepAliveTime, TimeUnit unit, BlockingQueue<Runnable> workQueue)
	{
    	this(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue,
             Executors.defaultThreadFactory(), defaultHandler);
	}
	public ScheduledThreadPoolExecutor(int corePoolSize) {
        super(corePoolSize, Integer.MAX_VALUE, 0, NANOSECONDS,
              new DelayedWorkQueue());
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

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



<h3 id="tdk">Thread Deadlock</h3>

What is deadlock

A situation where two or more threads are blocked forever, waiting for each other.

__How to avoid deadlock__

- don't use multiple threads
- don't hold several locks at once. If you do, always acquire the locks in the same order.
- don't execute foreign code while holding a lock.
- use interruptible locks.

Deadlock Example

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
		new Thread(() -> {
			synchronized(lock2)
			{
				System.out.println(Thread.currentThread().getName() + "hold lock2...");
				sleep();
				synchronized(lock1)
				{
					System.out.println(Thread.currentThread().getName() + "hold lock1...");
				}
			}
		}).start();
	}
```



[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------







### VI. Design Patterns



<h3 id="cdp"># Common Design Patterns</h3>

(Composite, Strategy, Decorator, Abstract Factory, Bridge, )

- Abstract Factory
- Factory Method
- Singleton
- Proxy
- Strategy

__Abstract Factory__

__1.Intent__

__2.Functions__

__2.Implementation__



__Factory Method__

__Singleton__

__Proxy__

__Strategy__

[`back to content`](#content)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

--END--