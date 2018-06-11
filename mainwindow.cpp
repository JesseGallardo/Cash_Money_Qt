#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BudgetSheet.h"

BudgetSheet bs;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    checkDirectory();
    setMessages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMessages(){
    ui->statusBar->showMessage(tr("Welcome, please click the help button to know how to use this app!"));
}

void MainWindow::checkDirectory(){
    DIR *check;
    string path(getenv("HOME"));
    path += "/Desktop/BudgetSheet";
    const char *tpath = path.c_str();
    check = opendir(tpath);
    if(!check){
        string command = "mkdir -p " + path;
        const char *tcommand = command.c_str();
        const int test = system(tcommand);
        if(test == -1){
            cout << "fuck" << endl;
        }
    }
    else{
        cout << "cool" << endl;
    }
}

void MainWindow::on_CreateButton_clicked()
{
    //This works for Mac and possibly Linux, unsure about Windows
    string path(getenv("HOME"));
    path += "/Desktop/BudgetSheet/";

    QString qmonth = ui->CreateMonth->currentText();
    QString qyear = ui->CreateYear->text();

    if(qyear == ""){
        return;
    }

    string month = qmonth.toStdString();
    string year = qyear.toStdString();

    string fname = month + "-" + year + ".txt";

    path += fname;

    ofstream newf(path);
}
