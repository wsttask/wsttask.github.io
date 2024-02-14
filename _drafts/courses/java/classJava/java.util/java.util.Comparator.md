@接口定义

```java
@FunctionalInterface
public interface Comparator<T> {
 
    int compare(T o1, T o2);
 
    boolean equals(Object obj);
}
```



若一个类要实现Comparator接口：它一定要实现`compareTo(T o1, T o2)` 函数，但可以不实现 `equals(Object obj)` 函数。经过网上查阅得知，这是因为任何类，默认都是已经实现了`equals(Object obj)`的。 Java中的一切类都是继承于`java.lang.Object`，在`Object.java`中实现了equals(Object obj)函数；所以，其它所有的类也相当于都实现了该函数。这里可以用反编译去验证，就不在这写了。



外部比较器
