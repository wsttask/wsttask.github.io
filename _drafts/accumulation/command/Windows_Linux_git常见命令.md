#### windows

1. 直接在文件地址上写cmd，可以在该文件地址下打开dos窗口
2. Tab键可以自动补全，上下左右箭头可以翻出历史命令
3. 在dos命令后面加/?可以查看该命令的意思
4. 命令+*.type:对所有的文件执行该命令

* copy con test.java
* exit：退出当前dos命令窗口
* cls：清屏
* dir：列出当前目录下所有的子文件/子目录
* cd：表示：change directory 【改变目录】*****************1
* cd .. 回到上级目录
* cd \直接回到根目录
* del 删除文件 参数/P表示可以使用户在删除多个文件时对每个文件都显示删除询问。
* rd 删除空的文件夹
* 怎么切换盘符：
1. *c:回车
2. *d:回车
3. *e:回车
4. *f:回车
* ipconficd：显示IP地址
* at 14:30 Shutdown -s:表示在14:30准时关机。
* shutdown -s:在一分钟以后关机
* shutdown -s -t 3600:在3600秒(即1个小时)后准时关机。
* shutdown -r:在一分钟之后重启
* shutdown -r -t 3600:在3600秒后重启。
* shutdown -a:取消重启/关机命令
1、
* 绝对路径：表示该路径从某个磁盘的盘符下作为出发点的路径
* 相对路径：表示该路径从当前所在的路径下作为出发点的路径
* 假设当前所在的路径是c:\users\Administrator  那么在此时输入cd Desktop，那么其中Desktop就是一个相对路径,从当前所在的c:\Users\Administrator这个路径作为出发点，开始找Desktop目录。
* 假设是这样写的:cd c:\Users\Administrator\Desktop
其中c:\Users\Administrator\Desktop路径就是一个绝对路径。

#### 常用的Linux命令

平时一定要多使用这些基础的命令！

1）、cd : 改变目录。

2）、cd . . 回退到上一个目录，直接cd进入默认目录

3）、pwd : 显示当前所在的目录路径。

4）、ls(ll):  都是列出当前目录中的所有文件，只不过ll(两个ll)列出的内容更为详细。

5）、touch : 新建一个文件 如 touch index.js 就会在当前目录下新建一个index.js文件。

6）、rm:  删除一个文件, rm index.js 就会把index.js文件删除。

7）、mkdir:  新建一个目录,就是新建一个文件夹 如 mkdir test 就会在当前目录下新建一个 test 文件夹

8）、rm -r :  删除一个文件夹, rm -r src 删除src目录

```
rm -rf / 切勿在Linux中尝试！删除电脑中全部文件！
```

9）、mv 移动文件, mv index.html src index.html 是我们要移动的文件, src 是目标文件夹,当然, 这样写,必须保证文件和目标文件夹在同一目录下。

10）、reset 重新初始化终端/清屏。

11）、clear 清屏。windows 是 cls

12）、history 查看命令历史。

13）、help 帮助。

14）、exit 退出。

15）、#表示注释

#### git 常用命令

1）、git config -l 查看git所有配置

1）、git config --system --list 查看系统的配置，其中--system是筛选条件    、Git\etc\gitconfig  ：Git 安装目录下的 gitconfig     --system 系统级

1）、git config --global --list 查看个人的配置     、C:\Users\Administrator\ .gitconfig    只适用于当前登录用户的配置  --global 全局

1）、git config --global user.name "Sheng" 配置user.name

1）、git config --global user.email "704341315@qq.com" 配置user.email

2）、git clone "adress" 克隆远程仓库    

3）、git init 在当前目录新建一个Git代码库

4）、git status [filename] 查看指定文件状态

4）、git status 查看所有文件状态

5）、git add . 添加所有文件到暂存区

6）、git commit -m "消息内容"    提交暂存区中的内容到本地仓库 -m 提交信息

7）、git push 

#### MySQL 常用命令

1）、mysql -u root -p    登录
