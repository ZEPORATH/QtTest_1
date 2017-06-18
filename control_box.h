#ifndef CONTROL_BOX_H
#define CONTROL_BOX_H

#include <QDialog>

namespace Ui {
class Control_BOX;
}

class Control_BOX : public QDialog
{
    Q_OBJECT

public:
    explicit Control_BOX(QWidget *parent = 0);
    ~Control_BOX();

private:
    Ui::Control_BOX *ui;
};

#endif // CONTROL_BOX_H
