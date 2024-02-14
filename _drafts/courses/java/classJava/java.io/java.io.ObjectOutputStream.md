对象流：ObjectInputStream 和 ObjectOutStream，DataInputStream/DataOutputStream流只是解决了Java8种基础数据类型的流，而对象流不仅仅有读写Java的8种基础数据类型还可以将一个实例化的对象写入磁盘。

序列化：将一个实例化对象写入磁盘叫做序列化。

反序列化：将一个写入磁盘的的实例化读取出来转化为一个对象叫做反序列化。

需要序列化的对象类一定要实现Serializable接口。

```java
writeObject(Serializab);//
```

