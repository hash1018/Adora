/********************************************************************************
** Form generated from reading UI file 'TimeLimitSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMELIMITSETTINGWIDGET_H
#define UI_TIMELIMITSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeLimitSettingWidget
{
public:
    QCheckBox *useTimeLimitCheckBox;
    QSpinBox *hourSpinBox;
    QSpinBox *minuteSpinBox;
    QSpinBox *secondSpinBox;

    void setupUi(QWidget *TimeLimitSettingWidget)
    {
        if (TimeLimitSettingWidget->objectName().isEmpty())
            TimeLimitSettingWidget->setObjectName(QStringLiteral("TimeLimitSettingWidget"));
        TimeLimitSettingWidget->resize(540, 431);
        useTimeLimitCheckBox = new QCheckBox(TimeLimitSettingWidget);
        useTimeLimitCheckBox->setObjectName(QStringLiteral("useTimeLimitCheckBox"));
        useTimeLimitCheckBox->setGeometry(QRect(30, 30, 191, 19));
        hourSpinBox = new QSpinBox(TimeLimitSettingWidget);
        hourSpinBox->setObjectName(QStringLiteral("hourSpinBox"));
        hourSpinBox->setGeometry(QRect(30, 70, 51, 22));
        hourSpinBox->setMaximum(99);
        minuteSpinBox = new QSpinBox(TimeLimitSettingWidget);
        minuteSpinBox->setObjectName(QStringLiteral("minuteSpinBox"));
        minuteSpinBox->setGeometry(QRect(110, 70, 51, 22));
        minuteSpinBox->setMaximum(59);
        secondSpinBox = new QSpinBox(TimeLimitSettingWidget);
        secondSpinBox->setObjectName(QStringLiteral("secondSpinBox"));
        secondSpinBox->setGeometry(QRect(180, 70, 51, 22));
        secondSpinBox->setMaximum(59);

        retranslateUi(TimeLimitSettingWidget);

        QMetaObject::connectSlotsByName(TimeLimitSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *TimeLimitSettingWidget)
    {
        TimeLimitSettingWidget->setWindowTitle(QApplication::translate("TimeLimitSettingWidget", "Form", nullptr));
        useTimeLimitCheckBox->setText(QApplication::translate("TimeLimitSettingWidget", "useTimeLimit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeLimitSettingWidget: public Ui_TimeLimitSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMELIMITSETTINGWIDGET_H
