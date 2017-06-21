#ifndef SERIALMONITOR_H
#define SERIALMONITOR_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtCore/QtGlobal>
#include <QtSerialPort/QSerialPortInfo>
//#include "console.h"


class Console;
namespace Ui {
class SerialMonitor;
}

class SerialMonitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialMonitor(QWidget *parent = 0);
    ~SerialMonitor();
    struct Settings{
        QString name;
        qint32 baudrate;
        QString stringBaudate;
        bool newlineEnabled;

    };
    Settings settings1() const{
        return current_settings;
    }


private slots:
    void setBaudRate();
    void setSerilaPort();
//    void setNewLineEnding();
    void sendSerialData();
    void recieveSerialData();
    void openSerialPort();
    void closeSerialPort();
//    void showStatusMessage(const QString &message);
    void on_sendpushButton_clicked();
    void handleError(QSerialPort::SerialPortError error);

private:
//    void initActionsConnections();

private:
    Ui::SerialMonitor *ui;
    QSerialPort* serial;
    Console* console;
    void updateSettings();
    Settings current_settings;
};

#endif // SERIALMONITOR_H
