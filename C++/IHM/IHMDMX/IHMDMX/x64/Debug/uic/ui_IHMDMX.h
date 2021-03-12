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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMDMXClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IHMDMXClass)
    {
        if (IHMDMXClass->objectName().isEmpty())
            IHMDMXClass->setObjectName(QString::fromUtf8("IHMDMXClass"));
        IHMDMXClass->resize(600, 400);
        menuBar = new QMenuBar(IHMDMXClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        IHMDMXClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IHMDMXClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        IHMDMXClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(IHMDMXClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        IHMDMXClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IHMDMXClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IHMDMXClass->setStatusBar(statusBar);

        retranslateUi(IHMDMXClass);

        QMetaObject::connectSlotsByName(IHMDMXClass);
    } // setupUi

    void retranslateUi(QMainWindow *IHMDMXClass)
    {
        IHMDMXClass->setWindowTitle(QCoreApplication::translate("IHMDMXClass", "IHMDMX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHMDMXClass: public Ui_IHMDMXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMDMX_H
