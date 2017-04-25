#include "contol_window.h"
#include "ui_contol_window.h"

#include <QDebug>
#include <QString>
#include <QStringList>



Contol_window::Contol_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Contol_window)
{
    ui->setupUi(this);
    initControls();
}

Contol_window::~Contol_window()
{
    delete ui;
}

void Contol_window::initControls(){



    //Edit the variables for comboboxes
//    QStringList sequence_len_scd = QStringList()<<QString("70")<<QString("100")<<QString("200")<<QString("400");
    QStringList sequence_len_scd = QStringList()<<tr("70")<<tr("100")<<tr("200")<<tr("400");
    QStringList sequence_len_sct = QStringList()<<tr("44")<<tr("67")<<tr("89")<<tr("111")<<\
                                                  tr("133")<<tr("155")<<tr("178")<<tr("200");
    QStringList sequence_len_uvd = QStringList()<<tr("1")<<tr("4")<<tr("8")<<tr("16");
    QStringList sequence_len_ocd = QStringList()<<tr("8")<<tr("20")<<tr("40")<<tr("60")<<\
                                                  tr("160")<<tr("320")<<tr("640")<<tr("1280");
    QStringList sequence_len_oct = QStringList()<<tr("17")<<tr("22")<<tr("28")<<tr("33")<<\
                                                  tr("39")<<tr("44")<<tr("50")<<tr("56")<<\
                                                  tr("61")<<tr("67")<<tr("72")<<tr("78")<<\
                                                  tr("83")<<tr("89")<<tr("94")<<tr("94");
    QStringList sequence_len_ovd = QStringList()<<tr("1")<<tr("4")<<tr("8")<<tr("16");
    QStringList sequence_len_sct_rsns = QStringList()<<tr("22")<<tr("33")<<tr("44")<<tr("56")\
                                                    <<tr("67")<<tr("78")<<tr("89")<<tr("100");
    QStringList sequence_len_oct_rsns = QStringList()<<tr("8")<<tr("1")<<tr("14")<<tr("17")<<\
                                                       tr("19")<<tr("22")<<tr("25")<<tr("28")\
                                                    <<tr("31")<<tr("33")<<tr("36")<<tr("39")\
                                                   <<tr("42")<<tr("44")<<tr("47")<<tr("50");


    ui->SCD_comboBox->addItems(sequence_len_scd);
//All ui containing sequence_len_scd didnot had the mentioned table for input n their requirement sheets
    ui->SCT_comboBox->addItems(sequence_len_sct);

    ui->UVD_comboBox->addItems(sequence_len_uvd);

    ui->UVT_comboBox->addItems(sequence_len_scd);

    ui->OCD_comboBox->addItems(sequence_len_ocd);

    ui->OCT_comboBox->addItems(sequence_len_scd);

    ui->OVD_comboBox->addItems(sequence_len_ovd);

    ui->OVT_comboBox->addItems(sequence_len_scd);


}
int Contol_window::changeColor(QPushButton* button, QString* button_color){
    if (*button_color == QString("green")){
    button->setStyleSheet("font: 75 12pt \"Tahoma\";\
                                    background-color:red;border-style: solid;\
                                    border-width:4px;\
                                    border-radius:20px;\
                                    border-color: red;\
                                    max-width:400px;\
                                    max-height:400px;\
                                    min-width:20px;\
                                    min-height:20px;");
     *button_color = "red";
//     qDebug() << "Inside if loop button_4\n";
     return 1;

    }
    else{

        button->setStyleSheet("font: 75 12pt \"Tahoma\";\
                                        background-color:rgb(85, 255, 0);\
                                        border-style: solid;\
                                        border-width:4px;\
                                        border-radius:20px;\
                                        border-color: red;\
                                        max-width:400px;\
                                        max-height:400px;\
                                        min-width:20px;\
                                        min-height:20px;");
        *button_color = "green";
//         qDebug() << "Inside else loop button_4 \n";
         return 2;
    }
}

void Contol_window::on_OV_Button_clicked()
{
  static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->OV_Button,&local_button_color);

}

void Contol_window::on_CC_READY_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->CC_READY_pushButton,&local_button_color);

}


void Contol_window::on_OCD_pushButton_clicked()
{
    static QString local_button_color = button_color;
   qDebug() << changeColor(ui->OCD_pushButton,&local_button_color);

}



void Contol_window::on_LOAD_PRESENT_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->LOAD_PRESENT_pushButton,&local_button_color);
}



void Contol_window::on_UV_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->UV_pushButton,&local_button_color);
}



void Contol_window::on_SCD_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->SCD_pushButton,&local_button_color);
}



void Contol_window::on_ADC_EN_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->ADC_EN_pushButton, &local_button_color);
}

void Contol_window::on_DSG_ON_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->DSG_ON_pushButton, &local_button_color);
}



void Contol_window::on_CHG_ON_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->CHG_ON_pushButton, &local_button_color);

}



void Contol_window::on_DEVICE_X_READY_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->DEVICE_X_READY_pushButton, &local_button_color);
}

void Contol_window::on_TEMP_SEL_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->TEMP_SEL_pushButton, &local_button_color);
}

void Contol_window::on_CC_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->CC_pushButton, &local_button_color);
}

void Contol_window::on_DELAY_DIS_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->DELAY_DIS_pushButton, &local_button_color);
}



void Contol_window::on_OVERD_ALERT_pushButton_clicked()
{
    static QString local_button_color = button_color;
    qDebug() <<changeColor(ui->OVERD_ALERT_pushButton, &local_button_color);

}


void Contol_window::on_RSNS_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->RSNS_pushButton, &local_button_color);
    qDebug() << res;
    if(res==1){
    ui->SCT_comboBox->clear();
    ui->SCT_comboBox->addItems(sequence_len_sct);
    }else{
        ui->SCT_comboBox->clear();
        ui->SCT_comboBox->addItems(sequence_len_sct_rsns);

    }
}
