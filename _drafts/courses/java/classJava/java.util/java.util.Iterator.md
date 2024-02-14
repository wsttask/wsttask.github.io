@定义

```java
public interface Iterator<E>
```

所有继承Java.util.Collection的容器都提供了一个方法iterator()

```java
public interface Collection<E> extends Iterable<E> {
    Iterator<E> iterator();
}
//所有继承Java.util.Collection的容器都提供了一个方法iterator()
```

@方法：

```java
E next();//返回容器中的下一个元素，第一次使用时，返回第一个元素。
Boolean hasNext();//判断容器中是否还有元素可以通过next()方法返回。
void remove();//删去刚刚跳过的元素，所以在用remove之前必须调用一次next()
```