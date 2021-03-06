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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdoraClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdoraClass)
    {
        if (AdoraClass->objectName().isEmpty())
            AdoraClass->setObjectName(QStringLiteral("AdoraClass"));
        AdoraClass->resize(600, 400);
        menuBar = new QMenuBar(AdoraClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        AdoraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdoraClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AdoraClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AdoraClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AdoraClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AdoraClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AdoraClass->setStatusBar(statusBar);

        retranslateUi(AdoraClass);

        QMetaObject::connectSlotsByName(AdoraClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdoraClass)
    {
        AdoraClass->setWindowTitle(QApplication::translate("AdoraClass", "Adora", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdoraClass: public Ui_AdoraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADORA_H
