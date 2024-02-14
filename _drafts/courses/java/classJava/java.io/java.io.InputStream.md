```java
public abstract class InputStream
```
@构造函数
```java
public InputStream()
```
@方法
```java
int read();	//从输入流中读取一个 8 位的字节，并把它转换为 0~255 的整数，最后返回整数。如果返回 -1，则表示已经到了输入流的末尾。为了提高 I/O 操作的效率，建议尽量使用 read() 方法的另外两种形式 

int read(byte[] b);	//从输入流中读取若干字节，并把它们保存到参数 b 指定的字节数组中。 该方法返回读取的字节数。如果返回 -1，则表示已经到了输入流的末尾

int read(byte[] b, int off, int len); //从输入流中读取若干字节，并把它们保存到参数 b 指定的字节数组中。其中，off 指定在字节数组中开始保存数据的起始下标；len 指定读取的字节数。该方法返回实际读取的字节数。如果返回 -1，则表示已经到了输入流的末尾

void close(); //关闭输入流。在读操作完成后，应该关闭输入流，系统将会释放与这个输入流相关的资源。注意，InputStream 类本身的 close() 方法不执行任何操作，但是它的许多子类重写了 close() 方法

int available(); //返回可以从输入流中读取的字节数

long skip(long n); //从输入流中跳过参数 n 指定数目的字节。该方法返回跳过的字节数

void mark(int readLimit); //在输入流的当前位置开始设置标记，参数 readLimit 则指定了最多被设置标记的字节数
boolean markSupported(); //判断当前输入流是否允许设置标记，是则返回 true，否则返回 false

void reset(); //将输入流的指针返回到设置标记的起始处
```