### Pattern

```java
public final class Pattern
    implements java.io.Serializable
```

##### @构造方法

```java
private Pattern(String p, int f) {
    pattern = p;
    flags = f;

    // Reset group index count
    capturingGroupCount = 1;
    localCount = 0;

    if (pattern.length() > 0) {
        compile();
    } else {
        root = new Start(lastAccept);
        matchRoot = lastAccept;
    }
}
//构造器私有，所以不能使用new创建
```

@常量

```java
/**
  * The original regular-expression pattern string.
  *
  * @serial
  */
private String pattern;
```



@常用方法

```java
/**
 * 调用静态方法compile返回Pattern实例。
 */
public static Pattern compile(String regex) {
    return new Pattern(regex, 0);
}
/**
 * 返回正则表达式
 */
public String pattern() {
    return pattern;
}

public Matcher matcher(CharSequence input) 
//返回一个Matcher对象，Pattern类只能做一些简单的匹配操作,要想得到更强更便捷的正则匹配操作,那就需要将Pattern与Matcher一起合作
```

