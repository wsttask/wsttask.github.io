```java
public final class Naming;
```

@方法

```java
    /**
     * Binds the specified <code>name</code> to a remote object.
     *
     * @param name a name in URL format (without the scheme component)
     * @param obj a reference for the remote object (usually a stub)
     */
    public static void bind(String name, Remote obj)
        throws AlreadyBoundException,
            java.net.MalformedURLException,
            RemoteException 
    {	
        ParsedNamingURL parsed = parseURL(name);
        Registry registry = getRegistry(parsed);

        if (obj == null)
        throw new NullPointerException("cannot bind to null");

        registry.bind(parsed.name, obj);
    }


    private static Registry getRegistry(ParsedNamingURL parsed)
        throws RemoteException
    {
        return LocateRegistry.getRegistry(parsed.host, parsed.port);
    }


    public static void rebind(String name, Remote obj)
        throws RemoteException, java.net.MalformedURLException
    {
        ParsedNamingURL parsed = parseURL(name);
        Registry registry = getRegistry(parsed);

        if (obj == null)
            throw new NullPointerException("cannot bind to null");

        registry.rebind(parsed.name, obj);
    }

	/**
	 * 返回与指定的 name关联的远程对象的引用（stub）
	 *
	 */
    public static Remote lookup(String name)
        throws NotBoundException,
            java.net.MalformedURLException,
            RemoteException
    {
        ParsedNamingURL parsed = parseURL(name);
        Registry registry = getRegistry(parsed);

        if (parsed.name == null)
            return registry;
        return registry.lookup(parsed.name);
    }
```



 “Naming.rebind”和“Naming.bind”的区别。前置是指“重绑定”，如果“重绑定”时“RMI 注册表”已经有了这个服务name的存在，则之前所绑定的Remote Object将会被替换；而后者在执行时如果“绑定”时“RMI注册表”已经有这个服务name的存在，则系统会抛出错误。所以除非您有特别的业务要求，那么建议使用rebind方法进行Remote Object绑定。



Naming其实是对Registry的一个封装
