#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void getPorts();
    void getBaudRate();

private slots:
    void readSerial();
    void updateLCDs(QString);
    void on_start_push_button_clicked();
    void logger_mgr(QString);
    void on_logger_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    bool startlogging;
    static const quint16 arduino_uno_vendor_id= 9025;
    static const quint16 arduino_uno_product_id = 67;
    QSerialPort *arduino;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;



};

#endif // MAINWINDOW_H
