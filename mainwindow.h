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
private slots:
    void readSerial();
    void updateLCDs(QString);
private:
    Ui::MainWindow *ui;

    static const quint16 arduino_uno_vendor_id= 9025;
    static const quint16 arduino_uno_product_id = 67;
    QSerialPort *arduino;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;



};

#endif // MAINWINDOW_H
