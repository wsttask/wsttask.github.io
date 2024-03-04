# HTML 5 <!DOCTYPE> 标签

## 定义和用法

<!DOCTYPE>

 声明必须位于 HTML5 文档中的第一行，也就是位于 <html> 标签之前。该标签告知浏览器文档所使用的 HTML 规范。

doctype 声明不属于 HTML 标签；tag; 它是一条指令，告诉浏览器编写页面所用的标记的版本。

doctype：document type

**注释：**<!DOCTYPE> 标签没有结束标签！

**提示：**<!DOCTYPE> 对大小写不敏感。

## 什么是 HTML5？

HTML5 是最新的 HTML 标准。

HTML5 是专门为承载丰富的 web 内容而设计的，并且无需额外插件。

HTML5 拥有新的语义、图形以及多媒体元素。

HTML5 提供的新元素和新的 API 简化了 web 应用程序的搭建。

HTML5 是跨平台的，被设计为在不同类型的硬件（PC、平板、手机、电视机等等）之上运行。

# head

```html
<head>
    <title>First webpage</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!--
        viewport窗口
meta name="viewport" content="width=device-width, initial-scale=1"
    可以让网页的宽度自动适应手机屏幕的宽度    
    -->
</head>
```

# 注释

```html
<!--
这是html的注释规范
-->
```

# img

| 属性     | 属性值  | 说明                 |
| ------ | ---- | ------------------ |
| src    | 图片路径 | 必须属性               |
| alt    | 文本   | 替换文本。图像不能显示的文字     |
| title  | 文本   | 提示文本。鼠标悬停在图像上显示的文字 |
| width  | 像素   | 设置宽度               |
| height | 像素   | 设置高度               |
| border | 像素   | 设置边框粗细             |

当您同时指定height和 时width，图像可能会丢失其纵横比。您可以通过仅指定width并设置height为auto使用 CSS 属性来保留纵横比。

# a

1）a 标签的 href 属性值如果是以 http 开头的，那么浏览器会马上去解释该网址：首先会在本地机器去找一个 hosts 文件， 如果在 hosts 文件上该域名没有对应的主机，那么浏览器就去到对应的 dns 服务器去寻找该域名对应的主机号。如果找到了对应的主机，那么该请求就会发给对应的主机，最后打开该页面。
2）如果 a 标签的 href 属性值没有以任何协议开头，那么浏览就会启动 file 协议解释器去解释该资源路径。
3）如果 a 标签的 href 属性值并不是以 http 协议，而且其他的一些协议，那么这时候浏览器就会到我们本地电脑的注册表中去查找是否有处理这种协议的应用程序，如果有，那么马上启动该应用程序处理该协议。

```html
<a href="https://bilibili.com">网址直接跳转</a> 
<a href="images/1.webp">相对路径跳转</a>
<a href="hello.exe">如果是打不开的文件，则下载之</a>
<a href="">空链接是刷新</a>
<a href="#">#是回到顶部</a>
<a href="javascript:;">禁止链接跳转</a>

<a href="https://bilibili.com" tatget="_blank">新窗口打开网页</a> 
<a href="https://bilibili.com" tatget="_self">当前窗口打开网页</a> 
```

# label

显示关联

```html
爱好：
<input type='checkbox' name='basket' id='basketball'>   
<label for="basketball">篮球</label>
<input type='checkbox' name='football' id='football'>   
<label for="football">足球</label>
```

**优点**：减少标签嵌套层数；label标签和表单可以在不同的位置
**缺点**：控件需要定义id属性；label标签和表单控件不利于作为一个整体来控制

隐式关联

直接将表单控件放到label标签内，这种情况下，label标签只能包含一个表单元素，包含多个只对第一个有效

```html
<label>点击我可使文本框获得焦点
    <input type='text' name='theinput' id='theinput'>
</label>
```

**优点**：控件无需定义id；标签和控件方便作为一个整体控制
**缺点**：增加了标签嵌套层数；不能将标签和关联控件放到不同的位置

# CSS类选择器和ID选择器的异同

1.id属性是标准属性，任何元素都可以有id属性。
2.使用id选择器时，要在id值前加上"#"
3.id选择器只能选中一个元素，同一个页面要保证id的唯一性(不同元素有相同id，也属于非法)
4.定义id时，必须要以字母开头，可以包含数字、下划线等符号。
5.定义id时，不要与标签名相同

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>ID选择器</title>
    <style type="text/css">
        #one{
            color: red;
        }
        #two{
            font-size: 30px;
        }
    </style>
</head>
<body>
    <ul>
        <li id="one">ID选择器1</li>
        <li id="two">ID选择器2</li>
        <li>ID选择器3</li>
        <li>ID选择器4</li>
        <li>ID选择器5</li>
        <li>ID选择器6</li>
    </ul>
</body>
</html>
```

1.class属性是标准属性，任何元素都可以有class属性。
2.使用class选择器时，要在class值前加上"."
3.class选择器可以被多个元素共同使用，不同元素可以有相同的class值
4.同一个元素可以有多个类名，多个类名时要用空格隔开
5.尽量使用类选择器，而不是id选择器。(id一般是js使用，class是css使用)

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>类选择器</title>
    <style type="text/css">
        .one{
            color: red;
            font-weight: 600;
        }
        .two{
            font-size:30px;
        }
    </style>
</head>
<body>
    <div>
        <div class="one">我要自学网1</div>
        <p class="one two">我要自学网2</p>
        <span class="one">我要自学网3</span>
    </div>
    <strong class="two">Strong元素下我要自学网</strong>
</body>
</html>
```

# div

div 是 division 的简写，division 意为分割、区域、分组。比方说，当你将一系列的链接组合在一起，就形成了文档的一个 division。

div 可定义文档中的分区或节（division/section）。div标签可以把文档分割为独立的、不同的部分。它可以用作严格的组织工具，并且不使用任何格式与其关联。如果用 id 或 class 来标记 ，那么该标签的作用会变得更加有效。

```css
class：
footer

id： 
footer

定义class的css是用点：“.”，如.footer
定义id的css是用井号“#”，如#footer

如下面：
* {
 margin: 0px;
 padding: 0px;
}
body{
 width:910px;
 height:auto;
 margin-left:auto;/*左右自动可以居中*/
 margin-right:auto;
 }
.header{
 background-color: #F6F;
 float: left;
 height: 80px;
 width: 910px;
}
.content{
 background-color: #FCF;
 float: left;
 height: auto;
 width: 910px;
 margin-top: 20px;
 padding-bottom:20px;

 }
.left{
 background-color: #930;
 float: left;
 height: 500px;
 width: 290px;
 margin-top: 20px;
 margin-left: 10px;
 display:inline;/*先把这个去掉看下，边距的问题，在IE6下双边据。加上这个就正常了*/
 margin-right:10px;
 }
.mid{
 background-color: #F06;
 float: left;
 height: 500px;
 width: 290px;
 margin-top:20px;
}
.right{
 float: right;
 height: 500px;
 width: 290px;
 margin-top: 20px;
 background-color:#0F0;
 margin-right:10px;
 display:inline;
}
.kuai{
 background-color: #00F;
 float: left;
 height: 80px;
 width: 890px;
 margin-left:10px;
 display:inline;
 margin-top:10px;
}
.footer{
 background-color: #000;
 float: left;
 height: 50px;
 width: 910px;
 margin-top: 20px;
}
```

# css调用

1.HTML文件顶部植入样式表

```html
<!DOCTYPE html>
<html>
    <style tpye="text/css">
        <!--
        H1 { color: green; font-family: impact }
        P { background: yellow; font-family: courier }
        -->
    </style>


    <head>
        <title>My First Stylesheet</title>
    </head>


    <body>
        <h1>Stylesheets: The Tool of the Web Design Gods</h1>
        <p>Amaze your friends! Squash your enemies!</p>
    </body>
</html>
```

2.HTML页面头部HEAD元素中调用

```html
<head> <!--页面头部内容开始-->
    <title>头部调用样式</title>
    <style>
        .content {
            width: 400px;
            height: 100px;
            color: #ffffff;
            background: #333333;
        }
    </style>
</head> <!--页面头部内容结束-->

<body class="body">
    <div class="content">这是一个页面头部调用样式的示例。</div> <!--调用CSS样式-->
</body>
```

3.HTML元素中直接调用

元素中直接使用样式的写法如下：

```html
<元素名称 style="属性:属性值"></元素名称>
```

说明：样式中直接使用CSS，语法是使用style标签。其中""中，样式的语法结构和独立样式表中完全相同。

```html
<div style="width:400px; height:100px; background-color:#cccccc;font-size:18px;">
```

4.使用link元素外部调用

你可以将多个HTML文件都链接到一个中心样式表文件，这里是样式表功能发挥得淋漓尽致的地方，把CSS声明做成一个CSS文件有3个好处：网速处理速度会更快一些，尤其是多个网页共用一份CSS样式表时更为出色；维护方便，只需要一次修改CSS文件就可以批量改变网页；维护个人知识产权，防止别人直接通过源码查看CSS语言．

```html
<html>
    <head>
        <title>my first stylesheet
        </title>
        <link rel=stylesheet href="style.css" type="text/css">
    </head>

    <body>
        <h1>stylesheets: the tool of the web design gods</h1>
        <p>amaze your friends! squash your enemies!</p>
    </body>
</html>
```

```css
H1 { color: green; font-family: impact }
P { background: yellow; font-family: courier }
```

# form

```html
<form>  
    <input type="text">    
    <button type="submit">提交按钮</button >
</form>
```

txt文本框

```html
输入框：<input type="text" placeholder="这是输入框"><br/>
```

password密码框

```html
密码框：<input type="password" placeholder="这是密码框"><br/>
```

radio单选框（name属性一样才能有只选择一个的效果）

```html
单选框：<input type="radio" name="gender">男<input type="radio" name="gender">女
```

radio单选框（**如果想要设置默认选择则必须添加checked属性值，页面打开后就会默认选中一个选项**）

```html
单选框：<input type="radio" name="gender" >男<input type="radio" name="gender" checked>女
```

checkbox多选框

```html
多选框：<input type="checkbox" checked>
```

submit提交按钮

```java
<input type="submit" value="提交按钮上字体">
```

select option下拉菜单（selected 初始选择）    

```html
下拉菜单
<select>
    <option>广州市</option>
    <option selected>海珠区</option>
    <option>月秀区</option>
</select>
```

textarea文本域

```html
评论：<br/>
<textarea></textarea>
```

lable标签

- 解释**lable标签其实就是标签的说明文本**
- 作用：**增大表单控件的点击范围**
- 运用范围：**文本框、密码框、文件、单选框、多选框、下拉菜单、文本域等**

```html
<label>用户名：<input type="text" placeholder="请输入用户名"></label>
<label>密码：<input type="password" placeholder="请输入密码"></label>
```

# 列表标签

## 无序列表标签<ul>

```html
 <body>
    <!-- 快捷生成多个子列表项：ul>li*3或li*5或ul.li{$}*5 -->
    <ul>
        <!-- 列表项的默认样式是实心圆 -->
        <li>我是列表项一</li>
        <li>我是列表项二</li>
        <li>我是列表项三</li>
    </ul>

    <ul type="circle">
        <!-- 指定列表项的样式是空心点 -->
        <li>我是列表项一</li>
        <li>我是列表项二</li>
        <li>我是列表项三</li>
    </ul>
    <ul type="square">
        <!-- 指定列表项的样式是实心方块 -->
        <li>我是列表项一</li>
        <li>我是列表项二</li>
        <li>我是列表项三</li>
    </ul>
    <ul type="none">
        <!-- 指定列表项不显示符号 -->
        <li>我是列表项一</li>
        <li>我是列表项二</li>
        <li>我是列表项三</li>
    </ul>
</body>
```

## 有序列表标签

```html
<!-- 默认是阿拉伯数字123排序 -->
    <ol>
        <li>张三</li>
        <li>李四</li>
        <li>王五</li>
    </ol>
    <ol type="a">
        <!-- 指定用小写字母a开始排序 -->
        <li>张三</li>
        <li>李四</li>
        <li>王五</li>
    </ol>
    <ol type="A">
        <!-- 指定用大写字母A开始排序 -->
        <li>张三</li>
        <li>李四</li>
        <li>王五</li>
    </ol>
    <ol type="i">
        <!-- 指定用小写罗马字母i开始排序 -->
        <li>张三</li>
        <li>李四</li>
        <li>王五</li>
    </ol>
    <ol type="I">
        <!-- 指定用大写罗马字母I开始排序 -->
        <li>张三</li>
        <li>李四</li>
        <li>王五</li>
    </ol>
```

## 有序列表前无符号显示

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>清除有序列表前面的符号</title>
    <!-- 方法二：通过引入外部样式里，有默认清除 -->
    <!-- <link rel="stylesheet" href="rest.css"> -->

    <!-- 方法一：直接给ol加一个样式就可以清除前面的符号 -->
    <style>
        /* 直接给ol加一个样式就可以清除前面的符号了，也可以通过引入外部样式里，有默认清除 */
        ol {
            list-style: none;
        }
    </style>
</head>

<body>
    <!-- 注意，有序列表顾名思义就是要有顺序，如果非要有序列表没有顺序的话，它是不支持type属性的值为none的。那么如果硬要有序列表前面不显示符号，方法是：给它加一个list-style:none的样式（可以直接添加在内部样式里或是引入外部样式默认清除样式）
 -->
    <ol type="I">
       <p>这是有序列表但是我可以通过设置list-style: none属性值去掉符号</p>
        <li>张三</li>
        <li>李四</li>
        <li>王五</li>
    </ol>
</body>

</html>
```
