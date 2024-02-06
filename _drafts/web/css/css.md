层叠样式表（Caacading Style Sheets)css，是一种样式表语言，用来描述html文档的呈现（美化内容）

书写位置：title标签下方添加style双标签，style标签里面书写CSS代码

## CSS引入方式

- 内部样式表
  - CSS代码写在style标签里面
  - style标签写在title标签下面
- 外部样式表
  - CSS代码写在单独的CSS文件中（.css）
  - 在HTML使用link标签引入
    - link标签写在title标签下面
    - <link rel="stylesheet" href="./my.css">
- 行内样式：配合JavaScript使用

## 选择器

- 标签选择器（都是标签）
  - 直接设置所有标签都是这样
  - 例如：p，h1，div，

- 类选择器
  - 首先定义类选择器
    - .类名
  - 使用类选择器
    - 标签添加class=”类名“
  - 类选择器用几次都行
- id选择器
  - 定义id选择器名
    - #id名
  - 使用id选择器
    - 标签添加 id=”id名“
  - id选择器只能用一次

开发习惯：类名见名知意，多个单词使用-连接，例如：news-hd



[36-字体族_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1kM4y127Li/?p=37&spm_id_from=pageDriver&vd_source=ec2d561dc8bd6d2bdcc13e464af382d0)