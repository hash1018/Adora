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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdoraFrameWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *minimizeButton;
    QPushButton *closeButton;

    void setupUi(QWidget *AdoraFrameWidget)
    {
        if (AdoraFrameWidget->objectName().isEmpty())
            AdoraFrameWidget->setObjectName(QStringLiteral("AdoraFrameWidget"));
        AdoraFrameWidget->resize(778, 40);
        AdoraFrameWidget->setMinimumSize(QSize(0, 40));
        AdoraFrameWidget->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(AdoraFrameWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 5, 10, 5);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minimizeButton = new QPushButton(AdoraFrameWidget);
        minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
        minimizeButton->setMinimumSize(QSize(30, 30));
        minimizeButton->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(minimizeButton);

        closeButton = new QPushButton(AdoraFrameWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(closeButton);


        retranslateUi(AdoraFrameWidget);

        QMetaObject::connectSlotsByName(AdoraFrameWidget);
    } // setupUi

    void retranslateUi(QWidget *AdoraFrameWidget)
    {
        AdoraFrameWidget->setWindowTitle(QApplication::translate("AdoraFrameWidget", "Form", nullptr));
        minimizeButton->setText(QApplication::translate("AdoraFrameWidget", "_", nullptr));
        closeButton->setText(QApplication::translate("AdoraFrameWidget", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdoraFrameWidget: public Ui_AdoraFrameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADORAFRAMEWIDGET_H
