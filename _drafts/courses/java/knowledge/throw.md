作用：

可以使用throw关键字在指定的方法中抛出指定的异常

使用格式：

throw new xxxException（“异常产生的原因”）

注意：

1、throw关键字必须写在方法的内部

2、throw关键字后边new的对象必须是Exception或者Exception的子类对象

3、throw关键字抛出指定的异常对象，我们就必须处理这个异常对象

​    throw关键字后边创建的是RumtimeException或者是RumtimeException的子类对象，我们可以不处理，默认交给JVM处理（打印异常对象，中断程序）

throw关键字后边创建的是编译异常（写代码的时候报错），我们就必须处理这个异常，要么throw，要try...catch
