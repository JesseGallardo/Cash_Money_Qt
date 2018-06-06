/*
 * Debit.h
 *
 *  Created on: Jun 2, 2018
 *      Author: jesse
 */

#ifndef DEBIT_H
#define DEBIT_H

#include <string> //for strings

using namespace std;

class Debit {
private:
    string nameOf;
    string dateOf;
    string typeOf;
    double valueOf;
public:
    Debit();
    Debit(string name, string date, string type, double value);

    string getDateOf();
    void setDateOf(string dateOf);

    string getNameOf();
    void setNameOf(string nameOf);

    string getTypeOf();
    void setTypeOf(string typeOf);

    double getValueOf();
    void setValueOf(double valueOf);
};

#endif /* DEBIT_H_ */
