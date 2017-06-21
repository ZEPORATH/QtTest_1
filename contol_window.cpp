#include "contol_window.h"
#include "ui_contol_window.h"
#include "serialportprovider.h"
#include "mainwindow.h"

#include <QDebug>
#include <QString>
#include <QStringList>
#include <string>
#include <ctime>


Contol_window::Contol_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Contol_window)
{
    ui->setupUi(this);
    qDebug()<<"Failing before connect \n"<<endl;
    //QObject::connect(SerialPortProvider::getInstance()->arduino,SIGNAL(readyRead()),this,SLOT(readSerial()));
    qDebug()<<"Failing After this connect \n"<<endl;
    qDebug()<<MainWindow::serialBuffer;
//    string_recv_buffer = serialBuffer;
    qDebug()<<string_recv_buffer;

    initControls();
    initmap();
}

Contol_window::~Contol_window()
{
    delete ui;
}
void Contol_window::initmap(){
    //Make the parameters 1 for True, or 0 for false
    default_param["DEVICCE_READY"] = 0;
    default_param["OVRD_ALERT"] = 0;
    default_param["ADC_EN"] = 0;
    default_param["TEMP_SEC"] = 0;
    default_param["DELAY_DIS"] = 0;
    default_param["CC"] = 0;
    default_param["DSG_ON"] = 0;
    default_param["CHG_ON"] = 0;
    default_param["RSNS"] = 0;
    default_param["SCD"] = 70;
    default_param["OCD"] = 8;
    default_param["OVD"] = 1;
    default_param["OVT"] = 22;
    default_param["UVD"] = 1;
    default_param["UVT"] = 8;
    default_param["SCT"] = 44;
    default_param["OCT"] = 17;

}

void Contol_window::getSharedString(QString rec)
{   qDebug()<<rec;
    string_recv_buffer = rec;
    update_status_indicator();
}


void Contol_window::initControls(){
    ui->SCD_comboBox->addItems(sequence_len_scd);
//All ui containing sequence_len_scd didnot had the mentioned table for input n their requirement sheets
    ui->SCT_comboBox->addItems(sequence_len_sct);

    ui->UVD_comboBox->addItems(sequence_len_uvd);

    ui->UVT_comboBox->addItems(sequence_len_uvt);

    ui->OCD_comboBox->addItems(sequence_len_ocd);

    ui->OCT_comboBox->addItems(sequence_len_oct);

    ui->OVD_comboBox->addItems(sequence_len_ovd);

    ui->OVT_comboBox->addItems(sequence_len_ovt);




}

void Contol_window::initParamAndDefaultParam()
{
    QStringList key_list ;
    key_list.push_back("ADC_EN");
}
int Contol_window::changeColor(QPushButton* button, QString* button_color/*,QString* parent_color*/){
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
                                        border-color: rgb(85, 255, 0);\
                                        max-width:400px;\
                                        max-height:400px;\
                                        min-width:20px;\
                                        min-height:20px;");
        *button_color = "green";
//         qDebug() << "Inside else loop button_4 \n";
         return 2;
    }
}

void Contol_window::readSerial()
{
    serialData = SerialPortProvider::getInstance()->arduino->readAll();
    QString str = "";
    serialBuffer =serialBuffer+QString::fromStdString(serialData.toStdString());
    serialData.clear();
    if(serialBuffer.contains("\r\n")){
     string_recv_buffer = serialBuffer;
}
    qDebug()<<string_recv_buffer<<"\n";
}

//void qSleep(int ms){
//    sleep(ms);
//}

void Contol_window::writeSerial(QString msg)
{
    QByteArray data (msg.toStdString().c_str());
    qDebug()<<"got message from control box \n";
    SerialPortProvider::getInstance()->arduino->write(data);
//    nanosleep();
//    SerialPort1Provider::getInstance()->arduino->clear();
}

void Contol_window::changeColor_indicators(QPushButton *button, QString str)
{
  if (str=="green"){
      button->setStyleSheet("font: 75 12pt \"Tahoma\";\
                         background-color:green;border-style: solid;\
                         border-width:4px;\
                         border-radius:20px;\
                         border-color: green;\
                         max-width:400px;\
                         max-height:400px;\
                         min-width:20px;\
                         min-height:20px;");
  }
  else if (str=="red"){
      button->setStyleSheet("font: 75 12pt \"Tahoma\";\
                         background-color:red;border-style: solid;\
                         border-width:4px;\
                         border-radius:20px;\
                         border-color: red;\
                         max-width:400px;\
                         max-height:400px;\
                         min-width:20px;\
                         min-height:20px;");
  }
}

void Contol_window::update_status_indicator(){

    QString res = string_recv_buffer;

    QStringList res_list = res.split(" ");

    if (res_list[33]=="34"){
        changeColor_indicators(ui->UV_pushButton,"green");
    }
    else{
        changeColor_indicators(ui->UV_pushButton,"red");

    }
    if (res_list[34]=="35"){
        changeColor_indicators(ui->OV_Button,"green");
    }
    else{
        changeColor_indicators(ui->OV_Button,"red");
    }
    if (res_list[35]=="36"){
        changeColor_indicators(ui->SCD_pushButton,"green");
    }
    else{
        changeColor_indicators(ui->SCD_pushButton,"red");
    }
    if (res_list[36]=="37"){
        changeColor_indicators(ui->CC_READY_pushButton,"green");
    }
    else{
        changeColor_indicators(ui->CC_READY_pushButton,"red");
    }
    if (res_list[37]=="38"){
        changeColor_indicators(ui->OCD_pushButton, "green");
    }
    else{
        changeColor_indicators(ui->OCD_pushButton,"red");
    }
    if (res_list[38]=="39"){
        changeColor_indicators(ui->LOAD_PRESENT_pushButton,"green");
    }
    else{
        changeColor_indicators(ui->LOAD_PRESENT_pushButton,"red");
    }


}

void Contol_window::reset(){
    param = default_param;
}



void Contol_window::on_ADC_EN_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->ADC_EN_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1)param["ADC_EN"] = 1;
    else param["ADC_EN"] = 0;
}

void Contol_window::on_DSG_ON_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->DSG_ON_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1)param["DSG_ON"] = 1;
    else param["DSG_ON"] = 2;
}

void Contol_window::on_CHG_ON_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->CHG_ON_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1) param["CHG_ON"] = 1;
    else param["CHG_ON"] = 2;
}

void Contol_window::on_DEVICE_X_READY_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->DEVICE_X_READY_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1) param["DEVICE_XREADY"] = 1;
    else param["DEVICE_XREADY"] = 2;
}

void Contol_window::on_TEMP_SEL_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->TEMP_SEL_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1) param["TEMP_SEL"] = 1;
    else param["TEMP_SEL"] = 2;

}

void Contol_window::on_CC_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->CC_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1) param["CC"] = 1;
    else param["CC"] = 2;
}

void Contol_window::on_DELAY_DIS_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->DELAY_DIS_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1)param["DELAY_DIS"] = 1;
    else param["DELAY_DIS"] = 2;
}

void Contol_window::on_OVERD_ALERT_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->OVERD_ALERT_pushButton, &local_button_color);
    qDebug() << res;
    if (res == 1)param["OVRD_ALERT"] = 1;
    else param["OVRD_ALERT"]  = 2;
}

void Contol_window::on_RSNS_pushButton_clicked()
{
    static QString local_button_color = button_color;
    int res = changeColor(ui->RSNS_pushButton, &local_button_color);
    qDebug() << res;
    //clear the combox and push the needed new selectable values

    if(res==1){

    ui->SCT_comboBox->clear();
    ui->SCT_comboBox->addItems(sequence_len_sct);
    ui->OCT_comboBox->clear();
    ui->OCT_comboBox->addItems(sequence_len_oct);
    param["RSNS"] = 1;
    }else{
        ui->SCT_comboBox->clear();
        ui->SCT_comboBox->addItems(sequence_len_sct_rsns);
        ui->OCT_comboBox->clear();
        ui->OCT_comboBox->addItems(sequence_len_oct_rsns);
        param["RSNS"]= 2;

    }
}

void Contol_window::on_CCC1_pushButton_clicked()
{
    static QString local_button_color = "green";
    if(local_button_color=="green"){
        ui->CCC1_pushButton->styleSheet();
    }else{

    }
}

void Contol_window::on_SLEEP_pushButton_clicked()
{
    static QString local_button_color = "red";
    if (local_button_color == QString("green")){
    ui->SLEEP_pushButton->setStyleSheet("font: 75 11pt \"MS Shell Dlg 2\" ;\
                                        color:rgb(255, 255, 255);\
                                         border-style: solid;\
                                         border-width:3px;\
                                         border-radius:40px;\
                                        background-color: rgb(255, 85, 0);\
                                         border-color: green;\
                                         max-width:400px;\
                                         max-height:400px;\
                                         min-width:60px;\
                                         min-height:60px;"\
                                         );
     local_button_color = "red";
     qDebug() << "Inside if loop button_4 red\n";
//     return 1;
    param["SLEEP"] = 1;
    }
    else{

        ui->SLEEP_pushButton->setStyleSheet("font: 75 11pt \"MS Shell Dlg 2\" ;\
                                            color:rgb(255, 255, 255);\
                                             border-style: solid;\
                                             border-width:3px;\
                                             border-radius:40px;\
                                            background-color: rgb(0, 190, 0);;\
                                             border-color: green;\
                                             max-width:400px;\
                                             max-height:400px;\
                                             min-width:60px;\
                                             min-height:60px;"\
                                             );
        local_button_color = "green";
         qDebug() << "Inside else loop button_4 green\n";
//         return 2;
         param["SLEEP"] = 2;

    }
}

void Contol_window::on_LOAD_CONFIG_pushButton_clicked()
{


    QString msg = "Hello from LOAD_CONFIG_BUTTON \n";//Change the message to required message type.
    //Extract the value from the map
    for (auto e: param.keys()){
        send_msg.append(" ").append(QString::number(param.value(e)));
    }
     qDebug()<<"Sending messgae :"<<send_msg;
     send_msg = "Hello arduino from QT";
    writeSerial(send_msg);
    send_msg = "";
    QMessageBox msgBox;
    msgBox.setText("New control Pushed/Loaded");
    msgBox.exec();


}


void Contol_window::on_RESET_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("RESET control Pushed/Loaded");
    msgBox.exec();
    reset();
}


