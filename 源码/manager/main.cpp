#include "widget.h"
#include <QApplication>
#include "connection.h"
#include "logindialog.h"
#include "port.h"

extern "C"
{
    #include "ReadDLL.h"
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection()||!createXml())return 0;
    Widget w;
    LoginDialog dlg;

    if(dlg.exec()==QDialog::Accepted){
        w.show();
        return a.exec();
    }else{
        return 0;
    }
}
