@构造方法
```java
//创建一个新的缓冲输出流，以将数据写入指定的底层输出流。
public BufferedOutputStream(OutputStream out);

//创建一个新的缓冲输出流，以将具有指定缓冲区大小的数据写入指定的底层输出流。
public BufferedOutputStream(OutputStream out,int size);
```

@常用方法

```java
//向输出流中输出一个字节
public void write(int b);

//将指定 byte 数组中从偏移量 off 开始的 len 个字节写入此缓冲的输出流。
public void write(byte[] b,int off,int len);

//刷新此缓冲的输出流。这迫使所有缓冲的输出字节被写出到底层输出流中。
public void flush();
```

