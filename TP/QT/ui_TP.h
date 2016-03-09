/********************************************************************************
** Form generated from reading UI file 'TP.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_H
#define UI_TP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionParametre;
    QAction *actionConvertion;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_18;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(605, 288);
        actionParametre = new QAction(MainWindow);
        actionParametre->setObjectName(QString::fromUtf8("actionParametre"));
        actionConvertion = new QAction(MainWindow);
        actionConvertion->setObjectName(QString::fromUtf8("actionConvertion"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 581, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 2, 2, 1, 1);

        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 3, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_14 = new QPushButton(verticalLayoutWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout_2->addWidget(pushButton_14, 0, 1, 1, 1);

        pushButton_15 = new QPushButton(verticalLayoutWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout_2->addWidget(pushButton_15, 2, 0, 1, 1);

        pushButton_18 = new QPushButton(verticalLayoutWidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout_2->addWidget(pushButton_18, 3, 0, 1, 2);

        pushButton_16 = new QPushButton(verticalLayoutWidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        gridLayout_2->addWidget(pushButton_16, 1, 1, 1, 1);

        pushButton_17 = new QPushButton(verticalLayoutWidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout_2->addWidget(pushButton_17, 2, 1, 1, 1);

        pushButton_13 = new QPushButton(verticalLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout_2->addWidget(pushButton_13, 0, 0, 1, 1);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_2->addWidget(pushButton_12, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 605, 19));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionParametre);
        menuFichier->addAction(actionConvertion);
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionParametre->setText(QApplication::translate("MainWindow", "Parametre", 0, QApplication::UnicodeUTF8));
        actionConvertion->setText(QApplication::translate("MainWindow", "Convertion", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("MainWindow", "$ -> \342\202\254", 0, QApplication::UnicodeUTF8));
        pushButton_15->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        pushButton_18->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        pushButton_16->setText(QApplication::translate("MainWindow", "\342\202\254 -> $", 0, QApplication::UnicodeUTF8));
        pushButton_17->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_H
