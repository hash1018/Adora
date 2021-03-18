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
    QLabel *AdoraLabel;
    QWidget *groupWidget;
    QLabel *githubLabel;
    QLabel *developerLabel;
    QLabel *emailLabel;
    QLabel *developerLabel2;
    QLabel *emailLabel2;
    QLabel *githubLabel2;
    QLabel *versionLabel;

    void setupUi(QWidget *AboutWidget)
    {
        if (AboutWidget->objectName().isEmpty())
            AboutWidget->setObjectName(QStringLiteral("AboutWidget"));
        AboutWidget->resize(616, 533);
        AboutWidget->setStyleSheet(QLatin1String("QWidget#groupWidget {\n"
"   background-color:#F6F6F6;\n"
"   border-radius:15px;\n"
"   \n"
"}\n"
"\n"
"QLabel#AdoraLabel {\n"
"    background-image:url(:/Main/adora_black);\n"
"}"));
        AdoraLabel = new QLabel(AboutWidget);
        AdoraLabel->setObjectName(QStringLiteral("AdoraLabel"));
        AdoraLabel->setGeometry(QRect(57, 132, 162, 42));
        AdoraLabel->setMinimumSize(QSize(162, 42));
        AdoraLabel->setMaximumSize(QSize(162, 42));
        groupWidget = new QWidget(AboutWidget);
        groupWidget->setObjectName(QStringLiteral("groupWidget"));
        groupWidget->setGeometry(QRect(48, 232, 475, 140));
        groupWidget->setMinimumSize(QSize(475, 140));
        groupWidget->setMaximumSize(QSize(475, 140));
        githubLabel = new QLabel(groupWidget);
        githubLabel->setObjectName(QStringLiteral("githubLabel"));
        githubLabel->setGeometry(QRect(29, 83, 54, 36));
        githubLabel->setMinimumSize(QSize(54, 36));
        githubLabel->setMaximumSize(QSize(54, 36));
        githubLabel->setTextFormat(Qt::AutoText);
        githubLabel->setOpenExternalLinks(true);
        githubLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
        developerLabel = new QLabel(groupWidget);
        developerLabel->setObjectName(QStringLiteral("developerLabel"));
        developerLabel->setGeometry(QRect(29, 21, 45, 36));
        developerLabel->setMinimumSize(QSize(45, 36));
        developerLabel->setMaximumSize(QSize(45, 36));
        emailLabel = new QLabel(groupWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setGeometry(QRect(29, 52, 44, 36));
        emailLabel->setMinimumSize(QSize(44, 36));
        emailLabel->setMaximumSize(QSize(44, 36));
        developerLabel2 = new QLabel(groupWidget);
        developerLabel2->setObjectName(QStringLiteral("developerLabel2"));
        developerLabel2->setGeometry(QRect(102, 21, 250, 36));
        developerLabel2->setMinimumSize(QSize(250, 36));
        developerLabel2->setMaximumSize(QSize(250, 36));
        emailLabel2 = new QLabel(groupWidget);
        emailLabel2->setObjectName(QStringLiteral("emailLabel2"));
        emailLabel2->setGeometry(QRect(102, 52, 250, 36));
        emailLabel2->setMinimumSize(QSize(250, 36));
        emailLabel2->setMaximumSize(QSize(250, 36));
        githubLabel2 = new QLabel(groupWidget);
        githubLabel2->setObjectName(QStringLiteral("githubLabel2"));
        githubLabel2->setGeometry(QRect(102, 83, 250, 36));
        githubLabel2->setMinimumSize(QSize(250, 36));
        githubLabel2->setMaximumSize(QSize(250, 36));
        versionLabel = new QLabel(AboutWidget);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setGeometry(QRect(232, 162, 100, 12));
        versionLabel->setMinimumSize(QSize(100, 12));
        versionLabel->setMaximumSize(QSize(100, 12));

        retranslateUi(AboutWidget);

        QMetaObject::connectSlotsByName(AboutWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutWidget)
    {
        AboutWidget->setWindowTitle(QApplication::translate("AboutWidget", "Form", nullptr));
        AdoraLabel->setText(QString());
        githubLabel->setText(QString());
        developerLabel->setText(QString());
        emailLabel->setText(QString());
        developerLabel2->setText(QString());
        emailLabel2->setText(QString());
        githubLabel2->setText(QString());
        versionLabel->setText(QApplication::translate("AboutWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutWidget: public Ui_AboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
