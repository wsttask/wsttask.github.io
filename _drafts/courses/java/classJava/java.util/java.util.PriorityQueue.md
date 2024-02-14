@定义

```java
public class PriorityQueue<E> extends AbstractQueue<E>
    implements java.io.Serializable{}
```

- PriorityQueue不是线程安全的。如果多个线程中的任意线程从结构上修改了列表， 则这些线程不应同时访问 PriorityQueue 实例，这时请使用线程安全的PriorityBlockingQueue 类。
- 不允许插入 null 元素。
- PriorityQueue实现插入方法（offer、poll、remove() 和 add 方法） 的时间复杂度是O(log(n)) ；实现 remove(Object) 和 contains(Object) 方法的时间复杂度是O(n) ；实现检索方法（peek、element 和 size）的时间复杂度是O(1)。所以在遍历时，若不需要删除元素，则以peek的方式遍历每个元素。
- 方法iterator()中提供的迭代器并不保证以有序的方式遍历优PriorityQueue中的元素。

@构造函数

```java
/**
 * 注意比较器中的E和Priorityqueue<E>是一样的，即泛型定义和比较器中的泛型定义是一样的
 *
 */
public PriorityQueue(Comparator<? super E> comparator);
```

@常用方法

```java
public E peek();//返回队首元素
poll()//返回队首元素，队首元素出队列
add();//添加元素，如果队列已满，则抛出一个IIIegaISlabEepeplian异常
public boolean offer(E e);//添加元素，如果队列已满，则返回false
size()//返回队列元素个数
isEmpty()//判断队列是否为空，为空返回true,不空返回false
```

@example

```java
class Node{
    public Node(int chang,int kuan)
    {
        this.chang=chang;
        this.kuan=kuan;
    }
    int chang;
    int kuan;
}

public class Test {
　　　　//自定义比较类，先比较长，长升序排列，若长相等再比较宽，宽降序
    static Comparator<Node> cNode=new Comparator<Node>() {
        public int compare(Node o1, Node o2) {
            if(o1.chang!=o2.chang)
                return o1.chang-o2.chang;
            else
                return o2.kuan-o1.kuan;
        }
        
    };
    public static void main(String[] args) {
        Queue<Node> q=new PriorityQueue<>(cNode);
        Node n1=new Node(1, 2);
        Node n2=new Node(2, 5);
        Node n3=new Node(2, 3);
        Node n4=new Node(1, 2);
        q.add(n1);
        q.add(n2);
        q.add(n3);
        Node n;
        while(!q.isEmpty())
        {
            n=q.poll();
            System.out.println("长: "+n.chang+" 宽：" +n.kuan);
        }
　　　　　/**
　　　　　　* 输出结果
　　　　　　* 长: 1 宽：2
　　　　　　* 长: 2 宽：5
　　　　　　* 长: 2 宽：3
　　　　　　*/
    }
}
```
