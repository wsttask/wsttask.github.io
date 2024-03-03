---
layout: post
title: jekyll blog
categories: [task]

---





### 示例

[Jekyll 的 Categories 设计 | Cotes' Blog](https://cotes.page/posts/jekyll-categroies-design/)

### 目标

- 读取_drafts中的目录结构，根据目录结构进行 jekyll 的Categories的设计
  - 懂每个文件的Front matter约定是怎么做的
  - 然后python脚本撰写categories

- 目录可以与文件共存
- 只允许markdown文件
- 注意表示参考文件

### 问题

- 文件资源过多会不会卡顿？
  - 不至于吧，到时候卡顿再说
- 每一级目录都需要进行一个页面设计？
  - 方案1，干脆直接展示所有文件
  - 方案2，像资源管理器那样展示本级目录下的所有文件
  - 方案3，展示本级目录下的文件夹，不展示md文件

[Jekyll 的 Categories 设计 | Cotes' Blog](https://cotes.page/posts/jekyll-categroies-design/)

### 设计

- layout中设计categoires.html，展示categoires界面
- layout中设计category.html，展示单级目录

### 学习

- Liquid
- python
- 箭头展开，应该是js
- bootstrap







### 问题

- 无法做出多重嵌套的效果

### 方案

- 使用permalink，这样生成的_site就是多级结构的样子
  - 如何做目录呢
- 我想是通过python写一个脚本，生成一个目录文件，里面按照结构生成目录文件，这样不需要jekyll进行读取，