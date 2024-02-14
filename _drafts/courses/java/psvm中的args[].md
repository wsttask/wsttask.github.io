有的小伙伴看到后不理解，为什么是 String[] args，这个 args 是干嘛的？

String[] args 可以看出来它是一个数组。在命令行中比如运行 Test.class 文件,你可以这样写：

```java
java Test runoob
```

相当于给数组传入了一个 runoob 字符串。也可以打印出来，可以作为简单的输入。

例如：

```java
public class Test {
    public static void main(String[] args) {
        System.out.println(args[0]);
    }
}
```

运行以上实例，输出结果如下：

```java
$ javac Test.java
$ java Test runoob
runoob
```

此处注意，main 是一个程序的入口，一个 java 程序运行必须而且有且仅有一个 main 方法。

args[0] 是你传入的第一个参数，args[1]是传入的第二个参数，以此类推。





```
/**
 * Main方法，启动服务器，根据启动参数打开根目录。
 * Idea中设定启动参数的方法：运行->编辑配置->在构建和运行中选中HttpServer类->输入运行参数
 * @param args 须传递一个启动参数，参数为启动文件服务的根目录。
 */
```