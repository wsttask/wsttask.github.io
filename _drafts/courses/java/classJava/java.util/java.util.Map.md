```java
Map是用于保存具有映射关系的数据集合，它具有双列存储的特点，即一次必须添加两个元素，即一组键值对==><Key,Value>，其中Key的值不可重复（当Key的值重复的时候，后面插入的对象会将之前插入的具有相同的Key值的对象覆盖掉），Value的值可重复。Map作为接口，它最常见的实现类是HashMap和TreeMap，作为接口它抽取了所有实现类的共有方法。同时Map不具有带索引的方法，因此无法使用普通for循环来遍历Map集合
```

```java
其中<Key,Value>键值对，在Java语言中又被称之为Entry/entry，Map.Entry就相当于Student.name，若name的数据类型为String，则Student.name的数据类型为String，同理若<key,value>中key的数据类型为Integer，value的数据类型为String，则Map.Entry的数据类型为<Integer,String>。
```

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

