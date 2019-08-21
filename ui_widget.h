/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 116, 48, 16));
        doubleSpinBox_1 = new QDoubleSpinBox(Widget);
        doubleSpinBox_1->setObjectName(QStringLiteral("doubleSpinBox_1"));
        doubleSpinBox_1->setGeometry(QRect(180, 90, 58, 20));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 180, 75, 23));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 180, 75, 23));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 145, 48, 16));
        doubleSpinBox_2 = new QDoubleSpinBox(Widget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(90, 119, 58, 20));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(91, 86, 48, 16));
        doubleSpinBox = new QDoubleSpinBox(Widget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(91, 60, 58, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\350\241\245\345\201\277\345\210\232\345\272\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\346\240\241\345\207\206", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\346\265\213\351\207\217\345\210\232\345\272\246", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\240\207\345\207\206\345\210\232\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
