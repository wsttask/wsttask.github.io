### @Random

```java
public class Random implements RandomGenerator, java.io.Serializable
```

### @构造方法

```java
public Random();//创建一个新的随机数生成器。默认当前系统时间的毫秒数作为种子数
public Random(long seed);//构造Random对象的时候指定种子
```

### @常用方法

```java
/**
 * 返回0-bound(不包括)之间的任意一个值
 */
public int nextInt(int bound);

/**
 * 返回[0,1)之间的随机一个数
 */
public double nextDouble();
```

