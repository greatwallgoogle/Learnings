#ifndef CUSTOMLISTIEW_H
#define CUSTOMLISTIEW_H
#include <QListView>

class XELogListView :public QListView
{
    Q_OBJECT
public:
    explicit XELogListView(QWidget *parent = NULL);
    virtual ~XELogListView(){}

    virtual void			mousePressEvent(QMouseEvent *event);
    void					clearSelectedItem();

protected:
    void					focusInEvent(QFocusEvent *event);//get focus
    void					focusOutEvent(QFocusEvent *event);//lost focus

signals:
    void					clearSelectedSignal(QModelIndex& index);

};

#endif // CUSTOMLISTIEW_H
