#ifndef PORT_H
#define PORT_H

#include <QDialog>
extern "C"
{
    #include "ReadDLL.h"
}
namespace Ui {
class port;
}

class port : public QDialog
{
    Q_OBJECT

public:
    explicit port(int t,QWidget *parent = 0);
    ~port();
public:
    bool flag;//存储读卡状态
    BYTE uuid[8];
    BYTE readid[8];
    int totalofport;
private:
    QString id;//暂存id号
    BYTE read[4];
    BYTE write[4];
    QByteArray temp_re;

private slots:
    void on_btnOpenSerial_clicked();

    void on_btnadd_clicked();

    void on_btnclose_clicked();

    void on_readsell_clicked();

private:
    Ui::port *ui;
};

#endif // PORT_H
