下载完软件后

```
git config --global user.name "用户名"    //这里填写自己的用户名
git config --global user.email "邮箱"

//这里使用了 --global选项，下次就不用再设置，永久生效
//这个设置了好像只要电脑git不卸载，在任何一个文件夹打开都可以查寻到设置\
```

```
# 查看所有的全局配置项
git config --list --global

# 查看单个的配置项，比如查看用户名
git config user.name
git config user.email  //查看自己设置的邮箱
```

