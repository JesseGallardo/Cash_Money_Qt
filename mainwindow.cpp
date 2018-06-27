#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDoubleValidator>
#include <QIntValidator>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BudgetSheet.h"

BudgetSheet bs;
bool fileLoaded = false;
string loadedFName;
string loadedMonth;
int total;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    checkDirectory();
    setMessages();
    resizeQComboBoxes();
    setSpecialRules();
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

void MainWindow::resizeQComboBoxes(){
    int width1 = ui->CreateMonth->minimumSizeHint().width();

    ui->CreateMonth->setMinimumWidth(width1);
    ui->CreateMonth->view()->setMinimumWidth(width1);

    ui->LoadMonth->setMinimumWidth(width1);
    ui->LoadMonth->view()->setMinimumWidth(width1);
}

string MainWindow::getFileDirectory(){
    //This works for Mac and possibly Linux, unsure about Windows
    string temp(getenv("HOME"));
    temp += "/Desktop/BudgetSheet/";
    return temp;
}

void MainWindow::updateDebitList(){
    ui->DebitList->clear();

    int length = bs.getDLSize();

    for(int i = 0; i < length; i++){
        Debit temp = bs.getDebitAt(i);
        string nameOf = temp.getNameOf();

        ostringstream tempStr;
        double value = temp.getValueOf();
        tempStr << value;
        string valueOf = tempStr.str();

        string dateOf = temp.getDateOf();

        string item = dateOf +  " " + nameOf + " $" + valueOf;

        ui->DebitList->addItem(item.c_str());
    }
}

void MainWindow::updateCreditList(){
    ui->CreditList->clear();

    int length = bs.getCLSize();

    for(int i = 0; i < length; i++){
        Credit temp = bs.getCreditAt(i);
        string nameOf = temp.getNameOf();

        ostringstream tempStr;
        double value = temp.getValueOf();
        tempStr << value;
        string valueOf = tempStr.str();

        string dateOf = temp.getDateOf();

        string item = dateOf + " " + nameOf + " $" + valueOf;

        ui->CreditList->addItem(item.c_str());
    }
}

string MainWindow::monthToNum(string month){
    if(month == "Jan"){
        return "1";
    }
    else if(month == "Feb"){
        return "2";
    }
    else if(month == "Mar"){
        return "3";
    }
    else if(month == "April"){
        return "4";
    }
    else if(month == "May"){
        return "5";
    }
    else if(month == "June"){
        return "6";
    }
    else if(month == "July"){
        return "7";
    }
    else if(month == "Aug"){
        return "8";
    }
    else if(month == "Sept"){
        return "9";
    }
    else if(month == "Oct"){
        return "10";
    }
    else if(month == "Nov"){
        return "11";
    }
    else if(month == "Dec"){
        return "12";
    }
    else{
        return "";
    }
}

string MainWindow::ithWord(string text, int ith){
    char *dup = strdup(text.c_str());

    int loop = 1;
    char *tok = strtok(dup, " ");

    while(tok != NULL){
        if(loop == ith){
            string word(tok);
            return word;
        }
        loop++;
        tok = strtok(NULL, " ");
    }
}

void MainWindow::setSpecialRules(){
    ui->NewValue->setValidator(new QDoubleValidator(0, 100000, 2, this));
    ui->CreateYear->setValidator(new QIntValidator(0, 10000, this));
    ui->LoadYear->setValidator(new QIntValidator(0, 10000, this));
}

/*Sockets*/
void MainWindow::on_CreateButton_clicked()
{
    QString qmonth = ui->CreateMonth->currentText();
    QString qyear = ui->CreateYear->text();

    if(qyear == ""){
        return;
    }

    string month = qmonth.toStdString();
    string year = qyear.toStdString();

    string fname = month + "-" + year + ".txt";

    string path = getFileDirectory() + fname;

    ofstream newf(path);
    newf << "empty" << endl;
    newf.close();
}

void MainWindow::on_NewItemButton_clicked()
{
    if(ui->NewName->text() == "" || ui->NewValue->text() == "" || ui->NewDay->currentText() == "Day" || loadedMonth == ""){
        cout << "Nope" << endl;
        return;
    }

    string itemName = ui->NewName->text().toStdString();

    string itemValStr = ui->NewValue->text().toStdString();

    double itemValue = atof(itemValStr.c_str());
    itemValue = (int) (itemValue * 100 + .5);
    itemValue = (float)itemValue / 100;

    //string itemMonth = ui->NewMonth->currentText().toStdString();
    string itemDay = ui->NewDay->currentText().toStdString();
    string itemDate = monthToNum(loadedMonth) + "/" + itemDay;

    cout << itemName << ": $" << itemValue << endl;

    cout << itemDate << endl;

    string itemType = ui->NewType->currentText().toStdString();

    if(itemType == "Debit"){
        if(bs.addDebit(itemName, itemDate, itemType, itemValue) == true){
            total += itemValue;
            updateDebitList();
        }
        else{
            QMessageBox error;
            error.setText("No Duplicate Names Allowed.");
            error.setInformativeText("If you must, include '(#)' after the name where # is a number.");
            error.exec();
        }
    }
    else{
        if(bs.addCredit(itemName, itemDate, itemType, itemValue)){
            total -= itemValue;
            updateCreditList();
        }
        else{
            QMessageBox error;
            error.setText("No Duplicate Names Allowed.");
            error.setInformativeText("If you must, include '(#)' after the name where # is a number.");
            error.exec();
        }
    }
}

void MainWindow::on_LoadButton_clicked()
{
    cout << "hi" << endl;
    QString qmonth = ui->LoadMonth->currentText();
    QString qyear = ui->LoadYear->text();

    if(qyear == ""){
        return;
    }

    string month = qmonth.toStdString();
    string year = qyear.toStdString();

    string fname = month + "-" + year + ".txt";

    string path = getFileDirectory() + fname;

    fstream loadFile;

    loadFile.open(path, fstream::in);

    if(!loadFile.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    loadedFName = fname;
    loadedMonth = month;

    string line;
    int lineNum = 0;
    int fiveLineNum = 0;

    while(getline(loadFile, line)){
        if(line == "empty"){
            break;
        }
        else if(lineNum > 4){
            if(line == "-----"){
                fiveLineNum++;
                if(fiveLineNum == 2){
                    break;
                }
                continue;
            }//if
            else if(line == "Credit:"){
                continue;
            }
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

    loadFile.close();

    ui->LoadButton->setEnabled(false);


}

void MainWindow::on_FinishedButton_clicked()
{
    fstream fwrite;
    string path = getFileDirectory() + loadedFName;

    fwrite.open(path, std::fstream::out | fstream::trunc);

    fwrite << "# of Debit Items: " << bs.getDLSize() << ", # of Credit Items: " << bs.getCLSize() << ", Net Value: $" << endl;
    fwrite << "------------------------------------------------------------------------------------------" << endl;

    for(int row = 0; row < ui->DebitList->count(); row++){
        QString qstring = ui->DebitList->item(row)->text();
        string str = qstring.toStdString();
        str = "Debit " + str;
        fwrite << str << endl;
    }

    for(int row = 0; row < ui->CreditList->count(); row++){
        QString qstring = ui->CreditList->item(row)->text();
        string str = qstring.toStdString();
        str = "Credit " + str;
        fwrite << str << endl;
    }

    fwrite.close();

    loadedFName = "";

    ui->LoadButton->setEnabled(true);
}

void MainWindow::on_DebitRemoveButton_clicked()
{
    if(ui->DebitList->currentItem() != NULL){
        QListWidgetItem *item = ui->DebitList->currentItem();
        QString temp = item->text();
        string itemString = temp.toStdString();

        string itemName = ithWord(itemString, 2);

        bs.removeDebit(itemName);

        updateDebitList();
    }

}

void MainWindow::on_CreditRemoveButton_clicked()
{
    if(ui->CreditList->currentItem() != NULL){
        QListWidgetItem *item = ui->CreditList->currentItem();
        QString temp = item->text();
        string itemString = temp.toStdString();

        string itemName = ithWord(itemString, 2);

        bs.removeCredit(itemName);

        updateCreditList();
    }
}
