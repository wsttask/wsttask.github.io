### Matcher

```java
public final class Matcher implements MatchResult
```

Matcher类的构造方法不是公开的，所以程序员不能直接通过new关键字创建它的对象。创建Matcher类对象需要调用Pattern对象的matcher()方法来完成，

### @常用方法

```java
public boolean find() 
//尝试查找与该模式匹配的输入序列的下一个子序列
    
public boolean matches() 
//尝试将整个区域与模式匹配
    
String replaceFirst(String rep)
//把字符串中第一个匹配项替换为rep，并返回替换后的字符串

String replaceAll (String rep)
//把字符串中所有匹配项替换为rep，并返回替换后的字符串  
    
```

##### 实例

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class test02 {
    public static void main(String[] args) {
       String rex="[0-9]{16}";//匹配16个数字组成的字符串
       String s="dad121345446464645464ada";
        Pattern pattern = Pattern.compile(rex);
        Matcher matcher = pattern.matcher(s);
        //完全匹配
        System.out.println(matcher.matches());//显然这个字符串不符合输出false
        
        //部分匹配，检查字符串中是否存在16个数字组成的字符串
        if(matcher.find()){
            System.out.println(matcher.group(0));//输出第一个16个数字的字符串
        }
    }
}


import java.util.regex.*;
public class Exam16_17 {
    public static void main(String[] args) {
        String str = "xyzabbauvwcddc";
        String reg = "(.)(.)\\2\\1";//正则表达式定义了4字符对称结构
        Pattern p = Pattern.compile(reg);
        Matcher m = p.matcher(str);
        //替换第一个对称字符串
        String replace1 = m.replaceFirst("*");
        System.out.println(replace1);
        //替换所有的对称字符串
        String replace2 = m.replaceAll("*");
        System.out.println(replace2);
    }
}
```

##### 疑问

为什么要多次一举，用完pattern再用Matcher呢？
