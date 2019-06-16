#include "port.h"
#include "ui_port.h"
#include <QtSql>
#include <QDebug>
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/qserialport.h"
#include "QSerialPortInfo"
#include "QMessageBox"
#include "string.h"
#include "widget.h"

extern "C"
{
    #include "ReadDLL.h"
}

port::port(int t, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::port)
{
    ui->setupUi(this);
    ui->cbPortName->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->cbPortName->addItem(info.portName());
    }
    flag=0;
    id="0000000000000000";
    totalofport=t;




}

port::~port()
{
    delete ui;
}

void port::on_btnOpenSerial_clicked()//打开串口
{
        QSqlQuery query;
        char com[5]={0};
        QByteArray temp=ui->cbPortName->currentText().toLocal8Bit();
        for(int i=0;i<4;i++)
        {
            com[i]=temp[i];
        }
        int ret=0;
        qDebug()<<ui->cbBaudrate->currentText().toInt()<<endl;
        qDebug()<<com<<endl;
        qDebug()<<temp<<endl;
        ret=SetCom(com,ui->cbBaudrate->currentText().toInt(),8,"NONE","1");
        //ret=SetCom(com,115200,8,"NONE","1");
        qDebug()<<"ret of SetCom "<<ret<<endl;
        if(ret==0)
        {
            BYTE struid[8]={0};
            DWORD tagCount=0;
            ret=Inventory(struid,0x27,tagCount);
            qDebug()<<struid[7]<<endl;
            for(int i=0;i<8;i++)
            {
            uuid[i]=struid[i];
            readid[i]=struid[i];
            }
            qDebug()<<"ret of Inventory "<<ret<<endl;
            if(ret==0)
            {
                QByteArray temp;
                temp.resize(8);
                for(int i=0;i<8;i++)
                {
                    temp[i]=struid[i];
                }

                QString uid=temp.toHex();
                query.exec(QString("select * from uid where uidName='%1'").arg(uid));


                //以下代码应放在构造函数

                 qDebug()<<"read1 status "<<ReadSingleBlock(struid,0x06,0x04,read)<<endl;//读取当前销售业绩
                int current=0;
                int rll=read[3]%16;
                int rlh=read[3]/16;
                int rhl=read[2]%16;
                int rhh=read[2]/16;
                current=rhh*1000+rhl*100+rlh*10+rll;//将读取到的16进制数转换为int
                qDebug()<<"current:"<<current<<endl;

                int newsum=current+totalofport;//累加销售业绩=读卡读到当前的+本次的

                int low=newsum%100;//将int转换为“16进制”
                int ll=low%10;
                int lh=low/10;
                int high=newsum/100;
                int hl=high%10;
                int hh=high/10;
                write[0]=0x00;
                write[1]=0x00;
                write[2]=(hh*16+hl);//写入
                write[3]=(lh*16+ll);
                qDebug("write 3 Hex: %x",write[3]);
                qDebug("write 2 Hex: %x",write[2]);

                qDebug()<<"write status "<<WriteSingleBlock(struid,0x06,0x04,write)<<endl;



                int numberOfRows = 0;
                if(query.last())
                {
                    numberOfRows =  query.at() + 1;
                    query.first();
                    query.previous();
                }


                if(numberOfRows>=1)
                {
                    flag=true;

                    CloseCom();
                    QDialog::accept();
                }
                else
                {
                    CloseCom();
                    id=uid;
                    ui->uidview->setText(uid);
                    ui->uidview->append("您的令牌未注册，请先添加用户！");
                }
            }
            else
            {
                CloseCom();
                id="0000000000000000";
                QMessageBox::about(NULL,"提示","读取标签错误");
            }
        }
        else
        {
            id="0000000000000000";
            QMessageBox::about(NULL,"提示","打开串口出错，请检查");
        }

        //ReadSingleBlock(srpt.uuid,0x10,0x04,read);
        //int re=read;//Read转int
        //int sell=ui->sellSumLineEdit->text().toInt();//读取本次销售额
       // write=sell+re;

       // qDebug()<<readid[7]<<endl;
        //qDebug()<<WriteSingleBlock(readid,0x06,0x04,write)<<endl;


        ui->cbPortName->clear();
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            ui->cbPortName->addItem(info.portName());
        }

}

void port::on_btnadd_clicked()//添加新用户
{
        QSqlQuery query;
        if(id==QString("0000000000000000"))
        {

            QMessageBox::about(NULL,"提示","请放上你的id卡或检查硬件串口是否有故障");
        }
        else
        {
            query.exec(QString("select * from uid where uidName='%1'").arg(id));

            //query.exec(QString("select * from uid where uidName='e004015081655172'"));
            int numberOfRows = 0;
            if(query.last())
            {
                numberOfRows =  query.at() + 1;
                query.first();
                query.previous();
            }

            qDebug()<<numberOfRows<<endl;
            if(numberOfRows>=1)
            {
                QMessageBox::about(NULL,"提示","该用户已存在，不用重复添加");
            }
            else
            {
                QMessageBox::about(NULL,"提示","增加该新用户");
                query.exec(QString("insert into uid values('%1')").arg(id));
            }
        }

}

void port::on_btnclose_clicked()//关闭读卡界面
{
    QDialog::accept();
}

void port::on_readsell_clicked()
{
    qDebug()<<"total:"<<totalofport<<endl;
    QSqlQuery query;
    char com[5]={0};
    QByteArray temp=ui->cbPortName->currentText().toLocal8Bit();
    for(int i=0;i<4;i++)
    {
        com[i]=temp[i];
    }
    int ret=0;
    qDebug()<<ui->cbBaudrate->currentText().toInt()<<endl;
    qDebug()<<com<<endl;
    qDebug()<<temp<<endl;
    ret=SetCom(com,ui->cbBaudrate->currentText().toInt(),8,"NONE","1");
    //ret=SetCom(com,115200,8,"NONE","1");
    qDebug()<<"ret of SetCom "<<ret<<endl;
    if(ret==0)
    {
        BYTE struid[8]={0};
        DWORD tagCount=0;
        ret=Inventory(struid,0x27,tagCount);

        qDebug()<<"read2 status "<<ReadSingleBlock(struid,0x06,0x04,read)<<endl;

        //以下代码用于在界面上显示read值



        QByteArray temp;
        temp.resize(4);
        for(int i=0;i<4;i++)
        {
            temp[i]=read[i];
        }
        QString prt=temp.toHex();
        qDebug()<<prt<<endl;
        ui->sell->setText(prt);



        for(int i=0;i<8;i++)
        {
        uuid[i]=struid[i];
        readid[i]=struid[i];
        }
        qDebug()<<"ret of Inventory "<<ret<<endl;
        if(ret==0)
        {
            QByteArray temp;
            temp.resize(8);
            for(int i=0;i<8;i++)
            {
                temp[i]=struid[i];
            }

            QString uid=temp.toHex();
            query.exec(QString("select * from uid where uidName='%1'").arg(uid));


            int numberOfRows = 0;
            if(query.last())
            {
                numberOfRows =  query.at() + 1;
                query.first();
                query.previous();
            }


            if(numberOfRows>=1)
            {
                flag=true;
                CloseCom();
            }
            else
            {
                CloseCom();
                id=uid;
                ui->uidview->setText(uid);
            }
        }
        else
        {
            CloseCom();
            id="0000000000000000";
            QMessageBox::about(NULL,"提示","读取标签错误");
        }
    }
    else
    {
        id="0000000000000000";
        QMessageBox::about(NULL,"提示","打开串口出错，请检查");
    }

    //ReadSingleBlock(srpt.uuid,0x10,0x04,read);
    //int re=read;//Read转int
    //int sell=ui->sellSumLineEdit->text().toInt();//读取本次销售额
   // write=sell+re;

   // qDebug()<<readid[7]<<endl;
    //qDebug()<<WriteSingleBlock(readid,0x06,0x04,write)<<endl;


    ui->cbPortName->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->cbPortName->addItem(info.portName());
    }




    QString uid_re=temp_re.toHex();
   // ui->dailyList->clear();
    //ui->dailyList->addItem(uid_re);

}
