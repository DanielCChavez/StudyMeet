/********************************************************************************
** Form generated from reading UI file 'createnewsession.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWSESSION_H
#define UI_CREATENEWSESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewSession
{
public:
    QLabel *HostName;
    QLineEdit *HostNameEntry;
    QLabel *SubjectLabel;
    QLineEdit *SubjectEntry;
    QLabel *TimeLabel;
    QLineEdit *TimeEntry;
    QLabel *LocationLabel;
    QLineEdit *LocationEntry;
    QLabel *ParticipantLabel;
    QLineEdit *ParticipantEntry;
    QLabel *DescriptionLabel;
    QPushButton *PublishSessionButton;
    QTextEdit *DesciptionEntry;
    QPushButton *CancelButton;

    void setupUi(QWidget *CreateNewSession)
    {
        if (CreateNewSession->objectName().isEmpty())
            CreateNewSession->setObjectName(QStringLiteral("CreateNewSession"));
        CreateNewSession->resize(775, 411);
        HostName = new QLabel(CreateNewSession);
        HostName->setObjectName(QStringLiteral("HostName"));
        HostName->setGeometry(QRect(80, 50, 71, 16));
        HostNameEntry = new QLineEdit(CreateNewSession);
        HostNameEntry->setObjectName(QStringLiteral("HostNameEntry"));
        HostNameEntry->setGeometry(QRect(50, 70, 113, 22));
        SubjectLabel = new QLabel(CreateNewSession);
        SubjectLabel->setObjectName(QStringLiteral("SubjectLabel"));
        SubjectLabel->setGeometry(QRect(230, 50, 55, 16));
        SubjectEntry = new QLineEdit(CreateNewSession);
        SubjectEntry->setObjectName(QStringLiteral("SubjectEntry"));
        SubjectEntry->setGeometry(QRect(190, 70, 113, 22));
        TimeLabel = new QLabel(CreateNewSession);
        TimeLabel->setObjectName(QStringLiteral("TimeLabel"));
        TimeLabel->setGeometry(QRect(370, 50, 55, 16));
        TimeEntry = new QLineEdit(CreateNewSession);
        TimeEntry->setObjectName(QStringLiteral("TimeEntry"));
        TimeEntry->setGeometry(QRect(330, 70, 113, 22));
        LocationLabel = new QLabel(CreateNewSession);
        LocationLabel->setObjectName(QStringLiteral("LocationLabel"));
        LocationLabel->setGeometry(QRect(500, 50, 55, 16));
        LocationEntry = new QLineEdit(CreateNewSession);
        LocationEntry->setObjectName(QStringLiteral("LocationEntry"));
        LocationEntry->setGeometry(QRect(470, 70, 113, 22));
        ParticipantLabel = new QLabel(CreateNewSession);
        ParticipantLabel->setObjectName(QStringLiteral("ParticipantLabel"));
        ParticipantLabel->setGeometry(QRect(634, 50, 71, 20));
        ParticipantEntry = new QLineEdit(CreateNewSession);
        ParticipantEntry->setObjectName(QStringLiteral("ParticipantEntry"));
        ParticipantEntry->setGeometry(QRect(610, 70, 113, 22));
        DescriptionLabel = new QLabel(CreateNewSession);
        DescriptionLabel->setObjectName(QStringLiteral("DescriptionLabel"));
        DescriptionLabel->setGeometry(QRect(50, 150, 71, 16));
        PublishSessionButton = new QPushButton(CreateNewSession);
        PublishSessionButton->setObjectName(QStringLiteral("PublishSessionButton"));
        PublishSessionButton->setGeometry(QRect(50, 330, 121, 41));
        DesciptionEntry = new QTextEdit(CreateNewSession);
        DesciptionEntry->setObjectName(QStringLiteral("DesciptionEntry"));
        DesciptionEntry->setGeometry(QRect(50, 176, 381, 121));
        CancelButton = new QPushButton(CreateNewSession);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(310, 330, 121, 41));

        retranslateUi(CreateNewSession);

        QMetaObject::connectSlotsByName(CreateNewSession);
    } // setupUi

    void retranslateUi(QWidget *CreateNewSession)
    {
        CreateNewSession->setWindowTitle(QApplication::translate("CreateNewSession", "CreateNewSession", 0));
        HostName->setText(QApplication::translate("CreateNewSession", "Host Name", 0));
        SubjectLabel->setText(QApplication::translate("CreateNewSession", "Subject", 0));
        TimeLabel->setText(QApplication::translate("CreateNewSession", "Time", 0));
        LocationLabel->setText(QApplication::translate("CreateNewSession", "Location", 0));
        ParticipantLabel->setText(QApplication::translate("CreateNewSession", "Participants", 0));
        DescriptionLabel->setText(QApplication::translate("CreateNewSession", "Description:", 0));
        PublishSessionButton->setText(QApplication::translate("CreateNewSession", "Publish", 0));
        CancelButton->setText(QApplication::translate("CreateNewSession", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNewSession: public Ui_CreateNewSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWSESSION_H
