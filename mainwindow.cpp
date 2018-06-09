#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BudgetSheet.h"

BudgetSheet bs;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_existingok_clicked()
{
    //Implement File Finder Here and Load the File As Such

}
