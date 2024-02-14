```java
public abstract class Writer
```
@构造方法
```java
    protected Writer();
```
@方法 
```java
void write(int c); //向输出流中写入一个字符

void write(char[] cbuf); //把参数 cbuf 指定的字符数组中的所有字符写到输出流中

void write(char[] cbuf,int off,int len);//把参数 cbuf 指定的字符数组中的若干字符写到输出流中。其中，off 指定字符数组中的起始下标，len 表示元素个数

void write(String str);//向输出流中写入一个字符串

void write(String str, int off,int len);//向输出流中写入一个字符串中的部分字符。其中，off 指定字符串中的起始偏移量，len 表示字符个数

append(char c);//将参数 c 指定的字符添加到输出流中

append(charSequence esq);//	将参数 esq 指定的字符序列添加到输出流中

append(charSequence esq,int start,int end);//将参数 esq 指定的字符序列的子序列添加到输出流中。其中，start 指定子序列的第一个字符的索引，end 指定子序列中最后一个字符后面的字符的索引，也就是说子序列的内容包含 start 索引处的字符，但不包括 end索引处的字符

abstract void close();
```