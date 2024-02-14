@构造方法
```java
BufferedReader(Reader in);//参数是Reader类型(字符型），buf=new BufferedReader(new InputStreamReader(System.in));
```
@成员变量

```java
private char[] cb;

这是一个字符数组，通常用于存储从底层 Reader 对象（在 BufferedReader 内部的 in）读取的字符数据。字符缓冲区的使用可以减少对底层 Reader 的直接读取次数，提高读取效率。BufferedReader 在读取字符时，会从底层的 Reader 中读取一块字符数据并存储在 cb 中，然后逐步从 cb 中返回给调用者。
```

@方法

```java
String readLine() 一次性读一行
```