/********************************************************************************
** Form generated from reading UI file 'LicenseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENSEWIDGET_H
#define UI_LICENSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LicenseWidget
{
public:
    QLabel *licenseLabel;
    QTextEdit *licenseTextEdit;

    void setupUi(QWidget *LicenseWidget)
    {
        if (LicenseWidget->objectName().isEmpty())
            LicenseWidget->setObjectName(QStringLiteral("LicenseWidget"));
        LicenseWidget->resize(716, 300);
        licenseLabel = new QLabel(LicenseWidget);
        licenseLabel->setObjectName(QStringLiteral("licenseLabel"));
        licenseLabel->setGeometry(QRect(40, 10, 64, 15));
        licenseTextEdit = new QTextEdit(LicenseWidget);
        licenseTextEdit->setObjectName(QStringLiteral("licenseTextEdit"));
        licenseTextEdit->setGeometry(QRect(20, 50, 481, 231));
        licenseTextEdit->setReadOnly(true);

        retranslateUi(LicenseWidget);

        QMetaObject::connectSlotsByName(LicenseWidget);
    } // setupUi

    void retranslateUi(QWidget *LicenseWidget)
    {
        LicenseWidget->setWindowTitle(QApplication::translate("LicenseWidget", "Form", nullptr));
        licenseLabel->setText(QApplication::translate("LicenseWidget", "license", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LicenseWidget: public Ui_LicenseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEWIDGET_H
