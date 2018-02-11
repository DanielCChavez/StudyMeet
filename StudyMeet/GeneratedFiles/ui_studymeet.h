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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyMeetClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *heyButton;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *name_label;
    QLineEdit *petName;
    QLabel *age_label;
    QLineEdit *petAge;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *insertButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *getStartedButton;
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
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 70, 185, 308));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        heyButton = new QPushButton(layoutWidget);
        heyButton->setObjectName(QStringLiteral("heyButton"));

        gridLayout_2->addWidget(heyButton, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 228, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(-30, 0, 601, 71));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(418, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitButton = new QPushButton(layoutWidget1);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 348, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(250, 80, 258, 323));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        name_label = new QLabel(layoutWidget2);
        name_label->setObjectName(QStringLiteral("name_label"));

        gridLayout->addWidget(name_label, 0, 0, 1, 1);

        petName = new QLineEdit(layoutWidget2);
        petName->setObjectName(QStringLiteral("petName"));

        gridLayout->addWidget(petName, 0, 1, 1, 1);

        age_label = new QLabel(layoutWidget2);
        age_label->setObjectName(QStringLiteral("age_label"));

        gridLayout->addWidget(age_label, 1, 0, 1, 1);

        petAge = new QLineEdit(layoutWidget2);
        petAge->setObjectName(QStringLiteral("petAge"));

        gridLayout->addWidget(petAge, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        insertButton = new QPushButton(layoutWidget2);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        gridLayout->addWidget(insertButton, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 1, 0, 1, 1);

        getStartedButton = new QPushButton(centralWidget);
        getStartedButton->setObjectName(QStringLiteral("getStartedButton"));
        getStartedButton->setGeometry(QRect(190, 420, 75, 23));
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
        QObject::connect(exitButton, SIGNAL(clicked()), StudyMeetClass, SLOT(close()));

        QMetaObject::connectSlotsByName(StudyMeetClass);
    } // setupUi

    void retranslateUi(QMainWindow *StudyMeetClass)
    {
        StudyMeetClass->setWindowTitle(QApplication::translate("StudyMeetClass", "StudyMeet", 0));
        label->setText(QApplication::translate("StudyMeetClass", "Hi", 0));
        heyButton->setText(QApplication::translate("StudyMeetClass", "Hey", 0));
        exitButton->setText(QApplication::translate("StudyMeetClass", "exit", 0));
        name_label->setText(QApplication::translate("StudyMeetClass", "Pet Name:", 0));
        age_label->setText(QApplication::translate("StudyMeetClass", "Pet Age:", 0));
        insertButton->setText(QApplication::translate("StudyMeetClass", "Insert into (test) DB", 0));
        getStartedButton->setText(QApplication::translate("StudyMeetClass", "Get Started", 0));
    } // retranslateUi

};

namespace Ui {
    class StudyMeetClass: public Ui_StudyMeetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYMEET_H
