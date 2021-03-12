#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IHMDMX.h"

class IHMDMX : public QMainWindow
{
    Q_OBJECT

public:
    IHMDMX(QWidget *parent = Q_NULLPTR);

private:
    Ui::IHMDMXClass ui;
};
