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
    #include "../../common/sm1.h"
    #include "../../common/sm2.h"
}
extern boolean pin_v1, pin_bp, pin_s11, pin_s12, pin_s21, pin_s22, pin_s1_e, pin_s2_e;
void MainWindow::Update_GUI(){
    ui->led_v1->setPower(pin_v1);
    ui->led_s11->setPower(pin_s11);
    ui->led_s12->setPower(pin_s12);
    ui->led_s21->setPower(pin_s21);
    ui->led_s22->setPower(pin_s22);
    ui->led_s1_e->setPower(pin_s1_e);
    ui->led_s2_e->setPower(pin_s2_e);
    ui->led_bomba->setPower(pin_bp);

    ui->tank_1->setValue(tanque1);
    ui->tank_2->setValue(tanque2);
    ui->bomba_principal->setValue(pin_bp*(ui->bomba_principal->value() + 25)%100);
}

void MainWindow::Physical_process(){
    pin_s11 = (tanque1 >= 10);
    pin_s12 = (tanque1 >= 90);
    pin_s21 = (tanque2 >= 10);
    pin_s22 = (tanque2 >= 90);

    pin_s1_e = (COMPARE(sm1,sm1_v1_error));
    pin_s2_e = (COMPARE(sm2,sm2_bp_error));

    if(pin_v1){
        tanque1 += .02;
        if(tanque1 > 100) tanque1 = 100;
    }

    if(pin_bp){
        tanque1 -= .04;
        tanque2 += .04;
        if(tanque2 > 100) tanque2 = 100;
    }

    // Vazão tanque 2 (consumo)
    if (tanque2 >=.01 && !pin_bp)
        tanque2 -= .003;


    // Erro tanque 1(teste)
//    pin_s11 = FALSE;
//    pin_s12 = TRUE;

    // Erro tanque 2(teste)
//    pin_s21 = FALSE;
//    pin_s22 = TRUE;
}
