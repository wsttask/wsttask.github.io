#### 1、线程安全：

Vector 使用了 **Synchronized** 来实现线程同步，是线程安全的，而 ArrayList 是非线程安全的。
vector的add方法

#### 2、性能：

ArrayList 在性能方面要优于 Vector。
因为ArrayList没有使用synchronized加锁，不加锁，所以处理速度会快一些

#### 3、扩容：

ArrayList 和 Vector 都会根据实际的需要动态的调整容量，只不过在 Vector 扩容每次会增加 1 倍，而 ArrayList 只会增加 50%。

vector扩容：如果不是指定的话，会扩大一倍

ArrayList扩容：增加1/2的容量

#### 4、同步

Vector类的所有方法都是同步的。
可以由两个线程安全地访问一个Vector对象、但是一个线程访问Vector的话代码要在同步操作上耗费大量的时间。

Arraylist不是同步的，所以在不需要保证线程安全时时建议使用Arraylist。