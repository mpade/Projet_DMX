/********************************************************************************
** Form generated from reading UI file 'IHMDMX.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMDMX_H
#define UI_IHMDMX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMDMXClass
{
public:
    QWidget *centralWidget;
    QLabel *ResultatConnexionBdd;
    QPushButton *ConnexionBdd;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IHMDMXClass)
    {
        if (IHMDMXClass->objectName().isEmpty())
            IHMDMXClass->setObjectName(QString::fromUtf8("IHMDMXClass"));
        IHMDMXClass->resize(793, 400);
        centralWidget = new QWidget(IHMDMXClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ResultatConnexionBdd = new QLabel(centralWidget);
        ResultatConnexionBdd->setObjectName(QString::fromUtf8("ResultatConnexionBdd"));
        ResultatConnexionBdd->setGeometry(QRect(270, 80, 151, 41));
        ConnexionBdd = new QPushButton(centralWidget);
        ConnexionBdd->setObjectName(QString::fromUtf8("ConnexionBdd"));
        ConnexionBdd->setGeometry(QRect(70, 90, 91, 23));
        IHMDMXClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IHMDMXClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 793, 21));
        IHMDMXClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IHMDMXClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        IHMDMXClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IHMDMXClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IHMDMXClass->setStatusBar(statusBar);

        retranslateUi(IHMDMXClass);

        QMetaObject::connectSlotsByName(IHMDMXClass);
    } // setupUi

    void retranslateUi(QMainWindow *IHMDMXClass)
    {
        IHMDMXClass->setWindowTitle(QCoreApplication::translate("IHMDMXClass", "IHMDMX", nullptr));
        ResultatConnexionBdd->setText(QCoreApplication::translate("IHMDMXClass", "ResultatConnexionBdd", nullptr));
        ConnexionBdd->setText(QCoreApplication::translate("IHMDMXClass", "ConnexionBdd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHMDMXClass: public Ui_IHMDMXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMDMX_H
