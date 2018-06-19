#include "mainwindow.h"
#include <QSplitter>

#include "customlistiew.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QSplitter* pSplitter = new QSplitter(Qt::Horizontal,this);

    m_pLeftList = new QListView(pSplitter);
    m_pRightList = new QListView(pSplitter);

    InitLeftList();
    InitRightList();

    pSplitter->setStretchFactor(0,1);
    pSplitter->setStretchFactor(1,3);

    setCentralWidget(pSplitter);
}

MainWindow::~MainWindow()
{
}

void MainWindow::InitLeftList()
{
    //设置焦点获取方式
    m_pLeftList->setFocusPolicy(Qt::ClickFocus);

    QStandardItemModel* pModel = new QStandardItemModel(m_pLeftList);

    //========================LeftItem1====================
    QStandardItem* pItem = new QStandardItem("LeftItem1");
    pModel->appendRow(pItem);
    //构建Item对应的右边的model
    QStandardItemModel* rmodel = new QStandardItemModel(m_pRightList);
    QStandardItem* item = new QStandardItem("IT");
    rmodel->appendRow(item);
    m_itemToModelHash[pItem] = rmodel;

    //========================LeftItem2====================
    pItem = new QStandardItem("LeftItem2");
    pModel->appendRow(pItem);

    //构建Item对应的右边的model
    rmodel = new QStandardItemModel(m_pRightList);
    item = new QStandardItem("Chinese");
    rmodel->appendRow(item);

    item = new QStandardItem("English");
    rmodel->appendRow(item);
    m_itemToModelHash[pItem] = rmodel;

    //========================LeftItem3====================
    pItem = new QStandardItem("LeftItem3");
    pModel->appendRow(pItem);

    //构建Item对应的右边的model
    rmodel = new QStandardItemModel(m_pRightList);
    item = new QStandardItem("TestActor333");
    rmodel->appendRow(item);

    item = new QStandardItem("TestActor4444");
    rmodel->appendRow(item);
    m_itemToModelHash[pItem] = rmodel;

     //====================================================

    m_pLeftList->setModel(pModel);
    connect(m_pLeftList, &QListView::clicked, this, &MainWindow::onLeftListClick);
}

void MainWindow::InitRightList()
{
    //设置焦点获取方式
    m_pRightList->setFocusPolicy(Qt::ClickFocus);
    m_pRightList->setModel(NULL);
}


void MainWindow::onLeftListClick(QModelIndex index)
{
    QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(m_pLeftList->model());
    if (!model)return;

    QStandardItem* item = model->itemFromIndex(index);
    if (!item)return;

    QHash<QStandardItem*, QStandardItemModel*>::Iterator iter = m_itemToModelHash.find(item);
    auto a = item->text();
    if (iter != m_itemToModelHash.cend())
        m_pRightList->setModel(*iter);
}
