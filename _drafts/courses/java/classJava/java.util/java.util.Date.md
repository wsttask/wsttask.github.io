@构造方法

```java
public Date();//使用无参构造，可以自动设置当前系统时间的毫秒时刻；
public Date(long date);//将指定参数的毫秒值date,转换成Date对象，分配Date对象并初始化此对象，以表示自从标准基准时间（称为“历元（epoch）”，即1970年1月1日00:00:00 GMT）以来的指定毫秒数。
```





@方法

```java
public long getTime();//把日期对象转换成对应的时间毫秒值。

public void setTime(long time);//把方法参数给定的毫秒值设置给日期对象


    
/**
* 1.如果两个日期相等，则返回值为0。
* 2.如果Date在date参数之后，则返回值大于0。
* 3.如果Date在date参数之前，则返回值小于0。
*/
public int compareTo(Date anotherDate) {
    long thisTime = getMillisOf(this);
    long anotherTime = getMillisOf(anotherDate);
    return (thisTime<anotherTime ? -1 : (thisTime==anotherTime ? 0 : 1));
}
public boolean after(Date when) {
    return getMillisOf(this) > getMillisOf(when);
}

public boolean before(Date when) {
    return getMillisOf(this) < getMillisOf(when);
}

public boolean equals(Object obj) {
    return obj instanceof Date && getTime() == ((Date) obj).getTime();
}
```



@例子

```java
 // 创建日期对象，把当前的时间
System.out.println(new Date()); // Tue Jan 16 14:37:35 CST 2020
// 创建日期对象，把当前的毫秒值转成日期对象
System.out.println(new Date(0L)); // Thu Jan 01 08:00:00 CST 1970

//tips:在使用println方法时，会自动调用Date类中的toString方法。Date类对Object类中的toString方法进行了覆盖重写，所以结果为指定格式的字符串。


System.currentTimeMillis();//查了一下发现是用来获取当前的总毫秒数
date.setTime(System.currentTimeMillis()+1000);//一秒等于一千毫秒

```

