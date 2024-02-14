多态的概念：同一个方法，在不同的情境下会有不同的表现
    
多态的核心体现主要有以下两点：

一、方法的多态性
（1）方法的重载
定义：同一个方法名可以根据参数列表的不同调用不同的方法体
（2）方法的覆写
定义：同一个父类的方法，可以根据实例化子类的不同也有不同的表现

二、对象的多态性
前提：方法覆写
（1）对象的向上转型
    父类 父类对象=new 子类（）;    

核心作用：操作参数统一 

Simple：
```java
class Person {
	public void print() {
		System.out.println("1.我是人类！");
	}
}


class Student extends Person {
	public void print() {
		System.out.println("2.我是学生！");
	}
}

class Worker extends Person {
	public void print() {
		System.out.println("3.我是工人！");
	}
}

public class test {
	public static void main(String[] args) {
		whoYouAre(new Student());
		whoYouAre(new Worker());
	}

	public static void whoYouAre(Person per) {
		per.print();
	}
}
```
（2）对象的向下转型

什么时候需要向下转型：当父类没有子类的方法，但又想使用时就向下转型；

父类 父类对象=new 子类（）;
子类 子类对象=（子类）父类对象;

要向下转型必须先向上转型，这里存在安全隐患

错误示例：

父类 父类对象=new 父类（）;
子类 子类对象=（子类）父类对象;

这样是不行的，虽然说两者有关系，但是前提并没有发生关系，因而不能强转，会报错ClassCastException

那么该怎么解决呢，这里可以使用instanceof关键字实现，先判断new的是否是子类，若是，再进行下一步：
```java
public class test {
    public static void main(String[] args) {
        //Student student= (Student) new Person();//这里会报错ClassCastException，因为没有向上转型
        //Person person=new Person();
        //Student student0=(Student) person;//这里也会报错ClassCastException，上面那个是匿名Person对象，这个不是匿名，实际上表达式一样的
        //先向上转型，才能实现向下转型
        Person person1=new Student();
        if (person1 instanceof Student){
            Student student1=(Student) person1;
            student1.study();
        }
    }
}
class Person{
    public void study(){
        System.out.println("有人在学习");
    }
}
class Student extends Person{
    @Override
    public void study() {
        System.out.println("学生在学习");
    }
}
```