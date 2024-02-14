Java 中 System 类可以取得与系统有关的信息
如：public static Properties getProperty()    方法可以查看 JVM 的默认编码，代码如下：
in,out,err变量的作用域为 public 和 static，因此在程序的任何部分都不需引用 System 对象就可以使用它们。

@构造方法
```java
private System()
```
@方法
```java
void exit(int status)   终止了JVM的运行;
```

@成员
```java
public static final InputStream in;//从键盘的流读入
public static final PrintStream out;
public static final PrintStream err;
```

（1）System.exit(0);//终止了JVM的运行（当程序需要非正常退出时，可以使用此方法强制退出。）这是最直接简单的方法，可以直接退出所有程序的运行。