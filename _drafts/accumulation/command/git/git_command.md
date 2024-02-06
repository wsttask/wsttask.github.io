### 初始化仓库，并与远程仓库建立连接

```bash
// 初始化仓库，无参数代表初始化本目录为仓库
git init <filename>
// 使用 git remote add 命令将本地仓库与远程仓库进行关联，其中 origin 是远程仓库的别名，也可以是其他的名字
git remote add origin https://github.com/xu-xiaoya/Elegent.git
//

```

### git push详解

```bash
// 命令格式
git push <远程主机名> <本地分支名>:<远程分支名>
// 如果本地分支名与远程分支名相同，则可以省略冒号与远程分支名
git push <远程主机名> <本地分支名>

example:
// 以下命令将本地的 master 分支推送到 origin 主机的 master 分支。
git push origin master

// 如果本地版本与远程版本有差异，但又要强制推送可以使用 --force 参数：
git push --force origin master

```

[git push 的 -u 参数含义_git push -u-CSDN博客](https://blog.csdn.net/Lakers2015/article/details/111318801)

### git remote

```bash
git remote -v //查看git对应的远程仓库地址

git remote remove <remote_name>//从当前仓库中删除指定的远程仓库。

git remote -v //查看是否删除成功，如果没有任何返回结果，表示OK

git remote rename <old_name> <new_name>//将已配置的远程仓库重命名。

git remote add origin https://github.com/***.git //重新关联git远程仓库地址
```

### git substree

```bash
```

### git pull

```bash
git pull <远程主机名> <远程分支名>:<本地分支名>
```

