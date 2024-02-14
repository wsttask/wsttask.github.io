字符流适用于文本文件的读写，OutputStreamWriter类其实也是借助FileOutputStream类实现的，故其构造方法是FileOutputStream的对象

@构造函数
```java
OutputStreamWriter(OutputStream out);//   使用默认的字符集构造OutputStreamReader流
OutputStreamWriter(OutputStream out, CharsetEncoder enc);// 使用指定的字符集名称构造OutputStreamReader流
```
@方法
    


注意：一般的txt格式的编码都是UTF-8