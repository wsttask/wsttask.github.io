---
layout: post
title: "Java SE, Java EE"
---

Java SE(Java Platform,Standard Edition)，应该先说这个，因为这个是标准版本。

Java EE (Java Platform，Enterprise Edition)，java 的企业版本

Java ME(Java Platform，Micro Edition)，java的微型版本。

JavaSE 可以开发和部署在桌面、服务器、嵌入式环境和实时环境中使用的 Java 应用程序。是EE，和ME的基础。一般就是指JDK。就是Java的基础语法（变量、方法、类之间的调用、关系，继承、接口、线程之类的），工具包（java.util.*  ）,或者其他的一些封装

JavaEE，其实是一套规范，就是用java语言做企业开发（目前看来就是开发一些动态网站，或者对外提供调用服务的网站，或者其他没接触过的。。。）中的一整套规范，比如类怎么封装，网页的请求要用什么方法处理，语言编码一类的处理，拦截器啊什么的定义，请求返回得有什么信息。。。（具体看servlet的接口就知道了）

比如：tomcat就是按照这套规范开发的容器软件，还有什么weblogic，JBoss、Resin等等

正因为我们开发网站（使用JSP，Servelet。。或者封装了这些的框架：SSH。。。）可以放在tomcat，也可以放在JBoss。。。。，因为都是按照一个规范开发的东西，实际使用的还是JavaSE的那些东西，多出来的就是EE的一些规范类的封装代码。

JavaME 是微型版本，顾名思义，使用在手机啊，小设备啊上面的Java版本，特点就是小，相比JavaSE精简了很大一部分东西，（增加了一些小设备上的专有API，？？？这个不是很确定），

我在2009年培训的时候，这个还写过游戏，还用在移动啊什么的开发上，可是后来你们应该知道了。。。安卓时代来临了。

安卓中既然用的是Java，那么Java的语法应该都是适用的。所以SE是核心基础。其他的都是使用方法方式不同。

