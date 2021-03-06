/********************************************************************************
** Form generated from reading UI file 'GeneralSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETTINGWIDGET_H
#define UI_GENERALSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralSettingWidget
{
public:
    QLineEdit *savePathLineEdit;
    QPushButton *searchPathButton;
    QPushButton *openDirectoryButton;

    void setupUi(QWidget *GeneralSettingWidget)
    {
        if (GeneralSettingWidget->objectName().isEmpty())
            GeneralSettingWidget->setObjectName(QStringLiteral("GeneralSettingWidget"));
        GeneralSettingWidget->resize(706, 558);
        savePathLineEdit = new QLineEdit(GeneralSettingWidget);
        savePathLineEdit->setObjectName(QStringLiteral("savePathLineEdit"));
        savePathLineEdit->setGeometry(QRect(30, 70, 311, 31));
        savePathLineEdit->setReadOnly(true);
        searchPathButton = new QPushButton(GeneralSettingWidget);
        searchPathButton->setObjectName(QStringLiteral("searchPathButton"));
        searchPathButton->setGeometry(QRect(350, 70, 93, 28));
        openDirectoryButton = new QPushButton(GeneralSettingWidget);
        openDirectoryButton->setObjectName(QStringLiteral("openDirectoryButton"));
        openDirectoryButton->setGeometry(QRect(450, 70, 93, 28));

        retranslateUi(GeneralSettingWidget);

        QMetaObject::connectSlotsByName(GeneralSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *GeneralSettingWidget)
    {
        GeneralSettingWidget->setWindowTitle(QApplication::translate("GeneralSettingWidget", "Form", nullptr));
        searchPathButton->setText(QApplication::translate("GeneralSettingWidget", "...", nullptr));
        openDirectoryButton->setText(QApplication::translate("GeneralSettingWidget", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralSettingWidget: public Ui_GeneralSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSETTINGWIDGET_H
