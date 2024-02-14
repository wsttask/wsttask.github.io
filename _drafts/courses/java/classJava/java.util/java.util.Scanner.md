### @定义

```java
public final class Scanner implements Iterator<String>, Closeable
```

### @构造方法

```java

//Scanner(System.in);//从键盘输入
```
### @成员变量

```java
// Pattern used to delimit tokens
private Matcher matcher;
```

### @方法:

```java
一定要读取到有效字符后才可以结束输入,对输入的有效字符之前所遇到的空白，会自动将其去除,只有输入的有效字符后才将其后面输入的空白作为结束符。

public String next() {
    ensureOpen();     // 检查 Scanner 是否已经关闭
    clearCaches();    // 清除缓存
    modCount++;       // 修改计数器
    while (true) {
        String token = getCompleteTokenInBuffer(null);  // 从缓冲区获取完整的标记
        if (token != null) {
            matchValid = true;  // 匹配有效
            skipped = false;    // 未跳过
            return token;       // 返回获取的标记
        }
        if (needInput)
            readInput();       // 如果需要输入，则读取输入
        else
            throwFor();        // 否则，抛出异常
    }
}

String nextLine();//以回车符作为结束标识符，获取到的是回车符前输入的所有字符串（包括空格）。也就是说不会读入\n，而是把它留在缓冲区中
int nextInt();//读入下一个int类型的值，对输入的有效字符之前所遇到的空白，会自动将其去除，如果碰到非空白，如果不是数字，会报错，",\.adc"等
float nextFloat();//读".222"也不会报错
double nextDouble();//读".222"也不会报错
```
input.next();和input.nextLine();的区别：
input.next();的含义为接收到""空白字符前的一个字符。
input.nextLine();的含义为接收到"\n"换行字符前的一个字符。

//使用完Scanner后，我们一定要记得将它关闭!
//因为使用Scanner本质上是打开了一个IO流，如果不关闭的话，它将会一直占用系统资源。
sc.close();
//但是注意一旦你关闭后，就算在sc.close()这行代码后你再重新new Scanner(System.in)，那也不能重新再打开一个扫描器了，如下图会发现程序会报错
//所以大家一定要在用不到扫描器之后再关闭，即把sc.close()代码放到最后。

### `private String getCompleteTokenInBuffer(Pattern pattern)`

```java
private String getCompleteTokenInBuffer(Pattern pattern) {
    matchValid = false;  // 将匹配标志设置为无效
    // 跳过分隔符（delimiters）
    matcher.usePattern(delimPattern);
    if (!skipped) {  // 仅跳过一次分隔符
        matcher.region(position, buf.limit());
        if (matcher.lookingAt()) {
            if (matcher.hitEnd() && !sourceClosed) {
                // 如果更多的输入可能扩展分隔符，则等待更多的输入
                needInput = true;
                return null;
            }
            skipped = true;  // 标记已跳过分隔符
            position = matcher.end();  // 更新位置
        }
    }

    if (position == buf.limit()) {
        // 如果位置在缓冲区的末尾，表示没有更多的标记
        if (sourceClosed)
            return null;
        needInput = true;  // 等待更多的输入
        return null;
    }

    // 查找下一个分隔符
    matcher.region(position, buf.limit());
    boolean foundNextDelim = matcher.find();
    if (foundNextDelim && (matcher.end() == position)) {
        // 零长度的分隔符匹配；使用自动移过零长度匹配找到下一个分隔符
        foundNextDelim = matcher.find();
    }
    if (foundNextDelim) {
        // 如果更多的输入可能导致匹配丢失并且有更多的输入，则等待更多的输入
        if (matcher.requireEnd() && !sourceClosed) {
            needInput = true;
            return null;
        }
        int tokenEnd = matcher.start();  // 标记的结束位置
        // 有一个完整的标记
        if (pattern == null) {
            // 必须继续匹配以提供有效的 MatchResult
            pattern = FIND_ANY_PATTERN;
        }
        // 尝试匹配所需的模式
        matcher.usePattern(pattern);
        matcher.region(position, tokenEnd);
        if (matcher.matches()) {
            String s = matcher.group();
            position = matcher.end();
            return s;
        } else {
            // 完整的标记但不匹配
            return null;
        }
    }

    if (sourceClosed) {
        if (pattern == null) {
            // 必须继续匹配以提供有效的 MatchResult
            pattern = FIND_ANY_PATTERN;
        }
        // 最后一个标记；在此处匹配模式或抛出异常
        matcher.usePattern(pattern);
        matcher.region(position, buf.limit());
        if (matcher.matches()) {
            String s = matcher.group();
            position = matcher.end();
            return s;
        }
        // 最后一部分不匹配
        return null;
    }

    // 缓冲区中有部分标记；必须读取更多内容以完成它
    needInput = true;
    return null;
}
```

