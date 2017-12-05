/**
 *
 * @file customer.h
 * @author John Poulos, jpoulos2
 * @date Dec 2, 2017
 *
 * @brief ITCS 3112 Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for Customer definitions.
 *
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

class Customer {
private:

    string firstName;
    string lastName;
    int customerID;

public:

    //Constructors
    Customer();
    Customer(string firstName, string lastName, int custoerID);

    void setFirstName(string firstName);
    string getFirstName();
    void setLastName(string lastName);
    string getLastName();
    void setCustomerID(int customerID);
    int getCustomerID();

    string toString();


};

#endif
