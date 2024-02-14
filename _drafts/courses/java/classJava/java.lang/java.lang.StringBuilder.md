#String与StringBuilder的主要区别

​    String类的内容是不可变的，StringBuilder的内容是可变的
​    二者之间的区别主要是拼接字符串上的区别

#StringBuilder内部对象

​    StringBuilder对象则代表一个字符序列可变的字符串，StringBuilder内部维护了一个char[]类型的value

#用法

​    通过StringBuilder构造好字符串之后，通过stringBuilder.toString()方法。

@构造方法
```java
StringBuilder();	//StringBuilder默认的初始容量是16
StringBuilder(int capacity);//设置一定容量的StringBuilder
StringBuilder(String str);//设置初始状态中StringBuilder的存储的字符串，可以通过这个构造函数，把String变成StringBuilder
```
@方法
```java
StringBuilder append(boolean b);//字符串连接
StringBuilder insert(int offset, boolean b);//在指定位置offset插入b，会导致offset及以后的所有值都向后挪。
String toString();//将StringBuilder变成String类型返回
```
注：
    1.  Object、String、StringBuffer、CharSequence、char[]、boolean、char、int、long、float、double都是StringBuilder可以append的对象