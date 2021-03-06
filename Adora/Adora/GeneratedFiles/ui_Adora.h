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

        verticalLayout->addWidget(adoraFrameWidget, 0, Qt::AlignTop);

        Adora->setCentralWidget(centralWidget);

        retranslateUi(Adora);

        QMetaObject::connectSlotsByName(Adora);
    } // setupUi

    void retranslateUi(QMainWindow *Adora)
    {
        Adora->setWindowTitle(QApplication::translate("Adora", "Adora", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adora: public Ui_Adora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADORA_H
