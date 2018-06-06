/*
 * Credit.h
 *
 *  Created on: Jun 2, 2018
 *      Author: jesse
 */

#ifndef CREDIT_H_
#define CREDIT_H_

#include <string> //for strings

using namespace std;

class Credit {
private:
    string nameOf;
    string dateOf;
    string typeOf;
    double valueOf;
public:
    Credit();
    Credit(string name, string date, string type, double value);

    string getDateOf();
    void setDateOf(string dateOf);

    string getNameOf();
    void setNameOf(string nameOf);

    string getTypeOf();
    void setTypeOf(string typeOf);

    double getValueOf();
    void setValueOf(double valueOf);
};

#endif /* CREDIT_H_ */
