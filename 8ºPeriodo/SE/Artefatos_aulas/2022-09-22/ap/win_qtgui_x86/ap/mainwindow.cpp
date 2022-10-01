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
    tanque2=11;
    tanque3=89;
    temperatura = 36;
    tbehavior.start();
}

MainWindow::~MainWindow(){
    delete ui;
}

extern "C"{
    #include "../../common/definitions.h"
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
            tanque1 += vazao_v1_t1;
        if(tanque1 > 100) tanque1 = 100;
    }

    if(pin_bp){
        if (ui->t2->value()){
            tanque2 = ui->t2->value();
            tanque3 = ui->t3->value();
        }
        else {
            tanque1 -= vazao_t1_t2;
            tanque2 += vazao_t1_t2;
        }
        if(tanque2 > 100) tanque2 = 100;
    }

    if(pin_v2){
        if (tanque2 < (tanque3/2)){
           tanque2 += vazao_t2_t3;
           tanque3 -= vazao_t2_t3*4;
        } else {
           tanque2 -= vazao_t2_t3;
           tanque3 += vazao_t2_t3*4;
        }
        if (tanque3 > 100) tanque3 = 100;
    }

    // Vazão do tanque 3 (consumo)
    if(tanque3 > 0.01){
        tanque3 -= vazao_t3;
    }

    if (temperatura < (temp_padrao+val_histerese) && !histerese && pin_r){
        temperatura += delta_t_pos + ui->t4->value()/25;
    } else if (temperatura > (temp_padrao-val_histerese) && histerese){
        temperatura -= delta_t_neg + ui->t4->value()/25;
    } else if (temperatura >= 51){
        histerese = TRUE;
    } else {
        histerese = FALSE;
    }
}
