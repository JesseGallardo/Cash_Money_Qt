/*
 * Debit.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: jesse
 */

#include <string> //for strings
#include "Debit.h"

using namespace std;

string Debit::getDateOf(){
    return dateOf;
}

void Debit::setDateOf(string dateOf){
    this->dateOf = dateOf;
}

string Debit::getNameOf(){
    return nameOf;
}

void Debit::setNameOf(string nameOf){
    this->nameOf = nameOf;
}

string Debit::getTypeOf(){
    return typeOf;
}

void Debit::setTypeOf(string typeOf) {
    this->typeOf = typeOf;
}

double Debit::getValueOf(){
    return valueOf;
}

void Debit::setValueOf(double valueOf) {
    this->valueOf = valueOf;
}

Debit::Debit() {
    nameOf = "";
    dateOf = "";
    typeOf = "";
    valueOf = 0.00;
}

Debit::Debit(string name, string date, string type, double value){
    nameOf = name;
    dateOf = date;
    typeOf = type;
    valueOf = value;
}
