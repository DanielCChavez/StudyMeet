/********************************************************************************
** Form generated from reading UI file 'studymeet.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYMEET_H
#define UI_STUDYMEET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyMeetClass
{
public:
    QWidget *centralWidget;
    QPushButton *toDSWButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StudyMeetClass)
    {
        if (StudyMeetClass->objectName().isEmpty())
            StudyMeetClass->setObjectName(QStringLiteral("StudyMeetClass"));
        StudyMeetClass->resize(582, 590);
        centralWidget = new QWidget(StudyMeetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toDSWButton = new QPushButton(centralWidget);
        toDSWButton->setObjectName(QStringLiteral("toDSWButton"));
        toDSWButton->setGeometry(QRect(150, 120, 201, 23));
        StudyMeetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StudyMeetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 21));
        StudyMeetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StudyMeetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StudyMeetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StudyMeetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StudyMeetClass->setStatusBar(statusBar);

        retranslateUi(StudyMeetClass);

        QMetaObject::connectSlotsByName(StudyMeetClass);
    } // setupUi

    void retranslateUi(QMainWindow *StudyMeetClass)
    {
        StudyMeetClass->setWindowTitle(QApplication::translate("StudyMeetClass", "StudyMeet", 0));
        toDSWButton->setText(QApplication::translate("StudyMeetClass", "To Detailed Session Window", 0));
    } // retranslateUi

};

namespace Ui {
    class StudyMeetClass: public Ui_StudyMeetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYMEET_H
