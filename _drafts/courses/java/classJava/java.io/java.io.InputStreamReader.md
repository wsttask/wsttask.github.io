InputStreamReader类是从字节流到字符流的桥接器：它使用指定的字符集读取字节并将它们解码为字符。 
它使用的字符集可以通过名称指定，也可以明确指定，或者可以接受平台的默认字符集。

@构造函数
```java
InputStreamReader(InputStream in);  //使用默认的字符集构造InputStreamReader
InputStreamReader(InputStream in, String charsetName);//使用指定的字符集名称构造InputStreamReader流
```
@方法
```java
int read()//读入一个字符，采用charsetName的编码格式，这样也可以一个汉字一个汉字的输入了
```

注意：一般的txt格式的编码都是UTF-8