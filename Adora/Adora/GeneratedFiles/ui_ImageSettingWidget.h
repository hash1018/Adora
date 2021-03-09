/********************************************************************************
** Form generated from reading UI file 'ImageSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESETTINGWIDGET_H
#define UI_IMAGESETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSettingWidget
{
public:
    QCheckBox *includeCursorCheckBox;
    QLabel *imageFormatLabel;
    QComboBox *imageFormatComboBox;
    QCheckBox *imageCaptureHotkeyCheckBox;

    void setupUi(QWidget *ImageSettingWidget)
    {
        if (ImageSettingWidget->objectName().isEmpty())
            ImageSettingWidget->setObjectName(QStringLiteral("ImageSettingWidget"));
        ImageSettingWidget->resize(400, 300);
        includeCursorCheckBox = new QCheckBox(ImageSettingWidget);
        includeCursorCheckBox->setObjectName(QStringLiteral("includeCursorCheckBox"));
        includeCursorCheckBox->setGeometry(QRect(30, 30, 161, 19));
        imageFormatLabel = new QLabel(ImageSettingWidget);
        imageFormatLabel->setObjectName(QStringLiteral("imageFormatLabel"));
        imageFormatLabel->setGeometry(QRect(30, 60, 101, 16));
        imageFormatComboBox = new QComboBox(ImageSettingWidget);
        imageFormatComboBox->setObjectName(QStringLiteral("imageFormatComboBox"));
        imageFormatComboBox->setGeometry(QRect(190, 60, 171, 31));
        imageCaptureHotkeyCheckBox = new QCheckBox(ImageSettingWidget);
        imageCaptureHotkeyCheckBox->setObjectName(QStringLiteral("imageCaptureHotkeyCheckBox"));
        imageCaptureHotkeyCheckBox->setGeometry(QRect(30, 100, 171, 19));

        retranslateUi(ImageSettingWidget);

        QMetaObject::connectSlotsByName(ImageSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageSettingWidget)
    {
        ImageSettingWidget->setWindowTitle(QApplication::translate("ImageSettingWidget", "Form", nullptr));
        includeCursorCheckBox->setText(QApplication::translate("ImageSettingWidget", "includeCursor", nullptr));
        imageFormatLabel->setText(QApplication::translate("ImageSettingWidget", "imageFormat", nullptr));
        imageCaptureHotkeyCheckBox->setText(QApplication::translate("ImageSettingWidget", "imageCaptureHotkey", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSettingWidget: public Ui_ImageSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESETTINGWIDGET_H
