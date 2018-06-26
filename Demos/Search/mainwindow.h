#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QListView>

class FindWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FindWidget(QWidget *parent = 0);
    ~FindWidget(){}

signals:
    void Signal_SearchChanged(const QString& text);
public slots:
    void Slot_Search(const QString& text);

private:
    QAction* m_pSearchAction;
    QLineEdit* m_pFindLineEdit1;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void Slot_SearchText(const QString& text);

private:
    QStandardItemModel*         m_pStandModel;
    QListView*                  m_pListView;
};

#endif // MAINWINDOW_H
