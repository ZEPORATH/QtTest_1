#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <string>

#include "contol_window.h"
#include "settingsdialog.h"

namespace Ui {
class MainWindow;
}

class Contol_window;
class SettingsDialog;
extern  QString string_recv_buffer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void getPorts();
//    void getBaudRate();
    void writeSerial(QString);
//    friend class contol_window;
      QString string_recv_buffer;


signals:
      void setSharedString(QString);
private slots:
    void readSerial();
    bool openSerialPort();
    void updateLCDs(QString);
    void on_start_push_button_clicked();
    void logger_mgr(QString);
    void on_logger_checkBox_stateChanged(int arg1);

    void on_CONTROL_pushButton_clicked();

    void on_actionQuit_triggered();

    void on_actionEdit_PORT_triggered();

    void showStatusMessage(const QString &message);
    void handleError(QSerialPort::SerialPortError error);
    void closeSerialPort();
private:
    Ui::MainWindow *ui;

//    PortSettings* port_settings;
    SettingsDialog* settings;
    QLabel *status;


    bool startlogging;
    static const quint16 arduino_uno_vendor_id= 9025;
    static const quint16 arduino_uno_product_id = 67;
    QSerialPort *arduino;
    QByteArray serialData;

    QString parsed_data;
public:
     static QString serialBuffer;
     Contol_window* contol_window;


};

#endif // MAINWINDOW_H
