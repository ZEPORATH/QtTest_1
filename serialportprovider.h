#ifndef SERIALPORTPROVIDER_H
#define SERIALPORTPROVIDER_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

//Implementing a Singleton Class for arduino reading
class SerialPortProvider
{
    static SerialPortProvider *port;
    SerialPortProvider(){
        arduino = new QSerialPort();
    }


public:
    QSerialPort *arduino;
    static SerialPortProvider *getInstance(){
        if (!port){
            port = new SerialPortProvider();
        }
        return port;
    }
    bool writing_to_arduino = false;

};

#endif // SERIALPORTPROVIDER_H
