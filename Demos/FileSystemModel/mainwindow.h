#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>

class XETreeView;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    XETreeView* m_pXETreeView;
};

class XETreeView : public QTreeView
{
public:
    explicit XETreeView(QWidget* parent = nullptr);
    void SelectItem(const QModelIndex& index);

};

#endif // MAINWINDOW_H
