#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QListWidget>
#include <QLabel>
#include <QTextEdit>
/*
 * 1. QSplitter默认是横向分割
 * 2. 默认大小均分
 * 3. 可以通过setStretchFactor函数设置分割比例，例如：
 * pSplitter->setStretchFactor(0, 1);
 * pSplitter->setStretchFactor(1, 3);表示第一个占1/4，第二个占3/4
 * 4. 设置分割元素时，索引从0开始
 * 5. 可以通过setHandleWidth设置分割线的宽度
 * 6. 可以嵌套子QSplitter
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{


    QSplitter* splitterMain = new QSplitter(Qt::Horizontal,this);
    //splitterMain->setOrientation(Qt::Vertical);设置分割方向

    QTextEdit* pLeftLabel = new QTextEdit(splitterMain);
    pLeftLabel->setText("left label");
    pLeftLabel->setAlignment(Qt::AlignHCenter);


    QTextEdit* pMiddleLabel = new QTextEdit(splitterMain);
    pMiddleLabel->setText("middle label");
    pMiddleLabel->setAlignment(Qt::AlignHCenter);

    QSplitter *splitterRight=new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);

    QTextEdit* pTopLabel = new QTextEdit(splitterRight);
    pTopLabel->setText("top label");
    pTopLabel->setAlignment(Qt::AlignCenter);


    QTextEdit* pBottomLabel = new QTextEdit(splitterRight);
    pBottomLabel->setText("bottom label");
    pBottomLabel->setAlignment(Qt::AlignCenter);

    splitterRight->setStretchFactor(0,1);//第一个控件占1/3
    splitterRight->setStretchFactor(1,2);//第二个控件占2/3
    splitterRight->setStyleSheet("QSplitter::handle { background-color: gray }");//通过样式修改分割线的颜色


    //设置分割线的宽度
    splitterMain->setHandleWidth(3);


    splitterMain->setStretchFactor(0,1);//占1/4
    splitterMain->setStretchFactor(1,2);//占2/4
    splitterMain->setStretchFactor(3,1);//占1/4

    //作为中心部件
    this->setCentralWidget(splitterMain);
}

MainWindow::~MainWindow()
{
}