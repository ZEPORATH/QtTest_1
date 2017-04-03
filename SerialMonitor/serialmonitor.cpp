#include "serialmonitor.h"
#include "ui_serialmonitor.h"
//#include "console.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>
#include <QScrollBar>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

SerialMonitor::SerialMonitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialMonitor)
{
    ui->setupUi(this);
    setBaudRate();
    setSerilaPort();
//    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
//                this, &SerialMonitor::handleError);

    //! [2]
        connect(serial, &QSerialPort::readyRead, this, &SerialMonitor::recieveSerialData);
    //! [2]
//        connect(console, &SerialMonitor::on_sen, this, &SerialMonitor::sendSerialData);
}

SerialMonitor::~SerialMonitor()
{
    delete ui;
}
//Settings SerialMonitor::settings1(){
//    return current_settings;
//}

void SerialMonitor::setBaudRate(){
    ui->baudRateBox->addItem(QStringLiteral ("9600"),QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->addItem(tr("Custom"));
}

void SerialMonitor::setSerilaPort(){
    ui->serialPortInfoListBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        ui->serialPortInfoListBox->addItem(info.portName());
    }

}

void SerialMonitor::openSerialPort(){
    Settings p = settings1();
    serial->setBaudRate(p.baudrate);
    serial->setPortName(p.name);
    if (serial->open(QIODevice::ReadWrite)) {
//        showStatusMessage(tr("Connected to %1 ")
//                                  .arg(p.name));

            }

}

void SerialMonitor::closeSerialPort(){
    if (serial->isOpen())
            serial->close();
//    showStatusMessage(tr("Disconnected"));
}


void SerialMonitor::updateSettings(){
current_settings.name = ui->serialPortInfoListBox->currentText();
if (ui->baudRateBox->currentIndex() == 4) {
        current_settings.baudrate = ui->baudRateBox->currentText().toInt();
    } else {
        current_settings.baudrate = static_cast<QSerialPort::BaudRate>(
                    ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
    }
current_settings.stringBaudate = QString::number(current_settings.baudrate);
}


void SerialMonitor::sendSerialData(){
    QString str = ui->SerialInputConsole->toPlainText();
    QByteArray data(str.toStdString().c_str());
    serial->write(data);
    ui->SerialInputConsole->clear();

}

void SerialMonitor::recieveSerialData(){
    QByteArray data = serial->readAll();
        ui->serialConsole->append(QString(data));
        QScrollBar *bar =new QScrollBar(Qt::Vertical);
        bar->setValue(bar->maximum());
}

//void MainWindow::showStatusMessage(const QString &message)
//{
//    status->setText(message);
//}

void SerialMonitor::on_sendpushButton_clicked()
{
    sendSerialData();
}
void SerialMonitor::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
