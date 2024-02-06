PATHEXT环境变量简介
最近在机子上装了一些软件之后，机子出了点问题，所有的exe工具文件(甚至包括一些cmd下的命令)，都无法直接打开执行了，必须要输全整个文件名，例如sqlplus.exe。在问了一圈同事之后(不包括我们的系统管理员)，居然还是没有一个准确的答案。最后询问了系统管理员之后，发现只是因为简单的环境变量设置问题，真是感叹大家对操作系统的白痴了-_-|||
在网上找了点资料看一下，简单介绍介绍PATHEXT这个环境变量，顺便就当练习英文了。
----------------------
Windows XP’s Run commandprovides a quick and easy way for experienced users to open fileswithout the need to navigate through the Start menu or browsefolders looking for a file. For example, if you type cmd.exe at theRun command and press Enter, a Command Prompt windows will open.Type msconfig.exe and the System Configuration Utility does thesame.
You may also be aware of thefact that its not always necessary to enter certain file extensionswhen using the Run command. For example, entering just the filenameportion of the command - say, cmd rather than cmd.exe - if OKbecause the EXE file extension is one of those tried by XP when anextension isn’t supplied. XP will attempt to use a number of fileextensions when you don’t provide one, as dictated byit’s declared PATHEXTvariables.
By default, the followingPATHEXT system variables are declared by XP:.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH. One notable onethat isn’t present is the .MSC extension used by saved MMCconsoles. If you want pre-built consoles like the Services MMC toopen without needing to type its full filename - services.msc - atthe Run command, then you’ll need to add .MSC to the XP’s PATHEXTvariable.
To add a new file extensionto XP’s PATHEXT system variable, follow these steps:
1. Open the System applet inControl Panel.
2. Click the Advanced tab,and then click the Environment Variables button.
3. Double-click the PATHEXTvariable in the System variables section and then clickEdit.
4. After the .WSH entry,type a semi-colon and then type .MSC (no spaces required) and thenclick OK.
5. Reboot your system andthen attempt to open the Services MMC from the Run command bysimply typing services and then click OK.
----------------------
WindowsXP的“运行”命令为一些有经验的用户提供了一个简单快速的方法来打开文件，而不再需要通过“开始”目录，或在文件夹中寻找文件。例如：当我再“运行”窗口中输入cmd.exe 并点击确定时，命令行窗口就直接被打开了。同样的，输入 msconfig.exe后，可以直接打开“系统配置”界面。
其实很多人都知道，当使用“运行”命令时，并不需要总是输入某些文件的扩展名的，例如只输入文件名部分，用cmd代替cmd.exe即可。如果这样可以，那是因为EXE文件扩展名是XP中的可靠扩展名而无须提供。当你没有输入扩展名时，XP会尝试几种默认扩展名，这些XP默认的扩展名就在PATHEXT变量中声明。
PATHEXT系统变量默认的声明如下：.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH。需要注意的是 .MSC扩展名并不在此之列。这个后缀的文件用来打开XP的管理控制台。如果你希望打开类似Services这类MMC文件，而不在“运行”窗口输入文件全名(services.msc)，那么就需要将.MSC添加到XP的PATHEXT变量中。
要增加一个新的文件扩展名到XP的PATHEXT变量中的步骤如下：
1、打开控制面板 - 性能和维护 - 系统
2、点击“高级”，再点击“环境变量”按钮
3、在系统变量列表中，双击PATHEXT变量并点击“编辑”按钮
4、在.WSH后面输入一个分号，再输入.MSC，然后点击“确定”
5、重启系统后尝试不加扩展名打开services.msc

> 注意，这里是通过cmd打开，在运行界面不可以

其实对于PATHEXT的性质来说，还可以用来做一些其他的用途，例如在网上看到的一个，不希望别人在自己机子上使用ping、net等命令，就可以通过修改PATHEXT中的文件扩展名排列顺序来实现，主要就是因为XP系统在自己匹配默认扩展名是是根据PATHEXT中的排列顺序依次进行的，简单讲一讲做法：
首先将PATHEXT中的扩展名排列顺序修改为.BAT排在最前，然后创建ping.bat、net.bat文件，存放到%SystemRoot%\system32(即存放ping.exe、net.exe的地方)，bat中的内容如下：
@echo off
echo '%0' 不是内部或外部命令，也不是可运行的程序
echo 或批处理文件。
这样，当在cmd下输入ping之后，由于未加后缀，导致windows自己匹配，在首先匹配到ping.bat之后执行该文件，在前段显示该命令不存在的信息，这样就可以简单欺骗不熟悉系统的用户(比如说我)。当然自己用的时候，输全ping.exe来执行命令就可以了。