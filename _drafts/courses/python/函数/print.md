# print

函数原型：

```python
def print(self, *args, sep=' ', end='\n', file=None):

print(*objects, sep=' ', end='\n', file=sys.stdout, flush=False)
objects -- 复数，表示可以一次输出多个对象。输出多个对象时，需要用 , 分隔。
sep -- 用来间隔多个对象，默认值是一个空格。
end -- 用来设定以什么结尾。默认值是换行符 \n，我们可以换成其他字符串。
file -- 要写入的文件对象。
flush -- 输出是否被缓存通常决定于 file，但如果 flush 关键字参数为 True，流会被强制刷新。
正常情况下print到test.txt中的内容先从到内存中，当文件对象关闭时才把内容输出到
test.txt 中，当flush=True时它会立即把内容刷新存到 test.txt 中
```

```python
print("www","runoob","com",sep=".")

>
www.runoob.com

Process finished with exit code 0

# 注意这里的 sep/sequence 是指的是不同的对象之间用.隔开
```

```python
a = 'abc';b = 'bcd';print(a,b);print(a+b)

>
abc bcd
abcbcd

Process finished with exit code 0

# 注意在print函数中可以用+号将多个对象连接起来
```

# python 中的 + 号

```python
1.对于int类型，“+”表示两个数相加
2 + 3
结果是5


2.对于str类型，“+”表示字符串的连接

'ab' + 'cd'
结果是'abcd'


3.两个list相加，表示两个list相连

python_list = [1, 2, 3]
python_list + python_list
结果是 [1, 2, 3, 1, 2, 3]


4.对于python中的numpy，“+”表示值相加

import numpy as np
numpy_array = np.array([1, 2, 3])
numpy_array + numpy_array 
结果是 array([2, 4, 6])


总之，在python中，对于“+”，不同的类型=不同的行为
```

