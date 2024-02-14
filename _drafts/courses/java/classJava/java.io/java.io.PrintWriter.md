具有自动行刷新的缓冲字符输出流，特点是可以按行写出字符串，并且可以自动行刷新。

1. 




@构造方法

```java
PrintWriter(File f);//传文件名
PrintWriter(String s,);//传路径
public PrintWriter(Writer out, boolean autoFlush)
```

PrintWriter创建时如果有参数true时，会有行刷新。PrintWriter调用println()方法有行刷新。

当创建PW时第一个参数为一个流时，

那么就可以再传入一个boolean值类型的参数，

若该值为true，那么当前PW久具有自动行刷新的功能，

即：每当使用println方法写出一行字符串后就会自动调用flush

注：使用自动行刷新可以提高写出数据的即时性，

但是由于会提高写出次数，必然会导致写效率降低







java.io.BufferedWriter是缓冲字符输出流，内部有缓冲区可以进行块写操作提供效率，而PrintWriter就是通过连接它实现的缓冲功能（PW的很多构造方法内部自动连接它）。

1.  PW是一个高级流
2.  \* 实际上PW包装了字节流、字符流和字符缓冲流。
3.  \* PW负责自动行刷新
4.  \* bw负责提高效率
5.  \* osw负责读字符
6.  \* fos负责写字节
7.  \* 最后PW能够按行很快地把一个字符串变成字节写在文件

8.  缓冲字符流中所有构造方法中第一个参数都是Reader或Writer对象。
