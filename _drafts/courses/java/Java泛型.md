##  一、为什么要使用泛型？

​	泛型俗称“标签”，使用<E>表示。泛型就是在允许定义类，接口时通过一个标识表示某个属性的类型或者是某个方法的返回值或者是参数类型，参数类型在具体使用的时候确定，在使用之前对类型进行检查。

​	泛型意味着编写的代码可以被很多不同类型的对象重用。例如集合ArrayList，如果集合不添加泛型，里面可以存储任何类型也就是Object，当添加泛型的时候，提高了代码的重用。 
​	泛型提供了类型参数，比如ArrayList类有一个类型参数来指示元素的类型，使得代码具有更好的可读性，一看就知道数组列表中包含的是String对象。



## 二、通配符表达式

​	在 Java 中，通配符表达式主要有两种：`? extends T` 和 `? super T`，分别用于表示 "上界通配符" 和 "下界通配符"

 **上界通配符 (`? extends T`)**: 表示通配符可以匹配 `T` 或 `T` 的任何子类型。通常用于读取数据，获取元素的操作。

```java
List<? extends Number> numbers = new ArrayList<>();
```

在这个例子中，`numbers` 可以引用任何类型的 List，只要该 List 中的元素是 `Number` 或 `Number` 的子类型。但由于不知道具体的子类型是什么，通配符限制了我们不能往里面添加元素（除了 `null`），因为编译器无法保证添加的元素是合法的子类型。



**下界通配符 (`? super T`)**: 表示通配符可以匹配 `T` 或 `T` 的任何父类型。通常用于写入数据，往集合中添加元素的操作。

```java
List<? super Integer> integers = new ArrayList<>();
```

在这个例子中，`integers` 可以引用任何类型的 List，只要该 List 的元素是 `Integer` 或 `Integer` 的超类型。我们可以添加 `Integer` 或 `Integer` 的子类型的元素到这个 List 中，但读取时只能以 `Object` 的形式读取，因为我们不知道确切的元素类型。



这两种通配符表达式在不同的场景中使用，具体取决于你是要从集合中读取数据还是向集合中写入数据。在泛型编程中，通配符可以帮助实现更灵活的代码，同时提高代码的安全性。

# 三、类型擦除

### 1.`Java`泛型的实现方法：类型擦除

大家都知道，Java的泛型是伪泛型，这是因为Java在编译期间，所有的泛型信息都会被擦掉，正确理解泛型概念的首要前提是理解类型擦除。Java的泛型基本上都是在编译器这个层次上实现的，在生成的字节码中是不包含泛型中的类型信息的，使用泛型的时候加上类型参数，在编译器编译的时候会去掉，这个过程成为类型擦除。

如在代码中定义`List<Object>`和`List<String>`等类型，在编译后都会变成`List`，JVM看到的只是List，而由泛型附加的类型信息对JVM是看不到的。Java编译器会在编译时尽可能的发现可能出错的地方，但是仍然无法在运行时刻出现的类型转换异常的情况，类型擦除也是Java的泛型与C++模板机制实现方式之间的重要区别。

**例1.原始类型相等**

```java
public class Test {

    public static void main(String[] args) {

        ArrayList<String> list1 = new ArrayList<String>();
        list1.add("abc");

        ArrayList<Integer> list2 = new ArrayList<Integer>();
        list2.add(123);

        System.out.println(list1.getClass() == list2.getClass());
    }

}
```

在这个例子中，我们定义了两个`ArrayList`数组，不过一个是`ArrayList<String>`泛型类型的，只能存储字符串；一个是`ArrayList<Integer>`泛型类型的，只能存储整数，最后，我们通过`list1`对象和`list2`对象的`getClass()`方法获取他们的类的信息，最后发现结果为`true`。说明泛型类型`String`和`Integer`都被擦除掉了，只剩下原始类型。

# 四、泛型类和泛型方法

#### 泛型方法定义

```java
    public <T> T getData() {
        return data;
    }
```

#### 泛型类方法定义

```java
/**
 * 泛型类
 *  该 T 类型作为参数使用
 *  T 是参数化类型 , 可以由外部传入
 *
 * @param <T>
 */
public class Student<T> {

    private String name;
    private int age;
    /**
     * 该数据的类型未知
     *  使用泛型表示 , 运行时确定该类型
     */
    private T data;

    public Student(String name, int age, T data) {
        this.name = name;
        this.age = age;
        this.data = data;
    }

    /**
     * 该方法不是泛型方法
     *  该方法是普通方法 , 返回值类型是 T 类型
     * @return
     */
    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }
}

```

