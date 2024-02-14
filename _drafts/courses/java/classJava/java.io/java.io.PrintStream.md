### @`PrintStream`

```java
public class PrintStream extends FilterOutputStream
    implements Appendable, Closeable
```

System

### @构造方法

```java
```

@成员变量

```java
private BufferedWriter textOut;//这是一个缓冲字符输出流，用于将字符数据写入底层的输出流。缓冲是为了提高性能，允许一次写入一块字符数据而不是逐个字符地写入。

private OutputStreamWriter charOut;//这是一个字符输出流的包装器，用于将字符转换为字节并写入底层的输出流。OutputStreamWriter 将字符编码转换为字节流。在 PrintStream 中，它用于处理字符输出的底层实现。
```

@常用方法

```java
//格式化输出，注意是printf方法
public PrintStream printf(String format, Object ... args) {
    return format(format, args);
}


//这个是String类里面的方法
//注意这个valueof方法，它是返回这个对象的toString方法
public static String valueOf(Object obj) {
    return (obj == null) ? "null" : obj.toString();
}
//这个是PrintStream的方法，System.out也是PrintStream对象
//可以看到它是调用了包装类String的valueOf方法，所以输出对象就是输出这个对象的toString
public void println(Object x) {
    String s = String.valueOf(x);
    if (getClass() == PrintStream.class) {
        // need to apply String.valueOf again since first invocation
        // might return null
        writeln(String.valueOf(s));
    } else {
        synchronized (this) {
            print(s);
            newLine();
        }
    }
}
```

