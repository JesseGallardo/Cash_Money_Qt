/*
 * BudgetSheet.h
 *
 *  Created on: Jun 3, 2018
 *      Author: jesse
 */

#ifndef BUDGETSHEET_H_
#define BUDGETSHEET_H_

#include <string> //for strings
#include <map> //for maps
#include "Debit.h"
#include "Credit.h"

using namespace std;

class BudgetSheet {
private:
    map<string, Debit> DebitList; //list full of debit items
    map<string, Credit> CreditList;	 //list full of credit items
public:
    BudgetSheet();

    void addDebit(string name, string date, string type, double value); //adds a debit items to the list
    void removeDebit(string name); //removes a debit item from the list
    void printDebit(string name); //prints a debit item's values
    int getDLSize(); //gets the size of DebitList
    Debit getDebitAt(int index);

    void addCredit(string name, string date, string type, double value); //adds a credit item to the list
    void removeCredit(string name); //removes a credit item from the list
    void printCredit(string name); //prints a credit item's value
    int getCLSize();
};

#endif /* BUDGETSHEET_H_ */
