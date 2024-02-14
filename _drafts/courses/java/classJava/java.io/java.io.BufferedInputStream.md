缓冲字节流是为高效率而设计的，真正的读写操作还是靠FileOutputStream和FileInputStream，所以其构造方法入参是这两个类的对象也就不奇怪了。

@构造方法

```java
public BufferedInputStream(InputStream in);//创建一个未指定缓冲区大小的 BufferedInputStream 对象
public BufferedInputStream(InputStream in, int size);//创建一个指定缓冲区大小的 BufferedInputStream 对象
public BufferedInputStream(InputStream in, byte[] buffer);//将指定的字节数组作为缓冲区
```

@成员变量

```java
    /**
     * The internal buffer array where the data is stored. When necessary,
     * it may be replaced by another array of
     * a different size.
     */
protected volatile byte[] buf;

protected： 这是Java中的访问修饰符之一。protected 表示该成员变量对于同一包内的类以及该类的子类是可见的。子类可以访问这个成员变量，而其他类则不能直接访问。

volatile： volatile 是Java中的关键字，用于修饰成员变量。在多线程环境下，当一个线程修改了 volatile 变量的值，其他线程能够立即看到这个变化，而不会使用本地缓存。这样可以确保多个线程之间对于这个变量的操作是可见的。

byte[] buf： 这是一个成员变量，类型为字节数组。在这里，buf 被用作缓冲区，用于暂存从输入流中读取的字节或者将要写入输出流的字节。
```



@方法

```java
public synchronized int read() throws IOException;//从输入流中读取下一个字节的数据。
public synchronized int read(byte[] b, int off, int len) throws IOException;//从输入流中读取最多 len 个字节的数据到字节数组 b 中，从偏移量 off 开始存储。
```

