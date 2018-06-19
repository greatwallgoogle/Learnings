#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customlistiew.h"
#include <QHash>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndex>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void InitLeftList();
    void InitRightList();
    void onLeftListClick(QModelIndex index);
private:
    QListView*      m_pLeftList;
    QListView*      m_pRightList;

    QHash<QStandardItem*, QStandardItemModel*>	m_itemToModelHash;

};

#endif // MAINWINDOW_H
