## 一、Dao层是什么

DAO（Data Access Object）模型就是写一个类，把访问数据库的代码封装起来，DAO在数据库与业务逻辑（Service）之间。

Dao是数据访问层，Dao的作用是封装对数据库的访问：增删改查，不涉及业务逻辑，只是达到按某个条件获得指定数据的要求。

### 二、Entity层是什么？

Entity层，顾名思义就是实体层，放置一个个实体，及其相应的set、get方法。如果想要对数据库进行一些操作（比如说读取）的话，就要先写entity层。

###### 怎么写entity层?

1.理解业务需求，分析需要从数据库中读取哪些字段；
2.根据这些字段写对应属性，写完后[自动生成get、set方法]。（这里我用的是`IntelliJ IDEA` ，快捷键`Alt+Insert`,然后就有`Getter和Setter`方法）