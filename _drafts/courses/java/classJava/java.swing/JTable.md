#### JTable常用构造方法:

```
// 创建空表格，后续再添加相应数据
JTable() 

// 创建指定行列数的空表格，表头名称默认使用大写字母（A, B, C ...）依次表示
JTable(int numRows, int numColumns) 

// 创建表格，指定 表格行数据 和 表头名称
JTable(Object[][] rowData, Object[] columnNames)
```

#### JTable字体和网格颜色设置:


```
// 设置内容字体
void setFont(Font font)

// 设置字体颜色
void setForeground(Color fg)

// 设置被选中的行前景（被选中时字体的颜色）
void setSelectionForeground(Color selectionForeground)

// 设置被选中的行背景
void setSelectionBackground(Color selectionBackground)

// 设置网格线颜色
void setGridColor(Color gridColor)

// 设置是否显示网格
void setShowGrid(boolean showGrid)

// 水平方向网格线是否显示
void setShowHorizontalLines(boolean showHorizontalLines)

// 竖直方向网格线是否显示
void setShowVerticalLines(boolean showVerticalLines)

```

#### JTable表头设置:


```
// 获取表头
JTableHeader jTableHeader = jTable.getTableHeader();

// 设置表头名称字体样式
jTableHeader.setFont(Font font);

// 设置表头名称字体颜色
jTableHeader.setForeground(Color fg);

// 设置用户是否可以通过在头间拖动来调整各列的大小。
jTableHeader.setResizingAllowed(boolean resizingAllowed);

// 设置用户是否可以拖动列头，以重新排序各列。
jTableHeader.setReorderingAllowed(boolean reorderingAllowed);
```
#### JTable行列相关设置:


```
// 设置所有行的行高
void setRowHeight(int rowHeight)

// 设置指定行的行高
void setRowHeight(int row, int rowHeight)

/**
 * 设置当手动改变某列列宽时，其他列的列宽自动调整模式，可选值:
 *     JTable.AUTO_RESIZE_ALL_COLUMNS 在所有的调整大小操作中，按比例调整所有的列。
 *     JTable.AUTO_RESIZE_LAST_COLUMN 在所有的调整大小操作中，只对最后一列进行调整。
 *     JTable.AUTO_RESIZE_NEXT_COLUMN 在 UI 中调整了一个列时，对其下一列进行相反方向的调整。
 *     JTable.AUTO_RESIZE_OFF 不自动调整列的宽度；使用滚动条。
 *     JTable.AUTO_RESIZE_SUBSEQUENT_COLUMNS 在 UI 调整中，更改后续列以保持总宽度不变；此为默认行为。
 */
void setAutoResizeMode(int mode)

/*
 * 调整列宽
 */
// 先获取到某列
TableColumn tableColumn = jTable.getColumnModel().getColumn(int columnIndex);

// 设置列的宽度、首选宽度、最小宽度、最大宽度
tableColumn.setWidth(int width);
tableColumn.setPreferredWidth(int preferredWidth);
tableColumn.setMinWidth(int minWidth);
tableColumn.setMaxWidth(int maxWidth);

// 调整该列的列宽，以适合其标题单元格的宽度。
tableColumn.sizeWidthToFit();

// 是否允许手动改变该列的列宽
tableColumn.setResizable(boolean isResizable);

// 设置该列的表头名称
tableColumn.setHeaderValue(Object headerValue);

```

#### JTable数据相关操作:


```
/*
 * 表格数据的简单设置和获取
 */
// 设置表格中指定单元格的数据
jTable.getModel().setValueAt(Object aValue, int rowIndex, int columnIndex);

// 获取表格中指定单元格的数据
Object value = jTable.getModel().getValueAt(int rowIndex, int columnIndex);
```
#### 创建带滚动条的表格

```
创建带滚动条的表格基本步骤:

// 创建表格
JTable table = new JTable(...);

/* 设置表格相关数据 */

// 设置滚动面板视口大小（超过该大小的行数据，需要拖动滚动条才能看到）
table.setPreferredScrollableViewportSize(new Dimension(int width, int height));

// 创建滚动面板，把 表格 放到 滚动面板 中（表头将自动添加到滚动面板顶部）
JScrollPane scrollPane = new JScrollPane(table);

/* 再把滚动面板 scrollPane 添加到其他容器中显示 */
```
