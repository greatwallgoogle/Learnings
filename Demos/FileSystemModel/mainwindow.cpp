#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QFileSystemModel>
#include <QRect>
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_pXETreeView = new XETreeView(this);
    setCentralWidget(m_pXETreeView);
}

MainWindow::~MainWindow()
{
}


//----------------------------------------------------
XETreeView::XETreeView(QWidget* parent)
    :QTreeView(parent)
{
    QFileSystemModel* model = new QFileSystemModel(this);
    this->setModel(model);


    model->setReadOnly(true);//坑！！！！必须将setReadOnly设为true，否则只能站到到assetPath路径，不能展开其子路径

    this->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

    QString assetPath = QString("D:\\AR\\ARProjects\\Demo0619\\Asset");//
    QModelIndex index = model->setRootPath(assetPath);
    this->setRootIndex(index);

    //test path
    QString pathTest = QString("D:\\AR\\ARProjects\\Demo0619\\Asset\\wujiang\\textures\\FNPC_BianJunJunGuan001_A.pvr");
    qDebug() << "---****  pathTest:"<<pathTest;

    QModelIndex curIndex = model->index(pathTest);
    this->SelectItem(curIndex);
}

void XETreeView::SelectItem(const QModelIndex& curIndex)
{
    if(curIndex.isValid())
    {
        /*
         //展开所有父节点，即便不适用这段代码，使用下面的setCurrentIndex也能展开其父节点
        QModelIndex parent = curIndex.parent();
        while(parent.isValid())
        {
            this->expand(parent);
            parent = parent.parent();
        }
        */

        QRect rect(this->visualRect(curIndex));
        this->setSelection(rect,QItemSelectionModel::ClearAndSelect|QItemSelectionModel::Rows);
        //选中当前项
        this->setCurrentIndex(curIndex);
        //定位到当前项，如果选中的某个节点超出了窗口大小，会将当前节点显示到中间
        this->scrollTo(curIndex);
    }
}
