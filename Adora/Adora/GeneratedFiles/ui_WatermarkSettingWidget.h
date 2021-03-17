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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QRadioButton *topLeftRadioButton;
    QRadioButton *topCenterRadioButton;
    QRadioButton *topRightRadioButton;
    QRadioButton *centerLeftRadioButton;
    QRadioButton *centerCenterRadioButton;
    QRadioButton *centerRightRadioButton;
    QRadioButton *bottomLeftRadioButton;
    QRadioButton *bottomCenterRadioButton;
    QRadioButton *bottomRightRadioButton;
    QLabel *watermarkLabel;

    void setupUi(QWidget *WatermarkSettingWidget)
    {
        if (WatermarkSettingWidget->objectName().isEmpty())
            WatermarkSettingWidget->setObjectName(QStringLiteral("WatermarkSettingWidget"));
        WatermarkSettingWidget->resize(700, 756);
        WatermarkSettingWidget->setStyleSheet(QLatin1String("QPushButton#openExplorerButton {\n"
"    border-radius:5px;\n"
"    background-color: #A0A0A0;\n"
"    color: #FFFFFF;\n"
"\n"
"}\n"
"\n"
"QPushButton#openExplorerButton:hover{\n"
"     background-color:#B5B5B5;\n"
"}"));
        useWatermarkCheckBox = new QCheckBox(WatermarkSettingWidget);
        useWatermarkCheckBox->setObjectName(QStringLiteral("useWatermarkCheckBox"));
        useWatermarkCheckBox->setGeometry(QRect(48, 84, 150, 36));
        useWatermarkCheckBox->setMinimumSize(QSize(150, 36));
        useWatermarkCheckBox->setMaximumSize(QSize(150, 36));
        imagePathLabel = new QLabel(WatermarkSettingWidget);
        imagePathLabel->setObjectName(QStringLiteral("imagePathLabel"));
        imagePathLabel->setGeometry(QRect(48, 130, 100, 36));
        imagePathLabel->setMinimumSize(QSize(100, 36));
        imagePathLabel->setMaximumSize(QSize(100, 36));
        imagePathLineEdit = new QLineEdit(WatermarkSettingWidget);
        imagePathLineEdit->setObjectName(QStringLiteral("imagePathLineEdit"));
        imagePathLineEdit->setGeometry(QRect(47, 166, 360, 36));
        imagePathLineEdit->setMinimumSize(QSize(360, 36));
        imagePathLineEdit->setMaximumSize(QSize(360, 36));
        imagePathLineEdit->setReadOnly(true);
        openExplorerButton = new QPushButton(WatermarkSettingWidget);
        openExplorerButton->setObjectName(QStringLiteral("openExplorerButton"));
        openExplorerButton->setGeometry(QRect(419, 166, 50, 36));
        openExplorerButton->setMinimumSize(QSize(50, 36));
        openExplorerButton->setMaximumSize(QSize(50, 36));
        opacityLabel = new QLabel(WatermarkSettingWidget);
        opacityLabel->setObjectName(QStringLiteral("opacityLabel"));
        opacityLabel->setGeometry(QRect(48, 214, 100, 36));
        opacityLabel->setMinimumSize(QSize(100, 36));
        opacityLabel->setMaximumSize(QSize(100, 36));
        opacitySpinBox = new QSpinBox(WatermarkSettingWidget);
        opacitySpinBox->setObjectName(QStringLiteral("opacitySpinBox"));
        opacitySpinBox->setGeometry(QRect(48, 250, 80, 36));
        opacitySpinBox->setMinimumSize(QSize(80, 36));
        opacitySpinBox->setMaximumSize(QSize(80, 36));
        opacitySpinBox->setMaximum(100);
        watermarkLayoutGroupBox = new QGroupBox(WatermarkSettingWidget);
        watermarkLayoutGroupBox->setObjectName(QStringLiteral("watermarkLayoutGroupBox"));
        watermarkLayoutGroupBox->setGeometry(QRect(48, 298, 232, 160));
        watermarkLayoutGroupBox->setMinimumSize(QSize(232, 160));
        watermarkLayoutGroupBox->setMaximumSize(QSize(232, 160));
        gridLayout = new QGridLayout(watermarkLayoutGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        topLeftRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        topLeftRadioButton->setObjectName(QStringLiteral("topLeftRadioButton"));
        topLeftRadioButton->setMinimumSize(QSize(20, 20));
        topLeftRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(topLeftRadioButton, 0, 0, 1, 1);

        topCenterRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        topCenterRadioButton->setObjectName(QStringLiteral("topCenterRadioButton"));
        topCenterRadioButton->setMinimumSize(QSize(20, 20));
        topCenterRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(topCenterRadioButton, 0, 1, 1, 1);

        topRightRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        topRightRadioButton->setObjectName(QStringLiteral("topRightRadioButton"));
        topRightRadioButton->setMinimumSize(QSize(20, 20));
        topRightRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(topRightRadioButton, 0, 2, 1, 1);

        centerLeftRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        centerLeftRadioButton->setObjectName(QStringLiteral("centerLeftRadioButton"));
        centerLeftRadioButton->setMinimumSize(QSize(20, 20));
        centerLeftRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(centerLeftRadioButton, 1, 0, 1, 1);

        centerCenterRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        centerCenterRadioButton->setObjectName(QStringLiteral("centerCenterRadioButton"));
        centerCenterRadioButton->setMinimumSize(QSize(20, 20));
        centerCenterRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(centerCenterRadioButton, 1, 1, 1, 1);

        centerRightRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        centerRightRadioButton->setObjectName(QStringLiteral("centerRightRadioButton"));
        centerRightRadioButton->setMinimumSize(QSize(20, 20));
        centerRightRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(centerRightRadioButton, 1, 2, 1, 1);

        bottomLeftRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        bottomLeftRadioButton->setObjectName(QStringLiteral("bottomLeftRadioButton"));
        bottomLeftRadioButton->setMinimumSize(QSize(20, 20));
        bottomLeftRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(bottomLeftRadioButton, 2, 0, 1, 1);

        bottomCenterRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        bottomCenterRadioButton->setObjectName(QStringLiteral("bottomCenterRadioButton"));
        bottomCenterRadioButton->setMinimumSize(QSize(20, 20));
        bottomCenterRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(bottomCenterRadioButton, 2, 1, 1, 1);

        bottomRightRadioButton = new QRadioButton(watermarkLayoutGroupBox);
        bottomRightRadioButton->setObjectName(QStringLiteral("bottomRightRadioButton"));
        bottomRightRadioButton->setMinimumSize(QSize(20, 20));
        bottomRightRadioButton->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(bottomRightRadioButton, 2, 2, 1, 1);

        watermarkLabel = new QLabel(WatermarkSettingWidget);
        watermarkLabel->setObjectName(QStringLiteral("watermarkLabel"));
        watermarkLabel->setGeometry(QRect(48, 45, 176, 23));
        watermarkLabel->setMinimumSize(QSize(176, 23));
        watermarkLabel->setMaximumSize(QSize(176, 23));

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
        watermarkLabel->setText(QApplication::translate("WatermarkSettingWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WatermarkSettingWidget: public Ui_WatermarkSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATERMARKSETTINGWIDGET_H
