### @定义

```java
public class Arrays
```

### @构造方法

```java
private Arrays()
```
### @方法

```java
/**
 * 如果a==null,输出null
 * 如果a为空,输出"[]"
 * 否则输出a中所有数据
 */
public static String toString(int[] a) {
    if (a == null)
        return "null";
    int iMax = a.length - 1;
    if (iMax == -1)
        return "[]";

    StringBuilder b = new StringBuilder();
    b.append('[');
    for (int i = 0; ; i++) {
        b.append(a[i]);
        if (i == iMax)
            return b.append(']').toString();
        b.append(", ");
    }
}

/**
 * 将传入的数组或元素转换为一个 List 对象
 */

public static <T> List<T> asList(T... a) {
    return new ArrayList<>(a);
}
/**
 *注意这里没有返回值，它是直接把int[] a;里面的a中的顺序给改变了
 *
 */
static void sort(int[] a);//默认按照升序排序long[],short[],char[],byte[],float[],double[]同理
static void sort(int[] a, int fromIndex, int toIndex);//从fromIndex开始排序，排第toIndex个。
static boolean equals(int[] a, int[] a2);//判断两个数组的内容是否完全一样
int Arrays.binarySearch( Datatype[], Datatype key)//二分查找，查找指定元素，返回其下标，注意前提是有序数组
```

