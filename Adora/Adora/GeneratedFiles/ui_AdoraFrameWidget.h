/********************************************************************************
** Form generated from reading UI file 'AdoraFrameWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADORAFRAMEWIDGET_H
#define UI_ADORAFRAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdoraFrameWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *adoraLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *minimizeButton;
    QPushButton *closeButton;

    void setupUi(QWidget *AdoraFrameWidget)
    {
        if (AdoraFrameWidget->objectName().isEmpty())
            AdoraFrameWidget->setObjectName(QStringLiteral("AdoraFrameWidget"));
        AdoraFrameWidget->resize(750, 66);
        AdoraFrameWidget->setMinimumSize(QSize(750, 66));
        AdoraFrameWidget->setMaximumSize(QSize(750, 66));
        AdoraFrameWidget->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: #FFC23D\n"
"}\n"
"\n"
"QLabel#adoraLabel{\n"
"   background-image: url(:/Main/adora);\n"
"}\n"
"\n"
"QPushButton{\n"
"    padding: 0px 0px 0px 0px;\n"
"    border: 0px;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QPushButton#minimizeButton {\n"
" \n"
"    background-color: transparent;\n"
"    background-image: url(:/Frame/minimize);\n"
"    \n"
"}\n"
"\n"
"QPushButton#minimizeButton:hover{\n"
"   background-color: #FFCE64;\n"
"}\n"
"\n"
"QPushButton#minimizeButton:pressed{\n"
"   background-color: #FFD477;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton#closeButton {\n"
"    background-color: transparent;\n"
"    background-image: url(:/Frame/minimize);\n"
"}\n"
"\n"
"QPushButton#closeButton:hover{\n"
"   background-color: #FFCE64;\n"
"}\n"
"\n"
"QPushButton#closeButton:pressed{\n"
"   background-color: #FFD477;\n"
"}"));
        horizontalLayout = new QHBoxLayout(AdoraFrameWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(325, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        adoraLabel = new QLabel(AdoraFrameWidget);
        adoraLabel->setObjectName(QStringLiteral("adoraLabel"));
        adoraLabel->setMinimumSize(QSize(101, 26));
        adoraLabel->setMaximumSize(QSize(101, 26));
        adoraLabel->setLayoutDirection(Qt::LeftToRight);
        adoraLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(adoraLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        minimizeButton = new QPushButton(AdoraFrameWidget);
        minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
        minimizeButton->setMinimumSize(QSize(50, 66));
        minimizeButton->setMaximumSize(QSize(50, 66));

        horizontalLayout->addWidget(minimizeButton, 0, Qt::AlignRight);

        closeButton = new QPushButton(AdoraFrameWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(50, 66));
        closeButton->setMaximumSize(QSize(50, 66));

        horizontalLayout->addWidget(closeButton, 0, Qt::AlignRight);


        retranslateUi(AdoraFrameWidget);

        QMetaObject::connectSlotsByName(AdoraFrameWidget);
    } // setupUi

    void retranslateUi(QWidget *AdoraFrameWidget)
    {
        AdoraFrameWidget->setWindowTitle(QApplication::translate("AdoraFrameWidget", "Form", nullptr));
        adoraLabel->setText(QString());
        minimizeButton->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdoraFrameWidget: public Ui_AdoraFrameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADORAFRAMEWIDGET_H
