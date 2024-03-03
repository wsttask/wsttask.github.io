##### 定义： 设$f(t)$使$[0,+\infty]$上的实（或复）值函数，若对参数$s=\beta+jw$，$F(x)=\int_{0}^{+\infty}f(t)e^{-st}dt$在$s$平面内的某一区域内收敛，则称其为$f(t)$的Laplace变换，记为

$$
L[f(t)]=F(s)=\int_{0}^{+\infty}f(t)e^{-st}dt
$$
其中$F(s)$称为像函数，$f(t)$称为原像函数。

##### 拉氏变换的存在定理

​	若函数$f(t)$满足：

​	（1）在$t\ge0$的任一有限区间上分段连续

​	（2）当$t\rightarrow+\infty$时，$f(t)$的增长速度不超过某一指数函数，即存在常数$M>0$及$c\ge0$，使得$|f(t)|\le Me^{ct},\quad 0<t<+\infty$，则$f(t)$的拉氏变换在半平面$Re(s)>c$上一定存在，并且在$Ree(s)>c$的半平面内，$F(s)$为解析函数。



#### 第二节、Laplace变换的性质

##### （1）线性性质

##### （2）微分性质

​		若$L[f(t)]=F(s)$，则有
$$
L[f'(t)]=sF(s)-f(0)
$$

​		推论：
$$
L[f^{n}(t)]=s^nF(s)-s^{n-1}f(0)-...-f^{n-1}(0)
$$


##### （3）积分性质

​		若$L[f(t)]=F(s)$，则有
$$
L[\int_0^tf(t)dt]=\frac1sF(s)
$$

##### （4）位移性质

$$
L[e^{at}f(t)]=F(s-a)
$$



##### （5）延迟性质

$$
L[f(t-\tau)]=e^{-s\tau}F(s)
$$



#### 第三节、Laplace逆变换

$$
L^{-1}[F(s)]=\sum\limits_{k=1}^nRes[F(s)e^{st},s_k]
$$

#### 第四节、卷积

##### 卷积的概念：

$f_1(t)*f_2(t)=\int_{-\infty}^{+\infty}f_1(\tau)f_2(t-\tau)d\tau$

如果$f_1(t)$和$f_2(t)$都满足条件：当$t<0$时，$f_1(t)=f_2(t)=0$，则上式可以写成：
$$
f_1(t)*f_2(t)=\int_0^tf_1(\tau)f_2(t-\tau)d\tau
$$

##### 卷积定理

$$
L[f_1(t)*f_2(t)]=L[f_1(t)]·L[f_2(t)]=F_1(s)·F_2(s)\\
L^{-1}[F_1(s)·F_2(s)]=f_1(t)*f_2(t)
$$

#### 补充：常见函数的Laplace变换

![image-20230512224250084](../images/image-20230512224250084.png)