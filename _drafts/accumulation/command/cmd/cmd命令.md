### windows

1. 直接在文件地址上写cmd，可以在该文件地址下打开dos窗口
2. Tab键可以自动补全，上下左右箭头可以翻出历史命令
3. 在dos命令后面加/?可以查看该命令的意思
4. 命令+*.type:对所有的文件执行该命令 ，它代表通配符

> ```bash
> # 新建文件，ctrl+z结束编写，如果已经有了，就可以覆盖文件
> $ copy con test.java
> 
> # 退出当前dos命令窗口$ 
> $ exit
> 
> # 查看文件内容
> $ type [路径]
> 
> # 覆盖输入文件，如果没有，那么就创建一个
> $ echo [txt] > [file]
> 
> # 追加式输入某文件
> $ echo [txt] >> [file]
> 
> # 清屏
> $ cls
> 
> # 列出当前目录下所有的子文件/子目录
> $ dir
> 
> # 表示：change directory 【改变目录】*****************1
> $ cd [路径]
> 
> # 回到上级目录
> $ cd .. 
> 
> # 直接回到根目录
> $ cd \
> 
> # 删除文件 参数/P表示可以使用户在删除多个文件时对每个文件都显示删除询问
> $ del [文件]
> 
> # 删除所有文件
> $ del *.*
> 
> # 删除空的文件夹
> $ rd 
> 
> # 显示IP地址
> $ ipconficd
> 
> # 表示在14:30准时关机
> $ at 14:30 Shutdown -s
> 
> # 在一分钟以后关机
> $ shutdown -s
> 
> # 在3600秒(即1个小时)后准时关机。
> $ shutdown -s -t 3600
> 
> # 在一分钟之后重启
> $ shutdown -r
> 
> # 在3600秒后重启
> $ shutdown -r -t 3600
> 
> # 取消重启/关机命令
> $ shutdown -a
> 
> # 打开文件
> $ start [文件]
>  
> # 打开对应目录的文件资源管理器
> $ start [目录]    .\ 表示打开当前目录下的文件资源管理器
> 
> # 使用默认浏览器打开网站
> $ start URL
> 
> $ netstat -an | find "8080"
> # 上述命令将列出所有网络连接及其状态，然后通过 find 过滤出包含 "8080" 的行。
> ```


1. *c:回车
2. *d:回车
3. *e:回车
4. *f:回车

* 绝对路径：表示该路径从某个磁盘的盘符下作为出发点的路径
* 相对路径：表示该路径从当前所在的路径下作为出发点的路径
* 假设当前所在的路径是c:\users\Administrator  那么在此时输入cd Desktop，那么其中Desktop就是一个相对路径,从当前所在的c:\Users\Administrator这个路径作为出发点，开始找Desktop目录。
* 假设是这样写的:cd c:\Users\Administrator\Desktop
  其中c:\Users\Administrator\Desktop路径就是一个绝对路径。
