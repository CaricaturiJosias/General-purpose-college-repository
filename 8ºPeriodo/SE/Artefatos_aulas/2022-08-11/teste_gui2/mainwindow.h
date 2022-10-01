#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    QTimer timer_principal;

private:
    Ui::MainWindow *ui;

public slots:
    void MudaNome();
    void MudaBox();
    void AtualizaProgresso();
    void UmSegundo();
};

#endif // MAINWINDOW_H
