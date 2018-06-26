#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QHBoxLayout>
#include <QStandardItem>
#include <QVBoxLayout>


/* 1.可以使用QLineEdit实现搜索控件。
 * 2.QLineEdit是一个单行文本输入框，提供了撤销和重做，复制和粘贴，以及拖拽等编辑功能。
 * 3.QLineEdit::ActionPosition：可以设置加入编辑框中action部件的位置，比如添加的action部件在文本之前还是之后。
 * 4.QLineEdit::EchoMode：描述输入框如何显示其内容，比如是正常输入（默认值），还是向输入密码时需要隐藏输入信息等等。
 * 5.可以设置文本的最大长度。
 */


/* QLineEdit::EchoMode:
 * QLineEdit::Normal	            0	正常显示输入的字符，默认选项。
 * QLineEdit::NoEcho	            1	不显示任何输入，常用于密码类型，其密码长度都需要保密的时候。
 * QLineEdit::Password	            2	显示平台相关的密码掩码字符，而不是实际的字符输入。
 * QLineEdit::PasswordEchoOnEdit	3	在编辑的时候显示字符，负责显示密码类型
 */

/* QLineEdit::ActionPosition:
 * QLineEdit::LeadingPosition	   0	当使用布局方向Qt::LeftToRight时，部件显示在文本左侧；使用Qt::RightToLeft时，则显示在右侧。
 * QLineEdit::TrailingPosition	   1	当使用布局方向Qt::LeftToRight时，部件显示在文本右侧；使用Qt::RightToLeft时，则显示在左侧。
 */

FindWidget::FindWidget(QWidget *parent)
    :QWidget(parent)
{
    QHBoxLayout* pLayout = new QHBoxLayout(this);
    m_pFindLineEdit1 = new QLineEdit(this);
    m_pFindLineEdit1->setObjectName("FindLineEdit");
    m_pFindLineEdit1->setPlaceholderText(tr("Search"));
    connect(m_pFindLineEdit1, &QLineEdit::textChanged, this,
        &FindWidget::Slot_Search);

    //可以添加Icon
//    m_pSearchAction = new QAction(this);
//    m_pSearchAction->setText(tr("Find"));
//	  m_pSearchAction->setIcon(QIcon("Resources/icon/search_bone"));
//    m_pFindLineEdit1->addAction(m_pSearchAction, QLineEdit::TrailingPosition);
//    connect(m_pSearchAction, &QAction::triggered, this, &SocketOrBoneChooser::Slot_SearchCloseAction);

    pLayout->addWidget(m_pFindLineEdit1);
}

void FindWidget::Slot_Search(const QString& text)
{
    if(!text.isEmpty())
        emit Signal_SearchChanged(text);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setObjectName("MainWidget");

    QVBoxLayout* vLayout = new QVBoxLayout(mainWidget);

    FindWidget* pFindWidget = new FindWidget(mainWidget);
    connect(pFindWidget,&FindWidget::Signal_SearchChanged,this, &MainWindow::Slot_SearchText);

    m_pListView = new QListView(mainWidget);
    m_pStandModel = new QStandardItemModel(m_pListView);

    QStandardItem* pItem = new QStandardItem("QStandardItem1");
    m_pStandModel->appendRow(pItem);
    pItem = new QStandardItem("QStandardItem2");
    m_pStandModel->appendRow(pItem);
    pItem = new QStandardItem("QStandardItem3");
    m_pStandModel->appendRow(pItem);
    pItem = new QStandardItem("English");
    m_pStandModel->appendRow(pItem);
    pItem = new QStandardItem("Chinese");
    m_pStandModel->appendRow(pItem);

    vLayout->addWidget(pFindWidget);
    vLayout->addWidget(m_pListView);

    m_pListView->setModel(m_pStandModel);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::Slot_SearchText(const QString& text)
{
    if(text.isEmpty())
        return;

    QStandardItemModel* pModel = new QStandardItemModel(this);

    int rowCount = m_pStandModel->rowCount();
    for(int i = 0 ; i < rowCount;i++)
    {
        QModelIndex index = m_pStandModel->index(i,0);
        if(index.isValid())
        {
            QStandardItem* pItem = m_pStandModel->itemFromIndex(index);
            if(pItem->text().contains(text,Qt::CaseInsensitive))
            {
                QStandardItem* pCItem = new QStandardItem(pItem->text());
                pModel->appendRow(pCItem);
            }
        }
    }

    m_pListView->setModel(pModel);
}
