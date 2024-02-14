官方解释：Java接口是一系列方法的声明，是一些方法特征的集合，一个接口只有方法的特征没有方法的实现，因此这些方法可以在不同的地方被不同的类实现，而这些实现可以具有不同的行为（功能）。

接口可以理解为一种特殊的类，里面全部是由全局常量和公共的抽象方法所组成。接口是解决Java无法使用多继承的一种手段，但是接口在实际中更多的作用是制定标准的。或者我们可以直接把接口理解为100%的抽象类，既接口中的方法必须全部是抽象方法。（JDK1.8之前可以这样理解）



接口的语法实现：
```java
interface in1{
    //public static and final
    final int a = 10;

    //public and abstract
    void display();
}
```
为了实现这个接口，使用implements
```java
class testClass implements in1{
    //Impelmenting the capabilities
    //interface
    public void display{
        System.out.println("Geek");
    }
}
```
接口的进一步理解

先声明USB接口：其中规定了要实现USB接口就必须实现接口规定实现的read( )和write( )这两个方法。
```java
interface USB {
    void read();

    void write();
}
```
然后在写一个U盘类和一个键盘类，这两个类都去实现USB接口。（实现其中的方法）
这是优盘的具体实现。
```java
class YouPan implements USB {
    @Override
    public void read() {
        System.out.println("U盘正在通过USB功能读取数据");
    }
    @Override
    public void write() {
        System.out.println("U盘正在通过USB功能写入数据");
    }
}
```
这是键盘的具体实现。
```java
class JianPan implements USB {
    @Override
    public void read() {
        System.out.println("键盘正在通过USB功能读取数据");
    }
    @Override
    public void write() {
        System.out.println("键盘正在通过USB功能写入数据");
    }
}
```
关于接口的几个重点
我们不能直接去实例化一个接口，因为接口中的方法都是抽象的，是没有方法体的，这样怎么可能产生具体的实例呢？但是，我们可以使用接口类型的引用指向一个实现了该接口的对象，并且可以调用这个接口中的方法。
（实际上就是使用了Java中多态的特性）
```java
public class Main {
    public static void main(String[] args) {
        //生成一个实现可USB接口（标准）的U盘对象
        //但是使用一个接口引用指向对象
        //USB接口类引用可以指向一个实现了USB接口的对象
        USB youPan = new YouPan();
        //调用U盘的read( )方法读取数据
        youPan.read();
        //调用U盘的write( )方法写入数据
        youPan.write();
        //生成一个实现可USB接口（标准）的键盘对象
        //但是使用一个接口引用指向对象
        //USB接口类引用可以指向一个实现了USB接口的对象
        USB jianPan = new JianPan();
        //调用键盘的read( )方法读取数据
        jianPan.read();
        //调用键盘的write( )方法写入数据
        jianPan.write();
    }
}
```

2.一个类可以实现不止一个接口。

3.一个接口可以继承于另一个接口，或者另一些接口，接口也可以继承，并且可以多继承。

4.一个类如果要实现某个接口的话，那么它必须要实现这个接口中的所有方法。

5.接口中所有的方法都是抽象的和public的，所有的属性都是public,static,final的。

6.接口用来弥补类无法实现多继承的局限。

7.接口也可以用来实现解耦。



## Interface

在传统的Java编程中，被广为人知的一个知识点是：**java Interface接口中不能定义private私有方法**。只允许我们定义public访问权限的方法、抽象方法或静态方法。但是从Java 9 开始，Interface 接口中允许定义私有方法和私有静态方法。下面我们就来为大家介绍其语法规则，和为什么要有这样的设计。



其实在Java 8之前，还有另一个被广为人之的知识点：接口中所有的方法必须是[abstract](https://so.csdn.net/so/search?q=abstract&spm=1001.2101.3001.7020) 抽象方法。但是，从java 8开始接口中可以包含非abstract 方法，如下文中的default方法。这个不是我们本文要为大家介绍的内容，如不熟悉，请自行补课。



#### 一、Java 9接口定义私有方法

从Java 9开始，我们可以在Interface接口中添加[private](https://so.csdn.net/so/search?q=private&spm=1001.2101.3001.7020)的私有方法和私有静态方法。这些私有方法将改善接口内部的代码可重用性。例如，如果需要两个默认方法来共享代码，则私有接口方法将允许它们共享代码，但不将该私有方法暴露给它的实现类调用（后文中会给大家举一个例子）。

在接口中使用私有方法有四个规则：

- 接口中private方法不能是**abstract**抽象方法。因为abstract抽象方法是公开的用于给接口实现类实现的方法，所以不能是private。
- 接口中私有方法只能在接口内部的方法里面被调用。
- 接口中私有静态方法可以在其他静态和非静态接口方法中使用。
- 接口中私有非静态方法不能在私有静态方法内部使用。

```java

interface CustomInterface {
 
    public abstract void abstractMethod();  //抽象方法不能是私有的
 
    public default void defaultMethod() {
        privateMethod(); //可以调用接口中的私有方法
        privateStaticMethod(); //可以调用接口中的私有静态方法
        System.out.println("普通方法被调用");
    }
 
    public static void staticMethod() {
        privateStaticMethod(); //public静态方法可以调用private静态方法
        System.out.println("静态方法被调用");
    }
 
    private void privateMethod() {
        System.out.println("private私有方法被调用");
    }
 
    private static void privateStaticMethod() {
        System.out.println("private私有静态方法被调用");
    }
```



当你实现某个接口时，对于接口中的默认方法（default methods），你可以选择是否在实现类中提供这些方法的具体实现。如果你选择不提供实现，将会使用接口中的默认实现。

- 你不能不用default修饰一个非抽象方法，除非它是静态方法
- 可以用public static 修饰符修饰方法