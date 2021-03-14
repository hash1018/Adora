/********************************************************************************
** Form generated from reading UI file 'Adora.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADORA_H
#define UI_ADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Ui/AdoraFrameWidget.h>
#include <Ui/Item/MenuButton.h>

QT_BEGIN_NAMESPACE

class Ui_Adora
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    AdoraFrameWidget *adoraFrameWidget;
    QWidget *backgroundWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *menuAreaWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    MenuButton *generalButton;
    MenuButton *videoButton;
    MenuButton *audioButton;
    MenuButton *imageButton;
    MenuButton *timeLimitButton;
    MenuButton *watermarkButton;
    MenuButton *languageButton;
    MenuButton *licenseButton;
    MenuButton *aboutButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *buttonAreaWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *recordButton;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *menuStackWidget;

    void setupUi(QMainWindow *Adora)
    {
        if (Adora->objectName().isEmpty())
            Adora->setObjectName(QStringLiteral("Adora"));
        Adora->resize(750, 650);
        Adora->setMinimumSize(QSize(750, 650));
        Adora->setMaximumSize(QSize(750, 650));
        Adora->setStyleSheet(QLatin1String("QWidget#centralWidget {\n"
"   background-color: #FFC23D;\n"
"   border-radius: 15px;\n"
"   overflow: hidden;\n"
"\n"
"}\n"
"\n"
"QPushButton#generalButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#generalButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#generalButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton#videoButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#videoButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#videoButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton#audioButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#audioButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#audioButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton#imageButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
""
                        "}\n"
"QPushButton#imageButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#imageButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"QPushButton#timeLimitButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#timeLimitButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#timeLimitButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"QPushButton#watermarkButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#watermarkButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#watermarkButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"QPushButton#languageButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#languageButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#languageButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"QPushButton#licenseButton {\n"
"  "
                        "  background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#licenseButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#licenseButton:checked {\n"
"    background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton#aboutButton {\n"
"    background-color: transparent;\n"
"    border: 0px;\n"
"}\n"
"QPushButton#aboutButton:hover {\n"
"    background-color: #FFCE64;\n"
"}\n"
"QPushButton#aboutButton:checked {\n"
"    background-color: #FFD477;\n"
"}"));
        centralWidget = new QWidget(Adora);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        adoraFrameWidget = new AdoraFrameWidget(centralWidget);
        adoraFrameWidget->setObjectName(QStringLiteral("adoraFrameWidget"));
        adoraFrameWidget->setMinimumSize(QSize(750, 66));
        adoraFrameWidget->setMaximumSize(QSize(750, 66));

        verticalLayout->addWidget(adoraFrameWidget, 0, Qt::AlignHCenter);

        backgroundWidget = new QWidget(centralWidget);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        horizontalLayout = new QHBoxLayout(backgroundWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        menuAreaWidget = new QWidget(backgroundWidget);
        menuAreaWidget->setObjectName(QStringLiteral("menuAreaWidget"));
        menuAreaWidget->setMinimumSize(QSize(157, 0));
        menuAreaWidget->setMaximumSize(QSize(157, 16777215));
        verticalLayout_2 = new QVBoxLayout(menuAreaWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        generalButton = new MenuButton(menuAreaWidget);
        generalButton->setObjectName(QStringLiteral("generalButton"));
        generalButton->setMinimumSize(QSize(157, 42));
        generalButton->setMaximumSize(QSize(157, 42));
        generalButton->setCheckable(true);
        generalButton->setChecked(false);

        verticalLayout_2->addWidget(generalButton);

        videoButton = new MenuButton(menuAreaWidget);
        videoButton->setObjectName(QStringLiteral("videoButton"));
        videoButton->setMinimumSize(QSize(157, 42));
        videoButton->setMaximumSize(QSize(157, 42));
        videoButton->setCheckable(true);

        verticalLayout_2->addWidget(videoButton);

        audioButton = new MenuButton(menuAreaWidget);
        audioButton->setObjectName(QStringLiteral("audioButton"));
        audioButton->setMinimumSize(QSize(157, 42));
        audioButton->setMaximumSize(QSize(157, 42));
        audioButton->setCheckable(true);

        verticalLayout_2->addWidget(audioButton);

        imageButton = new MenuButton(menuAreaWidget);
        imageButton->setObjectName(QStringLiteral("imageButton"));
        imageButton->setMinimumSize(QSize(157, 42));
        imageButton->setMaximumSize(QSize(157, 42));
        imageButton->setCheckable(true);

        verticalLayout_2->addWidget(imageButton);

        timeLimitButton = new MenuButton(menuAreaWidget);
        timeLimitButton->setObjectName(QStringLiteral("timeLimitButton"));
        timeLimitButton->setMinimumSize(QSize(157, 42));
        timeLimitButton->setMaximumSize(QSize(157, 42));
        timeLimitButton->setCheckable(true);

        verticalLayout_2->addWidget(timeLimitButton);

        watermarkButton = new MenuButton(menuAreaWidget);
        watermarkButton->setObjectName(QStringLiteral("watermarkButton"));
        watermarkButton->setMinimumSize(QSize(157, 42));
        watermarkButton->setMaximumSize(QSize(157, 42));

        verticalLayout_2->addWidget(watermarkButton);

        languageButton = new MenuButton(menuAreaWidget);
        languageButton->setObjectName(QStringLiteral("languageButton"));
        languageButton->setMinimumSize(QSize(157, 42));
        languageButton->setMaximumSize(QSize(157, 42));
        languageButton->setCheckable(true);

        verticalLayout_2->addWidget(languageButton);

        licenseButton = new MenuButton(menuAreaWidget);
        licenseButton->setObjectName(QStringLiteral("licenseButton"));
        licenseButton->setMinimumSize(QSize(157, 42));
        licenseButton->setMaximumSize(QSize(157, 42));
        licenseButton->setCheckable(true);

        verticalLayout_2->addWidget(licenseButton);

        aboutButton = new MenuButton(menuAreaWidget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setMinimumSize(QSize(157, 42));
        aboutButton->setMaximumSize(QSize(157, 42));
        aboutButton->setCheckable(true);

        verticalLayout_2->addWidget(aboutButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        buttonAreaWidget = new QWidget(menuAreaWidget);
        buttonAreaWidget->setObjectName(QStringLiteral("buttonAreaWidget"));
        buttonAreaWidget->setMinimumSize(QSize(0, 73));
        buttonAreaWidget->setMaximumSize(QSize(16777215, 73));
        horizontalLayout_2 = new QHBoxLayout(buttonAreaWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        recordButton = new QPushButton(buttonAreaWidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));

        horizontalLayout_2->addWidget(recordButton);


        verticalLayout_2->addWidget(buttonAreaWidget);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(menuAreaWidget);

        menuStackWidget = new QStackedWidget(backgroundWidget);
        menuStackWidget->setObjectName(QStringLiteral("menuStackWidget"));

        horizontalLayout->addWidget(menuStackWidget);


        verticalLayout->addWidget(backgroundWidget);

        Adora->setCentralWidget(centralWidget);

        retranslateUi(Adora);

        QMetaObject::connectSlotsByName(Adora);
    } // setupUi

    void retranslateUi(QMainWindow *Adora)
    {
        Adora->setWindowTitle(QApplication::translate("Adora", "Adora", nullptr));
        generalButton->setText(QApplication::translate("Adora", "general", nullptr));
        videoButton->setText(QApplication::translate("Adora", "video", nullptr));
        audioButton->setText(QApplication::translate("Adora", "audio", nullptr));
        imageButton->setText(QApplication::translate("Adora", "image", nullptr));
        timeLimitButton->setText(QApplication::translate("Adora", "timeLimit", nullptr));
        watermarkButton->setText(QApplication::translate("Adora", "watermark", nullptr));
        languageButton->setText(QApplication::translate("Adora", "language", nullptr));
        licenseButton->setText(QApplication::translate("Adora", "license", nullptr));
        aboutButton->setText(QApplication::translate("Adora", "about", nullptr));
        recordButton->setText(QApplication::translate("Adora", "record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adora: public Ui_Adora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADORA_H
