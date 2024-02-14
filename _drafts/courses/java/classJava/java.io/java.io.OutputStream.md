```java
public abstract class OutputStream
```
@构造方法    

```java
OutputStream()
```
@方法
```java
void write(int b);//向输出流写入一个字节。这里的参数是 int 类型，但是它允许使用表达式，而不用强制转换成 byte 类型。为了提高 I/O 操作的效率，建议尽量使用write() 方法的另外两种形式
void write(byte[] b);//把参数 b 指定的字节数组中的所有字节写到输出流中
void write(byte[] b,int off,int len);//把参数 b 指定的字节数组中的若干字节写到输出流中。其中，off 指定字节数组中的起始下标，len 表示元素个数
void close();//关闭输出流。写操作完成后，应该关闭输出流。系统将会释放与这个输出流相关的资源。注意，OutputStream 类本身的 close() 方法不执行任何操作，但是它的许多子类重写了 close() 方法
void flush();//为了提高效率，在向输出流中写入数据时，数据一般会先保存到内存缓冲区中，只有当缓冲区中的数据达到一定程度时，缓冲区中的数据才会被写入输出流中。使用 flush() 方法则可以强制将缓冲区中的数据写入输出流，并清空缓冲区
```