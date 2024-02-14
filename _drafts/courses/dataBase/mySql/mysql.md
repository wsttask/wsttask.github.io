```mysql
//登录数据库
mysql -h localhost -u root -p

//显示所有数据库
show databases；

//进入数据库
user database_name


// 删除表
drop table 数据表名称

//查询表中信息
desc t_user;
```

## 表

//表的属性约束

Fileld|Type|Null|Key|Default|Extra
-|-|-|-|-|-
属性|数据类型|是否为空|主键|默认值|额外

##### Null

null / not null

- 没有显示定义时，默认的约束是属性列可以为空(null)。
- 可以显示定义属性列的数据不能为空(not null)。
- 数据库**默认字段基本都是字段为空**，但是实际开发时，尽可能保证字段不为空，因为数据为空没办法参与运算。
- 没有定义不能为空，当插入的时候，就Default NULL了

##### default

- 默认值的生效：数据在插入的时候不给该字段赋值，就使用默认值。
- 数据在插入的时候不给该字段赋值，并且表定义时没给默认值，无法直接插入。
- 设定默认值不代表数据不可能为空，用户可能指定插入空值。
- 系统默认的默认值为null。
- 设定not null就没有系统默认值。
- 如果没有设定not null，并且default了，在插入属性的时候没有指定，则是默认，指定了但为空，插入的为空

```sql
create table test (
	name varchar(20) not null,
    age tinyint default 18,
    sex char(1) not null default '男'
);
```

**非空属性和默认值是相互补充的，非空属性约束的是用户不能插入空值，默认值约束的是用户忽略该列时插入什么数据(没设置会报错)。**



##### comment

列描述

- 列描述是给程序员看的。
- 列描述不是硬性的约束，不会实际限制插入的数据。

- desc无法查看列描述

##### primary key

主键用来唯一的约束该字段里面的数据。主键所在的列通常是整数类型。

- 主键不能为空。
- 主键不能重复。
- 一张表中最多只能有一个主键。
- 可以在创建表时加主键约束，也可以在创建表后加主键约束。
- 给表加主键约束最好在表使用前加主键约束。

复合主键

- 复合主键是将多个属性组成的整体称为主键。
- 复合主键中的属性只要有一个不是重复的，就不产生冲突。

#####  外键(foreign key)

- 从表外键数据来源于**主表的主键或唯一键**。
- 删除主表中某一个键所在的记录，需要从表中没有该键做的外键。
- 外键使得表之间产生联系。
- 外键使得表互相约束。



##### 自增长(auto_increment)

自增长是对应的字段，不给值，会自动的被系统触发，系统会从当前字段中已经有的最大值 +1操作，得到一个新的不同的值。通常和主键搭配使用，作为逻辑主键。

- 任何一个字段要做自增长，前提是本身是一个索引（key一栏有值）。
- 自增长字段必须是整数 。
- 一张表最多只能有一个自增长。
- last_insert_id()函数(select last_insert_id())可以查看上次插入的 AUTO_INCREMENT 的值。
- 自增长的默认初始值为1，也可以自行设置。

##### 唯一键（unique）

唯一键用于解决表中有多个字段需要唯一性约束的问题。

- 唯一键允许为空，而且可以多个为空，空字段不做唯一性比较。
- 一张表中可以有多个唯一键。

**主键和唯一键的区别：**主键的作用是确定表中唯一一条记录，如果主键不是唯一的，通过主键就会查找到多个记录，因此主键必须唯一，如果主键为空，空和空无法比较，有多个空主键也就会无法确定唯一一条记录，因此主键不能为空。唯一键的作用是让某些属性在表中不重复，是为了满足某些数据需要唯一的要求，因此唯一键属性可以为空，因为没有实质数据做比较。实际上，主键只是在众多唯一键中选择出来的，然后加上了非空的限定

#### 表的操作

```sql
//进入数据库
user database_name



//创建表
create table t_user(
	user_id	int not null auto_increment,
	user_name Varchar(30) not null,
	user_password Varchar(30),
	user_type tinyint not null,
	user_locked	tinyint,
    sex enum('男','女'), # enum表示枚举类型
    primary key ('user_id'),
    foregin key(user_type) references counter(id) #设置外键
);

//查看表的信息
desc table name;
//查看数据库优化后的创建表的代
show create table name;

// 删除主键
alter table name drop primary key;

// 添加主键
alter table name add primary key;

// 设置外键
alter table name add foregin key(name) references name

// 导入sql文件	
source path

// 向表中插入数据
insert into 表名(列名1, 列名2, 列名3,...) values(列值1,列值2,列值3,...)
```

