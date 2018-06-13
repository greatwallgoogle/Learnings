# 学习笔记

记录学习```Qt```的脚步。

### 一、控件

#### 1. QSplitter分割器

```QSplitter```是一个分割器，用于将界面分为N个部分，默认是横向分割，也可以设置为纵向分割，简单易上手。另外分割器还可以嵌套子分割器。

- 可以通过构造函数或者```void setOrientation(Qt::Orientation);```方法设置分割朝向，默认是横向分割。
- 可以通过```void setStretchFactor(int index, int stretch);```函数设置被分割部分的占比，默认第一个控件的索引为```0```。例如假设有一个 ```QSplitter```对象，其包含两个控件，```splitterRight->setStretchFactor(0,1);```表示第一个控件占```1/3``` ，  ```splitterRight->setStretchFactor(1,2);```表示第二个控件占```2/3```。
- 可以通过```void setHandleWidth(int)```方法设置分割线的宽度。
- 可以嵌套子```QSplitter```。
- 可以使用```QSS```来设置```QSplitter```的样式，例如```Demo```中的分割线颜色的设置。
- 当用hide()方法隐藏一个子类控件时，它的空间会被其它的部件占用。当重新调用show()方法展示这个部件的时候，又会恢复之前的布局。
- 注意：不可以在QSplitter中添加一个QLayout，同样，也不可以将QSplitter添加到QLayout中去。

![](./Pics/QSplitter.png)
