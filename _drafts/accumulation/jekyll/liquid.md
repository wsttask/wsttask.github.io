---
layout: post
title: "liquid 学习"
categories: liquid
---



[操作符 – Liquid 模板语言中文文档 | Liquid 中文网 (bootcss.com)](https://liquid.bootcss.com/basics/operators/)





[迭代／循环 – Liquid 模板语言中文文档 | Liquid 中文网 (bootcss.com)](https://liquid.bootcss.com/tags/iteration/)

### for循环

```html
{% assign sorted_categories = site.categories | sort_natural %}
{% for category in sorted_categories %}
{% endfor %}
```

