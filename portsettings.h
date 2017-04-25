#ifndef PORTSETTINGS_H
#define PORTSETTINGS_H

#include <QDialog>

namespace Ui {
class PortSettings;
}

class PortSettings : public QDialog
{
    Q_OBJECT

public:
    explicit PortSettings(QWidget *parent = 0);
    ~PortSettings();

private:
    Ui::PortSettings *ui;
};

#endif // PORTSETTINGS_H
