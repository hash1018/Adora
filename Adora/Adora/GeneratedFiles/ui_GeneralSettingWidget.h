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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralSettingWidget
{
public:
    QLineEdit *savePathLineEdit;
    QPushButton *searchPathButton;
    QPushButton *openDirectoryButton;
    QPushButton *videoButton;
    QPushButton *imageButton;
    QPushButton *orderByButton;
    QListWidget *itemListWidget;
    QPushButton *playButton;
    QPushButton *uploadButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *GeneralSettingWidget)
    {
        if (GeneralSettingWidget->objectName().isEmpty())
            GeneralSettingWidget->setObjectName(QStringLiteral("GeneralSettingWidget"));
        GeneralSettingWidget->resize(706, 558);
        savePathLineEdit = new QLineEdit(GeneralSettingWidget);
        savePathLineEdit->setObjectName(QStringLiteral("savePathLineEdit"));
        savePathLineEdit->setGeometry(QRect(20, 70, 311, 31));
        savePathLineEdit->setReadOnly(true);
        searchPathButton = new QPushButton(GeneralSettingWidget);
        searchPathButton->setObjectName(QStringLiteral("searchPathButton"));
        searchPathButton->setGeometry(QRect(330, 70, 93, 28));
        openDirectoryButton = new QPushButton(GeneralSettingWidget);
        openDirectoryButton->setObjectName(QStringLiteral("openDirectoryButton"));
        openDirectoryButton->setGeometry(QRect(430, 70, 93, 28));
        videoButton = new QPushButton(GeneralSettingWidget);
        videoButton->setObjectName(QStringLiteral("videoButton"));
        videoButton->setGeometry(QRect(40, 120, 93, 28));
        imageButton = new QPushButton(GeneralSettingWidget);
        imageButton->setObjectName(QStringLiteral("imageButton"));
        imageButton->setGeometry(QRect(140, 120, 93, 28));
        orderByButton = new QPushButton(GeneralSettingWidget);
        orderByButton->setObjectName(QStringLiteral("orderByButton"));
        orderByButton->setGeometry(QRect(240, 120, 93, 28));
        itemListWidget = new QListWidget(GeneralSettingWidget);
        itemListWidget->setObjectName(QStringLiteral("itemListWidget"));
        itemListWidget->setGeometry(QRect(30, 170, 491, 192));
        playButton = new QPushButton(GeneralSettingWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(30, 380, 93, 28));
        uploadButton = new QPushButton(GeneralSettingWidget);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setGeometry(QRect(140, 380, 93, 28));
        deleteButton = new QPushButton(GeneralSettingWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(240, 380, 93, 28));

        retranslateUi(GeneralSettingWidget);

        QMetaObject::connectSlotsByName(GeneralSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *GeneralSettingWidget)
    {
        GeneralSettingWidget->setWindowTitle(QApplication::translate("GeneralSettingWidget", "Form", nullptr));
        searchPathButton->setText(QApplication::translate("GeneralSettingWidget", "...", nullptr));
        openDirectoryButton->setText(QApplication::translate("GeneralSettingWidget", "Open", nullptr));
        videoButton->setText(QApplication::translate("GeneralSettingWidget", "video", nullptr));
        imageButton->setText(QApplication::translate("GeneralSettingWidget", "image", nullptr));
        orderByButton->setText(QApplication::translate("GeneralSettingWidget", "\354\240\225\353\240\254", nullptr));
        playButton->setText(QApplication::translate("GeneralSettingWidget", "play", nullptr));
        uploadButton->setText(QApplication::translate("GeneralSettingWidget", "upload", nullptr));
        deleteButton->setText(QApplication::translate("GeneralSettingWidget", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralSettingWidget: public Ui_GeneralSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSETTINGWIDGET_H
