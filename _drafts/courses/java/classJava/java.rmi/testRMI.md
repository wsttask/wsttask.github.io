```java
package test;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {

    private static final int PORT = 1099;
    private static final String HOST = "127.0.0.1";

    public static void main(String[] args) {
        try {
            // 本地主机上的远程对象注册表Registry的实例,默认端口1099
            Registry registry = LocateRegistry.createRegistry(PORT);
            // 创建一个远程对象
            InterfaceImplement interfaceImplement = new InterfaceImplement();
            // 把远程对象注册到RMI注册服务器上，并命名为HelloRegistry
            registry.rebind("Test", interfaceImplement);
            // 添加远程对象的另一种方法，这样直接写LocateRegistry.createRegistry(PORT);就可以了
            //Naming.rebind("rmi://127.0.0.1:1099/Test",interfaceImplement);
            System.out.println("======= 启动RMI服务成功! =======");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


```

```java
package test;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

public class Client {

    RegistryInterface RMI;
    static final String HOST = "127.0.0.1";
    static final String PORT = "1099";

    public static void main(String[] args) {
        Client meetingClient = new Client();
        // Naming类提供存储和获得“远程对象注册表”上远程对象的引用的方法。
        // Naming 类的每个方法都可将某个名称作为其一个参数，该名称是使用以下形式的 URL 格式
        // 的 java.lang.String：//host:port/name
        // lookup()返回与指定 name 关联的远程对象的引用（一个 stub）。
        try {
            meetingClient.RMI = (RegistryInterface) Naming.lookup("//" + HOST + ":" + PORT + "/Test");
            String str;
            str = meetingClient.RMI.print();
            System.out.println(str);
        } catch (NotBoundException e) {
            e.printStackTrace();
        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (RemoteException e) {
            e.printStackTrace();
        }

    }
}
```

```java
package test;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface TestInterface extends Remote {
    /**
     *
     * @return
     * @throws RemoteException
     */
    public String print () throws RemoteException;

}
```

```java
package test;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class InterfaceImplement extends UnicastRemoteObject implements RegistryInterface {

    protected InterfaceImplement() throws RemoteException {
    }

    @Override
    public String print() throws RemoteException {
        System.out.println("this is test1");
        return "test1";
    }
}

```

