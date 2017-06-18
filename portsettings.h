#ifndef PORTSETTINGS_H
#define PORTSETTINGS_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>


namespace Ui {
class PortSettings;
}

class QIntValidator;


class PortSettings : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
            QString name;
            qint32 baudRate;
            QString stringBaudRate;
            QSerialPort::DataBits dataBits;
            QString stringDataBits;
            QSerialPort::Parity parity;
            QString stringParity;
            QSerialPort::StopBits stopBits;
            QString stringStopBits;
            QSerialPort::FlowControl flowControl;
            QString stringFlowControl;
            bool localEchoEnabled;
        };
    explicit PortSettings(QWidget *parent = 0);
    ~PortSettings();

private slots:
    void showPortInfo(int idx);
    void apply();
private:

    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();

private:
        Ui::PortSettings *ui;
        Settings currentSettings;
        QIntValidator *intValidator;

};

#endif // PORTSETTINGS_H
