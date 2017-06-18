#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialportprovider.h"

//#include "logger.h"

#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDir>
#include <QScopedPointer>
#include <QTextStream>
#include <QDateTime>
#include <QLoggingCategory>


// Smart pointer to log file
QScopedPointer<QFile>   m_logFile;

QString MainWindow::serialBuffer = "";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


            parsed_data = "";
    /**
    Identify the port , arduino uno is on
    **/
    settings = new SettingsDialog;
    //    getPorts();
    //    getBaudRate();
    startlogging = false;
    status = new QLabel;
    ui->statusBar->addWidget(status);
    QObject::connect(ui->logger_checkBox,&QCheckBox::stateChanged,this,&MainWindow::on_logger_checkBox_stateChanged);
    connect(SerialPortProvider::getInstance()->arduino, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);


}

MainWindow::~MainWindow()
{
    if(SerialPortProvider::getInstance()->arduino->isOpen()){
        SerialPortProvider::getInstance()->arduino->close();
    }
    delete settings;
    delete ui;

}

//void MainWindow::getPorts()
//{
//    ui->SerialPortBox->clear();
//    QString name;
//    const auto infos = QSerialPortInfo::availablePorts();
//    for (const QSerialPortInfo &info : infos) {
//        ui->SerialPortBox->addItem(info.portName());
//    }

//}

//void MainWindow::getBaudRate()
//{
//    ui->BaudRateBox->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
//    ui->BaudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
//    ui->BaudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
//    ui->BaudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
//    ui->BaudRateBox->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
//    ui->BaudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
//    ui->BaudRateBox->addItem(tr("Custom"));


//}

bool MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    SerialPortProvider::getInstance()->arduino->setPortName(p.name);
    SerialPortProvider::getInstance()->arduino->setBaudRate(p.baudRate);
    SerialPortProvider::getInstance()->arduino->setDataBits(p.dataBits);
    SerialPortProvider::getInstance()->arduino->setParity(p.parity);
    SerialPortProvider::getInstance()->arduino->setStopBits(p.stopBits);
    SerialPortProvider::getInstance()->arduino->setFlowControl(p.flowControl);
    if (SerialPortProvider::getInstance()->arduino->open(QIODevice::ReadWrite)) {
        //        console->setEnabled(true);
        //        console->setLocalEchoEnabled(p.localEchoEnabled);
        //        ui->actionConnect->setEnabled(false);
        //        ui->actionDisconnect->setEnabled(true);
        //        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        return true;
    } else {
        QMessageBox::critical(this, tr("Error"), SerialPortProvider::getInstance()->arduino->errorString());

        showStatusMessage(tr("Open error"));
        return false;
    }
}
void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}
void MainWindow::readSerial()
{
    //    QStringList buffer_split = serialBuffer.split("\n");

    {
        serialData = SerialPortProvider::getInstance()->arduino->readAll();
        QString str = "";
        serialBuffer =serialBuffer+QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }
    if(serialBuffer.contains("\r\n")){
        emit setSharedString(serialBuffer);
        updateLCDs(serialBuffer);
        if(startlogging==true)
            logger_mgr(serialBuffer);
        serialBuffer="";

    }
}


void MainWindow::updateLCDs(QString serialBuffer1)
{
    //    qDebug()<<serialBuffer<<"\n";
    string_recv_buffer = serialBuffer1;
    QStringList buffer_split = serialBuffer1.split(" ");

    ui->cell_1_lcd->display(buffer_split[0]);
    ui->temp_cell_1_lcd->display(buffer_split[1]);
    ui->cell_2_lcd->display(buffer_split[2]);
    ui->temp_cell_2_lcd->display(buffer_split[2]);
    ui->cell_3_lcd->display(buffer_split[3]);
    ui->temp_cell_3_lcd->display(buffer_split[4]);
    ui->cell_4_lcd->display(buffer_split[5]);
    ui->temp_cell_4_lcd->display(buffer_split[6]);
    ui->cell_5_lcd->display(buffer_split[7]);
    ui->temp_cell_5_lcd->display(buffer_split[8]);
    ui->cell_6_lcd->display(buffer_split[9]);
    ui->temp_cell_6_lcd->display(buffer_split[10]);
    ui->cell_7_lcd->display(buffer_split[11]);
    ui->temp_cell_7_lcd->display(buffer_split[12]);
    ui->cell_8_lcd->display(buffer_split[13]);
    ui->temp_cell_8_lcd->display(buffer_split[14]);
    ui->cell_9_lcd->display(buffer_split[15]);
    ui->temp_cell_9_lcd->display(buffer_split[16]);
    ui->cell_10_lcd->display(buffer_split[17]);
    ui->temp_cell_10_lcd->display(buffer_split[18]);
    ui->cell_11_lcd->display(buffer_split[19]);
    ui->temp_cell_11_lcd->display(buffer_split[20]);
    ui->cell_12_lcd->display(buffer_split[21]);
    ui->temp_cell_12_lcd->display(buffer_split[22]);


    ui->Die_Temp_lcd->display(buffer_split[23]);
    ui->Current_lcd->display(buffer_split[24]);
    ui->PACK_VOLT1_LCD->display(buffer_split[25]);
    ui->PACK_VOLT2_LCD->display(buffer_split[26]);
    ui->COL_COUNT_LCD->display(buffer_split[27]);
    ui->SOC_LCD->display(buffer_split[28]);

    ui->ADC_GAIN_LCD->display(buffer_split[29]);
    ui->ADC_OFFSET_LCD->display(buffer_split[30]);



}


void MainWindow::on_start_push_button_clicked()
{
    if(openSerialPort()){
        QObject::connect(SerialPortProvider::getInstance()->arduino,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }


}



void MainWindow::logger_mgr(QString s)
{
    // Set the logging file
    // check which a path to file you use
    QString filename = "log.txt";
    QFile file(filename);
    // Open the file logging
    if(file.open(QFile::Append | QFile::Text)){
        QTextStream stream(&file);
        stream <<  QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
        stream << s <<endl;

    }
}


void MainWindow::on_logger_checkBox_stateChanged(int arg1)
{   qDebug()<<"Inside Logger l1 \n";
    if(ui->logger_checkBox->isChecked()){
        if(SerialPortProvider::getInstance()->arduino->isOpen()){
            startlogging = true;
            qDebug()<<"Inside Logger l2 \n";
        }
        else{
            startlogging=false;
        }
        //       qDebug()<<"Inside Logger l2 \n";
        //        startlogging = true;
        //        logger_mgr("heloo");
    }
    else{

        startlogging=false;
    }
}


void MainWindow::on_CONTROL_pushButton_clicked()
{
    static int window_count = 0;
    if (window_count==0){
        contol_window = new Contol_window(this);
        //    contol_window->raise();
        contol_window->activateWindow();
        contol_window->show();
        connect(this,SIGNAL(setSharedString(QString)),contol_window, SLOT(getSharedString(QString)));
        window_count++;
    }
    else
    {
        contol_window->close();
        window_count--;
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionEdit_PORT_triggered()
{
    //    port_settings = new PortSettings(this);
    //    port_settings->show();
    settings = new SettingsDialog(this);
    settings->show();
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), SerialPortProvider::getInstance()->arduino->errorString());
        closeSerialPort();
    }
}

void MainWindow::closeSerialPort()
{
    if (SerialPortProvider::getInstance()->arduino->isOpen())
        SerialPortProvider::getInstance()->arduino->close();
}

void MainWindow::writeSerial(QString msg){
    QByteArray data (msg.toStdString().c_str());
    qDebug()<<"got message from control box \n";
    SerialPortProvider::getInstance()->arduino->write(data);
}
