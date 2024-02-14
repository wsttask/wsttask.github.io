在Linux中编写shell脚本时，在文本首行需要输入#!/bin/sh或者#!/bin/bash，这两个比较常见，还有其他的比如#!/bin/dash等，含义和区别如下：

```bash
#!/bin/bash
```

一、含义：定义使用哪种shell解释器来解释该shell脚本

#!/bin/sh表示该脚本使用/bin/sh来解释执行，#!/bin/bash表示该脚本使用/bin/bash来解释执行。每个脚本开头都使用**"#!"**，#!实际上是一个2字节魔法数字，指定一个文件类型的特殊标记，在这种情况下，指的就是一个可执行的脚本。在#!之后，接一个路径名，这个路径名指定一个解释脚本命令的程序，这个程序可以是shell，或者任意一个通用程序。

在命令行中输入 ls /bin/*sh -l 指令查看系统实际的解释器，显示如下：

![img](../images/20201210174340330.png)

sh是bash的一种特殊的模式，也就是/bin/sh相当于/bin/bash --posix。说白了sh就是开启了POSIX标准的bash 。在一般的Linux系统当中（如Ubuntu），使用sh调用执行脚本相当于打开了bash的POSIX标准模式。sh一般设成bash的软链接，如上图所示。

在命令行中输入 cat /etc/shells 指令查看自己系统可以使用的shell种类：

![img](../images/20201210174627107.png)

在命令行中输入 cat /etc/passwd指令查看当前系统默认使用的shell如下：

![img](../images/20201210180322395.png)



三种执行方式 （./xxx.sh bash xxx.sh . xxx.sh）
三种执行方式的不同点（./xxx.sh bash xxx.sh . xxx.sh）

./xxx.sh :先按照 文件中#!指定的解析器解析
如果#！指定指定的解析器不存在 才会使用系统默认的解析器

bash xxx.sh:指明先用bash解析器解析
如果bash不存在 才会使用默认解析器

. xxx.sh 直接使用默认解析器解析（不会执行第一行的#！指定的解析器）但是第一行还是要写的



##### 变量

定义变量
变量名=变量值
如：num=10
引用变量
$变量名
unset ：清除变量值

![在这里插入图片描述](../images/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzI4ODIwMQ==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](../images/watermark,type_ZmFuZ3poZZG4ubmV0L3dlaXhpbl80MzI4ODIwMQ==,size_16,color_FFFFFF,t_70)

从键盘获取值read

![在这里插入图片描述](../images/watermark,type_ZmFuZ3poZW5naGVpXhpbl80MzI4ODIwMQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](../images/20200420204743982.png)



![在这里插入图片描述](../images/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmN0L3dlaXhpbl80MzI4ODIwMQ==,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](../images/watermaVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzI4ODIwMQ==,size_16,color_FFFFFF,t_70)

读取多个值

```bash
#!/bin/bash
num=10
echo "num=$num"
read -p "请输入Num的值：" num
echo "num=$num"
read data1 data2
echo "data1=$data1"
echo "data2=$data2"
```

只读变量



![在这里插入图片描述](../images/251)

![在这里插入图片描述](../images/461)



注意事项：
1、变量名只能包含英文字母下划线，不能以数字开头
1_num=10 错误
num_1=20 正确
2、等号两边不能直接接空格符，若变量中本身就包含了空格，则整个字符串都要用双引号、或单引号括起来
3、双引号 单引号的区别
双引号：可以解析变量的值
单引号：不能解析变量的值

![image-20230602215356416](../images/image-20230602215356416.png)

![image-20230602220606610](../images/image-20230602220606610.png)

#### 6.2 字符串的操作

![在这里插入图片描述](../images/撒地方)

`这里的$好像意思是引用{#str}这一表达式的结果，要不然后边的表达式就不会转义，有点像\`



### 7、条件测试

##### 7.1 文件测试

test命令：用于测试字符串、文件状态和数字
test命令有两种格式:
test condition 或[ condition ]
使用方括号时，要注意在条件两边加上空格。

![在这里插入图片描述](../images/453)

![在这里插入图片描述](../images/3234)



:question:这里的$有点像c中的引用，fileName就好像一个地址



##### 7.2 字符串测试

![在这里插入图片描述](../images/23)

![在这里插入图片描述](../images/543)

![在这里插入图片描述](../images/765756)

##### 7.3 数值测试

![在这里插入图片描述](../images/3242)

![在这里插入图片描述](../images/2524524)

![在这里插入图片描述](../images/64457)



##### 7.4 复合语句测试

![在这里插入图片描述](../images/34234)

![在这里插入图片描述](../images/63736)

### 一、shell介绍

#### $ 的用法

##### 1. 引用变量

```bash
[root@localhost ~]# x=1024
[root@localhost ~]# echo $x
1024

[root@localhost ~]# x=1024
[root@localhost ~]# echo "x = $x"
x = 1024
# 利用双引号括起来的内容支持变量插值

[root@localhost ~]# x=1024
[root@localhost ~]# echo "x = ${x}xy"
x = 1024xy

[root@localhost etc]# s=helloworld
[root@localhost etc]# echo "s.length = ${#s}"
s.length = 10
```

##### 2.引用脚本或函数参数

```bash


```

##### 3. 执行命令并输出

```bash
[root@localhost ~]# echo `date`
2016年 06月 05日 星期日 12:39:08 CST
[root@localhost ~]# echo $(date)
2016年 06月 05日 星期日 12:39:34 CST

```

##### 4. 四种模式匹配替换结构

```bash
${var#pattern}：从变量 var 的开头删除最短匹配 pattern 的字符串。
${var##pattern}：从变量 var 的开头删除最长匹配 pattern 的字符串。
${var%pattern}：从变量 var 的结尾删除最短匹配 pattern 的字符串。
${var%%pattern}：从变量 var 的结尾删除最长匹配 pattern 的字符串。
${var/pattern/replacement}：将变量 var 中第一个匹配 pattern 的字符串替换为 replacement。
${var//pattern/replacement}：将变量 var 中所有匹配 pattern 的字符串替换为 replacement。

    # var=testcase  
    # echo $var  
    testcase  
    # echo ${var%s*e} 
    testca  
    # echo $var  
    testcase 
    # echo ${var%%s*e} 
    te
    # echo ${var#?e}  
    stcase
    # echo ${var##?e}  
    stcase
    # echo ${var##*e}  
 
    # echo ${var##*s}  
    e  
    # echo ${var##test}  
    case  
```



#### shell 中字符串拼接方法

```bash
#!/bin/bash

name="Shell"
url="http://c.biancheng.net/shell/"

str1=$name$url  #中间不能有空格
str2="$name $url"  #如果被双引号包围，那么中间可以有空格
str3=$name": "$url  #中间可以出现别的字符串
str4="$name: $url"  #这样写也可以
str5="${name}Script: ${url}index.html"  #这个时候需要给变量名加上大括号

echo $str1
echo $str2
echo $str3
echo $str4
echo $str5


Shellhttp://c.biancheng.net/shell/
Shell http://c.biancheng.net/shell/
Shell: http://c.biancheng.net/shell/
Shell: http://c.biancheng.net/shell/
ShellScript: http://c.biancheng.net/shell/index.html

```





### 二、shell环境变量

#### 2.1 shell变量

```bash
# 常见的3种变量
Shell编程中变量分为三种，分别是系统变量、环境变量和用户变量，Shell变量名在定义时，首个字符必须为字母（a-z，A-Z），不能以数字开头，中间不能有空格，可以使用下划线（_），不能使用（-），也不能使用标点符号等。

# 在Shell中，变量的值是没有类型的，也就是说，变量保存的值在使用时可以被视为任何类型。在Shell中，比较大小的操作符（如 -eq，-ne，-gt，-lt等）只适用于整数类型。但是，在比较大小时，如果变量的值可以被转换为整数类型，Shell会自动将其转换为整数类型然后进行比较。因此，即使read命令读取的值保存在变量中的是字符串类型，在使用时也可以被视为整数类型进行比较。例如：

read num1
read num2
if [ $num1 -gt $num2 ]
then
    echo "$num1 is greater than $num2"
else
    echo "$num1 is smaller than or equal to $num2"
fi

在这个例子中，我们使用read命令分别读取$num1和$num2的值，并使用比较大小的操作符 -gt 进行比较。即使$num1和$num2的值是字符串类型，在比较时也会被自动转换为整数类型。

```

#### 2.2 shell系统变量

```bash
# Shell常见的变量之一系统变量，主要是用于对参数判断和命令返回值判断时使用，系统变量详解如下：

$0 		当前脚本的名称；
$n 		当前脚本的第n个参数,n=1,2,…9；
$* 		当前脚本的所有参数(不包括程序本身)；
$# 		当前脚本的参数个数(不包括程序本身)；
$? 		令或程序执行完后的状态，返回0表示执行成功；
$$ 		程序本身的PID号。
```

#### 2.3 shell环境变量

##### 2.3.1 常见的系统环境变量

```bash
# Shell常见的变量之二环境变量，主要是在程序运行时需要设置，环境变量详解如下：

PATH  		命令所示路径，以冒号为分割；
HOME  		打印用户家目录；
SHELL 		显示当前Shell类型；
USER  		打印当前用户名；
ID    		打印当前用户id信息；
PWD   		显示当前所在路径；
TERM  		打印当前终端类型；
HOSTNAME    显示当前主机名；
PS1         定义主机命令提示符的；
HISTSIZE    历史命令大小，可通过 HISTTIMEFORMAT 变量设置命令执行时间;
RANDOM      随机生成一个 0 至 32767 的整数;
HOSTNAME    主机名
```



#### 2.4 shell用户环境变量

##### 2.4.1 自定义shell环境变量

```bash
# 常见的变量之三用户变量，用户变量又称为局部变量，主要用在Shell脚本内部或者临时局部使用，系统变量详解如下：
a=rivers 				       自定义变量A；
Httpd_sort=httpd-2.4.6-97.tar  自定义变量N_SOFT；
BACK_DIR=/data/backup/         自定义变量BACK_DIR；
IPaddress=10.0.0.1			   自定义变量IP1；

```

##### 2.4.3 shell 中彩色输出helloworld

```bash
#!/bin/bash
# This is echo color shell
# by author rivers 2021.09-23
# 字体颜色
for i in {31..37}; do
echo -e "\033[$i;40mHello world!\033[0m"
done
# 背景颜色
for i in {41..47}; do
echo -e "\033[47;${i}mHello world!\033[0m"
done
# 显示方式
for i in {1..8}; do
echo -e "\033[$i;31;40mHello world!\033[0m"
done
```

### 三、shell编程流程控制语句

#### 3.1 if 条件语句

##### test 命令的用法

> （1）test 是 Shell 内置命令，用来检测某个条件是否成立。
>
> （2）test 命令的格式如下，也可以简写为[ ]，如下所示。
>
> ```bash
> test expression
> #或者
> [ expression ]
> ```
>
> - 当 expression 成立时，test命令的退出状态为 0，否则为非 0 值。
> - 注意`[]`和`expression`之间必须有空格。
>
> （3）test命令通常和 if 语句一起使用，并且大部分 if 语句都依赖 test。下面代码中，`-le`选项表示小于等于，`-ge`选项表示大于等于，`&&`是逻辑与运算符。
>
> ```bash
> #!/bin/bash
>  
> read age
>  
> if test $age -le 2; then
>     echo "婴儿"
> elif test $age -ge 3 && test $age -le 8; then
>     echo "幼儿"
> elif [ $age -ge 9 ] && [ $age -le 17 ]; then
>     echo "少年"
> elif [ $age -ge 18 ] && [ $age -le 25 ]; then
>     echo "成年"
> elif test $age -ge 26 && test $age -le 40; then
>     echo "青年"
> elif test $age -ge 41 && [ $age -le 60 ]; then
>     echo "中年"
> else
>     echo "老年"
> fi
> ```
>
> （4）test 命令有很多选项，可以进行数值、字符串和文件三个方面的检测。学习 test 命令，重点是学习它的各种选项，下面我们就逐一讲解。

##### 与文件检测相关的test

##### 与数值比较相关的test选项

> （1）与数值比较相关的test选项如下表所示。
>
> ```bash
> num1 -eq num2	判断 num1 是否和 num2 相等。
> num1 -ne num2	判断 num1 是否和 num2 不相等。
> num1 -gt num2	判断 num1 是否大于 num2 。
> num1 -lt num2	判断 num1 是否小于 num2。
> num1 -ge num2	判断 num1 是否大于等于 num2。
> num1 -le num2	判断 num1 是否小于等于 num2。
> ```
>
> （2）实例演示。
>
> ```bash
> #!/bin/bash
>  
> read a b
>  
> if test $a -eq $b
> then
>     echo "两个数相等"
> else
>     echo "两个数不相等"
> fi
> ```
>
> （3）注意，test 只能用来比较整数，小数相关的比较需要用bc命令。

##### 与字符串判断相关的 test 选项

>```bash
>-z str	判断字符串 str 是否为空。
>-n str	判断宇符串 str 是否为非空。
>str1 = str2
>str1 == str2	=和==是等价的，都用来判断 str1 是否和 str2 相等。
>str1 != str2	判断 str1 是否和 str2 不相等。
>str1 \> str2	判断 str1 是否大于 str2。\>是>的转义字符，这样写是为了防止>被误认为成重定向运算符。
>str1 \< str2	判断 str1 是否小于 str2。同样，\<也是转义字符。
>```
>
>（2）test命令比较奇葩，用==、\>、\<这些选项来比较两个字符串，用-eq、-lt这些选项来比较两个数值的大小，注意不能混用，即==、\>、\<这些选项不能用于比较两个数字，而-eq、-lt这些选项也不能用于比较两个字符串。另外，test不支持 >= 和 <= 。
>
>（3）实例演示。
>
>```bash
>#!/bin/bash
> 
>read str1
>read str2
> 
>#检测字符串是否为空
>if [ -z "$str1" ] || [ -z "$str2" ]
>then
>    echo "字符串不能为空"
>    exit 0
>fi
> 
>#比较字符串
>if [ $str1 = $str2 ]
>then
>    echo "两个字符串相等"
>else
>    echo "两个字符串不相等"
>fi
>```
>
>![image-20230603160703570](../images/asfdsafddf)
>

##### 3.1.1 常用的单/双分支

```bash
# If条件判断语句，通常以if开头，fi结尾。也可加入else或者elif进行多条件的判断

# 单分支语句 ---比较大小
	if [条件表达式];then
		语句1
	fi

# 双分支if 语句
	if [表达式]
		语句1
	else
		语句2
	fi

# 多支条件语句 ---判断成绩
	if [表达式]
		语句1
	elif
		语句2
	elif
		语句2
	fi  
```

##### 3.1.2 if 常见判断逻辑运算符详解

```bash
-f	 	判断文件是否存在 eg: if [ -f filename ]；
-d	 	判断目录是否存在 eg: if [ -d dir     ]；
-eq		等于，应用于整型比较 equal；
-ne		不等于，应用于整型比较 not equal；
-lt		小于，应用于整型比较 letter；
-gt		大于，应用于整型比较 greater；
-le		小于或等于，应用于整型比较；
-ge 	大于或等于，应用于整型比较；
-a		双方都成立（and） 逻辑表达式 –a 逻辑表达式；
-o		单方成立（or） 逻辑表达式 –o 逻辑表达式；
-z		空字符串；
-x      是否具有可执行权限
||      单方成立；
&&      双方都成立表达式。
```

##### 3.1.3 使用单分支语句判断crond进程是否在运行

```bash
#!/bin/bash
# this is check crond
# by author rivers on 2021-9.23

# 定义一个变量名
name=crond
num=$(ps -ef|grep $name|grep -vc grep)
if [ $num -eq 1 ];then
    echo "$num running!"
else
    echo "$num is not running!"
fi
```

##### 3.1.5 多个条件判断学生分数等级

```bash
# if 语句可以直接对命令状态进行判断，就省去了获取$?这一步！
  # 如果第一个条件符合就不再向下匹配
#!/bin/bash
  # this check grade shell
  # by author rivers on 2021-09-27
  
  grade=$1
  # 获取传递给脚本的第一个参数
  if [ $grade -gt 90 ];then
    echo "Is's very good!"
  elif [ $grade -gt 70 ];then
    echo "Is's is good!"
  
  elif [ $grade -ge 60 ];then
    echo "pass"
  
  else
    echo "no pass"
  fi
```

![img](../images/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5a6d5bGx55qE5Y2a5a6i,size_20,color_FFFFFF,t_70,g_se,x_16)

#### 3.2 for 循环语句介绍

```bash
#格式：for name [ [ in [ word ... ] ] ; ] do list ; done
  for 变量名 in 取值列表; do
    语句 1
  done

形式一
for (( 初始值; 限制值; 执行步阶))
	do
		list
	done

形式二
for var in con1 con2 con3 ...
	do
		list
	done
```

##### 3.2.1 扫描当前文件

![在这里插入图片描述](../images/3767)

#### 3.3 while 循环语句介绍

```bash
# While循环语句与for循环功能类似，主要用于对某个数据域进行循环读取、对文件进行遍历，通常用于需要循环某个文件或者列表，满足循环条件会一直循环，不满足则退出循环，其语法格式以while…do开头，done结尾，与while 关联的还有一个 until 语句，它与 while 不同之处在于，是当条件表达式为 false 时才循环，实际使用中比较少，这里不再讲解。

while [表达式]
do
  语句1
done
```

```bash
# break 和 continue 语句
  break 是终止循环。
  continue 是跳出当前循环。
#示例 1：在死循环中，满足条件终止循环
while true; do
  let N++
  if [ $N -eq 5 ]; then
    break
fi
  echo $N
done
输出： 1 2 3 4

#示例 2：举例子说明 continue 用法
N=0
while [ $N -lt 5 ]; do
  let N++
if [ $N -eq 3 ]; then
  continue
fi
  echo $N
done

输出： 1 2 4

# 打印 1-100 数字
i=0
while ((i<=100))
do
        echo  $i
        i=`expr $i + 1`
done
```



### 四、gcc，makefile批编译

#### gcc编译程序的过程

- 预处理（Pre-Processing）
- 编译（Compiling）
- 汇编（Assembling）
- 链接（Linking）

![请添加图片描述](../images/f019f4b4c9d441d5991a4acabd1a916d.png)

##### 常用选项

![请添加图片描述](../images/498497)

##### 应用实例

```bash
gcc -E hello.c -o hello.i #预处理
gcc -S hello.i -o hello.s #编译
gcc -c hello.s -o hello.o #汇编
gcc hello.o -o hello #链接
gcc hello.c -o hello #直接编译链接成可执行目标文件
gcc -c hello.c 或 gcc -c hello.c -o hello.o #编译生成可重定位目标文件
```



### shell脚本实例

```bash
读取文件每一行
while read myline
do
 echo "LINE:"$myline
done < datafile.txt

cat datafile.txt | while read myline
do 
 echo "LINE:"$myline
done

//不太理解zh
```

