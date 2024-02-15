
#### ping命令的七种用法，看完瞬间成大神
一、ping基本使用详解

在网络中ping是一个十分强大的TCP/IP工具。它的作用主要为：

1、用来检测网络的连通情况和分析网络速度

2、根据域名得到服务器IP

3、根据ping返回的TTL值来判断对方所使用的操作系统及数据包经过路由器数量。

我们通常会用它来直接ping ip地址，来测试网络的连通情况。

![img](../images/XrXZ6uXDNddn5rU66xMi62.jpg)

类如这种，直接ping ip地址或网关，ping通会显示出以上数据，有朋友可能会问，bytes=32；time<1ms；TTL=128 这些是什么意思。

bytes值：数据包大小，也就是字节。

time值：响应时间，这个时间越小，说明你连接这个地址速度越快。

TTL值：Time To Live,表示DNS记录在DNS服务器上存在的时间，它是IP协议包的一个值，告诉路由器该数据包何时需要被丢弃。可以通过Ping返回的TTL值大小，粗略地判断目标系统类型是Windows系列还是UNIX/Linux系列。

默认情况下，Linux系统的TTL值为64或255，WindowsNT/2000/XP系统的TTL值为128，Windows98系统的TTL值为32，UNIX主机的TTL值为255。

因此一般TTL值：

100~130ms之间，Windows系统 ；

240~255ms之间，UNIX/Linux系统。

当然，我们今天主要了解并不是这些，而是ping的其它参考。

ping命令除了直接ping网络的ip地址，验证网络畅通和速度之外，它还有这些用法。

![img](../images/zLq96z8cDC6Hrr69kmkCCY.jpg)

二、ping -t的使用

不间断地Ping指定计算机，直到管理员中断。

![img](../images/BJlVgPBB95J077TG85rjtD.jpg)

这就说明电脑连接路由器是通的，网络效果很好。下面按按住键盘的Ctrl+c终止它继续ping下去，就会停止了，会总结出运行的数据包有多少，通断的有多少了。

三、ping -a的使用

ping-a解析计算机名与NetBios名。就是可以通过ping它的ip地址，可以解析出主机名。

![img](../images/gj07JZERiJTj1Z3T3898Cq.jpg.thumb.jpg)

四、ping -n的使用

在默认情况下，一般都只发送四个数据包，通过这个命令可以自己定义发送的个数，对衡量网络速度很有帮助，比如我想测试发送10个数据包的返回的平均时间为多少，最快时间为多少，最慢时间为多少就可以通过以下获知：

![img](../images/qqjvP9tiFqhyQR6QJPPbfI.jpg)

从以上我就可以知道在给47.93.187.142发送10个数据包的过程当中，返回了10个，没有丢失，这10个数据包当中返回速度最快为32ms，最慢为55ms，平均速度为37ms。说明我的网络良好。

如果对于一些不好的网络，比如监控系统中非常卡顿，这样测试，返回的结果可能会显示出丢失出一部分，如果丢失的比较多的话，那么就说明网络不好，可以很直观的判断出网络的情况。

五、ping -l size的使用

-l size：发送size指定大小的到目标主机的数据包。

在默认的情况下Windows的ping发送的数据包大小为32byt，最大能发送65500byt。当一次发送的数据包大于或等于65500byt时，将可能导致接收方计算机宕机。所以微软限制了这一数值；这个参数配合其它参数以后危害非常强大，比如攻击者可以结合-t参数实施DOS攻击。（所以它具有危险性，不要轻易向别人计算机使用）。

例如：ping -l 65500 -t 211.84.7.46

会连续对IP地址执行ping命令，直到被用户以Ctrl+C中断.



这样它就会不停的向211.84.7.46计算机发送大小为65500byt的数据包，如果你只有一台计算机也许没有什么效果，但如果有很多计算机那么就可以使对方完全瘫痪，网络严重堵塞，由此可见威力非同小可。

六、ping -r count 的使用

在“记录路由”字段中记录传出和返回数据包的路由，探测经过的

路由个数，但最多只能跟踪到9个路由。

ping -n 1 -r 9 202.102.224.25 （发送一个数据包，最多记录9个路由）



将经过 9个路由都显示出来了，可以看上图。

ping命令用的较多的就这6类的，大家有可能在项目中会用到的。

七、批量ping网段

对于一个网段ip地址众多，如果单个检测实在麻烦，那么我们可以直接批量ping网段检测，那个ip地址出了问题，一目了然。

先看代码，直接在命令行窗口输入：

for /L %D in (1,1,255) do ping 10.168.1.%D

IP地址段修改成你要检查的IP地址段。



当输入批量命令后，那么它就自动把网段内所有的ip地址都ping完为止。

那么这段“for /L %D in(1,1,255) do ping 10.168.1.%D” 代码是什么意思呢？

代码中的这个(1,1,255)就是网段起与始，就是检测网段192.168.1.1到192.168.1.255之间的所有的ip地址，每次逐增1，直接到1到255这255个ip检测完为止。
————————————————
版权声明：本文为CSDN博主「独爱米粒」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_42993535/article/details/89692630