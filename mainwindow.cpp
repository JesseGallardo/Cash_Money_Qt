#include <QtWidgets>
#include <stdio.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BudgetSheet.h"

BudgetSheet bs;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMessages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMessages(){
    ui->statusBar->showMessage(tr("Welcome, please click the help button to know how to use this app!"));
}
