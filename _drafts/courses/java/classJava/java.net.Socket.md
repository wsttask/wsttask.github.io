@成员变量

```java
private volatile InputStream in;
private volatile OutputStream out;
```



@构造方法

```java
public Socket(InetAddress address, int port);//创建一个流套接字并将其连接到指定 IP 地址的指定端口号。 
public Socket(InetAddress address, int port, InetAddress localAddr, int localPort) throws IOException;//创建一个指定源端口号的socke;
public Socket(String host, int port);
/*
请注意，指定源端口号并不总是必需的，因为在大多数情况下，操作系统会为你选择一个可用的动态端口。只有在特定的网络编程需求中才需要显式地指定源端口号。
*/
```

@方法

```java
public InputStream getInputStream() throws IOException;//返回in,从socket中拿信息
public OutputStream getOutputStream() throws IOException;//返回out,往socket中放信息
getInetAddress();//获得远程服务器的IP地址
getPort();//获得远程服务器的端口
getLocalAddress();//获得客户本地的地址
getLocalPort();//获得本地端口
```

可见，socket在创建过程中就自动把自己的端口和IP地址封装进去了
