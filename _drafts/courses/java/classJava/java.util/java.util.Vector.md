@定义

```java
public class Vector<E>
    extends AbstractList<E>
    implements List<E>, RandomAccess, Cloneable, java.io.Serializable
```

java.util.vector提供了向量类(Vector)以实现类似动态数组的功能。 

创建了一个向量类的对象后，可以往其中随意插入不同类的对象，即不需顾及类型也不需预先选定向量的容量，并可以方便地进行查找。

对于预先不知或者不愿预先定义数组大小，并且需要频繁地进行查找，插入，删除工作的情况，可以考虑使用向量类。

@构造方法

```java
public vector();
public vector(int initialcapacity,int capacityIncrement);
public vector(int initialcapacity);
```

使用第一种方法系统会自动对向量进行管理，若使用后两种方法，则系统将根据参数，initialcapacity设定向量对象的容量（即向量对象可存储数据的大小），当真正存放的数据个数超过容量时。系统会扩充向量对象存储容量。

参数capacityincrement给定了每次扩充的扩充值。当capacityincrement为0的时候，则每次扩充一倍，利用这个功能可以优化存储。

@常用方法

```java
public final int size();//返回向量中实际存在的元素个数
public final synchronized void setSize(int newsize);//此方法用来定义向量的大小，若向量对象现有成员个数已经超过了newsize的值，则超过部分的多余元素会丢失。
/**
 * 返回容器中是否存在对象o
 */
public boolean contains(Object o);
```

