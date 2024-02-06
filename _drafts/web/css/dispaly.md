#### 行内元素

```css
div {
    display: inline;
}
```

一行共存多个，宽高属性不生效，宽高由内容撑开

#### 块级元素

```css
div {
    display: block;
}
```

独占一行，宽度默认是父级的100%，但高度不是，添加宽高属性生效

#### 行内块元素

``` css
div {
    display: inline-block;
}
```

一行存在多个，宽高属性生效，宽高默认由内容撑开

#### 弹性盒子布局

```css
div {
    display: flex;
}
```

[flex弹性盒子布局](https://blog.csdn.net/qq_44537625/article/details/100040169)