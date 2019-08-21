/********************************************************************************
** Form generated from reading UI file 'dayin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYIN_H
#define UI_DAYIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dayin
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *dayin)
    {
        if (dayin->objectName().isEmpty())
            dayin->setObjectName(QStringLiteral("dayin"));
        dayin->resize(268, 494);
        verticalLayout = new QVBoxLayout(dayin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(dayin);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(dayin);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dayin);

        QMetaObject::connectSlotsByName(dayin);
    } // setupUi

    void retranslateUi(QWidget *dayin)
    {
        dayin->setWindowTitle(QApplication::translate("dayin", "Form", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("dayin", "\346\270\205\347\251\272\350\241\250\346\240\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dayin: public Ui_dayin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYIN_H
