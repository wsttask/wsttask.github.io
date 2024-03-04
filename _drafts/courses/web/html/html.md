### **HTML是什么**

1.超文本标记语言（Hyper Text Mark-up Language）

2.用来设计网页的标记语言

3.用该语言编写的文件，以.html或.htm为后缀

4.由浏览器解释执行

5.不区分大小写，建议小写

### **HTML标签**

1.HTML用于描述功能的符号成为“标签”

2.标签都封装在一对尖括号“<...>”之中，如<html>就是一个标签

3.封闭类型标记（也叫标记），必须成对出现，如<p></p>

非封闭类型标记，也叫空标记，或者但标记，如

web浏览器的作用是读取HTML文档，并以网页的形式显示出它们。浏览器不会显示HTML标签，而是使用标签来解释网页的内容。

### HTML骨架

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

</body>
</html>

输入!在vscode中可以自动生成
```

### HTML标题标签

```html
<h1></h1>
<h2></h2>
......
<h6></h6>
```

标题独占一行

### HTML段落标签

```html
<p></p>
```

特点

- 独占一行
- 段落之间存在间隙

### HTML换行水平线标签

```html
<br>
换行
<hr>
水平线
```

### 文本格式化标签

```html
<strong>加粗</strong>
<b>加粗</b>
<em>倾斜</em>
<i>倾斜</i>
<ins>下划线</ins>
<u>下划线</u>
<del>删除线</del>
<s>删除线</s>
```

### 图片标签

```html
<img src="图片的URL">
标签属性
alt 替换文本:图片加载不出来,替换的文本
title 提示文本:鼠标悬停上的时候提示的文本
width 图片宽度
height 图片高度
属性写在标签名后面,不用区分先后顺序
```

### 超链接

```html
<a>这是一个超链接</a>
标签属性
href 网址;必须属性;#代表空链接
target _blank:打开新窗口;
```

### 音频标签

```html
<audio>这是一个音频</audio>
标签属性
src 必须属性;
controls 显示音频控制面板;在html5里面,如果属性名和属性值完全一样,可以简写为一个单词
loop 循环播放;
autoplay 自动播放;
```

### 视频标签

```html
<video>这是一个视频</video>
src 必须属性;
controls 视频控制面板;
loop 循环播放;
muted 静音播放;
autoplay 自动播放;为了提升用户体验,浏览器支持静音自动播放
```

## 列表标签

#### ul

```html
<ul>
    <li>第一项</li>
    <li>第二项</li>
</ul>
ul 是无序列表;只能包裹li标签
li 是列表条目;可以包裹任何内容
```

### ol

```html
<ol>
    <li></li>
</ol>
```

### 定义列表

```html
<dl>
    <dt>标题</dt>
    <dd>详情1</dd>
    <dd>详情2</dd>
</dl>    
dl 只能包含dt和dd;dt和dd里面可以包含任何内容
```

#### 表格

```html
<table>
    <tr>
        <th>第一列</th>
        <th>第二列</th>
    </tr>
    <tr>
        <td>第二行第一列</td>
        <td>第二行第二列</td>
    </tr>
</table>

tr 里面包裹一行
th 表示表头单元格;有居中加粗的效果
td 内容单元格
border 设置是否有边框线;"1"代表边框线的粗细
```

表格中里面内容会把表格撑大

### 表格结构标签

```html
<thead>
</thead>

<tbody>
</tbody>

<tfoot>
</tfoot>
可以不写
浏览器解析更方便
```

### 合并单元格

```html

```

1.明确合并的目标

2.保留最左最上的单元格，添加属性（取值是数字，标识需要合并的单元格的数量）

​    跨行合并，保留最上单元格，添加属性rowspan

​    跨列合并，保留最左单元格，添加属性colspan

3.删除其他单元格

tips

合并单元格只能在自己结构中合并，比如head，body，不能跨结构合并

### 表单：input标签

```html
<input type="...">
type = text: 文本框;单行文本,不换行
type = password: 密码框;和text一样,只是都是以点代替的
type = radio: 单选框;是个小圆点
type = checkbox: 多选框;是个小方框
type = file: 上传文件
```

```html
<input type="text" placeholder="...">
placeholder: 提示信息;提示信息是灰色;可以在文本框密码框中使用
```

```html
<input type="radio" name="..." checked>
name: 组名称;多个单选框组名相同,只能有一个被选中
checked: 默认选中;属性名与值相同,只写一个checked就行
```

```html
<input type="file" mutiple>
mutiple: 可以选择多个文件
```

```html
<input type="checkbox" checked>
checked: 默认选中
```

### 表单：下拉菜单

```html
<select>
    <option selected></option>
    <option></option>
    <option></option>
</select>
```

### 表单：label标签：增大radio的点击范围

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=<device-width>, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <!-- 增大点击范围 -->
    <!-- 完成写法 id与for相同-->
    <input type="radio" name="gender" id="man"> <label for="man">男</label>
    <label><input type="radio" name="gender" >女</label>
</body>
</html>
```

### 字符实体

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <!-- 在网页中显示预留字符 -->
    <!-- 主要是空格，大于号，小于号三个字符 -->
    <!-- 在代码中有很多空格，网页只识别一个 -->
    乾坤未定，你我皆是黑          马
    <br>
    乾坤未定，你我皆是黑      马
    <P>
    <p>
</body>
</html>
```

## link

```html
<link href="main.css" rel="stylesheet" />
<!-- rel="stylesheet" 代表引入的href是层叠样式表 -->
```
