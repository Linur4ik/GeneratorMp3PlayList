/********************************************************************************
** Form generated from reading UI file 'window2.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW2_H
#define UI_WINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Window2
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;

    void setupUi(QDialog *Window2)
    {
        if (Window2->objectName().isEmpty())
            Window2->setObjectName(QString::fromUtf8("Window2"));
        Window2->resize(640, 480);
        Window2->setMinimumSize(QSize(640, 480));
        Window2->setMaximumSize(QSize(640, 480));
        pushButton = new QPushButton(Window2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 440, 75, 24));
        pushButton_2 = new QPushButton(Window2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 440, 75, 24));
        comboBox = new QComboBox(Window2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 140, 261, 22));
        label = new QLabel(Window2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 120, 211, 16));
        label_2 = new QLabel(Window2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 180, 221, 16));
        comboBox_2 = new QComboBox(Window2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 200, 261, 22));
        label_3 = new QLabel(Window2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 180, 201, 16));
        comboBox_3 = new QComboBox(Window2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(80, 200, 261, 22));
        checkBox = new QCheckBox(Window2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(80, 240, 351, 20));
        checkBox_2 = new QCheckBox(Window2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(80, 240, 261, 20));
        pushButton_2->raise();
        pushButton->raise();
        comboBox->raise();
        label->raise();
        label_2->raise();
        comboBox_2->raise();
        label_3->raise();
        comboBox_3->raise();
        checkBox->raise();
        checkBox_2->raise();

        retranslateUi(Window2);
        QObject::connect(pushButton_2, &QPushButton::clicked, pushButton_2, qOverload<>(&QPushButton::showMenu));

        QMetaObject::connectSlotsByName(Window2);
    } // setupUi

    void retranslateUi(QDialog *Window2)
    {
        Window2->setWindowTitle(QCoreApplication::translate("Window2", "Generator PlayList", nullptr));
        pushButton->setText(QCoreApplication::translate("Window2", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Window2", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Window2", "\320\221\320\265\320\267 \321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Window2", "\320\226\320\260\320\275\321\200", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Window2", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));

        label->setText(QCoreApplication::translate("Window2", "\320\236\321\202\320\276\320\261\321\200\320\260\321\202\321\214 \320\274\321\203\320\267\321\213\320\272\320\276 \320\277\320\276:", nullptr));
        label_2->setText(QCoreApplication::translate("Window2", "\320\236\321\202\320\276\320\261\321\200\320\260\321\202\321\214 \320\270\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\320\265\320\271:", nullptr));
        label_3->setText(QCoreApplication::translate("Window2", "\320\236\321\202\320\276\320\261\321\200\320\260\321\202\321\214 \320\266\320\260\320\275\321\200\321\213:", nullptr));
        checkBox->setText(QCoreApplication::translate("Window2", "\320\236\321\202\320\276\320\261\321\200\320\260\321\202\321\214 \321\202\320\276\320\273\321\214\320\272\320\276 \321\215\321\202\320\270\321\205 \320\270\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\320\265\320\271", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Window2", "\320\236\321\202\320\276\320\261\321\200\320\260\321\202\321\214 \321\202\320\276\320\273\321\214\320\272\320\276 \320\277\320\276 \321\215\321\202\320\270\320\274 \320\266\320\260\320\275\321\200\320\260\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window2: public Ui_Window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H
