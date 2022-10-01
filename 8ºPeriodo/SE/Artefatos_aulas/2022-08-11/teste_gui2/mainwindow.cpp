#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_principal->setText("Teste");
    connect(ui->MudaNome,
            SIGNAL(clicked(bool)),
            this,
            SLOT(MudaNome()));
    connect(ui->checkBox,
            SIGNAL(toggled(bool)),
            this,
            SLOT(MudaBox()));
    connect(ui->dial_principal,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(AtualizaProgresso()));
    connect(&timer_principal,
            SIGNAL(timeout()),
            this,
            SLOT(UmSegundo()));
    timer_principal.start(1000);
    AtualizaProgresso();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MudaNome(){
    ui->label_principal->setText("Teste");
    ui->checkBox->setChecked(!ui->checkBox->isChecked());
}

void MainWindow::MudaBox(){
    ui->label_principal->setText("Selecionado");
}

void MainWindow::AtualizaProgresso(){
    ui->progressBar_principal->setValue(ui->dial_principal->value());
}

void MainWindow::UmSegundo(){
    ui->dial_principal->setValue(ui->dial_principal->value()+10);
    if (ui->dial_principal->value() == 100)
       ui->dial_principal->setValue(0);
}
