这里要啰嗦一遍概念，jar包就是 Java Archive File，顾名思义，它的应用是与 Java 息息相关的，是 Java 的一种文档格式，是一种与平台无关的文件格式，可将多个文件合成一个文件。jar 包与 zip 包非常相似——准确地说，它就是 zip 包，所以叫它文件包。jar 与 zip 唯一的区别就是在 jar 文件的内容中，包含了一个 `META-INF/MANIFEST.MF` 文件，该文件是在生成 jar 文件的时候自动创建的，作为jar里面的"详情单"，包含了该Jar包的版本、创建人和类搜索路径Class-Path等信息，当然如果是可执行Jar包，会包含`Main-Class`属性，表明Main方法入口，尤其是较为重要的Class-Path和Main-Class，咱们一会在后续的内容里面会进行详细地讲解。

​	此外，值得注意的是，因为jar包主要是对class文件进行打包，而java编译生成的class文件是平台无关的，这就意味着jar包是跨平台的，所以不必关心涉及具体平台的问题。说到jar里面的文件，咱们来看看最普通的一个带有静态页面的springboot项目jar里面的内容，就会发现解压出来的jar并不简单，为了贴近实际咱们未做任何删减，可以看到有很多东西

​	只需要运行如下指令，就能看到jar里面的内容（调用jar指令的前提是已经配置了jdk的环境变量）

jar -tf springbootdemo-0.0.1-SNAPSHOT.jar

其中-tf 后接的jar就是我们要查看的jar