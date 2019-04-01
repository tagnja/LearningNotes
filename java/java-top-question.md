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
  - [Nested Exception Run Sequence](#ner)
- Container
- Library
- Advanced
  - Thread-deadlock
  - Multiple-Thread Development
  - Common Design Patterns(Composite, Strategy, Decorator, Abstract Factory, Bridge, )
- JVM
  - [How java works?](#hjw)
  - Java Run-time memory
  - JVM Specification concepts?
  - JVM configurations?
  - JVM Optimizations?

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




### JVM



<h3 id="hjw"># How Java Works</h3>

Javac convert source code => bytecode file

JVM Class Loader loading bytecode to memory, Byte Code Verifier verifying bytecode, Execution Engine convert bytecode file => machine code

Most Computer languages use the "compile-link-execute" format.

[`back to content`](#content)





--END--