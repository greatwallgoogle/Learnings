#include "customlistiew.h"
#include <QWidget>
#include <QMouseEvent>
#include <QStandardItem>
#include <qDebug>
XELogListView::XELogListView(QWidget *parent /*= NULL*/) :QListView(parent)
{

}

void XELogListView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //点在Item上
        QModelIndex index = this->indexAt(event->pos());
        if (!index.isValid())
        {
            clearSelectedItem();
            emit clearSelectedSignal(index);
        }
    }

    return QListView::mousePressEvent(event);
}

void XELogListView::clearSelectedItem()
{
    this->clearSelection();
    this->setCurrentIndex(QModelIndex());
}


//get focus ，需要为当前view设置焦点模式  setFocusPolicy()
void XELogListView::focusInEvent(QFocusEvent *event)
{
    this->setProperty("Focus", true);
    this->style()->unpolish(this);
    this->style()->polish(this);
    this->update();
}

//lost focus
void XELogListView::focusOutEvent(QFocusEvent *event)
{
    this->setProperty("Focus", false);
    this->style()->unpolish(this);
    this->style()->polish(this);
    this->update();
}
