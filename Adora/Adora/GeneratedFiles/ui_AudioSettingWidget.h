/********************************************************************************
** Form generated from reading UI file 'AudioSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOSETTINGWIDGET_H
#define UI_AUDIOSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioSettingWidget
{
public:
    QLabel *audioDeviceLabel;
    QLabel *audioVolumeLabel;
    QLabel *audioDevice2Label;
    QLabel *audioVolume2Label;
    QSlider *audioVolumeSlider;
    QSlider *audioVolume2Slider;

    void setupUi(QWidget *AudioSettingWidget)
    {
        if (AudioSettingWidget->objectName().isEmpty())
            AudioSettingWidget->setObjectName(QStringLiteral("AudioSettingWidget"));
        AudioSettingWidget->resize(554, 544);
        audioDeviceLabel = new QLabel(AudioSettingWidget);
        audioDeviceLabel->setObjectName(QStringLiteral("audioDeviceLabel"));
        audioDeviceLabel->setGeometry(QRect(40, 40, 64, 15));
        audioVolumeLabel = new QLabel(AudioSettingWidget);
        audioVolumeLabel->setObjectName(QStringLiteral("audioVolumeLabel"));
        audioVolumeLabel->setGeometry(QRect(40, 70, 64, 15));
        audioDevice2Label = new QLabel(AudioSettingWidget);
        audioDevice2Label->setObjectName(QStringLiteral("audioDevice2Label"));
        audioDevice2Label->setGeometry(QRect(40, 120, 64, 15));
        audioVolume2Label = new QLabel(AudioSettingWidget);
        audioVolume2Label->setObjectName(QStringLiteral("audioVolume2Label"));
        audioVolume2Label->setGeometry(QRect(40, 160, 64, 15));
        audioVolumeSlider = new QSlider(AudioSettingWidget);
        audioVolumeSlider->setObjectName(QStringLiteral("audioVolumeSlider"));
        audioVolumeSlider->setGeometry(QRect(160, 70, 160, 22));
        audioVolumeSlider->setMaximum(100);
        audioVolumeSlider->setOrientation(Qt::Horizontal);
        audioVolume2Slider = new QSlider(AudioSettingWidget);
        audioVolume2Slider->setObjectName(QStringLiteral("audioVolume2Slider"));
        audioVolume2Slider->setGeometry(QRect(160, 160, 160, 22));
        audioVolume2Slider->setMaximum(100);
        audioVolume2Slider->setOrientation(Qt::Horizontal);

        retranslateUi(AudioSettingWidget);

        QMetaObject::connectSlotsByName(AudioSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *AudioSettingWidget)
    {
        AudioSettingWidget->setWindowTitle(QApplication::translate("AudioSettingWidget", "Form", nullptr));
        audioDeviceLabel->setText(QApplication::translate("AudioSettingWidget", "audio", nullptr));
        audioVolumeLabel->setText(QApplication::translate("AudioSettingWidget", "volume", nullptr));
        audioDevice2Label->setText(QApplication::translate("AudioSettingWidget", "audio2", nullptr));
        audioVolume2Label->setText(QApplication::translate("AudioSettingWidget", "volume2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioSettingWidget: public Ui_AudioSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOSETTINGWIDGET_H
