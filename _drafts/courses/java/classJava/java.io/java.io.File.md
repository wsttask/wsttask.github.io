注意：File 类不能访问文件内容本身，如果需要访问文件内容本身，则需要使用输入/输出流。

### @构造方法

```java
File(String path);//如果 path 是实际存在的路径，则该 File 对象表示的是目录；如果 path 是文件名，则该 File 对象表示的是文件。
File(String path, String name);//path 是路径名，name 是文件名。
File(File dir, String name);//dir 是路径对象，name 是文件名。
```
### @方法

```java
boolean canRead()	测试应用程序是否能从指定的文件中进行读取
boolean canWrite()	测试应用程序是否能写当前文件
boolean delete()	删除当前对象指定的文件
boolean exists()	测试当前 File 是否存在
String getAbsolutePath()	返回由该对象表示的文件的绝对路径名
String getName()	返回表示当前对象的文件名或路径名（如果是路径，则返回最后一级子路径名）
String getParent()	返回当前 File 对象所对应目录（最后一级子目录）的父目录名
boolean isAbsolute()	测试当前 File 对象表示的文件是否为一个绝对路径名。该方法消除了不同平台的差异，可以直接判断 file 对象是否为绝对路径。在 UNIX/Linux/BSD 等系统上，如果路径名开头是一条斜线/，则表明该 File 对象对应一个绝对路径；在 Windows 等系统上，如果路径开头是盘符，则说明它是一个绝对路径。
boolean isDirectory()	测试当前 File 对象表示的文件是否为一个路径
boolean isFile()	测试当前 File 对象表示的文件是否为一个“普通”文件
long lastModified()	返回当前 File 对象表示的文件最后修改的时间
long length()	返回当前 File 对象表示的文件长度
String[] list()	返回当前 File 对象指定的路径文件列表
String[] list(FilenameFilter)	返回当前 File 对象指定的目录中满足指定过滤器的文件列表
boolean mkdir()	创建一个目录，它的路径名由当前 File 对象指定
boolean mkdirs()	创建一个目录，它的路径名由当前 File 对象指定
boolean renameTo(File)	将当前 File 对象指定的文件更名为给定参数 File 指定的路径名
```
### @常量

```java
File 类中有以下两个常用常量：
public static final String pathSeparator：指的是分隔连续多个路径字符串的分隔符，Windows 下指;。例如 java -cp test.jar;abc.jar HelloWorld。
public static final String separator：用来分隔同一个路径字符串中的目录的，Windows 下指/。例如 C:/Program Files/Common Files。
```

### 相对路径和绝对路径

```java
绝对路径：是一个固定的路径,从盘符开始
相对路径：是相对于某个位置开始
	·main（）方法中的相对路径是相对于当前工程
	·单元测试方法中的相对路径是相对于当前模块
```

```java
路径中的每级目录之间用一个路径分隔符隔开。
路径分隔符和系统有关：
	·windows和DOS系统默认使用"\"来表示
	·UNIX和URL使用"/"来表示
```

```java
Java程序支持跨平台运行，因此路径分隔符要慎用。
为了解决这个隐患，File类提供了一个常量：
public static final String separator:根据操作系统，动态的提供分隔符。
```

```java
File file1 = new File("d:\\atguigu\\info.txt");
File file2 = new File("d:" + File.separator + "atguigu" + File.separator + "info.txt");
File file3 = new File("d:/atguigu");
```

