#### git 常用命令

> ```bash
> # 查看git所有配置
> $ git config -l
> 
> # 查看系统的配置，其中--system是筛选条件   
> $ git config --system --list   、Git\etc\gitconfig:Git安装目录下的 gitconfig --system 系统级
> 
> # 查看缓存大小
> $ git config --get http.postBuffer 
> 
> # 重新设置缓存大小为1024M
> $ git config --global http.postBuffer 1024M 
> 
> # 查看个人的配置
> $ git config --global --list     、C:\Users\Administrator\ .gitconfig   只适用于当前登录用户的配置  --global 全局
> 
> # 配置user.name
> $ git config --global user.name "Sheng" 
> 
> # 配置user.email
> $ git config --global user.email "704341315@qq.com" 
> 
> (所有的配置，都是以文件形式保存在本地文件中) 
> 注意：git config --global 参数，有了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然你也可以对某个仓库指定的不同的用户名和邮箱。
> 
> # 克隆远程仓库
> $ git clone "adress" 
> 注意文件名中不能包含 \ / : * ? " < > ||
> 
> # 在当前目录新建一个Git代码库
> $ git init 
> 
> # 查看指定文件状态
> $ git status [filename]
> 
> #查看所有文件状态
> $ git status 
> 
> # 添加所有文件到暂存区
> $ git add . 
> 
> # 提交暂存区中的内容到本地仓库 -m 提交信息
> $ git commit -m "消息内容"    
> 
> # 把repository中的内容提交到远程仓库
> $ git push 
> 
> # 返回上一次修改
> $ git reset --hard HEAD^
> 
> # 返回该版本，直接更改workspace中的内容
> $ git reset --hard  [版本号]
> 
> # 不加参数即默认比较工作区与暂存区
> $ git diff [file] 
> 注意只能比较index和workspace中已有文件的差异，如果workspace中新增加了一个文件，那么就比较不出来这个文件
> 
> # 显示工作目录与当前git仓库之间的差异
> $ git diff HEAD 
> 
> # 显示工作目录与上一个版本git仓库之间的差异，或者可以说是git pull 之后查看修改
> $ git diff HEAD^
> 
> # 查看日志
> $ git log
> 
> # 查看日志
> $ git reflog 
> 
> # 可以丢弃工作区的修改，在index区进行检索file文件
> $ git checkout -- file
> 
> 1.readme.txt自动修改后，还没有放到暂存区，使用 撤销修改就回到和版本库一模一样的状态。
> 2.另外一种是readme.txt已经放入暂存区了，接着又作了修改，撤销修改就回到添加暂存区后的状态
> 3.可以恢复在工作区误删的文件file，只要repository区中有
> 
> # 列出所有本地分支
> $ git branch
> 
> # 列出所有远程分支
> $ git branch -r
> 
> # 列出所有本地分支和远程分支
> $ git branch -a
> 
> # 新建一个分支，但依然停留在当前分支
> $ git branch [branch-name]
> 
> # 新建一个分支，并切换到该分支
> $ git checkout -b [branch]
> 
> # 新建一个分支，指向指定commit
> $ git branch [branch] [commit]
> 
> # 新建一个分支，与指定的远程分支建立追踪关系
> $ git branch --track [branch] [remote-branch]
> 
> # 切换到指定分支，并更新工作区
> $ git checkout [branch-name]
> 
> # 切换到上一个分支
> $ git checkout -
> 
> # 建立追踪关系，在现有分支与指定的远程分支之间
> $ git branch --set-upstream [branch] [remote-branch]
> 
> # 合并指定分支到当前分支
> $ git merge [branch]
> 
> # 选择一个commit，合并进当前分支
> $ git cherry-pick [commit]
> 
> # 删除分支
> $ git branch -d [branch-name]
> 
> # 删除远程分支
> $ git push origin --delete [branch-name]
> $ git branch -dr [remote/branch]
> 
> 
> # 展示当前关联的其他仓库列表
> $ git remote -v 
> ```

### 关于git pull

git pull 会自动和本地提交合并，与本地有冲突时需要手动合并。

未提交本地代码进行 git pull 时，会提示异常提醒先 commit 后再进行 pull

也就是说，如果git pull拉下来的改变，你没有修改，就不会提示异常，

`git pull`实际上是`git fetch`和`git merge`两个命令的组合，它从远程仓库获取最新的代码并自动合并到当前分支。

### Git合并分支的具体步骤如下：

确认当前分支的状态：在执行合并分支命令之前，我们需要确认当前分支的状态，即是否有未提交的修改。可以通过git status命令查看当前分支的状态。

切换到要合并的分支：使用git checkout命令切换到要合并的分支，具体语法是git checkout <branch-name>，其中<branch-name>表示要合并的分支名。

合并分支：使用git merge命令合并分支，具体语法是git merge <branch-to-merge>，其中<branch-to-merge>表示要合并的分支名。

处理合并冲突：如果合并过程中存在冲突，需要手动解决冲突并提交代码。

确认合并结果：合并完成后，我们需要确认合并后分支的状态是否正确。可以使用git log命令查看分支的提交记录，或者使用git diff命令比较合并前后代码的差异。

**底层原理如下**

​	Git在底层存储时，使用了一种名为"commit graph"的数据结构来管理提交记录，该数据结构可以看作是一个**有向无环图**(DAG)，其中每个节点表示一个提交记录，每条有向边表示一个提交记录的父节点。在Git中，合并分支实际上是将两个分支的提交记录合并到一起，创建一个新的提交记录。合并分支的过程中，Git会执行以下操作：

​	找到两个分支最近的共同祖先：在合并分支前，Git会找到两个分支最近的共同祖先，这个祖先节点是合并操作的基础。

​	创建一个新的提交记录：Git会在共同祖先的基础上创建一个新的提交记录，该记录包含合并前两个分支的所有修改内容。这个新的提交记录将成为合并后分支的最新提交记录。

​	解决冲突：如果合并过程中存在冲突，Git会暂停合并操作，并让用户手动解决冲突。解决冲突后，用户需要使用git add命令将修改内容标记为已解决，然后使用git commit命令提交代码。

​	更新分支指针：合并完成后，Git会更新当前分支的指针，指向合并后的最新提交记录。同时，如果存在其他分支指针指向合并前的某个提交记录，也会被更新到指向合并后的最新提交记录。

