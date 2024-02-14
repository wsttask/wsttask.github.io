@定义

```java
public class Collections;
```

@常用方法

```java
public static <T extends Comparable<? super T>> void sort(List<T> list);
/**
 * @param c 这是一个list的比较器(Comparator<T>)，其中重写了compareTO方法
 */
public static <T> void sort(List<T> list, Comparator<? super T> c);

/**
 * 随机改变集合的顺序
 */
public static void shuffle(List<?> list);
```

Collections类是Java中针对集合类的一个工具类，其中提供一系列静态方法。

其中重写的最多的就是很多重载的sort
