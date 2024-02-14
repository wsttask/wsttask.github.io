1.HashMap底是哈希表，查询速度非常快（jdk1.8之前是数组+单向链表，1.8之后是数组+单向链表/红黑树 ，链表长度超过8时，换成红黑树）

2. HashMap是无序的集合，存储元素和取出元素的顺序有可能不一致
   

3.集合是不同步的，也就是说是多线程的，速度快

@常用方法

```java
void put(K key,V value);//增添数据
void remove(Object Key);//根据键删除键值对元素
void clear();//移除所有的键值对元素
boolean containsKey(Object key);//判断集合是否包含指定的键
boolean containsValue(Object value);//判断集合是否包含指定的值
boolean isEmpty();//判断集合是否为空
void get(Object key)();//根据键获取值
Set keySet();//获取所有键集合
```