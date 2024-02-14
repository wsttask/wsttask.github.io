
```
#include<stdio.h>
int strcmp(const char* str1, const char* str2)
```


strcmp()函数首先将str1字符串的第一个字符的ACSII值减去str2第一个字符的ACSII值(自左向右逐个字符相比，直到出现不同的字符或遇'\0'为止)

若差值为零则继续比较下去；若差值不为零，则返回差值。

特别注意：strcmp可用于比较两个字符串常量或比较数组和字符串常量，不能比较数字等其他形式的参数
