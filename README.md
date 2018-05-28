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
- 可以使用```void setOpaqueResize(bool opaque = true);```方法来设置是否在拖动分割线时实时改变大小。如果值为```false```，此时拖动分割线时，会额外显示一条线，当松开鼠标时，分割线才真正到所开鼠标的位置。

![QSplitter](Pics\QSplitter.png)
