/********************************************************************************
** Form generated from reading UI file 'createnewsession.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWSESSION_H
#define UI_CREATENEWSESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewSession
{
public:
    QLabel *timeEndLabel;
    QLabel *SubjectLabel;
    QLineEdit *SubjectEntry;
    QLabel *timeStartLabel;
    QLabel *LocationLabel;
    QLineEdit *LocationEdit;
    QLabel *sizeofSessionLabel;
    QLineEdit *sizeOfSessionEdit;
    QLabel *DescriptionLabel;
    QPushButton *PublishSessionButton;
    QTextEdit *DesciptionEdit;
    QPushButton *CancelButton;
    QTimeEdit *timeStartEdit;
    QTimeEdit *timeEndEdit;
    QDateEdit *dateEdit;
    QLabel *DateLabel;

    void setupUi(QWidget *CreateNewSession)
    {
        if (CreateNewSession->objectName().isEmpty())
            CreateNewSession->setObjectName(QStringLiteral("CreateNewSession"));
        CreateNewSession->resize(775, 411);
        timeEndLabel = new QLabel(CreateNewSession);
        timeEndLabel->setObjectName(QStringLiteral("timeEndLabel"));
        timeEndLabel->setGeometry(QRect(240, 60, 71, 16));
        SubjectLabel = new QLabel(CreateNewSession);
        SubjectLabel->setObjectName(QStringLiteral("SubjectLabel"));
        SubjectLabel->setGeometry(QRect(50, 30, 55, 16));
        SubjectEntry = new QLineEdit(CreateNewSession);
        SubjectEntry->setObjectName(QStringLiteral("SubjectEntry"));
        SubjectEntry->setGeometry(QRect(110, 30, 113, 22));
        timeStartLabel = new QLabel(CreateNewSession);
        timeStartLabel->setObjectName(QStringLiteral("timeStartLabel"));
        timeStartLabel->setGeometry(QRect(40, 60, 81, 20));
        LocationLabel = new QLabel(CreateNewSession);
        LocationLabel->setObjectName(QStringLiteral("LocationLabel"));
        LocationLabel->setGeometry(QRect(50, 90, 55, 16));
        LocationEdit = new QLineEdit(CreateNewSession);
        LocationEdit->setObjectName(QStringLiteral("LocationEdit"));
        LocationEdit->setGeometry(QRect(110, 90, 113, 22));
        sizeofSessionLabel = new QLabel(CreateNewSession);
        sizeofSessionLabel->setObjectName(QStringLiteral("sizeofSessionLabel"));
        sizeofSessionLabel->setGeometry(QRect(60, 130, 41, 20));
        sizeOfSessionEdit = new QLineEdit(CreateNewSession);
        sizeOfSessionEdit->setObjectName(QStringLiteral("sizeOfSessionEdit"));
        sizeOfSessionEdit->setGeometry(QRect(110, 130, 113, 22));
        DescriptionLabel = new QLabel(CreateNewSession);
        DescriptionLabel->setObjectName(QStringLiteral("DescriptionLabel"));
        DescriptionLabel->setGeometry(QRect(50, 190, 71, 16));
        PublishSessionButton = new QPushButton(CreateNewSession);
        PublishSessionButton->setObjectName(QStringLiteral("PublishSessionButton"));
        PublishSessionButton->setGeometry(QRect(50, 350, 121, 41));
        DesciptionEdit = new QTextEdit(CreateNewSession);
        DesciptionEdit->setObjectName(QStringLiteral("DesciptionEdit"));
        DesciptionEdit->setGeometry(QRect(50, 220, 381, 121));
        CancelButton = new QPushButton(CreateNewSession);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(300, 350, 121, 41));
        timeStartEdit = new QTimeEdit(CreateNewSession);
        timeStartEdit->setObjectName(QStringLiteral("timeStartEdit"));
        timeStartEdit->setGeometry(QRect(110, 60, 118, 22));
        timeStartEdit->setCalendarPopup(false);
        timeStartEdit->setTime(QTime(0, 0, 0));
        timeEndEdit = new QTimeEdit(CreateNewSession);
        timeEndEdit->setObjectName(QStringLiteral("timeEndEdit"));
        timeEndEdit->setGeometry(QRect(310, 60, 118, 22));
        dateEdit = new QDateEdit(CreateNewSession);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(510, 60, 110, 22));
        dateEdit->setCalendarPopup(true);
        DateLabel = new QLabel(CreateNewSession);
        DateLabel->setObjectName(QStringLiteral("DateLabel"));
        DateLabel->setGeometry(QRect(460, 60, 55, 16));
        QWidget::setTabOrder(SubjectEntry, timeStartEdit);
        QWidget::setTabOrder(timeStartEdit, timeEndEdit);
        QWidget::setTabOrder(timeEndEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, LocationEdit);
        QWidget::setTabOrder(LocationEdit, sizeOfSessionEdit);
        QWidget::setTabOrder(sizeOfSessionEdit, DesciptionEdit);
        QWidget::setTabOrder(DesciptionEdit, PublishSessionButton);
        QWidget::setTabOrder(PublishSessionButton, CancelButton);

        retranslateUi(CreateNewSession);

        PublishSessionButton->setDefault(true);


        QMetaObject::connectSlotsByName(CreateNewSession);
    } // setupUi

    void retranslateUi(QWidget *CreateNewSession)
    {
        CreateNewSession->setWindowTitle(QApplication::translate("CreateNewSession", "CreateNewSession", Q_NULLPTR));
        timeEndLabel->setText(QApplication::translate("CreateNewSession", "Time End:", Q_NULLPTR));
        SubjectLabel->setText(QApplication::translate("CreateNewSession", "Subject", Q_NULLPTR));
        timeStartLabel->setText(QApplication::translate("CreateNewSession", "Time Start", Q_NULLPTR));
        LocationLabel->setText(QApplication::translate("CreateNewSession", "Location", Q_NULLPTR));
        sizeofSessionLabel->setText(QApplication::translate("CreateNewSession", "Size", Q_NULLPTR));
        DescriptionLabel->setText(QApplication::translate("CreateNewSession", "Description:", Q_NULLPTR));
        PublishSessionButton->setText(QApplication::translate("CreateNewSession", "Publish", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("CreateNewSession", "Cancel", Q_NULLPTR));
        DateLabel->setText(QApplication::translate("CreateNewSession", "Date", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateNewSession: public Ui_CreateNewSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWSESSION_H
