## 2.2 AWT继承体系

所有和 AWT 编程相关的类都放在 java.awt 包以及它的子包中， AWT 编程中有两个基类 :Component和 MenuComponent。

- Component：代表一个能以图形化方式显示出来，并可与用户交互的对象，例如 Button 代表一个按钮，TextField 代表 一个文本框等；
- MenuComponent：则代表图形界面的菜单组件，包括 MenuBar (菜单条)、 Menultem (菜单项)等子类。

![](../../../images/AWT组件继承体系.png)

其中 Container 是一种特殊的 Component，它代表一种容器，可以盛装普通的 Component。

AWT中还有一个非常重要的接口叫LayoutManager ，如果一个容器中有多个组件，那么容器就需要使用LayoutManager来管理这些组件的布局方式。

![](../../../images/LayoutManager.png)

## 2.3 Container容器

### 2.3.1 Container继承体系
![](../../../images/Container继承体系.png)
- Winow是可以独立存在的顶级窗口,默认使用BorderLayout管理其内部组件布局;
- Panel可以容纳其他组件，但不能独立存在，它必须内嵌其他容器中使用，默认使用FlowLayout管理其内部组件布局；
- ScrollPane 是一个带滚动条的容器，它也不能独立存在，默认使用 BorderLayout 管理其内部组件布局；

### 2.3.2 常见API

#### Component
作为基类，提供了如下常用的方法来设置组件的大小、位置、可见性等。

| 方法签名                                       | 方法功能                   |
| ---------------------------------------------- | -------------------------- |
| setLocation(int x, int y)                      | 设置组件的位置。           |
| setSize(int width, int height)                 | 设置组件的大小。           |
| setBounds(int x, int y, int width, int height) | 同时设置组件的位置、大小。 |
| setVisible(Boolean b):                         | 设置该组件的可见性。       |

#### Container
作为容器根类，提供了如下方法来访问容器中的组件

| 方法签名                                 | 方法功能                                                     |
| --------------------------------------- | ------------------------------------------------------------ |
| Component add(Component comp)           | 向容器中添加其他组件 (该组件既可以是普通组件，也可以 是容器) ， 并返回被添加的组件 。 |
| Component getComponentAt(int x, int y)  | 返回指定点的组件 。                                          |
| int getComponentCount()                 | 返回该容器内组件的数量 。                                    |
| Component[] getComponents()             | 返回该容器内的所有组件 。                                    |

#### Window
| 方法名        |  方法功能           |
|---------------|-----------------------------------------------------|
| void pack()   | 调整窗口的大小，使其适应组件的大小和布局。              |

## 2.4 LayoutManager布局管理器

之前，我们介绍了Component中有一个方法 setBounds() 可以设置当前容器的位置和大小，但是我们需要明确一件事，如果我们手动的为组件设置位置和大小的话，就会造成程序的不通用性，例如：

```java
Label label = new Label("你好，世界");
```

创建了一个lable组件，很多情况下，我们需要让lable组件的宽高和“你好，世界”这个字符串自身的宽高一致，这种大小称为**最佳大小**。由于操作系统存在差异，例如在windows上，我们要达到这样的效果，需要把该Lable组件的宽和高分别设置为100px,20px,但是在Linux操作系统上，可能需要把Lable组件的宽和高分别设置为120px，24px，才能达到同样的效果。

如果要让我么的程序在不同的操作系统下，都有相同的使用体验，那么手动设置组件的位置和大小，无疑是一种灾难，因为有太多的组件，需要分别设置不同操作系统下的大小和位置。为了解决这个问题，Java提供了LayoutManager布局管理器，可以根据运行平台来自动调整组件大小，程序员不用再手动设置组件的大小和位置了，只需要为**容器**`Container`选择合适的布局管理器即可。

![](../../images/常用布局管理器.png)

### 2.4.1 FlowLayout

​        在 FlowLayout 布局管理器 中，组件像水流一样向某方向流动 (排列) ，遇到障碍(边界)就折回，重头开始排列 。在默认情况下， FlowLayout 布局管理器从左向右排列所有组件，遇到边界就会折回下一行重新开始。

| 构造方法                                | 方法功能                                                     |
| --------------------------------------- | ------------------------------------------------------------ |
| FlowLayout()                            | 使用默认 的对齐方式及默认的垂直间距、水平间距创建 FlowLayout 布局管理器。 |
| FlowLayout(int align)                   | 使用指定的对齐方式及默认的垂直间距、水平间距创建 FlowLayout 布局管理器。 |
| FlowLayout(int align,int hgap,int vgap) | 使用指定的对齐方式及指定的垂直问距、水平间距创建FlowLayout 布局管理器。 |

FlowLayout 中组件的排列方向(从左向右、从右向左、从中间向两边等) ， 该参数应该使用FlowLayout类的静态常量 : FlowLayout. LEFT 、 FlowLayout. CENTER 、 FlowLayout. RIGHT ，默认是左对齐。

FlowLayout 中组件中间距通过整数设置，单位是像素，默认是5个像素。

**代码演示：**

​	![](../../images/FlowLayout.jpg)

```java
import java.awt.*;

public class FlowLayoutDemo {

    public static void main(String[] args) {
        //1.创建Frame对象
        Frame frame = new Frame("这里测试FlowLayout");
        //2.修改Frame容器的布局管理器为FlowLayout
        frame.setLayout(new FlowLayout(FlowLayout.LEFT,20,20));

        //3.往Frame中添加100个button
        for (int i = 0; i < 100; i++) {
            frame.add(new Button("按钮"+i));
        }

        //4.设置Frame为最佳大小
        frame.pack();
        //5.设置Frame可见
        frame.setVisible(true);
    }
}
```

### 2.4.2 BorderLayout

BorderLayout 将容器分为 EAST 、 SOUTH 、 WEST 、 NORTH 、 CENTER五个区域，普通组件可以被放置在这 5 个区域的任意一个中 。 BorderLayout布局管理器的布局示意图如图所示 。

![](../../images/BorderLayout.png)

当改变使用 BorderLayout 的容器大小时， NORTH 、 SOUTH 和 CENTER区域水平调整，而 EAST 、 WEST 和 CENTER 区域垂直调整。使用BorderLayout 有如下两个注意点:

1. 当向使用 BorderLayout 布局管理器的容器中添加组件时 ， 需要指定要添加到哪个区域中 。 如果没有指定添加到哪个区域中，则默认添加到中间区域中；
2. 如果向同一个区域中添加多个组件时 ， 后放入的组件会覆盖先放入的组件；

| 构造方法                         | 方法功能                                                     |
| -------------------------------- | ------------------------------------------------------------ |
| BorderLayout()                   | 使用默认的水平间距、垂直 间距创建 BorderLayout 布局管理器 。 |
| BorderLayout(int hgap,int vgap): | 使用指定的水平间距、垂直间距创建 BorderLayout 布局管理器。   |

**代码演示1:**

​	![](../../images/BorderLayout.jpg)

```java
import java.awt.*;

public class BorderLayoutDemo1 {

    public static void main(String[] args) {
        //1.创建Frame对象
        Frame frame = new Frame("这里测试BorderLayout");
        //2.指定Frame对象的布局管理器为BorderLayout
        frame.setLayout(new BorderLayout(30,5));
        //3.往Frame指定东南西北中各添加一个按钮组件
        frame.add(new Button("东侧按钮"), BorderLayout.EAST);
        frame.add(new Button("西侧按钮"), BorderLayout.WEST);
        frame.add(new Button("南侧按钮"), BorderLayout.SOUTH);
        frame.add(new Button("北侧按钮"), BorderLayout.NORTH);
        frame.add(new Button("中间按钮"), BorderLayout.CENTER);
        //4.设置Frame为最佳大小
        frame.pack();
        //5.设置Frame可见
        frame.setVisible(true);
    }
}
```



如果不往某个区域中放入组件，那么该区域不会空白出来，而是会被其他区域占用

**代码演示2:**

​	![](../../images/BorderLayoutDemo2.jpg)

```java
import java.awt.*;

public class BorderLayoutDemo2 {

    public static void main(String[] args) {
        //1.创建Frame对象
        Frame frame = new Frame("这里测试BorderLayout");
        //2.指定Frame对象的布局管理器为BorderLayout
        frame.setLayout(new BorderLayout(30,5));
        //3.往Frame指定南，北，放入一个按钮，往中间区域放入一个Panel

        frame.add(new Button("南侧按钮"), BorderLayout.SOUTH);
        frame.add(new Button("北侧按钮"), BorderLayout.NORTH);

        Panel panel = new Panel();
        panel.add(new TextField("测试文本"));
        panel.add(new Button("中间按钮"));

        frame.add(panel, BorderLayout.CENTER);
	
        //4.设置Frame为最佳大小
        frame.pack();
        //5.设置Frame可见
        frame.setVisible(true);
    }
}
```

## 2.5 AWT中常用组件

### 2.5.1 基本组件

| 组件名        | 功能                                                         |
| ------------- | ------------------------------------------------------------ |
| Button        | 按钮                                                       |
| Canvas        | 用于绘图的画布                                               |
| Checkbox      | 复选框组件（也可当做单选框组件使用）                         |
| CheckboxGroup | 用于将多个Checkbox 组件组合成一组， 一组 Checkbox 组件将只有一个可以 被选中 ， 即全部变成单选框组件 |
| Choice        | 下拉选择框                                                   |
| Frame         | 窗口 ， 在 GUI 程序里通过该类创建窗口                        |
| Label         | 标签类，用于放置提示性文本                                   |
| List          | JU表框组件，可以添加多项条目                                 |
| Panel         | 不能单独存在基本容器类，必须放到其他容器中                   |
| Scrollbar     | 滑动条组件。如果需要用户输入位于某个范围的值 ， 就可以使用滑动条组件 ，比如调 色板中设置 RGB 的三个值所用的滑动条。当创建一个滑动条时，必须指定它的方向、初始值、 滑块的大小、最小值和最大值。 |
| ScrollPane    | 带水平及垂直滚动条的容器组件                                 |
| TextArea      | 多行文本域                                                   |
| TextField     | 单行文本框                                                   |

#### Button
| 方法名                           | 方法功能                                                                  |
|---------------------------------|----------------------------------------------------------------------------|
| Button()                        | 创建一个按钮组件                                                           |
| Button(String label)            | 创建一个label名称的按钮组件                                                 |
| void setLabel(String label)     | 重新设置按钮的名字                                                         |

## 3.2 Swing基本组件的用法

### 3.2.1 Swing组件层次

**Swing组件继承体系图：**

![](../../images/Swing组件继承体系.png)

​	大部分Swing 组件都是 JComponent抽象类的直接或间接子类(并不是全部的 Swing 组件)，JComponent 类定义了所有子类组件的通用方法 ，JComponent 类是 AWT 里 java.awt. Container 类的子类 ，这也是 AWT 和 Swing 的联系之一。 绝大部分 Swing 组件类继承了 Container类，所以Swing 组件都可作为 容器使用 ( JFrame继承了Frame 类)。
