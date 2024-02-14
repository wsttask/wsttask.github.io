# HQL

hql：即 hibernate query language

### 常用方式

```java
String hql = "HQL语句";
Query query = session.createQuery(hql);//创建query对象
List list = query.list(); //查询得到多个实体对象集合
Object result = query.uniqueResult(); //查询得到一个实体对象
int x = query.executeUpdate(); //执行update或delete语句，返回数据表受影响行数
```

#### 参数绑定

```java
String hql = "from Users where uid=:no1 or uid=:no2";
Query query = session.createQuery(hql);
query.setInteger("no1", 1);
query.setInteger("no2", 3);
//....
```

### createQuery

在Hibernate中，`session.createQuery(hql)`和`session.createQuery(hql, User.class)`是用于创建查询对象的两种方法，它们之间有一些区别。

1. **返回类型：**
   - `session.createQuery(hql)`返回的是一个`Query`对象，该对象可以用于执行HQL（Hibernate Query Language）查询。
   - `session.createQuery(hql, User.class)`返回的是一个`TypedQuery`对象，这个对象是类型安全的，它知道查询的返回类型是`User.class`。
2. **类型安全：**
   - `session.createQuery(hql)`返回的`Query`对象是类型不确定的，你需要手动进行类型转换，而且在运行时可能会抛出类型转换异常。
   - `session.createQuery(hql, User.class)`返回的`TypedQuery`对象是类型安全的，因为它已经指定了查询的返回类型为`User.class`，因此你不需要进行手动类型转换。
3. **编译时检查：**
   - 由于`session.createQuery(hql)`返回的`Query`对象是不带类型信息的，所以任何语法错误或拼写错误都只能在运行时被检测到。
   - `session.createQuery(hql, User.class)`中的`TypedQuery`对象可以在编译时检查HQL语句的正确性，从而避免在运行时发现错误。

### uniqueResult()

`query.uniqueResult()` 是 Hibernate 中用于执行查询并返回唯一结果的方法。该方法期望查询只返回一个结果，否则会抛出异常。以下是一些关键点：

1. **期望唯一结果：** `uniqueResult()` 方法适用于期望查询结果只有一个对象的情况。如果查询返回多个结果或者没有结果，`uniqueResult()` 将抛出 `NonUniqueResultException` 或 `NoResultException` 异常。
2. **使用谨慎：** 在使用 `uniqueResult()` 时，确保你的查询确实只返回一个结果。否则，最好使用 `list()` 方法，然后根据需要处理结果列表。
3. **类型转换：** 返回结果是一个 `Object`，因此在使用之前你可能需要进行类型转换。例如，如果你期望的结
