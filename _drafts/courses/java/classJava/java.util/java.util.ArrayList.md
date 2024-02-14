@构造函数
```java
ArrayList<E> a = new ArrayList<E>();
```
@成员变量

```java
/**
 * The array buffer into which the elements of the ArrayList are stored.
 * 存储ArrayList元素的数组缓冲区
 */
transient Object[] elementData;
```

@ArrayList<E> 常用方法：

```java
public int size();//返回容器中容纳的元素数
public boolean add(E o);//将指定的元素o添加到列表末尾
public E get(int index);//返回容器列表中指定位置的元素 #第一个的索引为0，即get(0)
public boolean remove(Object o);//从容器列表中删除指定对象元素实例
public E remove(int index);//从容器列表中删除指定索引的元素实例
public int indexOf(Object 0);//返回列表中指定元素的索引，无则返回-1
/**
 * 返回一个迭代器,注意Itr是一个内部类
 */
public Iterator<E> iterator() {
        return new Itr();
    }
```

@内部类

```java
private class Itr implements Iterator<E>;
```



@迭代器Iterator<E>

- 所有继承java.util.Collection的容器都有一个方法iterator(),该方法可以返回一个Iterator<E>对象。
  ​        方法的声明：
  ​            public Iterator<E> iterator()
  ​        迭代所用元素的声明：
  ​            Iterator<String> e = a.iterator(); #其中a对象是容器类型。

@Iterator<E> 常用方法：
```java
E next();//返回所访问容器中的下一个元素，第一次调用next()方法时，它返回容器中的第一个元素。get(0)
Bollean hasNext();//判断容器中是否还有元素可以通过next()方法进行访问并返回。
void remove();//删除next指针刚刚跳过去的元素。所以在调用它之前必须调用一次next()方法。
```