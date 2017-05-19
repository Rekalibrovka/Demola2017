#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void ssh_connect();
    void ssh_connect_test();
    void test_1();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
