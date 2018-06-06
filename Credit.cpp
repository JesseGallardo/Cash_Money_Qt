/*
 * Credit.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: jesse
 */

#include <string> //for strings
#include "Credit.h"

string Credit::getDateOf(){
    return dateOf;
}

void Credit::setDateOf(string dateOf) {
    this->dateOf = dateOf;
}

string Credit::getNameOf(){
    return nameOf;
}

void Credit::setNameOf(string nameOf) {
    this->nameOf = nameOf;
}

string Credit::getTypeOf(){
    return typeOf;
}

void Credit::setTypeOf(string typeOf) {
    this->typeOf = typeOf;
}

double Credit::getValueOf(){
    return valueOf;
}

void Credit::setValueOf(double valueOf) {
    this->valueOf = valueOf;
}

Credit::Credit() {
    nameOf = "";
    dateOf = "";
    typeOf = "";
    valueOf = 0.00;
}

Credit::Credit(string name, string date, string type, double value){
    nameOf = name;
    dateOf = date;
    typeOf = type;
    valueOf = value;
}
