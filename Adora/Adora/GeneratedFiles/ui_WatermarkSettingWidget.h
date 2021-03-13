/********************************************************************************
** Form generated from reading UI file 'WatermarkSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATERMARKSETTINGWIDGET_H
#define UI_WATERMARKSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WatermarkSettingWidget
{
public:
    QCheckBox *useWatermarkCheckBox;
    QLabel *imagePathLabel;
    QLineEdit *imagePathLineEdit;
    QPushButton *openExplorerButton;
    QLabel *opacityLabel;
    QSpinBox *opacitySpinBox;
    QGroupBox *watermarkLayoutGroupBox;
    QRadioButton *topLeftRadioButton;
    QRadioButton *topCenterRadioButton;
    QRadioButton *topRightRadioButton;
    QRadioButton *centerLeftRadioButton;
    QRadioButton *centerCenterRadioButton;
    QRadioButton *centerRightRadioButton;
    QRadioButton *bottomLeftRadioButton;
    QRadioButton *bottomCenterRadioButton;
    QRadioButton *bottomRightRadioButton;

    void setupUi(QWidget *WatermarkSettingWidget)
    {
        if (WatermarkSettingWidget->objectName().isEmpty())
            WatermarkSettingWidget->setObjectName(QStringLiteral("WatermarkSettingWidget"));
        WatermarkSettingWidget->resize(492, 300);
        useWatermarkCheckBox = new QCheckBox(WatermarkSettingWidget);
        useWatermarkCheckBox->setObjectName(QStringLiteral("useWatermarkCheckBox"));
        useWatermarkCheckBox->setGeometry(QRect(30, 20, 131, 19));
        imagePathLabel = new QLabel(WatermarkSettingWidget);
        imagePathLabel->setObjectName(QStringLiteral("imagePathLabel"));
        imagePathLabel->setGeometry(QRect(30, 60, 101, 16));
        imagePathLineEdit = new QLineEdit(WatermarkSettingWidget);
        imagePathLineEdit->setObjectName(QStringLiteral("imagePathLineEdit"));
        imagePathLineEdit->setGeometry(QRect(30, 90, 271, 31));
        imagePathLineEdit->setReadOnly(true);
        openExplorerButton = new QPushButton(WatermarkSettingWidget);
        openExplorerButton->setObjectName(QStringLiteral("openExplorerButton"));
        openExplorerButton->setGeometry(QRect(310, 90, 31, 28));
        opacityLabel = new QLabel(WatermarkSettingWidget);
        opacityLabel->setObjectName(QStringLiteral("opacityLabel"));
        opacityLabel->setGeometry(QRect(30, 140, 64, 15));
        opacitySpinBox = new QSpinBox(WatermarkSettingWidget);
        opacitySpinBox->setObjectName(QStringLiteral("opacitySpinBox"));
        opacitySpinBox->setGeometry(QRect(310, 130, 43, 22));
        opacitySpinBox->setMaximum(100);
        watermarkLayoutGroupBox = new QGroupBox(WatermarkSettingWidget);
        watermarkLayoutGroupBox->setObjectName(QStringLiteral("watermarkLayoutGroupBox"));
        watermarkLayoutGroupBox->setGeometry(QRect(30, 170, 261, 111));
        topLeftRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        topLeftRadioButton->setObjectName(QStringLiteral("topLeftRadioButton"));
        topLeftRadioButton->setGeometry(QRect(10, 20, 108, 19));
        topCenterRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        topCenterRadioButton->setObjectName(QStringLiteral("topCenterRadioButton"));
        topCenterRadioButton->setGeometry(QRect(130, 20, 108, 19));
        topRightRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        topRightRadioButton->setObjectName(QStringLiteral("topRightRadioButton"));
        topRightRadioButton->setGeometry(QRect(230, 20, 108, 19));
        centerLeftRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        centerLeftRadioButton->setObjectName(QStringLiteral("centerLeftRadioButton"));
        centerLeftRadioButton->setGeometry(QRect(10, 50, 108, 19));
        centerCenterRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        centerCenterRadioButton->setObjectName(QStringLiteral("centerCenterRadioButton"));
        centerCenterRadioButton->setGeometry(QRect(130, 50, 108, 19));
        centerRightRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        centerRightRadioButton->setObjectName(QStringLiteral("centerRightRadioButton"));
        centerRightRadioButton->setGeometry(QRect(230, 50, 108, 19));
        bottomLeftRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        bottomLeftRadioButton->setObjectName(QStringLiteral("bottomLeftRadioButton"));
        bottomLeftRadioButton->setGeometry(QRect(10, 80, 108, 19));
        bottomCenterRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        bottomCenterRadioButton->setObjectName(QStringLiteral("bottomCenterRadioButton"));
        bottomCenterRadioButton->setGeometry(QRect(130, 80, 108, 19));
        bottomRightRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        bottomRightRadioButton->setObjectName(QStringLiteral("bottomRightRadioButton"));
        bottomRightRadioButton->setGeometry(QRect(230, 80, 108, 19));

        retranslateUi(WatermarkSettingWidget);

        QMetaObject::connectSlotsByName(WatermarkSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *WatermarkSettingWidget)
    {
        WatermarkSettingWidget->setWindowTitle(QApplication::translate("WatermarkSettingWidget", "Form", nullptr));
        useWatermarkCheckBox->setText(QApplication::translate("WatermarkSettingWidget", "useWatermark", nullptr));
        imagePathLabel->setText(QApplication::translate("WatermarkSettingWidget", "Image Path", nullptr));
        openExplorerButton->setText(QApplication::translate("WatermarkSettingWidget", "...", nullptr));
        opacityLabel->setText(QApplication::translate("WatermarkSettingWidget", "opacity", nullptr));
        watermarkLayoutGroupBox->setTitle(QApplication::translate("WatermarkSettingWidget", "layout", nullptr));
        topLeftRadioButton->setText(QString());
        topCenterRadioButton->setText(QString());
        topRightRadioButton->setText(QString());
        centerLeftRadioButton->setText(QString());
        centerCenterRadioButton->setText(QString());
        centerRightRadioButton->setText(QString());
        bottomLeftRadioButton->setText(QString());
        bottomCenterRadioButton->setText(QString());
        bottomRightRadioButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WatermarkSettingWidget: public Ui_WatermarkSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATERMARKSETTINGWIDGET_H
