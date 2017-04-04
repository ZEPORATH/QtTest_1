#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    /**
    Identify the port , arduino uno is on
    **/
    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //check if the serialport has both a product identifier and vendor identifier
        if(serialPortInfo.productIdentifier() && serialPortInfo.hasProductIdentifier()){
            //check if the product ID and vendor Id match, with those of arduino

            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true;
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

/*
 * Open and Configure the arduino port if availaible
 * /
 */

    if(arduino_is_available){
        qDebug()<<"Found Arduino Port ...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QIODevice::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }
    else{
        qDebug()<<"Couldn't find the correct port for the arduino. \n";
        QMessageBox::information(this,"Serial Port Error", "Couldn't open serial port to arduino. ");

    }


}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void MainWindow::readSerial()
{
//    QStringList buffer_split = serialBuffer.split("\n");

    {
        serialData = arduino->readAll();
        QString str = "";
        serialBuffer =serialBuffer+QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }
    if(serialBuffer.contains("\r\n")){
        updateLCDs(serialBuffer);
        serialBuffer="";

    }
}



void MainWindow::updateLCDs(QString serialBuffer1)
{
    qDebug()<<serialBuffer<<"\n";
    QStringList buffer_split = serialBuffer1.split(" ");

    ui->lcdNumber->display(buffer_split[0]);
    ui->lcdNumber_2->display(buffer_split[1]);
    ui->lcdNumber_3->display(buffer_split[2]);
    ui->lcdNumber_4->display(buffer_split[3]);
    ui->lcdNumber_5->display(buffer_split[4]);
    ui->lcdNumber_6->display(buffer_split[5]);
    ui->lcdNumber_7->display(buffer_split[6]);
    ui->lcdNumber_8->display(buffer_split[7]);
    ui->lcdNumber_9->display(buffer_split[8]);
    ui->lcdNumber_10->display(buffer_split[9]);
    ui->lcdNumber_11->display(buffer_split[10]);
    ui->lcdNumber_12->display(buffer_split[11]);
    ui->lcdNumber_13->display(buffer_split[12]);
    ui->lcdNumber_14->display(buffer_split[13]);
    ui->lcdNumber_15->display(buffer_split[14]);
    ui->lcdNumber_16->display(buffer_split[15]);
    ui->lcdNumber_17->display(buffer_split[16]);
//    for(int i=0;i<buffer_split.size()-1;i++){
////        qDebug()<<buffer_split[i]<<" ";
//        ui->lcdNumber_17->display(buffer_split[i]);
//    }
//    qDebug()<<"\n";

}
