JFrame类是用来创建窗体的

![](../../images/JFrame_1.png)

注意：窗体是会为你提供一个最小化和可关闭化按钮

创建的窗体是一个可以任意拖动大小的窗体，你可以选中窗体的任意一个边框进行拖拽，他就会改变现有的大小，但是如果你想拥有一个固定大小的窗体那么你就需要给自己的窗体增加限制条件；可以调用窗体的setResizable方法对窗体的操作进行限制；

若要创建一个需要在多个地方使用的窗体，可将此窗体封装为JFrame的一个子类，即创建一个类继承JFrame类。

关于setContentPane()和getContentPane()的应用

我们可以在 JFrame 对象中添加 AWT 或者 Swing 组件。但是，虽然它有 add 方法，却不能直接用于添加组件，否则会抛出异常——不信就试试。造成这个现象的原因只有一个解释：JFrame 不是一个容器，它只是一个框架。那么，应该怎么添加组件呢？

JFrame 有一个 Content Pane，窗口能显示的所有组件都是添加在这个 Content Pane 中。JFrame 提供了两个方法：getContentPane 和 setContentPane 就是用于获取和设置其 Content Pane 的。

对JFrame添加组件有两种方式：

1) 用getContentPane()方法获得JFrame的内容面板，再对其加入组件：
```
frame.getContentPane().add(childComponent)
```
2) 建立一个Jpanel或JDesktopPane之类的中间容器，把组件添加到容器中，用setContentPane()方法把该容器置为JFrame的内容面板：
```
Jpanel contentPane=newJpanel();    
//把其它组件添加到Jpanel中;     
frame.setContentPane(contentPane); 
//把contentPane对象设置成为frame的内容面板
```
JFrame方法的代码举例
import javax.swing.*;
import java.awt.*;
 
public class JFrameDemo {
    public static void main(String[] args) {
        // 给窗体提供一个名称
        JFrame frame=new JFrame("窗体标题");
        //设置是否展示窗体
        frame.setVisible(true);
        /*
        *窗体关闭规则
        * EXIT_ON_CLOSE：设置关闭窗体停止程序
        * DO_NOTHING_ON_CLOSE：没有任何操作
        * HIDE_ON_CLOSE：关闭窗体但是不停止程序
        * DISPOSE_ON_CLOSE：释放窗体资源
        * */
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //设置窗体的大小 单位是像素
        frame.setSize(300,200);
        // 设置窗体的坐标
        frame.setLocation(200,200);
        // 设置窗体坐标和大小
        frame.setBounds(200,200,300,200);
        // 获取窗体容器
        Container container = frame.getContentPane();
        // 设置窗体背景颜色
        container.setBackground(Color.white);
        // 创建标签
        JLabel label = new JLabel("这是一个窗体");
        // 将窗体添加到容器中
        container.add(label);
        // 将窗体从容器中删除
        /*container.remove(label);*/
        // 验证容器中的组件
        container.validate();
        // 让窗体重新的载入这个容器(与上一步具有相同的效果)
        /*frame.setContentPane(container);*/
 
    }
}

### 对JFrame的getContentPane()的一些推测。
大一下学期开始学习JAVA，这个星期开始学JAVA的Swing，对于JFrame顶级容器并不了解，通过查询网上的一些信息结合自己的推理，得到以下的一些猜测。如有不对，实属正常，请指出错误，勿喷。首先我创建一个JFrame窗口，并用其引用设置窗口背景颜色，显然窗口颜色没有改变，（图一）。后面用getContentPane().setBackground()方法设置窗口颜色，运行后窗口背景颜色确实改变了（图二）。说明在创建JFrame实例的过程中就已经自动为JFrame加上了一个默认的ContentPane，PS（默认的这个ContentPane是什么类型的容器，有人说是JPanel类型，但是JPanel的默认布局管理器是FlowLayout，而这个默认的ContentPane的布局管理器是BorderLayout，这就是为什么通过JFrame的add()方法添加组件只能显示最后添加一个。所以我觉得默认的ContentPane类型应该不是JPanel类型。）所以只有使用getContentPane().setBackground()才能够改变窗口的背景颜色，因为现在我们在窗口看见的是这个默认的ContentPane而不是JFrame。接着利用getContentPane()方法，创建了两个引用，ct1,ct2,这里说明一下，使用getContentPane()方法返回的对象都是同一个对象，例如我通过ct2也改变了窗口的颜色，通过ct1,ct2的add()方法添加组件也就相当于JFrame实例的add()方法添加组件。同理，用setContentPane(XX)为JFrame设置窗口面板，将使得JFrame的默认面板改为XX。（图三图四图五图六）。接下来，我又创建了一个JPaneld的实例，并把这个实例添加到JFrame实例中。这里有个问题，就是添加的这个JPanel的实例是与默认的ContentPane同级还是被添加到默认的ContentPane面板上？答案是和其它组件一样被添加到默认的ContentPane面板上，可以通过下面这个程序证明，利用.getParent()方法，知道JPanel实例被添加到了默认的ContentPane上。还有System.out.println(jf1.getContentPane()==jf1.getRootPane().getContentPane());也是得到true。因为JFrame一共分为RootPane，LayeredPane，ContentPane。我们得到那个默认的ContentPane就是在ContentPane这层。之后加入的JPanel容器与实例等这些都将加入到这层上，不会被加到LayeredPane上，但是菜单栏例外。（结构图在图七）。以上全部为我猜想的，如果有误请大哥们指出。我马上改正。

#### JFrame常用构造方法
```
//创建一个jFrame面板，使用BorderLayout管理布局。
JFrame()

JFrame(String title)
```

#### JFrame常用方法
```
//获得JFrame的内容面板
Container getContentPane()

// 设置窗口的 标题
void setTitle(String title)

// 设置窗口的 图标
void setIconImage(Image image)

// 设置窗口的 宽高
void setSize(int width, int height)
void setSize(Dimension d)

/**
 * 设置窗口关闭按钮点击后的默认操作, 参考值:
 *     WindowConstants.DO_NOTHING_ON_CLOSE: 不执行任何操作。
 *     WindowConstants.HIDE_ON_CLOSE: 隐藏窗口（不会结束进程）, 再次调用 setVisible(true) 将再次显示。
 *     WindowConstants.DISPOSE_ON_CLOSE: 销毁窗口, 如果所有可显示的窗口都被 DISPOSE, 则可能会自动结束进程。
 *     WindowConstants.EXIT_ON_CLOSE: 退出进程。
 */
void setDefaultCloseOperation(int operation)

// 设置窗口是否可放大缩小，false：不可改变大小
void setResizable(boolean resizable)

// 设置窗口的 位置（相对于屏幕左上角）
void setLocation(int x, int y)
void setLocation(Point p)

// 设置窗口的 位置 和 宽高
void setBounds(int x, int y, int width, int height)
void setBounds(Rectangle rect)

// 获取窗口的位置坐标（相对于屏幕坐标空间）
Point getLocationOnScreen()
// 获取窗口的位置坐标（相对于父级坐标空间, 窗口的父级一般就是屏幕）
Point getLocation()

/**
 * 设置窗口的相对位置。
 * 如果 comp 整个显示区域在屏幕内, 则将窗口放置到 comp 的中心;
 * 如果 comp 显示区域有部分不在屏幕内, 则将该窗口放置在最接近 comp 中心的一侧;
 * comp 为 null, 表示将窗口放置到屏幕中心。
 */
void setLocationRelativeTo(Component comp)

// 设置将窗口 置顶 显示
void setAlwaysOnTop(boolean alwaysOnTop)

// 设置窗口的内容面板
void setContentPane(Container contentPane)

// 设置窗口是否可见, 窗口对象刚创建和添加相应组件后通过 setVisible(true) 绘制窗口, 其内部组件可能要此时才有宽高值
void setVisible(boolean b)

// 判断窗口是否处于显示状态
boolean isShowing()

// 销毁窗口, 释放窗口及其所有子组件占用的资源, 之后再次调用 setVisible(true) 将会重构窗口
void dispose()

// 调整窗口的大小, 以适合其子组件的首选大小和布局。
void pack()
```

#### JFrame添加组件
```
//用getContentPane()方法获得JFrame的内容面板，再对其加入组件：
frame.getContentPane().add(childComponent)

//建立一个Jpanel或JDesktopPane之类的中间容器，把组件添加到容器中，用setContentPane()方法把该容器置为JFrame的内容面板：
Jpanel contentPane = new Jpanel(); //把其它组件添加到Jpanel中;     
frame.setContentPane(contentPane); //把contentPane对象设置成为frame的内容面板
```