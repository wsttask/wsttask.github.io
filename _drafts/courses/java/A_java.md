@ 属性（成员）的访问权限：

###### public:

>表示共有；类的数据成员和函数可以被该类对象和派生类访问。

###### private:
>自己的类可以访问，但是派生类不能访问。位于同一个包中可以访问。？？？？？？？？？？？但是eclipse中在同一个包中也不能直接调用啊？不能通过类Point2D的对象变量和点运算符直接访问x坐标，只能通过可见方法进行调用

```
# protected:
	自己的类和派生类（子类）都可以访问，和private的区别就是对待派生类不同
# default:
	默认的，缺省的，只能在同一个包内访问	
```
@ java类的访问权限

```
#default：
	缺省的，只能被同一个包中的其他类访问和引用，但不可以被其他包中的类使用，这种又称包访问性
#public：
	它可以被任意类调用和使用，程序的其他部分可以创建这个类的对象、访问这个类内部可见的成员变量和调用类可见的方法。
	*因此，对于不同包中的类，他们之间互不可见，只有在import下可以引用public
```

@构造方法：

>构造方法必定有，不写出来Java会自动生成一个无参的
>构造方法的方法名必定与类名完全相同，没有返回类型，甚至连void都没有
>构造方法的使用必须与new联系起来

@对象的声名和创建
	声明：
	*Point2D pointOne;
	这个Java语句的意思是创建一个存Point2D类的对象地址的变量，但是该地址目前为空(null)
	创建：
	Point2D pointOne = new Point2D();
	使用new关键字来为pointOne在堆中申请空间。
		new
		*引起构造方法的调用
		*为对象分配存储其属性的内存空间
		*为对象返回一个该内存空间首地址。
@实例变量和类变量(静态变量)static
	*“类变量”分配的内存存在类所有对象共享的内存空间，所有对象共享同一个“类变量”
	*访问静态变量，直接通过Point2D.number即类名加点运算符直接访问。
	*注意静态变量在类的定义中就已经申请过空间了，哪怕没有该对象的空间，也可以调用静态变量。
@实例方法与类方法（静态方法）static
	*一个类所有的对象调用的“实例方法”在内存中只有一份拷贝。
	*在实例方法中，有一个默认的this关键字，它指向调用这个方法的对象。
	*public static void main(String[] strs)
	*类的实例方法可以调用该类的实例方法和静态方法，但是，类的静态方法只能调用该类的静态方法。
	*类方法不能访问实例变量，只能访问类变量。实例方法两者都可以访问。
@关键字final
	*修饰成员变量，称之为常量，其值初始化之后不能被改变。并且要求声明变量的同时给出变量的初始值，或在所有的构造函数中初始化该变量；

@Java的编译单元
	*一个.java命名的源文件称之为一个编译单元。
	*一个编译单元只能有一个类的访问权限是public，也可以没有

@Java包(package)
	*包中存在一个或多个相关类
	*包的命名遵循不同名原则？？——————数据结构课本。仅在eclipse中找到包java.util
	*全名引用类Java.util.Data data = new Java.util.Data();
	*导入类：import java.util.Data
	*导入包：import java.util.*
	#无论是API提供的类还是自己定义包中的类，都必须用import语句
		@位于同一个包内的类可以相互引用，不必使用import或类的全名
		@在源程序中用到了java类库中的Java.lang包中的类，可以直接引用，不必使用import或类的全名
	*自定义包
		#通过关键字package课可以定义一个包
		#package必须是文件中的第一条语句

@Java继承
	#语法结构：
		类访问限定符 子类名 extends 基类名
		*子类自动继承基类除构造方法外的所有属性和方法,但是子类不能继承父类的private类型的成员！，也不能直接调用
			@注意：这里如果基类自定义了构造方法，那子类也必须自定义构造方法。
	#super关键字
		*可以用super这个关键字调用父类的函数。
		*可以在子类的构造函数中调用父类的构造函数，但是必须是第一个可执行语句
	#向上转型
		*子类的对象可以当作基类的对象使用。
		simple：Employee employee = new Employee("Joe","100 Ave",3.0);
			Person person = employee;
			String name = person.getName();
			String adress = person.getAddress();
			double salary = person.getSalary();//报错——不能调用特有的成员和方法；
		*但是对象变量person不能调用Employee类中特有的方法，


	#向下转型
		simple：Employee employee = new Employee("Joe","100 Ave",3.0);
			Person person = employee;
			double salary = ((Employee)person).getSalary();//合法
		simple：Person person = new Person("Joe","10 Main Ave");
			double salary = ((Employee)person).getSalary();//不合法


	#方法的覆写
		*子类与基类内部定义相同的方法，子类的方法会将基类的方法覆写掉。

@多态：
		一、方法的多态性
		（1）方法的重载
		定义：同一个方法名可以根据参数列表的不同调用不同的方法体
		（2）方法的覆写
		定义：同一个父类的方法，可以根据实例化子类的不同也有不同的表现

		二、对象的多态性
		前提：方法覆写
		（1）对象的向上转型
		父类 父类对象=new 子类（）;
		$核心作用：操作参数统一 
		（2）对象的向下转型
		$什么时候需要向下转型：当父类没有子类的方法，但又想使用时就向下转型；
	
		父类 父类对象=new 子类（）;
		子类 子类对象=（子类）父类对象;
		要向下转型必须先向上转型，这里存在安全隐患

@泛型：
	#泛型类
		*格式： class Name<A,B>{
		*private A element1; private B element2;
			@泛型类可以不指定成员变量的类型
	#泛型方法
		*public<T> void f(T x){
			System.out.println(x.toString());
		}
			@泛型方法可以不指定

@容器：
	#主要分为两类容器：Collection<E>(每个位置存一个元素),和Map<K,V>(每个位置存放两个元素)
	#java.util.ArrayList

		@容器类的变量的声明和初始化：
		    ArrayList<E> a = new ArrayList<E>();
	
		@ArrayList<E> 常用方法：
		    int size() :返回容器中容纳的元素数
		    boolean add(E o) :将指定的元素o添加到列表末尾
		    E get(int index) :返回容器列表中指定位置的元素 #第一个的索引为0，即get(0)
		    boolean remove(Object o) :从容器列表中删除指定元素实例
	
		@迭代器Iterator<E>
		    #所用继承java.util.Collection的容器都有一个方法iterator(),该方法可以返回一个Iterator<E>对象。
		    方法的声明：
			public Iterator<E> iterator()
		    迭代所用元素的声明：
			Iterator<String> e = a.iterator(); #其中a对象是容器类型。
	
		@Iterator<E> 常用方法：
		    E next() :返回所访问容器中的下一个元素，第一次调用next()方法时，它返回容器中的第一个元素。get(0)
		    Bollean hasNext() :判断容器中是否还有元素可以通过next()方法进行访问并返回。
		    void remove() :删除next指针刚刚跳过去的元素。所以在调用它之前必须调用一次next()方法。

@抽象类和抽象方法：
	#抽象方法：public abstract void sleep(int hours)
	#抽象类：public abstract class className{	}
		$抽象类和一般类一样，可以通过它声明对象类型的变量，但是不能创建抽象类实例
			Container container;//√
			container = new Container();//×
			@抽象类是一种只可以作为基类的类型，可以被扩展/继承，创建子类。
			@抽象类的子类如果没有为该抽象类提供方法体，那么该子类必须被定义为抽象类。
			@抽象类可以没有抽象方法。

@接口
	#定义：public interface Name
	@public的接口也必须定义在与接口同名的文件中
	@接口中所用的方法都默认是公共的和抽象的，不能有实例化的变量，常量默认是公开的静态常量：public static final
	@接口也是一种对象类型，可以声明该类型的变量：Device device

	#接口的实现
	@接口被扩展/继承称之为接口的实现：public class TV implements Device
	@

??System.out.prinln(P)里面可以直接加类名？？

System.out.prinln(2+3+"2+3="+2+3+(2+3));
in.n

return "EM:" + super.getName();

数组定义 Person[] persons = {p1,p2};

-36：是否可以用对象+类变量来访问静态变量呢？
问：System.out.println()里面加类名有什么作用？

iterator()方法到底在哪里？
getType():为什么可以直接调用
Math.random