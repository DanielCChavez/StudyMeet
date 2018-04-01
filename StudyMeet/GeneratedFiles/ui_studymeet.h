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
    QPushButton *toVSWButton;
    QPushButton *addToSessionsButton;
    QPushButton *loggedInAsButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StudyMeetClass)
    {
        if (StudyMeetClass->objectName().isEmpty())
            StudyMeetClass->setObjectName(QStringLiteral("StudyMeetClass"));
        StudyMeetClass->resize(659, 590);
        centralWidget = new QWidget(StudyMeetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toDSWButton = new QPushButton(centralWidget);
        toDSWButton->setObjectName(QStringLiteral("toDSWButton"));
        toDSWButton->setGeometry(QRect(150, 120, 201, 23));
        toVSWButton = new QPushButton(centralWidget);
        toVSWButton->setObjectName(QStringLiteral("toVSWButton"));
        toVSWButton->setGeometry(QRect(120, 180, 271, 31));
        addToSessionsButton = new QPushButton(centralWidget);
        addToSessionsButton->setObjectName(QStringLiteral("addToSessionsButton"));
        addToSessionsButton->setGeometry(QRect(160, 280, 171, 23));
        loggedInAsButton = new QPushButton(centralWidget);
        loggedInAsButton->setObjectName(QStringLiteral("loggedInAsButton"));
        loggedInAsButton->setGeometry(QRect(160, 50, 161, 23));
        StudyMeetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StudyMeetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 21));
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
        toVSWButton->setText(QApplication::translate("StudyMeetClass", "To View Session Window", 0));
        addToSessionsButton->setText(QApplication::translate("StudyMeetClass", "Add to sessiond (test)", 0));
        loggedInAsButton->setText(QApplication::translate("StudyMeetClass", "Who Am I logged In As?", 0));
    } // retranslateUi

};

namespace Ui {
    class StudyMeetClass: public Ui_StudyMeetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYMEET_H
