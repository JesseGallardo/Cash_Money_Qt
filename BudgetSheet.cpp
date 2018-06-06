/*
 * BudgetSheet.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: jesse
 */

#include <iostream>
#include <string>
#include <map>
#include "BudgetSheet.h"
#include "Debit.h"
#include "Credit.h"

void BudgetSheet::addDebit(string name, string date, string type, double value){
    Debit temp = new Debit(name, date, type, value);
    DebitList.insert(make_pair(name, temp));
    cout << "Added " << name << " Successfully!" << endl;
}//addDebit

void BudgetSheet::removeDebit(string name){
    map<string, Debit>::iterator it;
    it = DebitList.find(name);
    if(it != DebitList.end()){
        DebitList.erase(it);
        cout << name << " deleted successfully!" << endl;
    }//if
    else{
        cout << name << " not in list!" << endl;
    }//else
}//removeDebit

void BudgetSheet::printDebit(string name){
    map<string, Debit>::iterator it = DebitList.begin();
    it = DebitList.find(name);
    if(it != DebitList.end()){
        Debit temp = it->second;
        cout << "Name: " << temp.getNameOf() << endl;
        cout << "Date: " << temp.getDateOf() << endl;
        cout << "Type: " << temp.getTypeOf() << endl;
        cout << "Value: " << temp.getValueOf() << endl;
    }
    else{
        cout << "Item not in list." << endl;
    }
}//printDebit


void BudgetSheet::addCredit(string name, string date, string type, double value){
    Credit temp = new Credit(name, date, type, value);
    CreditList.insert(make_pair(name , temp));
    cout << "Added " << name << " successfully!" << endl;
}//addCredit

void BudgetSheet::removeCredit(string name){
    map<string, Credit>::iterator it;
    it = CreditList.find(name);
    if(it != CreditList.end()){
        CreditList.erase(it);
        cout << name << " deleted successfully!";
    }//if
    else{
        cout << name << " is not in the list!" << endl;
    }//else
}
void BudgetSheet::printCredit(string name){
    map<string, Credit>::iterator it;
    it = CreditList.find(name);
    if(it != CreditList.end()){
        Credit temp = it->second;
        cout << "Name: " << temp.getNameOf() << endl;
        cout << "Date: " << temp.getDateOf() << endl;
        cout << "Type: " << temp.getTypeOf() << endl;
        cout << "Value: " << temp.getValueOf() << endl;
    }
}

BudgetSheet::BudgetSheet() {

}
