/********************************************************************************
** Form generated from reading UI file 'AboutWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIDGET_H
#define UI_ABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWidget
{
public:
    QLabel *developerLabel;
    QLabel *emailLabel;
    QLabel *githubLabel;

    void setupUi(QWidget *AboutWidget)
    {
        if (AboutWidget->objectName().isEmpty())
            AboutWidget->setObjectName(QStringLiteral("AboutWidget"));
        AboutWidget->resize(616, 533);
        developerLabel = new QLabel(AboutWidget);
        developerLabel->setObjectName(QStringLiteral("developerLabel"));
        developerLabel->setGeometry(QRect(50, 270, 181, 16));
        emailLabel = new QLabel(AboutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setGeometry(QRect(50, 300, 231, 16));
        githubLabel = new QLabel(AboutWidget);
        githubLabel->setObjectName(QStringLiteral("githubLabel"));
        githubLabel->setGeometry(QRect(50, 330, 261, 16));
        githubLabel->setTextFormat(Qt::AutoText);
        githubLabel->setOpenExternalLinks(true);
        githubLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

        retranslateUi(AboutWidget);

        QMetaObject::connectSlotsByName(AboutWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutWidget)
    {
        AboutWidget->setWindowTitle(QApplication::translate("AboutWidget", "Form", nullptr));
        developerLabel->setText(QApplication::translate("AboutWidget", "\352\260\234\353\260\234\354\236\220   \355\225\230\354\212\271\355\230\270", nullptr));
        emailLabel->setText(QApplication::translate("AboutWidget", "e-mail  sh.ha1018@gmail.com", nullptr));
        githubLabel->setText(QApplication::translate("AboutWidget", "github www.github.com/hash1018", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutWidget: public Ui_AboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
