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
    tanque3=0;
    temperatura = 36;
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
    #include "../../common/sm3.h"
    #include "../../common/sm4.h"
}
extern boolean pin_v1, pin_v2, pin_bp, pin_r, pin_s11, pin_s12, pin_s21, pin_s22, pin_s31, pin_s32, pin_s1_e, pin_s2_e, pin_s3_e, histerese;
void MainWindow::Update_GUI(){
    ui->led_v1->setPower(pin_v1);
    ui->led_v2->setPower(pin_v2);

    ui->led_s11->setPower(pin_s11);
    ui->led_s12->setPower(pin_s12);
    ui->led_s21->setPower(pin_s21);
    ui->led_s22->setPower(pin_s22);
    ui->led_s31->setPower(pin_s31);
    ui->led_s32->setPower(pin_s32);
    ui->led_s1_e->setPower(pin_s1_e);
    ui->led_s2_e->setPower(pin_s2_e);
    ui->led_s3_e->setPower(pin_s3_e);
    ui->led_bomba->setPower(pin_bp);
    ui->led_r->setPower(pin_r);

    ui->tank_1->setValue(tanque1);
    ui->tank_2->setValue(tanque2);
    ui->tank_3->setValue(tanque3);
    ui->term->setValue(temperatura);
    ui->bomba_principal->setValue(pin_bp*(ui->bomba_principal->value() + 25)%100);
}

void MainWindow::Physical_process(){
    pin_s11 = (tanque1 >= 10);
    pin_s12 = (tanque1 >= 90);
    pin_s21 = (tanque2 >= 10);
    pin_s22 = (tanque2 >= 90);
    pin_s31 = (tanque3 >= 10);
    pin_s32 = (tanque3 >= 90);

    pin_s1_e = (COMPARE(sm1,sm1_v1_error));
    pin_s2_e = (COMPARE(sm2,sm2_bp_error));
    pin_s3_e = (COMPARE(sm3,sm3_v2_error));

    if(pin_v1){
        if (ui->t1->value())
            tanque1 = ui->t1->value();
        else
            tanque1 += .02;
        if(tanque1 > 100) tanque1 = 100;
    }

    if(pin_bp){
        if (ui->t2->value())
            tanque2 = ui->t2->value();
        else {
            tanque1 -= .04;
            tanque2 += .04;
        }
        if(tanque2 > 100) tanque2 = 100;
    }

    if(pin_v2){
        if (ui->t3->value()!=0)
            tanque3 = ui->t3->value();
        else {
            if (tanque2 < (tanque3/4)){
                tanque2 += .06;
                tanque3 -= .06*4;
             } else {
                tanque2 -= .06;
                tanque3 += .06*4;
             }
        }
        if (tanque3 > 100) tanque3 = 100;
    }

    // Vazão do tanque 3 (consumo)
    if(tanque3 > 0.01){
        tanque3 -= 0.03;
    }

    if (temperatura < 51 && !histerese && pin_r){
        temperatura += 0.001 + ui->t4->value()/25;
    } else if (temperatura > 49 && histerese){
        temperatura -= 0.0005 + ui->t4->value()/25;
    } else if (temperatura >= 51){
        histerese = TRUE;
    } else {
        histerese = FALSE;
    }
}
