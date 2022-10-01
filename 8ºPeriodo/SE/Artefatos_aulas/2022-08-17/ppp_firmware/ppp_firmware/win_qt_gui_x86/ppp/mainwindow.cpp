#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar_principal->setValue(0);
    tBehavior.start();
    connect(&timer_principal,
            SIGNAL(timeout()),
            this,
            SLOT(AtualizaInterface()));
    timer_principal.start(33);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "../../common/datatypes.h"
extern boolean pin_LED1;
void MainWindow::AtualizaInterface(){
    // ui->checkBox_LED1->setChecked(pin_LED1);
    ui->progressBar_principal->setValue(100*pin_LED1);
}
