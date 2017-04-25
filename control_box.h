#ifndef CONTOL_WINDOW_H
#define CONTOL_WINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>

namespace Ui {
class Contol_window;
}

class Contol_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Contol_window(QWidget *parent = 0);
    ~Contol_window();


private slots:
    void on_OV_Button_clicked();
    void initControls();


    void on_CC_READY_pushButton_clicked();

    void on_OCD_pushButton_clicked();

    void on_LOAD_PRESENT_pushButton_clicked();

    void on_UV_pushButton_clicked();

    void on_SCD_pushButton_clicked();

    void on_ADC_EN_pushButton_clicked();

    void on_DSG_ON_pushButton_clicked();

    void on_CHG_ON_pushButton_clicked();

    void on_DEVICE_X_READY_pushButton_clicked();

    void on_TEMP_SEL_pushButton_clicked();

    void on_CC_pushButton_clicked();

    void on_DELAY_DIS_pushButton_clicked();

    void on_OVERD_ALERT_pushButton_clicked();

    void on_RSNS_pushButton_clicked();

private:
    Ui::Contol_window *ui;
    QString button_color="green";
//    void initgui();
    int changeColor(QPushButton* button, QString* button_color1);


#endif // CONTOL_WINDOW_H
