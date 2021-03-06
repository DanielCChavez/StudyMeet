/********************************************************************************
** Form generated from reading UI file 'createnewsession.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWSESSION_H
#define UI_CREATENEWSESSION_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewSession
{
public:
    QLabel *timeEndLabel;
    QLabel *SubjectLabel;
    QLabel *timeStartLabel;
    QLabel *LocationLabel;
    QLineEdit *LocationEdit;
    QLabel *sizeofSessionLabel;
    QLabel *DescriptionLabel;
    QPushButton *PublishSessionButton;
    QTextEdit *DesciptionEdit;
    QPushButton *CancelButton;
    QTimeEdit *timeStartEdit;
    QTimeEdit *timeEndEdit;
    QDateEdit *dateEdit;
    QLabel *DateLabel;
    QComboBox *subjectBox;
    QSpinBox *numberBox;

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
        dateEdit->setMaximumDate(QDate(7999, 12, 30));
        dateEdit->setCalendarPopup(true);
        DateLabel = new QLabel(CreateNewSession);
        DateLabel->setObjectName(QStringLiteral("DateLabel"));
        DateLabel->setGeometry(QRect(460, 60, 55, 16));
        subjectBox = new QComboBox(CreateNewSession);
        subjectBox->setObjectName(QStringLiteral("subjectBox"));
        subjectBox->setGeometry(QRect(110, 30, 69, 20));
        subjectBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        subjectBox->setFrame(true);
        numberBox = new QSpinBox(CreateNewSession);
        numberBox->setObjectName(QStringLiteral("numberBox"));
        numberBox->setGeometry(QRect(110, 130, 42, 22));
        numberBox->setMinimum(2);
        numberBox->setMaximum(20);
        QWidget::setTabOrder(subjectBox, timeStartEdit);
        QWidget::setTabOrder(timeStartEdit, timeEndEdit);
        QWidget::setTabOrder(timeEndEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, LocationEdit);
        QWidget::setTabOrder(LocationEdit, numberBox);
        QWidget::setTabOrder(numberBox, DesciptionEdit);
        QWidget::setTabOrder(DesciptionEdit, PublishSessionButton);
        QWidget::setTabOrder(PublishSessionButton, CancelButton);

        retranslateUi(CreateNewSession);

        PublishSessionButton->setDefault(true);


        QMetaObject::connectSlotsByName(CreateNewSession);
    } // setupUi

    void retranslateUi(QWidget *CreateNewSession)
    {
        CreateNewSession->setWindowTitle(QApplication::translate("CreateNewSession", "CreateNewSession", 0));
        timeEndLabel->setText(QApplication::translate("CreateNewSession", "Time End:", 0));
        SubjectLabel->setText(QApplication::translate("CreateNewSession", "Subject", 0));
        timeStartLabel->setText(QApplication::translate("CreateNewSession", "Time Start", 0));
        LocationLabel->setText(QApplication::translate("CreateNewSession", "Location", 0));
        sizeofSessionLabel->setText(QApplication::translate("CreateNewSession", "Size", 0));
        DescriptionLabel->setText(QApplication::translate("CreateNewSession", "Description:", 0));
        PublishSessionButton->setText(QApplication::translate("CreateNewSession", "Publish", 0));
        CancelButton->setText(QApplication::translate("CreateNewSession", "Cancel", 0));
        DateLabel->setText(QApplication::translate("CreateNewSession", "Date", 0));
        subjectBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateNewSession: public Ui_CreateNewSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWSESSION_H
