#include "control_box.h"
#include "ui_control_box.h"

Control_BOX::Control_BOX(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Control_BOX)
{
    ui->setupUi(this);
}

Control_BOX::~Control_BOX()
{
    delete ui;
}
