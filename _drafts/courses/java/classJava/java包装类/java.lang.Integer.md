#### @构造方法

```java
//构造一个新分配的 Integer 对象，它表示指定的 int 值
public Integer(int value) {
    this.value = value;
}
//构造一个新分配的 Integer 对象，它表示 String 参数所指示的 int 值。
public Integer(String s) throws NumberFormatException {
    this.value = parseInt(s, 10);
}
```

也就是说，创建对象时传入一个数字或者字符形式的参数，都将会赋予value一个int型的值。

#### @常量

```java
 @Native public static final int MAX_VALUE = 0x7fffffff;
```

#### @常用方法


```java
//在数字上比较两个 Integer 对象。
//如果该 Integer等于anotherInteger参数，则返回0值;如果该Integer在数字上小于Integer参数，则返回小于0的值；如果 Integer在数字上大于Integer参数，则返回大于0的值（有符号的比较)
int compareTo(Integer anotherInteger)

//以 int 类型返回该 Integer 的值。
//转换为 int 类型后该对象表示的数值。
int intValue()

//返回一个表示该 Integer 值的 String 对象。
toString()

//将字符串参数作为一个符号整数，进制由第二个参数指定。
static int parseInt(String s, int radix) throws NumberFormatException

//返回保存指定的 String 的值的 Integer 对象。
public static Integer valueOf(String s) throws NumberFormatException {
    return Integer.valueOf(parseInt(s, 10));
}

```
