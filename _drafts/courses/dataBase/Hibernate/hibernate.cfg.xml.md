### Hibernate配置

`hibernate.cfg.xml`总配置文件

```xml
<!DOCTYPE hibernate-configuration PUBLIC
        "-//Hibernate/Hibernate Configuration DTD 3.0//EN"
        "http://www.hibernate.org/dtd/hibernate-configuration-3.0.dtd">

<hibernate-configuration>
    <session-factory>
        <!-- 配置数据库信息 -->
        <property name="connection.url">jdbc:mysql:///luntan?useUnicode=yes&amp;characterEncoding=utf8</property>
        <!-- 初始化jdbc连接 -->
        <property name="hibernate.connection.driver_class">com.mysql.jdbc.Driver</property>
        <!-- mysql连接 -->
        <property name="connection.username">root</property>
        <property name="connection.password">root</property>
        <!-- 方言(连接的数据库类型) -->
        <property name="dialect">org.hibernate.dialect.MySQLDialect</property>
        <!-- 数据库更新方式 -->
        <property name="hibernate.hbm2ddl.auto">update</property>
        <!-- 打印sql语句 -->
        <property name="show_sql">true</property>
        <!-- sql语句格式化 -->
        <property name="format_sql">true</property>
        <!-- 3. 导入映射文件 -->
        <mapping resource="com/pojo/User.hbm.xml" />
        <mapping resource="com/pojo/Counter.hbm.xml"/>
        <mapping resource="com/pojo/Topic.hbm.xml"/>
        <mapping resource="com/pojo/Post.hbm.xml"/>

    </session-factory>
</hibernate-configuration>
```

#### 数据库更新方式

```xml
<property name="hibernate.hbm2ddl.auto">update</property>
```

- create 每次执行前删除表数据，重新创建然后创建该表，这是导致数据库表数据丢失的一个原因；

- create-drop 每次执行前删除表数据，重新创建然后创建该表，sessionFactory关闭时将删除该数据表；

- validate 每次加载hibernate时，都将验证数据表结构，只会和数据库中的表作比较，不会创建新表，不一致就会抛出异常，但是会插入新值；

- update  最常用的属性，第一次加载hiberbnate时根据model类会自动建立起表的结构（前提是先建立好数据库），以后加载hibernate时根据model类自动更新表结构，即使表结构改变了，但表中原来的行仍然存在，不会删除表中原来的行，要注意的是，在部署到服务器后，表结构是不会被马上建立起来的，是要等应用第一次运行起来后；

#### 打印sql语句

```xml
<!-- 打印sql语句 -->
<property name="show_sql">true</property>
<!-- sql语句格式化 -->
<property name="format_sql">true</property>
```

如果你是查询，idea会打印出sql语句

### 配置数据库信息

```xml
        <property name="connection.url">jdbc:mysql:///luntan?useUnicode=yes&amp;characterEncoding=utf8</property>
```

参数名称	|参数说明|	缺省值|	最低版本要求
-|-|-|-
user	|数据库用户名（用于连接数据库）	|	所有版本
password	|用户密码（用于连接数据库）	|	所有版本
useUnicode	|是否使用Unicode字符集，如果参数characterEncoding设置为gb2312或gbk，本参数值必须设置为true|	false	|1.1g
characterEncoding	|当useUnicode设置为true时，指定字符编码。比如可设置为gb2312或gbk	|false	|1.1g
autoReconnect	|当数据库连接异常中断时，是否自动重新连接？	|false	|1.1
autoReconnectForPools|	是否使用针对数据库连接池的重连策略	|false|	3.1.3
failOverReadOnly	|自动重连成功后，连接是否设置为只读？	|true|	3.0.12
maxReconnects|	autoReconnect设置为true时，重试连接的次数|	3	|1.1
initialTimeout	|autoReconnect设置为true时，两次重连之间的时间间隔，单位：秒	|2	|1.1
connectTimeout|	和数据库服务器建立socket连接时的超时，单位：毫秒。 0表示永不超时，适用于JDK 1.4及更高版本|	0	|3.0.1
socketTimeout	|socket操作（读写）超时，单位：毫秒。 0表示永不超时|	0	|3.0.1

mysql的常用配置：

jdbc:mysql://localhost:3306/数据库名?autoReconnect=true&useUnicode=true&characterEncoding=utf8&serverTimezone=GMT%2B8
