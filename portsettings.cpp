#include "portsettings.h"
#include "ui_portsettings.h"

PortSettings::PortSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortSettings)
{
    ui->setupUi(this);
}

PortSettings::~PortSettings()
{
    delete ui;
}

