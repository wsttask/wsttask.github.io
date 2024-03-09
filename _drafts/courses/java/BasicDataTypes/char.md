## 浅谈[Unicode](https://so.csdn.net/so/search?q=Unicode&spm=1001.2101.3001.7020)和char的关系（Java）

我们知道字符类型 char 在Java 中是和 Unicode编码 形成一一对应的映射来存储的，而采取的编码方式则为 UTF-16。

char只有两个字节,只能存unicode的UTF-16编码格式的两个字节的,所以有些汉字存不到