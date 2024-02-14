@构造方法

```java
ServerSocket()throws IOException;
ServerSocket(int port) throws IOException; 
ServerSocket(int port, int backlog) throws IOException;
ServerSocket(int port, int backlog, InetAddress bindAddr) throws IOException; 
//参数port指定服务器要绑定的端口（服务器要监听的端口），参数backlog指定客户连接请求队列的长度，参数bindAddr指定服务器要绑定的IP地址。
```

@方法

```java
public Socket accept() throws IOException;//ServerSocket 的 accept() 方法从连接请求队列中取出一个客户的连接请求，然后创建与客户连接的 Socket 对象，井将它返回。如果队列中没有连接请求，accept() 方法就会一直等待下去
```

