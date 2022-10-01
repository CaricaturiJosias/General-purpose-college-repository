#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_principal->setText("Teste");
    connect(ui->pushButton_MudaNome,
            SIGNAL(clicked(bool)),
            this,
            SLOT(MudaNome()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MudaNome(){
    ui->label_principal->setText("Teste");
}
