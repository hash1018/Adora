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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Ui/AdoraFrameWidget.h>

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
    QListWidget *menuListWidget;
    QWidget *buttonAreaWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *recordButton;
    QStackedWidget *menuStackWidget;

    void setupUi(QMainWindow *Adora)
    {
        if (Adora->objectName().isEmpty())
            Adora->setObjectName(QStringLiteral("Adora"));
        Adora->resize(750, 650);
        Adora->setMinimumSize(QSize(750, 650));
        Adora->setMaximumSize(QSize(750, 650));
        centralWidget = new QWidget(Adora);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        adoraFrameWidget = new AdoraFrameWidget(centralWidget);
        adoraFrameWidget->setObjectName(QStringLiteral("adoraFrameWidget"));
        adoraFrameWidget->setMinimumSize(QSize(0, 40));
        adoraFrameWidget->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(adoraFrameWidget);

        backgroundWidget = new QWidget(centralWidget);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        horizontalLayout = new QHBoxLayout(backgroundWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 15, 15, 15);
        menuAreaWidget = new QWidget(backgroundWidget);
        menuAreaWidget->setObjectName(QStringLiteral("menuAreaWidget"));
        menuAreaWidget->setMinimumSize(QSize(200, 0));
        menuAreaWidget->setMaximumSize(QSize(200, 16777215));
        verticalLayout_2 = new QVBoxLayout(menuAreaWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        menuListWidget = new QListWidget(menuAreaWidget);
        menuListWidget->setObjectName(QStringLiteral("menuListWidget"));

        verticalLayout_2->addWidget(menuListWidget);

        buttonAreaWidget = new QWidget(menuAreaWidget);
        buttonAreaWidget->setObjectName(QStringLiteral("buttonAreaWidget"));
        buttonAreaWidget->setMinimumSize(QSize(0, 50));
        buttonAreaWidget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(buttonAreaWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        recordButton = new QPushButton(buttonAreaWidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));

        horizontalLayout_2->addWidget(recordButton);


        verticalLayout_2->addWidget(buttonAreaWidget);


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
        recordButton->setText(QApplication::translate("Adora", "record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adora: public Ui_Adora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADORA_H
