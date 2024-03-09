1.final是java中的一个关键字

2.final表示最终的，不可变的。

3.final可以修饰变量以及方法，还有类等。

-final修饰的类（无法被继承）
```java
final class {
    //A是没有子孙的
}

class B extends A {
    //错误的，无法从最终类A进行继承
    //B类继承A类，相当于对A类功能进行扩展
     //如果不希望别人对A类进行扩展，可以给A类加final关键字，如String类
}
```
-final修饰的方法（无法被覆盖，重写）
```java
class C {
    public final void doSome() {
        System.out.pirntln("C's doSome...");
    }
    class D extends C {
        //错误，无法被覆盖
        /* 
            public void doSome() {
                System.out.println("D's doSome...");
            }
        */
    }
}
```

-final修饰的局部变量（只能赋一次值）

```java
public class FinalTest01 {
    public static void main(String[] args) {
        //局部变量
        int i = 100；
        i = 200；
        //重新赋值，没问题。

        //再定义一个局部变量
        final int k = 100;
        //重新赋值
        //错误：无法为 最终变量 k分配值
        //k = 300
    }
}
```

对于final类型成员变量，

​    其初始化可以在两个地方，有两种赋值方式： 

​    a) 在声明final类型的成员变量时就赋初值

​    b) 在声明final类型的成员变量时不赋初值，但在类的所有构造方法中都为其赋上初值。

 final修饰变量：

​    当一个属性被final所修饰时，表示该属性不能被改写。

​    基础类型 用fianl修饰后就变成了一个常量，不可以重新赋值。

​    包装类型 用final修饰后该变量指向的地址不变，但是该地址的的变量完全可以改变。
