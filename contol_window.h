#ifndef CONTOL_WINDOW_H
#define CONTOL_WINDOW_H



#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QMap>
#include "mainwindow.h"

namespace Ui {
class Contol_window;
}

class Contol_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Contol_window(QWidget *parent = 0);
    QString send_msg = "";
    QMap<QString, int> param, default_param;
    QString reset_string,status_string;
    QString string_recv_buffer;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;



    ~Contol_window();

public slots:
    void getSharedString(QString);



private slots:

    void initControls();
    void initParamAndDefaultParam(); //!Initializes param and default_param
    void update_status_indicator();
    void reset();
    void readSerial();
//    void on_OV_Button_clicked();

//    void on_CC_READY_pushButton_clicked();

//    void on_OCD_pushButton_clicked();

//    void on_LOAD_PRESENT_pushButton_clicked();

//    void on_UV_pushButton_clicked();

//    void on_SCD_pushButton_clicked();

    void on_ADC_EN_pushButton_clicked();

    void on_DSG_ON_pushButton_clicked();

    void on_CHG_ON_pushButton_clicked();

    void on_DEVICE_X_READY_pushButton_clicked();

    void on_TEMP_SEL_pushButton_clicked();

    void on_CC_pushButton_clicked();

    void on_DELAY_DIS_pushButton_clicked();

    void on_OVERD_ALERT_pushButton_clicked();

    void on_RSNS_pushButton_clicked();

    void on_SLEEP_pushButton_clicked();

    void on_LOAD_CONFIG_pushButton_clicked();

    void on_CCC1_pushButton_clicked();

    void on_RESET_pushButton_clicked();

    void on_SCD_comboBox_currentIndexChanged(const QString &arg1);

    void on_SCT_comboBox_currentIndexChanged(const QString &arg1);

    void on_OCD_comboBox_currentIndexChanged(const QString &arg1);

    void on_OCT_comboBox_currentTextChanged(const QString &arg1);

    void on_OVD_comboBox_currentIndexChanged(const QString &arg1);

    void on_OVT_comboBox_currentIndexChanged(const QString &arg1);

    void on_UVD_comboBox_currentIndexChanged(const QString &arg1);

    void on_UVT_comboBox_currentIndexChanged(const QString &arg1);

private:

    //Edit the variables for comboboxes

    QStringList sequence_len_scd = QStringList()<<tr("70")<<tr("100")<<tr("200")<<tr("400");

    QStringList sequence_len_sct = QStringList()<<tr("44")<<tr("67")<<tr("89")<<tr("111")<<\
                                                  tr("133")<<tr("155")<<tr("178")<<tr("200");
    QStringList sequence_len_uvd = QStringList()<<tr("1")<<tr("4")<<tr("8")<<tr("16");
    QStringList sequence_len_ocd = QStringList()<<tr("8")<<tr("20")<<tr("40")<<tr("60")<<\
                                                  tr("160")<<tr("320")<<tr("640")<<tr("1280");
    QStringList sequence_len_oct = QStringList()<<tr("17")<<tr("22")<<tr("28")<<tr("33")<<\
                                                  tr("39")<<tr("44")<<tr("50")<<tr("56")<<\
                                                  tr("61")<<tr("67")<<tr("72")<<tr("78")<<\
                                                  tr("83")<<tr("89")<<tr("94")<<tr("94");
    QStringList sequence_len_ovd = QStringList()<<tr("1")<<tr("4")<<tr("8")<<tr("16");
    QStringList sequence_len_ovt = QStringList()<<tr("22")<<tr("33")<<tr("44")<<tr("56")\
                                                    <<tr("67")<<tr("78")<<tr("89")<<tr("100");
    QStringList sequence_len_uvt = QStringList()<<tr("8")<<tr("1")<<tr("14")<<tr("17")<<\
                                                       tr("19")<<tr("22")<<tr("25")<<tr("28")\
                                                    <<tr("31")<<tr("33")<<tr("36")<<tr("39")\
                                                   <<tr("42")<<tr("44")<<tr("47")<<tr("50");
    QStringList sequence_len_sct_rsns = QStringList()<<tr("22")<<tr("33")<<tr("44")<<tr("56")\
                                                    <<tr("67")<<tr("78")<<tr("89")<<tr("100");
    QStringList sequence_len_oct_rsns = QStringList()<<tr("1")<<tr("4")<<tr("8")<<tr("16");


    Ui::Contol_window *ui;
    QString button_color="green";
    void changeColor_indicators(QPushButton* button, QString str);
    int changeColor(QPushButton* button, QString* button_color1);
public:

    void writeSerial(QString msg);
    void initmap();

};


#endif // CONTOL_WINDOW_H
