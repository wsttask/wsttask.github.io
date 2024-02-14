## StringTokenizer
StringTokenizer类提供将单词从字符串中分离出来的功能。各个单词依据分隔符被分成一个个token。


### 常用的构造方法：
方法签名|方法名称
-|-
public StringTokenizer(String str)|使用指定的字符串创建对象
public StringTokenizer(String str,String delim)|使用指定的字符串str和指定的字符串分隔符delim,创建对象
### 常用的方法：
方法签名|方法名称
-|-
int countTokens()|返回token的个数
boolean hasMoreTokens()|若仍存在token,则返回true,负责返回false
String nextToken()|返回下一个token

simple:

```
public class String2 {
    public static void main(String[] args) {
        String str = new String("Thinking Java Programming with you ");
        StringTokenizer stoken = new StringTokenizer(str);
        System.out.println(stoken.countTokens());
        for (int i = 1; stoken.hasMoreElements(); i++) {
            System.out.println("第"+i+"个token:"+stoken.nextToken());
        }
    }
}
```
