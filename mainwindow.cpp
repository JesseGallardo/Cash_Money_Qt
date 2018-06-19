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
bool fileLoaded = false;
string loadedFName;

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

/*Nonsockets*/
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

/*Sockets*/
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
    newf << "empty" << endl;
    newf.close();
}

void MainWindow::on_NewItemButton_clicked()
{
    if(ui->NewName->text() == "" || ui->NewValue->text() == "" || ui->NewMonth->currentText() == "Month" || ui->NewDay->currentText() == "Day"){
        cout << "Nope" << endl;
        return;
    }

    string itemName = ui->NewName->text().toStdString();

    string itemValStr = ui->NewValue->text().toStdString();

    double itemValue = atof(itemValStr.c_str());
    itemValue = (int) (itemValue * 100 + .5);
    itemValue = (float)itemValue / 100;

    string itemMonth = ui->NewMonth->currentText().toStdString();
    string itemDay = ui->NewDay->currentText().toStdString();
    string itemDate = itemMonth + "/" + itemDay;

    cout << itemName << ": $" << itemValue << endl;

    cout << itemDate << endl;


}

void MainWindow::on_LoadButton_clicked()
{
    //try using iostream.peek() to see if empty when loading the file
    string path(getenv("HOME"));
    path += "/Desktop/BudgetSheet/";

    QString qmonth = ui->LoadMonth->currentText();
    QString qyear = ui->LoadYear->text();

    if(qyear == ""){
        return;
    }

    string month = qmonth.toStdString();
    string year = qyear.toStdString();

    string fname = month + "-" + year + ".txt";

    path += fname;

    fstream loadFile;

    loadFile.open(path, fstream::in);

    if(!loadFile.is_open()){
        return;
    }

    string line;
    int lineNum = 0;
    int fiveLineNum = 0;

    while(getline(loadFile, line)){
        if(line == "empty"){
            break;
        }
        else if(lineNum > 3){
            if(line == "-----"){
                fiveLineNum++;
                if(fiveLineNum == 2){
                    break;
                }

                continue;
            }//if
            else{
                /*Use the global budgetsheet item known as "bs"*/
                if(fiveLineNum == 0){
                    //read debit items
                }
                else if(fiveLineNum == 1){
                    //read credit items
                }
            }//else
        }//else-if
    }//while



}
