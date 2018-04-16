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
#include <QtWidgets/QLabel>
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
    QPushButton *toVSWButton;
    QPushButton *loggedInAsButton;
    QLabel *studyMeetLogo;
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
        toVSWButton = new QPushButton(centralWidget);
        toVSWButton->setObjectName(QStringLiteral("toVSWButton"));
        toVSWButton->setGeometry(QRect(100, 140, 271, 31));
        loggedInAsButton = new QPushButton(centralWidget);
        loggedInAsButton->setObjectName(QStringLiteral("loggedInAsButton"));
        loggedInAsButton->setGeometry(QRect(160, 50, 161, 23));
        studyMeetLogo = new QLabel(centralWidget);
        studyMeetLogo->setObjectName(QStringLiteral("studyMeetLogo"));
        studyMeetLogo->setGeometry(QRect(80, 270, 491, 181));
        studyMeetLogo->setTextFormat(Qt::AutoText);
        studyMeetLogo->setPixmap(QPixmap(QString::fromUtf8("../Images/StudyMeetPrototype1.png")));
        StudyMeetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StudyMeetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 26));
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
        toVSWButton->setText(QApplication::translate("StudyMeetClass", "To View Session Window", 0));
        loggedInAsButton->setText(QApplication::translate("StudyMeetClass", "Who Am I logged In As?", 0));
        studyMeetLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudyMeetClass: public Ui_StudyMeetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYMEET_H
