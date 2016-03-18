/********************************************************************************
** Form generated from reading UI file 'mwinZt7484.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MWINZT7484_H
#define MWINZT7484_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionParametre;
    QAction *actionConversion;
    QAction *actionQuitter;
    QAction *actionA_propos_de_Qt;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_11;
    QGridLayout *gridLayout;
    QPushButton *pushButton_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_16;
    QPushButton *pushButton_18;
    QPushButton *pushButton_12;
    QPushButton *pushButton_17;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QMenu *menuA_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(432, 192);
        actionParametre = new QAction(MainWindow);
        actionParametre->setObjectName(QStringLiteral("actionParametre"));
        actionConversion = new QAction(MainWindow);
        actionConversion->setObjectName(QStringLiteral("actionConversion"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionA_propos_de_Qt = new QAction(MainWindow);
        actionA_propos_de_Qt->setObjectName(QStringLiteral("actionA_propos_de_Qt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 411, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_2->addWidget(pushButton_7, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_2->addWidget(pushButton_8, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_2->addWidget(pushButton_9, 2, 1, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_2->addWidget(pushButton_11, 3, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_15 = new QPushButton(verticalLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 1, 1, 1, 1);

        pushButton_13 = new QPushButton(verticalLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 0, 0, 1, 1);

        pushButton_14 = new QPushButton(verticalLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 0, 1, 1, 1);

        pushButton_16 = new QPushButton(verticalLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 3, 0, 1, 1);

        pushButton_18 = new QPushButton(verticalLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout->addWidget(pushButton_18, 4, 0, 1, 2);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 1, 0, 1, 1);

        pushButton_17 = new QPushButton(verticalLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout->addWidget(pushButton_17, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 432, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        menuA_propos = new QMenu(menubar);
        menuA_propos->setObjectName(QStringLiteral("menuA_propos"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());
        menubar->addAction(menuA_propos->menuAction());
        menuFichier->addAction(actionParametre);
        menuFichier->addAction(actionConversion);
        menuFichier->addAction(actionQuitter);
        menuA_propos->addAction(actionA_propos_de_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionParametre->setText(QApplication::translate("MainWindow", "Parametre", 0));
        actionConversion->setText(QApplication::translate("MainWindow", "Conversion", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionA_propos_de_Qt->setText(QApplication::translate("MainWindow", "A propos de Qt", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", ".", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "\342\202\254 -> $", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "$ -> \342\202\254", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "*", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "=", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "/", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
        menuA_propos->setTitle(QApplication::translate("MainWindow", "A propos", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MWINZT7484_H
