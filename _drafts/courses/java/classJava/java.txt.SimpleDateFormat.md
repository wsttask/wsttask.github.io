@构造方法

 ```java
 public SimpleDateFormat(String pattern);
 SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//上述示例中，"yyyy-MM-dd HH:mm:ss" 就是日期和时间的格式模式，定义了年、月、日、时、分、秒的显示方式。
 年：
 
 //y：年份，例如 "yy" 表示两位年份，"yyyy" 表示四位年份。
 //M：月份，"M" 表示月份，"MM" 表示两位月份。
 //d：日期，"d" 表示日期，"dd" 表示两位日期。
 //H：小时（24小时制），"H" 表示小时，"HH" 表示两位小时。
 //m：分钟，"m" 表示分钟，"mm" 表示两位分钟。
 //s：秒，"s" 表示秒，"ss" 表示两位秒。
 //S：毫秒，"S" 表示毫秒。
 //E：星期几，"E" 表示星期的缩写，"EEEE" 表示星期的全名。
 //z：时区，"z" 表示时区的缩写，"zzzz" 表示时区的全名。
 ```

@方法

```java
public String format(Date date);//将Date对象格式化为字符串。

public Date parse(String source);//将字符串解析为Date对象。
```

