/********************************************************************************
** Form generated from reading UI file 'port.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORT_H
#define UI_PORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_port
{
public:
    QComboBox *cbPortName;
    QComboBox *cbBaudrate;
    QPushButton *btnOpenSerial;
    QPushButton *btnclose;
    QTextBrowser *uidview;
    QPushButton *btnadd;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *readsell;
    QLabel *label_4;
    QTextBrowser *sell;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *port)
    {
        if (port->objectName().isEmpty())
            port->setObjectName(QStringLiteral("port"));
        port->resize(515, 497);
        cbPortName = new QComboBox(port);
        cbPortName->setObjectName(QStringLiteral("cbPortName"));
        cbPortName->setGeometry(QRect(100, 90, 111, 22));
        cbBaudrate = new QComboBox(port);
        cbBaudrate->setObjectName(QStringLiteral("cbBaudrate"));
        cbBaudrate->setGeometry(QRect(340, 90, 111, 22));
        btnOpenSerial = new QPushButton(port);
        btnOpenSerial->setObjectName(QStringLiteral("btnOpenSerial"));
        btnOpenSerial->setGeometry(QRect(50, 170, 101, 28));
        btnclose = new QPushButton(port);
        btnclose->setObjectName(QStringLiteral("btnclose"));
        btnclose->setGeometry(QRect(410, 460, 93, 28));
        uidview = new QTextBrowser(port);
        uidview->setObjectName(QStringLiteral("uidview"));
        uidview->setGeometry(QRect(200, 170, 291, 71));
        QFont font;
        font.setPointSize(13);
        uidview->setFont(font);
        btnadd = new QPushButton(port);
        btnadd->setObjectName(QStringLiteral("btnadd"));
        btnadd->setGeometry(QRect(50, 210, 101, 31));
        label_2 = new QLabel(port);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 90, 72, 15));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(port);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 90, 72, 15));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(port);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 50, 151, 21));
        QFont font2;
        font2.setPointSize(12);
        label_3->setFont(font2);
        readsell = new QPushButton(port);
        readsell->setObjectName(QStringLiteral("readsell"));
        readsell->setGeometry(QRect(50, 300, 111, 31));
        label_4 = new QLabel(port);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 140, 131, 21));
        QFont font3;
        font3.setPointSize(11);
        label_4->setFont(font3);
        sell = new QTextBrowser(port);
        sell->setObjectName(QStringLiteral("sell"));
        sell->setGeometry(QRect(200, 300, 181, 41));
        QFont font4;
        font4.setPointSize(20);
        sell->setFont(font4);
        label_5 = new QLabel(port);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 280, 81, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(port);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 310, 61, 21));

        retranslateUi(port);

        QMetaObject::connectSlotsByName(port);
    } // setupUi

    void retranslateUi(QDialog *port)
    {
        port->setWindowTitle(QApplication::translate("port", "\347\216\213\344\276\257\346\261\275\350\275\246\351\224\200\345\224\256\347\263\273\347\273\237", Q_NULLPTR));
        cbBaudrate->clear();
        cbBaudrate->insertItems(0, QStringList()
         << QApplication::translate("port", "1200", Q_NULLPTR)
         << QApplication::translate("port", "2400", Q_NULLPTR)
         << QApplication::translate("port", "4800", Q_NULLPTR)
         << QApplication::translate("port", "9600", Q_NULLPTR)
         << QApplication::translate("port", "14400", Q_NULLPTR)
         << QApplication::translate("port", "19200", Q_NULLPTR)
         << QApplication::translate("port", "38400", Q_NULLPTR)
         << QApplication::translate("port", "43000", Q_NULLPTR)
         << QApplication::translate("port", "57600", Q_NULLPTR)
         << QApplication::translate("port", "76800", Q_NULLPTR)
         << QApplication::translate("port", "115200", Q_NULLPTR)
         << QApplication::translate("port", "128000", Q_NULLPTR)
         << QApplication::translate("port", "230400", Q_NULLPTR)
         << QApplication::translate("port", "256000", Q_NULLPTR)
         << QApplication::translate("port", "460800", Q_NULLPTR)
         << QApplication::translate("port", "921600", Q_NULLPTR)
         << QApplication::translate("port", "1382400", Q_NULLPTR)
        );
        cbBaudrate->setCurrentText(QApplication::translate("port", "115200", Q_NULLPTR));
        btnOpenSerial->setText(QApplication::translate("port", "\345\224\256\350\275\246", Q_NULLPTR));
        btnclose->setText(QApplication::translate("port", "\345\205\263\351\227\255", Q_NULLPTR));
        btnadd->setText(QApplication::translate("port", "\346\267\273\345\212\240\346\226\260\347\224\250\346\210\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("port", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label->setText(QApplication::translate("port", "COM", Q_NULLPTR));
        label_3->setText(QApplication::translate("port", "\350\257\267\345\205\210\351\200\211\346\213\251\344\270\262\345\217\243\345\217\202\346\225\260\357\274\232", Q_NULLPTR));
        readsell->setText(QApplication::translate("port", "\350\257\273\345\217\226\351\224\200\345\224\256\344\270\232\347\273\251", Q_NULLPTR));
        label_4->setText(QApplication::translate("port", "\345\275\223\345\211\215\344\273\244\347\211\214\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("port", "\351\224\200\345\224\256\344\270\232\347\273\251\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("port", "\344\270\207\345\205\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class port: public Ui_port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORT_H
