```python
print()
//输出到控制台
print("我今年",age,"岁了")

type(variable)
# 返回variable的类型信息
# literal，也可以输出字面量的类型

int(x)
# 把x转换为一个整数

float(x)

str(x)
# str(x)可以把variable转换为字符串
# 所有变量都可转换成数字
# 字符串转换成数字必须符合其规则，int（只有数字）


exit()
//退出解释器
```

![image-20230523115300031](../images/image-20230523115300031.png)

pycharm设置快捷键

file->setting->搜索“incre”->右击“increase font size”->add mouse shortcut->ctrl+wheel up



##### 注释

1. 单行注释

   ```python
   # 我是注释
   print("Hello World") # 我是注释
   注意井号和注释内容建议一个空格隔开
   ```

2. 多行注释

   ```python
   """
   我是多行注释
   行一
   行二
   """
   ```

##### 注释之间的嵌套

```python
1.单行注释中能否使用多行注释
如果多行注释只占用一行，单行注释可以嵌套多行注释；若多行注释占用多行，则无法嵌套了，
2.多行注释中能否使用单行注释
可以。这种情况下，无论外层的多行注释占用几行都没有问题。
3.多行注释中能否使用多行注释
不可以。无论多行注释嵌套的多行注释共占据单行还是多行，都不可以成功。
多行注释嵌套多行注释，势必为"“”“”“注释内容”“”“”"。计算机会将最前面的三对双引号视为多行注释，再将最后面的三对双引号视为多行注释符，这两者的注释内容都为空。而真正的注释内容却暴露在外，没有多行注释符的提示，系统无法识别，只会认为是语法错误。
```



##### 变量和字面量

1. 变量是没有数据类型的！（有可能是指针）（而且指针可以指向任一一个数据类型

   > 这是python的一大特点

2. 字面量即常量

```python
print(字面量)，

如：
print(10)，输出整数10

print(13.14)，输出浮点数13.14

print("黑马程序员")，输出字符串：黑马程序员
# 整数与浮点数的字面量都与现实中的写法相同
# 只有字符串在程序中的写法相比较现实中的写法需要多加一个双引号“”
```

##### 数据类型转换

```python
int(x)
float(x)
str(x)

x = True
int(x) = 1
float(x) = 1.0

# 浮点数转换为整数会丢失精度
```



##### 标识符

1. 标识符命名元素：英文、中文、数字、下划线，
2. 数字不可以开头
3. 下划线可以开头
4. 大小写敏感
5. 不可使用关键字

##### 变量命名规范

1. 见明知意
2. 下划线命名
3. 英文字符应全小写

关键字

```python
False 
True
None
# 这三个关键字首字母大写
定义false,true,none不算占用关键字
```

##### 算数运算符

```python
+
-
*
/
# 直接得到小数！

//
# 取整除
# 注意和java，c都不一样

%
# 取余

**
# 指数
# x**y:x的y次方
```

##### 快捷键

```
pycharm
ctrl+d:复制当前一行代码
```

##### 字符串的三种定义方式

1. 单引号定义法：`name = '李华'`

2. 双引号定义法：`name = "李华"`

3. 三引号定义法：`name = """李华"""`

   > 三引号定义发可以加\n
   >
   > ```
   > name = """
   > 李
   > 华
   > """
   > ```

```python
name = '"李华"'
# 在字符串中包含双引号

name = "'李华'"
# 在字符串中包含单引号

name = '\"李华\"'
name = "\'李华\'"
#  转移zi'fu
```

##### 字符串拼接

1. 可以通过"+"进行字符串拼接

   ```python
   print("Hello"+"World")
   > HelloWorld
   print("Hello","World")
   > Hello World
   ```

   缺点，不可以和数字进行拼接，只能和字符串进行拼接

   ```python
   print("Hello"+"World"+1000)
   ```

   可以通过把数字变成字符串进行拼接

   ```python
   print("hello"+"world"+"1000")
   ```

##### 字符串格式化

```python
message = "我是练习时常%d年半的个人偶像练习生" % 2
message = "我是练习时常%s年%s的个人偶像练习生" % (2,0.50)
> 我是练习时常2年0.5的个人偶像练习生
message = "我是练习时常%s年%s的个人偶像练习生" % (2,0.50)
> 我是练习时常2年0.500000的个人偶像练习生
# %s 万物皆可转换成字符串

%s:字符串
%d:整数
%f:浮点数
```

##### 字符串格式化的精度控制

```pthon
%5d:将数字的宽度控制在5位，宽度不够补空格，限制宽度小于实际宽度，限制宽度不起作用
%5.2f:变送将宽度控制为5，将小数点精度设置为2，并且四舍五入（小数点也占一个宽度）
```

##### 快速字符串格式化

![image-20230526194757322](../images/image-20230526194757322.png)

快速格式化，不限制数据类型，但是也不做精度控制。

##### 表达式的格式化

```python
print("1*1的结果是:%d" % (1*1))
print(f"1*1的结果是:{1*1}")
print("字符串在Python中的类型名是：%s" % type("字符串"))
```

##### 数据输入（input）语句

```python
name = input("请告诉我你的银行卡密码")
# 也可以手动提示，提前用print打印提示信息
print("你的银行卡密码的数据类型是：",type(num))
# input输入的永远是字符串类型
```

##### bool变量

```python
a = True
print("%s" % a)
> True

a = True
print(a-1)
> 0

a = True
print(a > 3)
> False

a = True
print(a > 0)
> True

# 布尔变量在做运算的时候是当做1和0来进行运算的
```

##### if判断语句

```python
age = 18
# 判断语句的结果，必须是布尔类型True或False
if age >= 18:
# 需要一个冒号
	print("我已经成年了")
	print("我要上大学了")
# 归属于if判断的代码语句块，需要在前方填充4个空格缩进
# Python通过缩进判断代码块的归属关系
print("时间过的真快")

```

##### if-else语句

```python
age = int(input("请输入您的年龄："))
if age >= 18:
    print("您已经成年，需要买票")
elif age <= 10:
    print("您未成年，不需要买票")
else:
    print("mmmmm")
print("欢迎游玩")
```



##### for循环语句

for 临时变量 in 待处理数据集（可迭代对象）:

​		循环满足条件时执行的代码

```python
name = "python"
for x in name:
	print(x)
```

```python
range(num)
# 从0取到num-1
range(5)=[0,1,2,3,4]

range(num1,num2)
# 从num1取到num2（不包含num2本身）
range(5,10)=[5,6,7,8,9]

range(num1,num2,step)
# 从num1开始，到num2(不包含num2),是以step为间隔
range(5,10,2)=[5,7,9]
```

- 作用域

​	注意for中定义的临时变量不可以在for循环的外面使用！
##### continue和break

```python
continue:进入下一个循环
break:结束当前循环
```

### 函数

```python
#  函数的定义
def name(variable):
	body
    return value
# 注意:python不用写返回类型，自动匹配
```

思考：如果函数没有使用return语句返回数据，那么函数有返回值吗？

事实上：有的。

Python中有一个特殊的字面量：None，其类型是：<class 'NoneType'>，无返回值的函数，实际上就是返回了：None这个字面量

None表示：空的、无实际意义的意思

函数返回None，就表示，这个函数没有返回什么有意义的内容，也就是返回了空的意思。

**在Python中，None是一个单独的对象，它是NoneType类的唯一实例。它在内存中以单例模式存储，也就是说只有一个None对象存在。当我们使用None时，我们实际上是在引用这个唯一的None对象。**

None可以主动使用return返回，效果等同于不写return语句

- None类型的应用场景：

  - 用在函数无返回值上

  - 用在if判断上
    
    - **在if判断中，None等同于False**
    - **一般用于在函数中主动返回None，配合if判断做相关处理**
    
    ```py
    def check_age(age)
    	if age > 18
        	return "SUCCESS"
        return None
    
    result = check_age(5)
    if not result
    	print("未成年，不可进入")
    ```
  
    - 用于声明无内容的变量上
  
      - 定义变量，但暂时不需要变量有具体值，可以用None来代替
  
      ```py
      # 暂不赋予变量具体值
      name = None
      ```
  
- 函数的说明文档
  - 在PyCharm中可以通过鼠标悬停，查看调用函数的说明文档


```python
def func(x, y):
    """
    函数说明
    :param x: 形参x的说明
    :param y: 形参y的说明
    :retrun: 返回值的说明
    """
    body
    return 返回值
```

- 局部变量与全局变量
  - 在函数内部定义的就是局部变量
  - 在函数外定义的就是全局变量

- global 关键字可以在函数内部声明变量为全局变量

```python
num = 100
def testB()
	# global 关键字是声明a是全局变量
    global num
    num = 200
    print(num)
testB
print(f'全局变量num = {num}')
# 是对全局变量进行修改了
# 不加global不弄修改全局变量num，而是重新定义一个局部变量num
```







### 数据容器

#### 列表（list）

##### 列表的定义

```python
# 字面量
[元素1, 元素2, 元素3, 元素4, ...]

# 定义变量
变量名称 = [元素1, 元素2, 元素3, 元素4, ...]

# 定义空列表
变量名称 = []
变量名称 = list()
```

- 以 [] 作为标识
- 列表内每一个元素之间用 ，逗号 隔开

注意：列表可以一次存储多个数据，**且可以为不同的数据类型，支持嵌套**



##### 列表的下标（索引）

```python
# 语法： 列表[下表索引]

name_list = ['Tom', 'Lily', 'Rose']
print(name_list[0])
print(name_list[1])
print(name_list[2])
>
Tom
Lily
Rose

# 支持反向索引

name_list = ['Tom', 'Lily', 'Rose']
print(name_list[-1])
print(name_list[-2])
print(name_list[-3])
>
Rose
Lily
Tom

# 支持嵌套索引

my_list = [ [1, 2, 3], [4, 5, 6] ]

print(my_list[0])

print(my_list[0][0])
```

##### 列表的常用方法

```python
# 查询
# 语法：列表.index(元素)
# 功能：查找指定元素在列表的下标

my_list = ["itheima", "itcast", "python"]
print(my_list.index("itcast"))

>
1

# 修改
my_list = [1, 3, 5]
my_list[0] = 5
print(my_list[0])

my_list = [1, 3, 5]
my_list[-3] = 5
print(my_list)


# 插入
my_list = [1, 2, 3]
my_list.insert(1, "itheima")
print(my_list)

>
[1, 'itheima', 2, 3]

# 追加
my_list = [1, 2, 3]
my_list.append(4)
print(my_list)
>
[1, 2, 3, 4]

my_list = [1, 2, 3]
my_list.append([4, 5, 6])
print(my_list)
[1, 2, 3, [4, 5, 6]]

# 追加元素2
my_list = [1, 2, 3]
my_list.extend([4, 5, 6])
print(my_list)
> 
[1, 2, 3, 4, 5, 6]

# 删除元素
my_list = [1, 2, 3]

del my_list[0]
print

my_list.pop(0)
print(my_list)
```

##### 列表的特点

```python
1. 可以容纳多个数据（上限是2**63-1）

2. 可以容纳不同类型的数据（混装）

3. 数据是有序存储的

4. 允许重复数据存在

5. 可以修改
```



#### 元组（tuple）

列表是可以修改的，但是元组一旦定义完成，就不能修改

##### 元组的定义

```python
# 定义元组字面量
(元素，元素，......，元素)

# 定义元组变量
变量名称 = (元素,元素,.....,元素)

# 定义空元组
变量名称 = ()		# 方式1
变量名称 = tuple() 	# 方式2

注意！
# 定义3个元素的元组
t1 = (1, 'hello', True)

# 定义1个元素的元组
t2 = ('hello', )	# 注意，必须带有逗号，否则不是元组类型，而括号内唯一元素的类型

# 元组也支持嵌套
t1  = ( (1, 2, 3), (4, 5, 6) )
```

##### 元组的相关操作

```python
# 根据下标（索引）去除数据
t1 = (1, 2, 'hello')

# 根据index(),查找特定元素的的第一个匹配项
t1 = (1, 2, 'hello', 3, 4, 'hello')
print(t1.index('hello'))

# 统计某个数据在元组内出现的次数
t1 = (1, 2, 'hello', 3, 4, 'ehllo')
print(t1.count('hello'))

# 统计元组内的元素的个数
t1 = (1, 2, 3)
print(len(t1))

注意！

1. 不可以修改元组的内容，否则会直接报错

2. 可以修改元组内的list的内容

3. 不可以替换list为其他的list或其他类型
```

##### 元组的特点

```python
1. 可以容纳多个数据

2. 可以容纳不同类型的数据（混装）

3. 数据是有序存储的（下标索引）

4. 允许重复数据存在

5. 不可以修改（most important）

6. 支持for循环
```

#### 字符串

##### 字符串的特点

```python
同元组一样，字符串是一个：无法修改的数据容器。

不能！
1. 修改指定下表的字符	(str[0] = 'a')

2. 移除特定下表的字符	(del str[0])

3. 追加字符				(str.append())

如果必须要进行以上操作，只能得到一个新的字符串，旧的字符串是无法修改的
```

##### 字符串的常用操作

```python
# 查找特定字符串的下标索引值
my_str = "itcast and itheima"
print(my_str.index("and"))

# 字符串的替换（不是修改）
name = "itheima itcast"
new_name = name.replace("it", "he")

print(new_name)			# 结果，hetheiam hecast
print(name)				# 结果，ittheiam itcast

	可以看到，字符串name本身并没有发生变化
    而是得到了一个新的字符串对象

# 字符串的分割

name = "it he she"
name_list = name.split(" ")

print(name_list)		# 结果，['it', 'he', 'she']
print(type(name_list)) 	# 结果：<class 'list'>

.split函数是将给定的分割符对字符串进行分割，变成多个子字符串，并存入一个列表对象中。

# 字符串的规整操作1（去前后空格）

my_str = " itheima and itcast "
print(my_str.strip())			#结果："itheima and itcast"


# 字符串的规整操作2（去前后指定字符串）

my_str = "12itheima and itcast21"
print(my_str.strip("12")) 		# 结果："itheima and itcast"
——————————————————————————————————————————————————————————————————————？
问题：
1. 无论是12还是21都可以去除
2. 21i会把前面的去掉，但是后面的不变
——》推测不根据顺序，而是一个无顺序的集合


# 统计字符串中某字符串的出现次数

my_str = "itheima and itcast"
print(my_str.count("it")) 		# 结果:2

# 统计字符串的长度

my_str = "1234 abcd !@#$"
print(len(my_str))				# 结果:14
```

##### 字符串的特点

```python
1. 只能存储字符串

2. 长度任意

3. 支持下标索引

4. 允许重复字符存在

5. 不可以修改

6. 支持for循环
```

##### 序列切片

```python
切片：从一个序列中，取出一个子序列

语法：序列[起始下标:结束下标:步长]

>>
	不是由函数实现功能，是根据两个中括号来实现，推测是把函数内嵌进入python编辑器里边。

- 首先所有的序列都可以使用这个切片功能，包括元组，字符串，列表都可以

- 步长的含义：1:表示一个一个取元素
			2:表示跳过一个元素取
    		3:步长可以用负数表示，表示反向取，此时，起始下标和结束下标也要反向标记
        	4:反向标记，可以用来反着取比如12345取54321
            
！注意：步长不可以为0，其实想想就知道，走0步不就一直停在那了
```

#### 集合

```python
- 列表：[]
- 元组：()
- 字符串：""
- 集合：{}
```

##### 集合的定义

```python
# 定义集合字面量
{元素, 元素, ......, 元素}

# 定义集合变量
变量名称 = {元素, 元素, ......, 元素}

# 定义空集合
变量名称 = set()
```

##### 集合的特点

```python
- 不重复
	即使在定义集合变量的时候由重复的元素，也会自动去重

- 没有顺序
	不能保证顺序与创建的时候一致
    不支持下标索引
    
- 可以修改
	增加或删除元素等
    
- 支持for循环
```

##### 集合的常用操作

```python
# 修改
my_set = {"hello", "world"}
my_set.add("itheima")
print(my_set) # 结果{'hello', 'itheima', world}

# 移除
my_set = {"hello", "world", "itheima"}
my_set.remove("hello")
print(my_set) 	# 结果 {'hello', 'itheima'}

# 随机取出元素
my_set = {"hello", "world", "itheiam"}
element = my_set.pop()
print(my_set)	# 结果 {'world', 'itheima'}
print(element)	# 结果 'hello'

# 清空集合
my_set = {"hello", "world", "itheiam"}
my_set.clear()
print(my_set)	# 结果：set()	空集合

# 取出两个集合的差集
set1 = {1, 2, 3}
set2 = {1, 5, 6}
set3 = set1.difference(set2)
print(set3)
print(set1)
print(set2)

# 消除两个集合的差集
set1 = {1, 2, 3}
set2 = {1, 5, 6}
set1.difference_update(set2)
print(set1)	# {2, 3}
print(set2)	# {1, 5, 6}
！注意，此时集合1被修改，但是集合2不变

# 两个集合合并
set1 = {1, 2, 3}
set2 = {1, 5, 6}
set3 = set1.union(set2)
print(set3)	# 结果：{1, 2, 3, 5, 6}，新集合
print(set1)	# 结果：{1, 2, 3}，set1不变
print(set2)	# 结果：{1, 5, 6}，set2不变

# 查看集合的元素的数量
set1 = {1, 2, 3}
print(len(set1))	# 结果：3

# 集合同样支持使用for循环遍历
set1 = {1, 2, 3}
for i in set1:
    print(i)
   
# 结果
1
2
3

```

#### 字典（dict）

##### 字典的定义

```python
# 定义字典字面量
{key: value, key: value, ..., key: value}
# 定义字典变量
my_dict = {key: value, key: value, ..., key: value}
# 定义空字典
my_dict = {}	# 空字典定义方式1
my_dict = dict()# 空字典定义方式2

注意：
- 使用{}存储原始，每一个元素是一个键值对
- 每一个键值对包含Key和Value（用冒号分隔）
- 键值对之间使用逗号分隔
- Key和Value可以是任意类型的数据（key不可为字典）
- Key不可重复，重复会对原有数据覆盖
```

##### 字典数据的获取

```python
# 语法，字典[key]可以取到对应的value
stu_score = {"王力宏": 99, "周杰伦": 88, "林俊杰": 77}
print(stu_score["王力宏"])	# 结果：99
print(stu_score["周杰伦"])	# 结果：88
print(stu_score["林俊杰"])	# 结果：77
```

##### 字典可以嵌套

```python
stu_score = {
    "wang": {"chinese": 77, "math": 66, "English": 33}
    "zhou": {"chinese": 88, "math": 86, "English": 55}
    "lin": {"chinese": 99, "math": 96, "English": 66}
}

print(stu_score["wang"])	# 结果：{"chinese": 77, "math": 66, "English": 33}
```

##### 字典的操作

```python
# 新增元素
stu_score["zhang"] = 66

# 修改元素
stu_score["wang"] = 100

# 删除元素
value = stu_score.pop("wang")
print(value)		# 结果：77
print(stu_score)	# 结果：wang的key已经消失

# 清空字典
stu_score.clear()

# 获取字典中的全部的key
keys = stu_score.keys()
print(keys) # 结果：dict_keys(['wang', 'zhou', 'lin'])

# 遍历字典
stu_score = {"王力宏": 99, "周杰伦": 88, "林俊杰": 77}
keys = stu_score.keys()
for key in keys:
    print(f"学生:{key},分数:{stu_score[key]}")
    
# 计算字典内键值对的数量
stu_score = {
    "王力宏": 99, 
    "周杰伦": 88, 
    "林俊杰": 77
}
print(len(stu_score))		# 结果：3

```

