@定义

```java
public class UnicastRemoteObject extends RemoteServer
```

这是一个支持一对一远程通信的对象。在Java中，它通常用于使一个对象能够通过Java RMI框架进行远程调用，通过继承这个类或调用 `UnicastRemoteObject.exportObject()` 方法，使对象能够被远程客户端调用。
