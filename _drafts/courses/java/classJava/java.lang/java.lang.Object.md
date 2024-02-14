@Object类简介

Object类是Javajava.lang包下的核心类，Object类是所有类的父类，何一个类时候如果没有明确的继承一个父类的话，那么它就是Object的子类；

以下两种类的定义的最终效果是完全相同的：

(1) class Person 

(2) class Person extends Object 

@方法：
```java
/**
 * 判断两个对象变量的地址是否一样。
 */
public boolean equals(Object obj) {
	return (this == obj);
}
```