#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&update_ui_timer,
            SIGNAL(timeout()),
            this,
            SLOT(Update_GUI()));
    connect(&physical_process_timer,
            SIGNAL(timeout()),
            this,
            SLOT(Physical_process()));
    update_ui_timer.start(30);
    physical_process_timer.start(10);

    tanque1=0;
    tanque2=0;
    tbehavior.start();
}

MainWindow::~MainWindow(){
    delete ui;
}

extern "C"{
    #include "../../common/datatypes.h"
    #include "../../common/hal.h"
}
extern boolean pin_v1, pin_bp, pin_s11, pin_s12, pin_s21, pin_s22;
void MainWindow::Update_GUI(){
    ui->led_v1->setPower(pin_v1);
    ui->led_s11->setPower(pin_s11);
    ui->led_s12->setPower(pin_s12);
    ui->led_s21->setPower(pin_s21);
    ui->led_s22->setPower(pin_s22);

    ui->tank_1->setValue(tanque1);
    ui->tank_2->setValue(tanque2);
}

void MainWindow::Physical_process(){
    if(pin_v1){
        tanque1 += .2;
        if(tanque1 > 100) tanque1 = 100;
    }

    pin_s11 = (tanque1 >= 10);
    pin_s12 = (tanque1 >= 90);

    if(pin_bp){
        tanque2 += .1;
        if(tanque2 > 100) tanque2 = 100;
    }

    pin_s21 = (tanque2 >= 10);
    pin_s22 = (tanque2 >= 90);

    // Vazamento (teste)
    if (tanque1 >=.01)
        tanque1 -= .01;

    if (tanque2 >=.01)
        tanque2 -= .01;
}
