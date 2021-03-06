/********************************************************************************
** Form generated from reading UI file 'LanguageSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGESETTINGWIDGET_H
#define UI_LANGUAGESETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LanguageSettingWidget
{
public:
    QComboBox *languageComboBox;
    QPushButton *changeButton;

    void setupUi(QWidget *LanguageSettingWidget)
    {
        if (LanguageSettingWidget->objectName().isEmpty())
            LanguageSettingWidget->setObjectName(QStringLiteral("LanguageSettingWidget"));
        LanguageSettingWidget->resize(400, 300);
        languageComboBox = new QComboBox(LanguageSettingWidget);
        languageComboBox->setObjectName(QStringLiteral("languageComboBox"));
        languageComboBox->setGeometry(QRect(170, 140, 141, 31));
        changeButton = new QPushButton(LanguageSettingWidget);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        changeButton->setGeometry(QRect(170, 210, 93, 28));

        retranslateUi(LanguageSettingWidget);

        QMetaObject::connectSlotsByName(LanguageSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *LanguageSettingWidget)
    {
        LanguageSettingWidget->setWindowTitle(QApplication::translate("LanguageSettingWidget", "Form", nullptr));
        changeButton->setText(QApplication::translate("LanguageSettingWidget", "change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LanguageSettingWidget: public Ui_LanguageSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGESETTINGWIDGET_H
