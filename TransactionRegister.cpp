/*
 * TransactionRegister.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: jesse
 */

#include <iostream>
#include <string>
#include <map>
#include "TransactionRegister.h"
#include "Debit.h"
#include "Credit.h"

bool TransactionRegister::addDebit(string name, string date, string type, double value){
    if(DebitList.find(name) == DebitList.end()){
        Debit temp(name, date, type ,value);
        DebitList.insert(make_pair(name, temp));
        cout << "Added " << name << " Successfully!" << endl;
        return true;
    }
    else{
        cout << name << " exists already" << endl;
        return false;
    }

}//addDebit

void TransactionRegister::removeDebit(string name){
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

void TransactionRegister::printDebit(string name){
    map<string, Debit>::iterator it = DebitList.begin();
    it = DebitList.find(name);
    if(it != DebitList.end()){
        Debit temp = it->second;
        cout << "Name: " << temp.getNameOf() << endl;
        cout << "Date: " << temp.getDateOf() << endl;
        cout << "Type: " << temp.getTypeOf() << endl;
        cout << "Value: $" << temp.getValueOf() << endl;
    }
    else{
        cout << "Item not in list." << endl;
    }
}//printDebit

int TransactionRegister::getDLSize(){
    return DebitList.size();
}

Debit TransactionRegister::getDebitAt(int index){
    if(index < DebitList.size()){
        map<string, Debit>::iterator it = DebitList.begin();

        for(int i = 0; i < DebitList.size(); i++){
            if(i == index){
                return it->second;
            }
            it++;
        }

        return it->second;
    }
    else{
        Debit temp;
        return temp;
    }
}


bool TransactionRegister::addCredit(string name, string date, string type, double value){
    //Credit temp = new Credit(name, date, type, value);
    if(CreditList.find(name) == CreditList.end()){
        Credit temp(name, date, type, value);
        CreditList.insert(make_pair(name , temp));
        cout << "Added " << name << " successfully!" << endl;
        return true;
    }
    else{
        cout << name << " exists already!" << endl;
        return false;
    }
}//addCredit

void TransactionRegister::removeCredit(string name){
    map<string, Credit>::iterator it;
    it = CreditList.find(name);
    if(it != CreditList.end()){
        CreditList.erase(it);
        cout << name << " deleted successfully!" << endl;
    }//if
    else{
        cout << name << " is not in the list!" << endl;
    }//else
}
void TransactionRegister::printCredit(string name){
    map<string, Credit>::iterator it;
    it = CreditList.find(name);
    if(it != CreditList.end()){
        Credit temp = it->second;
        cout << "Name: " << temp.getNameOf() << endl;
        cout << "Date: " << temp.getDateOf() << endl;
        cout << "Type: " << temp.getTypeOf() << endl;
        cout << "Value: " << temp.getValueOf() << endl;
    }
    else{
        cout << "Item not in list!" << endl;
    }
}

int TransactionRegister::getCLSize(){
    return CreditList.size();
}

Credit TransactionRegister::getCreditAt(int index){
    if(index < CreditList.size()){
        map<string, Credit>::iterator it = CreditList.begin();
        for(int i = 0; i < CreditList.size(); i++){
            if(i == index){
                return it->second;
            }
            it++;
        }
    }
    else{
        Credit temp;
        return temp;
    }
}

TransactionRegister::TransactionRegister() {

}
