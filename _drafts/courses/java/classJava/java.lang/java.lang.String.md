#### String——引用类型
    String是引用类型，不是基本类型
    string1 == string2 是比较两个实例的地址是否一样
#### String——不可修改
    String是一个用 final 声明的常量类，不能被任何类所继承，且无法被修改。
    关于String类，一个重要的特性是其不可变性，即一个字符串一旦被创建，就不会再被修改。
    种不可变性指的是其内存中的实现。当我们创建一个字符串时，内存中会创建这样的一个字符串对象的引用。
    而当我们尝试修改s的内容时，我们并不是修改字符串对象，而是在内存中重新创建了一个字符串对象，并且将指针指向了这个新创建的字符串对象。
#### @String

```java
public final class String
    implements java.io.Serializable, Comparable<String>, CharSequence,
               Constable, ConstantDesc 
```

#### @构造方法

```java
String(byte[] bytes) 可以通过这个构造函数，将byte转化为String
String s = "String is a list of characters";
String s = new String("String is a list of characters");
——这两种对象变量的定义方法是等价的
```

#### @成员变量

```java
@Stable
private final byte[] value;//可以看到String是个对象,其中value中才存储着值

注解的作用
    
告知JVM该字段是稳定的： 通过使用 @Stable 注解，开发者在代码中明确表示 value 字段在对象的生命周期内不会被修改。这种不可变性使得JVM可以进行更强大的优化，例如对字段进行内联、更好地进行逃逸分析等。

在常量折叠中的作用： 注释中提到，value 字段在字符串实例是常量时，可以进行常量折叠（constant folding）。这意味着对于相同的字符串值，JVM可能会共享相同的 value 数组，以节省内存和提高性能。

数组内容的可信性： 注释中还提到 @Stable 被用于信任数组内容。这表示JVM可以更可靠地处理数组的内容，以便进行更高效的操作。

需要注意的是，@Stable 注解不是Java语言规范的一部分，而是一种用于特定JVM实现的标签。在这个上下文中，@Stable 的使用是为了提供更多关于 value 字段的语义信息，以便JVM做出更好的优化决策。在其他上下文中，可能会有其他用途。
```

#### @常用方法

```java
String trim();//反回移除头尾空格的字符串
public boolean matches(String regex);//对一个字符进行regex的正则表达式的判断
public boolean startsWith(String prefix, int toffset);//用于检测字符串是否以指定的前缀开始
public boolean startsWith(String prefix);
/*
prefix -- 前缀。
toffset -- 字符串中开始查找的位置。
*/
String intern()     如果该字符串在字符串常量池中存在对应字面量，则intern()方法返回该字面量的地址；如果不存在，则创建一个对应的字面量，并返回该字面量的地址
char charAt(int index)  从字符串中取出指定位置的字符 
char[] toCharArray()     将字符串转成字符数组并返回
boolean equals(Object anObject)比较两个字符串(类)是否相同
byte[] getBytes();//通过这个函数把string转化为byte
boolean isEmpty();//判断字符串是否为空
String concat(String str);//将指定字符串连接到此字符串的结尾。：注意这里也是创建了一个新的字符串
// 返回字符串数组
public String[] split(String regex) {
    return split(regex, 0);
}


public byte[] getBytes(String charsetName) throws UnsupportedEncodingException;
    
//注意这个valueof方法，它是返回这个对象的toString方法
public static String valueOf(Object obj) {
    return (obj == null) ? "null" : obj.toString();
}
//这个是PrintStream的方法，System.out也是PrintStream对象
//可以看到它是调用了包装类String的valueOf方法，所以输出对象就是输出这个对象的toString
public void println(Object x) {
    String s = String.valueOf(x);
    if (getClass() == PrintStream.class) {
        // need to apply String.valueOf again since first invocation
        // might return null
        writeln(String.valueOf(s));
    } else {
        synchronized (this) {
            print(s);
            newLine();
        }
    }
}
```

### public String[] split(String regex)

```java
public String[] split(String regex) {
    return split(regex, 0);
}
在Java中，String.split 方法使用正则表达式作为分隔符。正则表达式中.表示匹配任意字符（除了换行符 \n）。如果你想使用.作为实际的点字符进行分割，而不是正则表达式中的通配符，你需要使用双反斜杠 \\ 进行转义。

所以，当你想以实际的点字符 . 作为分隔符时，应该使用\\.而不是\.。这是因为在Java中，反斜杠本身也是一个转义字符，因此为了表示一个字面上的反斜杠，你需要使用两个反斜杠。

\表示将下一字符标记为特殊字符。如\d表示数字字符匹配，等效于 [0-9]。\w表示匹配任何字类字符，包括下划线。与"[A-Za-z0-9_]"等效。

在 Java 中，\\ 表示：我要插入一个正则表达式的反斜线，所以其后的字符具有特殊的意义。

\\中的第一个\表示java的转义字符\由编译器解析，第二个\是正则表达式\由正则表达式引擎解析。

Java正则表达式中匹配一个普通的反斜杠是\\\\

“\\\s+”中的+表示一个或多个的意思。
```

![](../images/1189489-20190811224147781-297478105.png)  

### public int length()

```java
 /**
     * Returns the length of this string.
     * The length is equal to the number of <a href="Character.html#unicode">Unicode
     * code units</a> in the string.
     *
     * @return  the length of the sequence of characters represented by this
     *          object.
     */
public int length() {
        return value.length >> coder();
    }
//返回真正的数
String str = "我喜欢?这个字符";
byte[] bytes = str.getBytes(StandardCharsets.UTF_16);
System.out.println(str.length());//8
System.out.println(bytes.length);//18

```

### public byte[] getBytes(Charset charset)

```java
//这个是用charset编码方式重新编码String
//string一般使用UTF-16编码的
//也就是先解码成unicode字符再重新编码成charset类型
public byte[] getBytes(Charset charset) {
    if (charset == null) throw new NullPointerException();
    return encode(charset, coder(), value);
}
```





  注意"=="是比较地址是否一样，.equals(),是比较内容是否一样
Java内存结构包含以下部分

1、栈区：由编译器自动分配释放，具体方法执行结束后，系统自动释放JVM内存资源。
其作用有保存局部变量的值，包括：1.用来保存基本数据类型的值；2.保存类的实例，即堆区对象的引用。也可以用来保存加载方法时的帧。

2、堆区：一般由程序员分配释放，JVM不定时查看这个对象，如果没有引用指向这个对象就回收。其作用为用来存放动态产生的数据，包括new出来的实例，字符数组等。注意创建出来的对象只包含属于各自的成员变量，并不包括成员方法。
因为同一个类的对象拥有各自的成员变量，存储在各自的堆中，但是他们共享该类的方法，并不是每创建一个对象就把成员方法复制一次。

3、代码区：存放程序中方法的二进制代码，而且是多个对象共享一个代码空间区域。

4、数据区：用来存放static定义的静态成员。

5、常量池：JVM为每个已加载的类型维护一个常量池，常量池就是这个类型用到的常量的一个有序集合。包括直接常量(基本类型，String)和对其他类型、方法、字段的符号引用。池中的数据和数组一样通过索引访问。由于常量池包含了一个类型所有的对其他类型、方法、字段的符号引用，所以常量池在Java的动态链接中起了核心作用。常量池存在于堆中。

Java中，字符串从索引0开始，在索引N-1处结束，其中N为字符串中字符的个数。
simple："hello" 的长度为5，最后一个字符的索引值为4。
java字符串在存储中是否会加一个

在Java中，字符串是以Unicode字符序列的形式存储的，而不是以C语言中的以null字符（\0）结尾的字符数组形式存储。在Java中，字符串是通过`java.lang.String`类来表示的，该类内部使用字符数组来存储字符串的内容，而不需要像C语言那样使用null字符来表示字符串的结尾。

Java的字符串是不可变的，这意味着一旦字符串被创建，它的内容就不能被修改。当你在Java中创建一个字符串时，它会在内存中创建一个对象，该对象包含字符串的字符数组和其他相关信息，但是不会在字符串的结尾加上null字符（\0）。

在Java中，你可以通过字符串的长度（`length()`方法）来获取字符串的长度，而不需要依赖于null字符来确定字符串的结束位置。因此，在Java中不需要使用null字符来标志字符串的结尾。



[Java：String类型为什么可以直接赋值？使用new String赋值不可以吗？_string可以直接赋值吗-CSDN博客](https://blog.csdn.net/qq_43437122/article/details/105806653)

```
1.String类可以直接使用字符串常量赋值
	string作为一个类，为什么可以被赋值
2.Stirng类可以直接被sout输出
	假定sout函数对String有解释，输出toString.
	1.了解sout函数的调用，没有写toString的类的输出是什么样子的
```

