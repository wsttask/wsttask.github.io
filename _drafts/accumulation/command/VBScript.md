### 输入输出





### 变量

- 必须以字母开头

- 不能包含点号（.）

- 不能超过 255 个字符

在 VBScript 中，所有的变量都与类型 *variant* 相关，可存储不同类型的数据。

```vbscript
Dim x
Dim carname
' 两种方式都可以创建变量
carname="Volvo"
```

现在您又创建了一个变量。变量的名称是 "carname"。然后，这个做法不是一个好习惯，因为您可能会在脚本中**拼错变量名**，那样可能会在脚本运行时引起奇怪的结果。

如果您拼错变量名，比如 "carname" 变量错拼为 "carnime"，脚本会自动创建一个名为 "carnime" 的新变量。为了防止脚本这样做，您可以使用 Option Explicit 语句。如果您使用这个语句，就必须使用 dim、public 或 private 语句来声明所有的变量。

```vbscript
Option Explicit
Dim carname
carname=some value
```

##### 为变量赋值

```vbscript
carname="Volvo"
x=10
```

变量名是在表达式的左侧，需要赋给变量的值在表达式的右侧。现在变量 "carname" 的值是 "Volvo"，变量 "x" 的值是 "10"。

##### 变量的生存期

变量的生存期指的是它可以存在的时长。

当您在一个子程序中声明变量时，变量只能在此程序内进行访问。当退出此程序时，变量也会失效。这样的变量称为本地变量。您可以在不同的子程序中使用名称相同的本地变量，因为每个变量只能在声明它的程序内得到识别。

如果您在子程序以外声明了一个变量，在您的页面上的所有子程序都可以访问它。这类变量的生存期始于它们被声明，止于页面被关闭。

#### VBScript 数组变量

##### 定义

```vbscript
Dim names(2)
' 注意，这里定义的数组是包含三个元素
names(0)="Tove"
names(1)="Jani"
names(2)="Stale"
```

##### 多维数组

```vbscript
Dim table(4,6)
```

### 条件语句

在 VBScript 中，我们可以使用四种条件语句：

- **If 语句** - 假如您希望在条件为 true 时执行一系列的代码，可以使用这个语句
- **If...Then...Else 语句** - 假如您希望执行两套代码其中之一，可以使用这个语句
- **If...Then...ElseIf 语句** - 假如您希望选择多套代码之一来执行，可以使用这个语句
- **Select Case 语句** - 假如您希望选择多套代码之一来执行，可以使用这个语句

##### If...Then...Else

在下面的情况中，您可以使用 If...Then...Else 语句：

- 在条件为 true 时，执行某段代码
- 选择两段代码之一来执行

在条件为 true 时只执行**一条**语句，可以把代码写为一行：

```vbscript
If i=10 Then alert("Hello")
```

在上面的代码中，没有 ..Else.. 语句。我们仅仅让代码在条件为 true 时（当 i=10 时）执行**一项操作**。

如果在条件为 true 时执行**不止一条**语句，那么就必须在一行写一条语句，然后使用关键词 "End If" 来结束这个语句：

```vbscript
If i=10 Then
alert("Hello")
i = i+1
End If
```

在上面的代码中，同样没有 ..Else.. 语句。我们仅仅让代码在条件为 true 时执行了**多项操作**。

假如您想要在条件为 true 时执行某条语句，并在条件不为 true 时执行另一条语句，就必须添加关键词 "Else"：

```vbscript
i=hour(time)
If i < 10 Then
document.write("Good morning!")
Else
document.write("Have a nice day!")
End If
```

##### If...Then...ElseIf

```vbscript
i=hour(time)
If i = 10 Then
document.write("Just started...!")
ElseIf i = 11 Then
document.write("Hungry!")
ElseIf i = 12 Then
document.write("Ah, lunch-time!")
ElseIf i = 16 Then
document.write("Time to go home!")
Else
document.write("Unknown")
End If
```

##### Select Case

```vbscript
d=weekday(date)
Select Case d
Case 1
document.write("Sleepy Sunday")
Case 2
document.write("Monday again!")
Case 3
document.write("Just Tuesday!")
Case 4
document.write("Wednesday!")
Case 5
document.write("Thursday...")
Case 6
document.write("Finally Friday!")
Case else
document.write("Super Saturday!!!!")
End Select
```

### 循环

循环语句用于运行相同的代码块指定的次数。Looping statements are used to run the same block of code a specified number of times.

在 VBScript 中，我们可以使用四种循环语句：

- **For...Next 语句** - 运行一段代码指定的次数
- **For Each...Next 语句** - 针对集合中的每个项目或者数组中的每个元素来运行某段代码
- **Do...Loop 语句** - 运行循环，当条件为 true 或者直到条件为 true 时
- **While...Wend 语句** - 不要使用这个语句 - 请使用 Do...Loop 语句代替它



##### For...Next

请使用 **For...Next** 语句运行一段代码指定的次数。

**For** 语句规定计数变量（**i**）以及它的初始值和结束值。**Next** 语句会以 1 作为步进值来递增变量（**i**）。

```vbscript
For i = 0 To 5
document.write("The number is " & i & "<br />")
Next
```

##### Step 关键词

通过 **Step** 关键词，您可以规定计数变量递增或递减的步进值。

在下面的实例中，计数变量（**i**）每次循环的递增步进值为 2。

```vbscript
For i=2 To 10 Step 2
some code
Next
```

如果要递减计数变量，您就必须使用负的 **Step** 值。并且必须规定小于开始值的结束值。

在下面的实例中，计数变量（**i**）每次循环的递减步进值为 2。

```vbscript
For i=10 To 2 Step -2
some code
Next
```



##### 退出 For...Next

您可以通过 Exit For 关键词退出 For...Next 语句。

```vbscript
For i=1 To 10
If i=5 Then Exit For
some code
Next
```

##### For Each...Next

```vbscript
Dim cars(2)
cars(0)="Volvo"
cars(1)="Saab"
cars(2)="BMW"

For Each x In cars
document.write(x & "<br />")
Next
```



#### Do...Loop

如果你不知道重复多少次，可以使用 Do...Loop 语句。

Do...Loop 语句重复执行某段代码直到条件是 true 或条件变成 true。



##### 重复执行代码直到条件是 true

您可以使用 While 关键字来检查 Do... Loop 语句的条件。

```vbscript
Do While i>10
some code
Loop
```

如果 **i** 等于 9，上述循环内的代码将终止执行。

```vbscript
Do
some code
Loop While i>10
```

这个循环内的代码将被执行至少一次，即使 **i** 小于 10。



##### 重复执行代码直到条件变成 true

您可以使用 Until 关键字来检查 Do...Loop 语句的条件。

```vbscript
Do Until i=10
some code
Loop
```

如果 **i** 等于 10，上述循环内的代码将终止执行。

```vbscript
Do
some code
Loop Until i=10
```

这个循环内的代码将被执行至少一次，即使 **i** 等于 10。



##### 退出 Do...Loop

您可以通过 Exit Do 关键词退出 Do...Loop 语句。

```vbscript
Do Until i=10
i=i-1
If i<10 Then Exit Do
Loop
```

这个循环内的代码，只要 **i** 不为 10 且 **i** 大于 10 时都将被执行。
