#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread_behavior.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    thread_behavior tBehavior;
    QTimer timer_principal;

private:
    Ui::MainWindow *ui;

public slots:
    void AtualizaInterface();
};

#endif // MAINWINDOW_H
