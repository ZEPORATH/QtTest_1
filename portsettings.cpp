#include "portsettings.h"
#include "ui_portsettings.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>

QT_USE_NAMESPACE

PortSettings::PortSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortSettings)
{
    ui->setupUi(this);
    intValidator = new QIntValidator(0, 4000000, this);


}

PortSettings::~PortSettings()
{
    delete ui;
}

