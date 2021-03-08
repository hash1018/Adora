/********************************************************************************
** Form generated from reading UI file 'VideoSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOSETTINGWIDGET_H
#define UI_VIDEOSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoSettingWidget
{
public:
    QCheckBox *startStopHotkeyCheckBox;
    QCheckBox *pauseResumeHotkeyCheckBox;
    QCheckBox *includeCursorCheckBox;
    QCheckBox *useHwEncoderCheckBox;
    QLabel *fpsLabel;
    QComboBox *fpsComboBox;
    QLabel *label;
    QSpinBox *videoBitrateSpinBox;

    void setupUi(QWidget *VideoSettingWidget)
    {
        if (VideoSettingWidget->objectName().isEmpty())
            VideoSettingWidget->setObjectName(QStringLiteral("VideoSettingWidget"));
        VideoSettingWidget->resize(777, 627);
        startStopHotkeyCheckBox = new QCheckBox(VideoSettingWidget);
        startStopHotkeyCheckBox->setObjectName(QStringLiteral("startStopHotkeyCheckBox"));
        startStopHotkeyCheckBox->setGeometry(QRect(40, 50, 161, 19));
        pauseResumeHotkeyCheckBox = new QCheckBox(VideoSettingWidget);
        pauseResumeHotkeyCheckBox->setObjectName(QStringLiteral("pauseResumeHotkeyCheckBox"));
        pauseResumeHotkeyCheckBox->setGeometry(QRect(40, 90, 171, 19));
        includeCursorCheckBox = new QCheckBox(VideoSettingWidget);
        includeCursorCheckBox->setObjectName(QStringLiteral("includeCursorCheckBox"));
        includeCursorCheckBox->setGeometry(QRect(40, 120, 141, 19));
        useHwEncoderCheckBox = new QCheckBox(VideoSettingWidget);
        useHwEncoderCheckBox->setObjectName(QStringLiteral("useHwEncoderCheckBox"));
        useHwEncoderCheckBox->setGeometry(QRect(40, 160, 151, 19));
        fpsLabel = new QLabel(VideoSettingWidget);
        fpsLabel->setObjectName(QStringLiteral("fpsLabel"));
        fpsLabel->setGeometry(QRect(40, 190, 64, 15));
        fpsComboBox = new QComboBox(VideoSettingWidget);
        fpsComboBox->setObjectName(QStringLiteral("fpsComboBox"));
        fpsComboBox->setGeometry(QRect(230, 190, 121, 22));
        label = new QLabel(VideoSettingWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 220, 101, 16));
        videoBitrateSpinBox = new QSpinBox(VideoSettingWidget);
        videoBitrateSpinBox->setObjectName(QStringLiteral("videoBitrateSpinBox"));
        videoBitrateSpinBox->setGeometry(QRect(230, 220, 121, 22));
        videoBitrateSpinBox->setMinimum(192);
        videoBitrateSpinBox->setMaximum(5000);
        videoBitrateSpinBox->setSingleStep(50);

        retranslateUi(VideoSettingWidget);

        QMetaObject::connectSlotsByName(VideoSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoSettingWidget)
    {
        VideoSettingWidget->setWindowTitle(QApplication::translate("VideoSettingWidget", "Form", nullptr));
        startStopHotkeyCheckBox->setText(QApplication::translate("VideoSettingWidget", "startStopHotkey", nullptr));
        pauseResumeHotkeyCheckBox->setText(QApplication::translate("VideoSettingWidget", "pauseResumeHotkey", nullptr));
        includeCursorCheckBox->setText(QApplication::translate("VideoSettingWidget", "includeCursor", nullptr));
        useHwEncoderCheckBox->setText(QApplication::translate("VideoSettingWidget", "useHwEncoder", nullptr));
        fpsLabel->setText(QApplication::translate("VideoSettingWidget", "fps", nullptr));
        label->setText(QApplication::translate("VideoSettingWidget", "videoBitrate", nullptr));
        videoBitrateSpinBox->setSuffix(QApplication::translate("VideoSettingWidget", "kbps", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoSettingWidget: public Ui_VideoSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOSETTINGWIDGET_H
