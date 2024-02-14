@定义

```java
public interface Comparable<T>;
```

@方法

```java
/**
 * 这个接口只有这一个方法
 * 注意这个接口是一个泛型接口，在实现的时候需要注意
 */
public int compareTo(T o);
```

内部比较器



泛型的必要性！

​	Comparable需要有很多比较的对象，不只是基本类型，而且最重要的是其的方法compareTo，如果Comparable不是一个泛型，那么这个方法的参数类型就没有办法定义
