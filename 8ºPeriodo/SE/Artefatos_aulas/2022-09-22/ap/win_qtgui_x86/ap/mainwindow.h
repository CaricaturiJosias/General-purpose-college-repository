#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "threadbehavior.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer update_ui_timer;
    QTimer physical_process_timer;

    double tanque1;
    double tanque2;
    double tanque3;
    double temperatura;
    ThreadBehavior tbehavior;

private:
    Ui::MainWindow *ui;
public slots:
    void Update_GUI();
    void Physical_process();
};

#endif // MAINWINDOW_H
