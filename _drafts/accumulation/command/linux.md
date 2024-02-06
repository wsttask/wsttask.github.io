### Linux 命令

```shell
$ [command] --help
在linux终端上获取命令帮助

# Global search REgular expression and Print out the line.
$ grep [options] [pattern] file
-i:ignorecase，忽略字符的大小写
-o:仅显示匹配到的字符串本身
-n:显示行号
-c:只输出有几行
-B1:同时输出上一行,B2就是两行
-A1:同时输出下一行，A2就是两行
-r:表示在当前目录下的所有文件中查找，包括子目录中的文件(recursion)递归
grep "^$" test -n :查看空行
//Linux平台下，所有行的结尾都有一个$符
grep "^.*t" test -n :以任意内容开头，知道t结束
grep "a" test -c :查看文章中多少行有a

# process status 用来列出系统中当前运行的进程
$ ps
# ps -ef          显示所有进程信息，连同命令行
ps -ef：查看所有进程
ps -aux：查看所有进程
ps -ef | grep tomcat：查看指定进程


# 打包和解包
$ tar
tar -cvf 文件名.tar files/directories
// 将文件或目录打包（不是压缩）
tar -xvf 文件名.tar
// 将文件解包
tar -zcvf 文件名.tar.gz files/directories
// 将文件打包并压缩
tar -jcvf 文件名.tar.bz2 files/directories
// 将文件打包并压缩

tar -zxvf 文件名.tar.gz
// 将文件解压
tar -jxvf 文件名.tar.bz2
// jian
tar -zxvf 文件名.tar.gz -C directory
// 将文件解压到指定目录


# Determine the type of FILEs
$ file
-b:brief列出辨识结果，不显示文件名称

# Copy files and directories
$ cp
cp SOURCE DIRECTOTY:把源文件复制到目标文件目录，source可以是多个
// 规则1：如果目标文件已经存在，同名文件会被覆盖
// 规则2：可以同时复制多个文件
cp source dest:把源文件复制到目的文件,destination是目标文件的路径
// 规则1：目的文件不存在，创建一个和目的文件同名，和源文件同内容的文件
// 规则2：目的文件存在，内容会被覆盖
// 规则3：source只能是一个
cp -r source_directory dest:把源文件夹复制到目标文件夹下，
-r:recursive递归

# 显示或配置网络设备（网络接口卡）或修改
$ ifconfig
//ipconfig是用于windows
注释1

# 查找指定条件的文件
$ find [directory] [options]
-a:and
-o:or
-name:"name"，使用名字搜索，"*.txt"
-iname:忽略大小写
-type:以文件类型检索，f:普通文件d:目录
-mtime [n]:n=0,返回最近24小时内修改的文件，n=1,返回24-48小时内修改的文件(modify time)
-atime [n]:访问时间(access time)
-ctime [n]:改变状态时间(change time)
-ls:显示详细信息
find . -name "*.txt":在当前目录查找“*.txt"的文件
默认在当前目录下查找
>
./dir1/file1.txt
./dir2/file2.txt



# 显示近期用户或终端的登录情况
$ last

# w或者who可以查看目前已登录在系统上面的用户
$ w
$ who

# whoami可以常看你所使用的登录名称


# 查看当前所在文件夹 print work directory(/dəˈrektəri/)
$ pwd

# 切换目录（change directory）
$ cd
~:/root
/:linux中的根目录

# 创建目录（make directory）
$ mkdir [-m] [-p] directory
用法：mkdir [选项]... 目录...
若指定<目录>不存在则创建目录。

必选参数对长短选项同时适用。
  -m, --mode=模式   设置权限模式（类似chmod），而不是 a=rwx 减 umask
  -p, --parents     需要时创建目标目录的上层目录，但即使这些目录已存在
                    也不当作错误处理，其文件权限模式不受 -m 选项影响。
  -v, --verbose     每次创建新目录都显示信息
  -Z                   设置每个创建的目录的 SELinux 安全上下文为默认类型
      --context[=CTX]  类似 -Z，或如果指定了 CTX，则将 SELinux 或 SMACK 安全
                         上下文设置为 CTX 对应的值
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出


mkdir –m 权限值 已有目录绝对路径/目录名
作用：在一个已有目录中创建一个拥有相应权限值的空目录文件
mkdir -m 755 /home/stu/Desktop/new/Test

mkdir –p 绝对路径/目录名
作用：在绝对路径中去创建一个空目录文件，如果该绝对路径下目录存在则直接在这个已存在的目录中去创建一个为目录名的空目录文件，如果该绝对路径下目录不存在，则直接在该绝对路径下去创建这个目录然后在这个目录下直接创建目录名的空目录文件
如：mkdir –p /home/stu/Desktop/New/test 在/home/stu/Desktop这个绝对路径下的New目录


mkdir 目录名1 目录名2 目录名3 ……
作用：直接在当前位置创建目录名1和目录名2两个空目录文件,甚至可以更多
如：mkdir new1 new2

mkdir –p –m 755 绝对路径目录/目录名
作用：在绝对路径下的目录中去创建一个空目录，然后给这个空目录权限值中的权限，这个绝对路径下的目录可存在也可不存在
如：mkdir -p -m 755 /home/stu/Desktop/new/New/New1 New为绝对路径下目录

# 移动或重命名文件
$ mv
mv file1 file2
// 规则1：如果file2不存在，就是把file1重命名为file2，如果存在，那么就是把file2覆盖掉，-f 不询问强制覆盖
mv file directory
// 把文件file移动到目录dir中
mv dir1 dir2
// 规则1：dir2存在,把文件夹dir1移动到问价夹dir2中
// 规则2：dir2不存在，把文件夹重命名为dir2
mv * ../
// 把当前问价夹中的所有文件移动到上一级目录
mv dir3/* dir2
// 把问价夹dir3中的所有文件移动到dir2中
-t --target-directory=DIRECTORY 先指定复制到哪个目录


# 删除文件（remove）
$ rm
$ rm -rf test
强制删除（不需要确认）并递归删除
用法：rm [选项]... [文件]...
删除（unlink）指定<文件>。

  -f, --force          强制删除。忽略不存在的文件，不提示确认
  -i                    每次删除前提示确认
  -I                    在删除超过三个文件或者递归删除前提示一次并要求确认；
                          此选项比 -i 提示内容更少，但同样可以阻止大多数
                          错误发生
      --interactive[=场景]  根据指定的<场景>进行确认提示：never（从不）、
                            once（一次，等效于使用 -I）或者 always（总是，
                            等效于使用 -i）。如果使用此参数没有指定<场景>则
                            总是提示
      --one-file-system		递归删除一个层级时，跳过所有不符合命令行参
				数的文件系统上的文件
      --no-preserve-root  不要对“/”特殊处理
      --preserve-root[=all]  不要删除“/”（默认行为）；
                              如添加了“all”参数，将拒绝处理与父目录位于
                              不同设备上的命令行参数
  -r, -R, --recursive   递归删除目录及其内容
  -d, --dir             删除空目录
  -v, --verbose         详细显示进行的步骤
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出

默认时，rm 不会删除目录。使用--recursive(-r 或-R)选项可删除每个给定
的目录，以及其下所有的内容。

# 查看当前文件夹下的内容(list)
$ ls
ll：显示详细信息
-a:列出所有文件和目录，包括隐藏文件
-1:一行一个文件
-l:显示详细信息
-lR:递归列出该目录下所有文件

# 显示文件详细信息比ll更详细
$ stat 
atime:(access time)：表示我们最后一次访问（仅仅是访问，没有改动）文件的时间
mtime:(modify time)：表示我们最后一次修改文件的时间
ctime:(change time)：表示我们最后一次对文件属性改变的时间，包括权限，大小，属性，时间等等

# 一是创建空文件，二是修改文件的时间属性。
$ touch 
-m:只更改修改时间
-a:只更改访问时间
但注意ctime是都会改的！

# 计算文件（word count）
$ wc [option] [file]
-l:显示行数
-w:显示字数
-m:显示字符数
-c:显示字节数

# 建立用户账号
$ useradd [name]
-c [comment]:描述新用户账号
-d [home]:设置用户主目录，默认值 I为用户的登录名，并放在“/home”目录下。
-u [ID]:设置用户ID。
-s [shell]:设定用户使用的登录shell类型。

# 变更登入账户（swith user）
$ su [option] [zhanghu]
su是最简单的身份切换命令，一般都是su - username，然后输入password就ok了，root用su至其他用户无须密码；但非root用户切换时需要密码。切换到root可以使用su -和su - root。

$ cut

# 将输入回显到标准输出
$ echo
-n:表示不换行输出
-e:输出转义字符
echo `date`:输出date命令打印的内容
echo "`ifconfig`":输出ifconfig命令打印的内容
\\    反斜杠
\a    响铃声
\b    退格
\c    不再产生新的输出
\e    转义符  
\f    换页
\n    新行
\r    回车
\t    水平制表符
\v    竖直制表符
重定向
>
追加重定向
>>
/bin/echo --help
# 查看echo的帮助文档

# 改变文件的权限
$ chmod [ugoa][+-=][rwxX][]
u 表示该档案的拥有着， g 表示和该档案拥有者同一个群组(group) o 表示其他以外的人 a 表示全部
+ 表示增加权限， - 表示取消权限 ， = 赋予给定权限并取消其他所有权限
r 表示可读取，w 表示可写入，x 表示可执行，X 表示只有当该档案是个子目录或者该档案已经被设定过为可执行。
-c : 若该档案权限确实已经更改，才显示其更改动作
-f : 若该档案权限无法被更改也不要显示错误讯息
-v : 显示权限变更的详细资料
-R : 对目前目录下的所有档案与子目录进行相同的权限变更(即以递回的方式逐个变更)
--help : 显示辅助说明
--version : 显示版本

chmod 777 file :也可以用数字来表示权限
r=4,w=2,x=1

# 更改文件的属主，属组
$ chown


# 从标准输入读取行数据然后把它分成字段。
$ read
# a b c 三个变量读取123这个输入，会看做一个变量，所以只有a被赋值
[root@server ~]# read a b c
123
[root@server ~]# echo $a
123
[root@server ~]# echo $b
 
[root@server ~]# echo $c
 
# 下边的方法可以避免上边的错误
[root@server ~]# read a b c
1 2 3
[root@server ~]# echo $a
1
[root@server ~]# echo $b
2
[root@server ~]# echo $c
3

# 将读取的数据存到 array 数组中
[root@server ~]# read -a array
Read a line from the standard input and split it into fields.
[root@server ~]# echo ${array[@]}
Read a line from the standard input and split it into fields.
[root@server ~]# echo ${array[0]}
Read
[root@server ~]# echo ${array[5]}
standard

指定读取结束符为"/"
[root@server ~]# read -d /
12345/[root@server ~]# read -d / a
12345/[root@server ~]# echo $a
12345


# 最多读取5个字符，不到5个字符时的换行符会终止读取
[root@server ~]# read -n5 a
12345[root@server ~]# echo $a
12345
[root@server ~]# read -n5 a
12
[root@server ~]# echo $a
12
 
# 最多读取5个字符，不到5个字符时的换行符不会终止读取
[root@server ~]# read -N5 a
12
34[root@server ~]#
[root@server ~]# echo $a
12 34


[root@server ~]# read -p 请输入用户名：
请输入用户名：123
[root@server ~]#

[root@server ~]# read -r a
\123
[root@server ~]# echo $a
\123
[root@server ~]# read a
\123
[root@server ~]# echo $a
123

# 退出当前账户
$ exit

# 一次显示整个文件，从键盘创建一个文件，将几个文件合并成一个文件 
$ cat [option] [filename]
cat:一行一行读入，并原样输出
cat filename:读取并显示整个文件
cat > 1.txt:从键盘读取输入到文件1.txt
cat file1 file2 > file:将几个文件合并为一个文件
-n:打印行号
cat<<EOF:以EOF输入字符为标准输入结束
cat>filename:创建文件，并把标准输入输入到filename文件中，以CTRL+d作为输入结束
cat>filename<<EOF
cat>>filename:追加写
-A:查看隐藏符号


# 改变/etc/sudoers
$ visudo
按Esc,键入":wq":保存并推出
键入"q":直接推出
```
##### 管道

```bash
使用管道符(|)连接的复合命令

# 统计当前目录下文件的个数(不包括目录)
$ ls -l | grep "^-" | wc -l

# 统计当前目录下文件的个数（包括子目录）
$ ls -lR | grep "^-" | wc -l

# 非
$ echo "123456" | passwd sc99 --stdin


```

##### 注释1：ifconfig显示内容分析

[(133条消息) 查看网卡信息：ifconfig命令及详细介绍_-纸短情长的博客-CSDN博客](https://blog.csdn.net/l_liangkk/article/details/114959914?ops_request_misc=%7B%22request%5Fid%22%3A%22168431947616800211580229%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168431947616800211580229&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-114959914-null-null.142^v87^control_2,239^v2^insert_chatgpt&utm_term=ifconfig&spm=1018.2226.3001.4187)

##### Linux中ls -l命令

<img src="../images/75948b4dcf9d4fd4b2b83a2ff80099b9.png" alt="img"  />

```
 1）表示文件的类型

- 普通文件
d 目录文件：directory
p 管理文件
l 链接文件
b 块设备文件
c 字符设备文件
s 嵌套字文件

2）所有者/所有者权限

r 读权限

w 写权限

x 可执行权限

- 无权限


3）组用户权限（一个组中除所有者拥有的权限）

4）其他用户权限（除当前所有者的组，其他组可以进行访问的权限）

5）

a.如果是普通用户，这个数字指的是链接数

b.如果是目录文件，这个数字指的是它的第一级子目录数

6）用户名

7）组名

8）文件大小（字节）

9）最后修改时间

10）文件名

```
##### Linux中的一些文件及其作用

```shell

/tmp 是存放临时文件的，任何的用户创建的进程都可以在此处新建文件和文件夹

/root 是root用户的家目录

/home 是普通用户的家目录

/bin 存放可执行二进制程序 binary

/usr 存放Linux系统资源：各种程序默认会安装到这个文件夹里 unix system resource

/etc 存放各种配置文件：/etc/passwd /etc/shadow /etc/group

/etc/sudoers

/proc  伪文件系统：Linux 内核提供了一种通过 /proc 文件系统，在运行时访问内核内部数据结构、改变内核设置的机制。proc文件系统是一个伪文件系统，它只存在内存当中，而不占用外存空间。它以文件系统的方式为访问系统内核数据的操作提供接口。
```

##### /etc/sudoers文件解释


```shell
[root@test ~]# cat /etc/sudoers
## Sudoers allows particular users to run various commands as
## the root user, without needing the root password.
##该文件允许特定用户像root用户一样使用各种各样的命令，而不需要root用户的密码 
##
## Examples are provided at the bottom of the file for collections
## of related commands, which can then be delegated out to particular
## users or groups.
## 在文件的底部提供了很多相关命令的示例以供选择，这些示例都可以被特定用户或  
## ## 用户组所使用  
## This file must be edited with the 'visudo' command.
## 该文件必须使用"visudo"命令编辑
## Host Aliases
#主机别名
## Groups of machines. You may prefer to use hostnames (perhap using 
## wildcards for entire domains) or IP addresses instead.
## 对于一组服务器，你可能会更喜欢使用主机名（可能是全域名的通配符）
## 或IP地址代替，这时可以配置主机别名
 
# Host_Alias     FILESERVERS = fs1, fs2
# Host_Alias     MAILSERVERS = smtp, smtp2
## User Aliases
#用户别名
## These aren't often necessary, as you can use regular groups
## (ie, from files, LDAP, NIS, etc) in this file - just use %groupname 
## rather than USERALIAS
## 这并不很常用，因为你可以通过使用组来代替一组用户的别名  
# User_Alias ADMINS = jsmith, mikem
 
## Command Aliases
## These are groups of related commands...
## 指定一系列相互关联的命令（当然可以是一个）的别名，通过赋予该别名sudo权限，  
## 可以通过sudo调用所有别名包含的命令，下面是一些示例
 
## Networking
#网络操作相关命令别名  
Cmnd_Alias NETWORKING = /sbin/route, /sbin/ifconfig, /bin/ping, /sbin/dhclient,
 /usr/bin/net, /sbin/iptables, /usr/bin/rfcomm, /usr/bin/wvdial, /sbin/iwconfig, 
 /sbin/mii-tool
## Installation and management of software
#软件安装管理相关命令别名  
Cmnd_Alias SOFTWARE = /bin/rpm, /usr/bin/up2date, /usr/bin/yum
## Services
#服务相关命令别名 
Cmnd_Alias SERVICES = /sbin/service, /sbin/chkconfig
## Updating the locate database
#本地数据库升级命令别名  
Cmnd_Alias LOCATE = /usr/sbin/updatedb
## Storage
#磁盘操作相关命令别名
Cmnd_Alias STORAGE = /sbin/fdisk, /sbin/sfdisk, /sbin/parted, /sbin/partprobe, /bin/mount, /bin/umount
## Delegating permissions
#代理权限相关命令别名 
Cmnd_Alias DELEGATING = /usr/sbin/visudo, /bin/chown, /bin/chmod, /bin/chgrp
## Processes
#进程相关命令别名
Cmnd_Alias PROCESSES = /bin/nice, /bin/kill, /usr/bin/kill, /usr/bin/killall
## Drivers
#驱动命令别名
Cmnd_Alias DRIVERS = /sbin/modprobe
#环境变量的相关配置
# Defaults specification
#
# Disable "ssh hostname sudo <cmd>", because it will show the password in clear. 
#         You have to run "ssh -t hostname sudo <cmd>".
#
Defaults    requiretty
Defaults    env_reset
Defaults    env_keep = "COLORS DISPLAY HOSTNAME HISTSIZE INPUTRC KDEDIR \
                        LS_COLORS MAIL PS1 PS2 QTDIR USERNAME \
                        LANG LC_ADDRESS LC_CTYPE LC_COLLATE LC_IDENTIFICATION \
                        LC_MEASUREMENT LC_MESSAGES LC_MONETARY LC_NAME LC_NUMERIC \
                        LC_PAPER LC_TELEPHONE LC_TIME LC_ALL LANGUAGE LINGUAS \
                        _XKB_CHARSET XAUTHORITY"
## Next comes the main part: which users can run what software on
## which machines (the sudoers file can be shared between multiple
## systems).
## 下面是规则配置：什么用户在哪台服务器上可以执行哪些命令（sudoers文件可以在多个系统上共享）
## Syntax:
##语法
##      user    MACHINE=COMMANDS
##  用户 登录的主机=（可以变换的身份） 可以执行的命令  
##
## The COMMANDS section may have other options added to it.
## 命令部分可以附带一些其它的选项  
##
## Allow root to run any commands anywhere 
## 允许root用户执行任意路径下的任意命令 
root    ALL=(ALL)       ALL
## Allows members of the 'sys' group to run networking, software,
## service management apps and more.
# %sys ALL = NETWORKING, SOFTWARE, SERVICES, STORAGE, DELEGATING, PROCESSES, LOCATE, DRIVERS
## 允许sys中户组中的用户使用NETWORKING等所有别名中配置的命令
 
## Allows people in group wheel to run all commands
# %wheel        ALL=(ALL)       ALL
## 允许wheel用户组中的用户执行所有命令  
## Same thing without a password
## 允许wheel用户组中的用户在不输入该用户的密码的情况下使用所有命令
# %wheel        ALL=(ALL)       NOPASSWD: ALL
## Allows members of the users group to mount and unmount the
## cdrom as root
## 允许users用户组中的用户像root用户一样使用mount、unmount、chrom命令 
# %users  ALL=/sbin/mount /mnt/cdrom, /sbin/umount /mnt/cdrom
## Allows members of the users group to shutdown this system
# %users  localhost=/sbin/shutdown -h now
## 允许users用户组中的用户像root用户一样使用shutdown命令
```

##### linux 系统目录结构及路径

```shell
1. /
根目录，Unix 和 Linux 中，没有盘符。 一个硬盘，一个根.。

2. /bin
系统的常用命令目录.。包括控制台命令, 系统可执行文件, 系统的核心二进制文件等

3. /etc
发布目录, 相当于 windows 系统中的 windows 目录, 保存系统中的所有核心内容.。要求控制权限高, 建议不要随便读写

4. /usr
用户目录, 相当于 windows 系统中的 program files 目录.。常用于安装系统所有用户共用的软件,资源

5. /root
root 根用户的用户目录.。相当于 windows 系统中的 C:/users/administrator 目录称为用户主目录

6. /home
保存其他用户主目录的目录。如: Linux系统中有 r_lee 用户. 那么一定有 /home/r_lee 目录存在， 代表用户的主目录

7. /var
系统运行过程的数据目录

路径
1. 全路径 (绝对路径)
从 file system（文件系统） 根目录开始寻找文件。

写法： 以 / 开头。例如找 usr 下 local 中内容，路径： /usr/local

2. 相对路径
从当前资源路径开始寻找，找到其他资源路径过程。
写法：一定不是以/开头。找当前资源的子目录直接写子目录名称，如果向上跳一级文件夹写法 ： …/
3. 特殊路径写法
/ 表示磁盘根
~ 表示/root ，root 文件夹的根目录
```

##### 注释2：权限值的计算

```
权限值的计算：r为4 ，w为2，x为1，每三位得到一个值，rwx的值为4+2+1=7，r-x的值为4+1=5， rwxr-xr-x 的总值就是755了
```

##### 快捷键

```shell
ctrl + c:强制停止当前命令
```

##### cat读入EOF

![image-20230529155623615](../images/image-20230529155623615.png)

![image-20230602223010357](../images/image-20230602223010357.png)

注意cat>test时，也必须在空行按ctrl+d才可以

#### linux文件结构

##### 文件目录

/：是所有文件的根目录；

/bin：存放二进制可执行命令目录；

/home：用户主目录的基点目录，默认情况每个用户主目录都设在该目录下，如默认：用户user01的主目录是/home/user01，可用~user01表示

/lib：存放标准程序设计库目录，又叫动态链接共享库目录，目录中文件类似windows里的后缀名为dll的文件；

/etc：存放系统管理和配置文件目录；

/dev：存放设备特殊文件目录，如声卡文件，磁盘文件等；

/usr：最庞大的目录，存放应用程序和文件目录；

/proc：虚拟目录，是系统内存的映射，可直接访问这个目录来获取系统信息；

/root：系统管理员的主目录（特权阶级）

##### /etc/group

**特殊组wheel**

在Linux中有一个特殊组wheel，wheel组就类似于一个管理员的组。在linux中，即使我们有系统管理员root的权限，也不推荐用root用户登录。一般情况下用普通用户登录就可以了，在需要root权限执行一些操作时，再su登录成为root用户。但是，任何人只要知道了root用户的密码，就都可以通过su命令来登录为root用户-------这无疑为系统带来了安全隐患。所以，将普通用户加入到wheel组中，被加入的这个普通用户就成了管理员组内的用户了，然后可以修改配置文件使得只有wheel组内的用户可以切换到root用户。

创建用户的时候系统会默认同时创建一个和这个用户名同名的组，这个组就是初始用户组，不可以把用户从初始用户组中删除

有效用户组表示用户此时此刻所在的用户组是什么，有效用户组是可以切换的。在切换有效用户组之前。注意，是之前，有效用户组就是初始用户组。想要知道用户自己当前的有效用户组和支持的用户组(在 /etc/group 文件中第四字段包含此用户的用户组)，使用 groups 即可。

![image-20230601153926650](../images/image-20230601153926650.png)

在这个输出的信息中，第一个输出的用户组就是当前的有效用户组了。

通常有效用户组的作用是新建文件。使用 newgrp 命令可以切换有效用户组，注意只能切换当前账号支持的用户组。用户是可以从附加组中被删除的。一个用户可以属于多个有效用户组。

```
 /etc/group文件是用户组的配置文件，内容包括用户和用户组，并且能显示出用户是归属哪个用户组或哪几个用户组，因为一个用户可以归属一个或多个不同的用户组；同一用户组的用户之间具有相似的特征。比如我们把某一用户加入到root用户组，那么这个用户就可以浏览root用户家目录的文件，如果root用户把某个文件的读写执行权限开放，root用户组的所有用户都可以修改此文件，如果是可执行的文件（比如脚本），root用户组的用户也是可以执行的.
 
   将用户分组是Linux系统中对用户进行管理及控制访问权限的一种手段。每个用户都属于某个用户组；一个组中可以有多个用户，一个用户也可以属于不同的组。当一个用户同时是多个组中的成员时，在/etc/passwd文件中记录的是用户所属的主组，也就是登录时所属的默认组，而其他组称为附加组。用户要访问属于附加组的文件时，必须首先使用newgrp命令使自己成为所要访问的组中的成员。用户组的所有信息都存放在/etc/group文件中。此文件的格式也类似于/etc/passwd文件。
```

 /etc/group的内容包括用户组（Group）、用户组口令、GID及该用户组所包含的用户

（User），每个用户组一条记录。/etc/group的内容依然是以“：”进行分割，共有四个字段。

![img](../images/aeee7ac2729c4382b719d657c48d39ee.png)

- 第一字段：用户组名称

​			就是用户组的名称，其命名规则与UID相同。

- 第二字段：用户组密码

​			这里的x同样表示密码已经迁移，其密码迁移到/etc/gshadow中。

- 第三字段：GID

​			用户组的唯一标示，同样的道理，计算机不识别组名，只能识别组的ID，GID也是一个整数，被系统内部用		来标识组；/etc/passwd中的GID就来源于/etc/group。

- 第四字段：用户组包含的用户

说明：GID和UID类似，是一个正整数或0，GID从0开始，GID为0的组让系统付予给root用户组；系统会预留一些较靠前的GID给系统虚拟用户（也被称为伪装用户）之用；

每个系统预留的GID都有所不同，比如Rethad预留了500个，我们添加新用户组时，用户组是从1000开始的；

而Slackware是把前100个GID预留，新添加的用户组是从100开始；查看系统添加用户组默认的GID范围应该查看/etc/login.defs中的GID_MIN和GID_MAX值。

##### /etc/gshadow 

![image-20230601153555138](../images/image-20230601153555138.png)

- 第一字段：用户组

就是用户组的名称，其命名规则与UID相同。

- 第二字段：用户组密码

这个字段可以是空的或!，如果是空的或有！，表示没有密码。

- 第三字段：用户组管理者

这个字段也可为空，如果有多个用户组管理者，用“,”号分割。

- 第四字段：组成员

如果有多个成员，用,号分割。

##### /etc/passwd

![image-20230601154133716](../images/image-20230601154133716.png)

1. 用户名称
   	第一个字段中保存的是用户名称。不过大家需要注意，用户名称只是为了方便管理员记忆，Linux 系统是通过用户 ID (UID) 来区分不同用户、分配用户权限的。而用户名称和 UID 的对应正是通过 /etc/passwd 这个文件来定义的。

2. 密码标志
       这里的"x"代表的是密码标志，而不是真正的密码，真正的密码是保存在 /etc/shadow 文件中的。

   在早期的 UNIX 中，这里保存的就是真正的加密密码串，但是这个文件的权限是 644，查询命令如下：
   [root@localhost ~]# ll /etc/passwd
   -rw-r–r-- 1 root root 1648 12月29 00:17 /etc/passwd

   所有用户都可以读取 /etc/passwd 文件，这样非常容易导致密码的泄露。虽然密码是加密的，但是采用暴力破解的方式也是能够进行破解的。所以现在的 Linux 系统把真正的加密密码串放置在影子文件/etc/shadow中，而影子文件的权限是 000，查询命令如下：
   [root@localhost ~]# ll /etc/shadow
   ---------- 1 root root 1028 12月29 00:18 /etc/shadow

   这个文件是没有任何权限的，但因为我是 root 用户，所以读取权限不受限制。当然，用强制修改的方法也是可以手工修改这个文件的内容的。只有 root 用户可以浏览和操作这个文件，这样就最大限度地保证了密码的安全。

   所以在 /etc/passwd 中只有一个"x"代表用户是拥有密码的，我们把这个字段称作密码标志，具体的密码要去 /etc/shadow 文件中查询。但是这个密码标志"x"也是不能被删除的，如果删除了密码标志"x"，那么系统会认为这个用户没有密码，从而导致只输入用户名而不用输入密码就可以登陆（当然只能在使用无密码登录，远程是不可以的），除非特殊情况（如破解用户密码），这当然是不可行的。

3. *UID*
       第三个字段就是用户 ID(UID)，我们已经知道系统是通过 UID 来识别不同的用户和分配用户权限的。这些 UID 是有使用限制和要求的：
       0：超级用户 UID。如果用户 UID 为 0，则代表这个账号是管理员账号。在 Linux 中如何把普通用户升级成管理员呢？只需把其他用户的 UID 修改为 0 就可以了，这一点和 Windows 是不同的。不过不建议建立多个管理员账号。
       1~499：系统用户（伪用户）UID。这些 UID 是系统保留给系统用户的 UID，也就是说 UID 是 1~499 范围内的用户是不能登录系统的，而是用来运行系统或服务的。其中，1~99 是系统保留的账号，系统自动创建；100~499 是预留给用户创建账号的。
   500~65535：普通用户 UID。建立的普通用户 UID 从 500 开始，最大到 65535。

   这些用户足够使用了，但是如果不够也不用害怕，2.6.x 内核以后的 Linux 系统用户 UID 已经可以支持 232 个用户了

   Linux允许不同用户拥有相同的UID，系统是根据UID来识别不同的用户和分配用户权限的

   

4. *GID*
   第四个字段就是用户的组 ID(GID)，也就是这个用户的初始组的标志号。这里需要解释一下初始组和附加组的概念。

   所谓初始组，指用户一登陆录就立刻拥有这个用户组的相关权限。每个用户的初始组只能有一个，一般就是将和这个用户的用户名相同的组名作为这个用户的初始组。举例来说，我们手工添加用户 lamp，在建立用户 lamp 的同时就会建立 lamp 组作为 lamp 用户的初始组。

   所谓附加组，指用户可以加入多个其他的用户组，并拥有这些组的权限。每个用户只能有一个初始组，除初始组要把用户再加入其他的用户组外，这些用户组就是这个用户的附加组。附加组可以有多个，而且用户可以有这些附加组的权限。

   举例来说，刚刚的 lamp 用户除属于初始组 lamp 外，我又把它加入了 users 组，那么 lamp 用户同时属于 lamp 组、users 组，其中 lamp 是初始组，users 是附加组。当然，初始组和附加组的身份是可以修改的，但是我们在工作中不修改初始组，只修改附加组，因为修改了初始组有时会让管理员逻辑混乱。

   需要注意的是，在 /etc/passwd 文件的第四个字段中看到的 ID 是这个用户的初始组。

5. 用户说明
   第五个字段是这个用户的简单说明，没有什么特殊作用，可以不写。

   

6. 家目录

   第六个字段是这个用户的家目录，也就是用户登录后有操作权限的访问目录，我们把这个目录称为用户的家目录。

   超级用户的家目录是 /root 目录，普通用户在 /home/ 目录下建立和用户名相同的目录作为家目录，如 lamp 用户的家目录就是 /home/lamp/ 目录。

7. 登录之后的Shell

   Shell 就是 Linux 的命令解释器。管理员输入的密码都是 ASCII 码，也就是类似 abcd 的英文。但是系统可以识别的编码是类似 0101 的机器语言。Shell 的作用就是把 ASCII 编码的命令翻译成系统可以识别的机器语言，同时把系统的执行结果翻译为用户可以识别的 ASCII 编码。Linux 的标准 Shell 就是 /bin/bash。

   在 /etc/passw 文件中，大家可以把这个字段理解为用户登录之后所拥有的权限。如果写入的是 Linux 的标准 Shell，/bin/bash 就代表这个用户拥有权限范围内的所有权限。例如：
   [root@localhost ~]# vi /etc/passwd
   lamp:x:502:502::/home/lamp:/bin/bash

   我手工添加了 lamp 用户，它的登录 Shell 是 /bin/bash，那么这个用户就可以使用普通用户的所有权限。如果我把 lamp 用户的 Shell 修改为 /sbin/nologin，例如：
   [root@localhost ~]# vi /etc/passwd
   lamp❌502:502::/home/lamp:/sbin/nologin

   那么这个用户就不能登录了，因为 /sbin/nologin 就是禁止登录的 Shell。这样说明白了吗？如果我在这里放入的系统命令，如 /usr/bin/passwd，例如：
   [root@localhost ~]#vi /etc/passwd
   lamp❌502:502::/home/lamp:/usr/bin/passwd

   那么这个用户可以登录，但登录之后就只能修改自己的密码了。这里不能随便写入和登陆没有关系的命令，如 ls，否则系统不会识别这些命令，也就意味着这个用户不能登录。

##### /etc/sudoers

```bash
/etc/sudoers 文件是 Linux 系统中用于定义特权用户的行为的配置文件。它指定了特权用户 (例如 root 用户) 可以执行的命令，并规定了他们可以以什么身份执行。

root ALL=(ALL)    
# ALL 是 Unix 和 Linux 的 sudo 权限命令，它的意思是给 root 用户授予所有有效用户的权限，也就是说 root 用户具有所有用户的权限、可以执行任何命令，并可以以任何用户身份登陆系统。

## 注意这里赋予了root用户所有用户的权限，但是假定所有用户都不可以执行某个文件，那么root账户也不可以执行该文件，但是root账户拥有更改一切信息的权限！

user ALL=(ALL) ALL 
# 表示用户user可以使用任何用户的任何命令，包括root命令。这表示该用户可以使用root用户的权限运行任何命令，但这不是普通用户的正常行为。


/etc/sudoers 文件的用户行和授权行的格式如下：

用户行格式： {用户名或组名} {主机列表}=(身份) {命令}

授权行格式： {用户名或组名} {主机列表}=(身份) {命令列表}

其中，各部分的含义如下：

- 用户名或组名：指定要授权的用户或用户组，可以使用通配符来匹配多个用户或组。例如，"user1"、"%dev"。
- 主机列表：指定可以在哪些主机上执行授权行的命令。可以使用通配符来匹配多个主机。例如，"localhost"、"%prod"。
- 身份：指定执行授权行的命令时要使用的身份。可以使用通配符来匹配多个身份。例如，"root"、"%admin"。
- 命令列表：指定授权行允许执行的命令，可以使用通配符来匹配多个命令，也可以使用 ALL 表示所有命令。

注意，用户行和授权行的格式略有不同，主要是在命令列表部分。用户行中的命令列表应该为 ALL，表示该用户可以执行所有命令，而授权行中的命令列表应该明确列出允许执行的命令。

另外，sudoers 文件支持一些特殊的命令别名，以便简化配置。例如，将"ls"、"ps"、"top" 列为命令别名"PROC"，那么授权行可以如下所示：

user1 ALL=(root) PROC

这表示 user1 用户只能以 root 用户身份执行 ls、ps、top 命令。


```

##### who命令

注意这里我使用who命令，出现两个账户的原因是我在不同的终端和远程连接中使用了相同的root账户登录

![image-20230602204408642](../images/image-20230602204408642.png)

##### ps -ef的信息

![image-20230602212350399](../images/image-20230602212350399.png)

```bash
F 代表这个程序的旗标 (flag)， 4 代表使用者为 super user

S 代表这个程序的状态 (STAT)，关于各 STAT 的意义将在内文介绍

UID 程序被该 UID 所拥有

PID 就是这个程序的 ID ！

PPID 则是其上级父程序的ID

C CPU 使用的资源百分比

PRI 这个是 Priority (优先执行序) 的缩写，详细后面介绍

NI 这个是 Nice 值，在下一小节我们会持续介绍

ADDR 这个是 kernel function，指出该程序在内存的那个部分。如果是个 running的程序，一般就是 "-"

SZ 使用掉的内存大小

WCHAN 目前这个程序是否正在运作当中，若为 - 表示正在运作

TTY 登入者的终端机位置

TIME 使用掉的 CPU 时间。

CMD 所下达的指令为何在预设的情况下， ps 仅会列出与目前所在的 bash shell 有关的 PID 而已，所以， 当我使用 ps -l 的时候，只有三个 PID。

USER：该 process 属于那个使用者账号的

PID ：该 process 的号码

%CPU：该 process 使用掉的 CPU 资源百分比

%MEM：该 process 所占用的物理内存百分比

VSZ ：该 process 使用掉的虚拟内存量 (Kbytes)

RSS ：该 process 占用的固定的内存量 (Kbytes)

TTY ：该 process 是在那个终端机上面运作，若与终端机无关，则显示 ?，另外， tty1-tty6 是本机上面的登入者程序，若为 pts/0 等等的，则表示为由网络连接进主机的程序。

STAT：该程序目前的状态，主要的状态有

R ：该程序目前正在运作，或者是可被运作

S ：该程序目前正在睡眠当中 (可说是 idle 状态)，但可被某些讯号 (signal) 唤醒。

T ：该程序目前正在侦测或者是停止了

Z ：该程序应该已经终止，但是其父程序却无法正常的终止他，造成 zombie (疆尸) 程序的状态

START：该 process 被触发启动的时间

TIME ：该 process 实际使用 CPU 运作的时间

COMMAND：该程序的实际指令
```

