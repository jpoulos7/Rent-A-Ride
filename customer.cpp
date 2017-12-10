/**
 *
 * @file cusomter.cpp
 * @author John Poulos, jpoulos2
 * @date Dec 2, 2017
 *
 * @brief ITCS 3112 Final Project
 *
 * @section DESCRIPTION
 *
 * Implementation of Customer.
 *
 */

#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

/**
* Class constructor.
**/
Customer::Customer(){

}

/**
* Class constructor takes in strings firstName and lastName
* and int customerID to populate those parameters for a specific customer.
**/
Customer::Customer(string firstName, string lastName, int customerID){
    this->firstName = firstName;
    this->lastName = lastName;
    this->customerID = customerID;
}

/**
* Function populates firstName with string.
* @param firstName
* @return none
**/
void Customer::setFirstName(string firstName){
    this->firstName = firstName;
}


/**
* Fucntion returns the firstName of Customer.
* @return firstName
**/
string Customer::getFirstName(){
    return firstName;
}

/**
* Function populates lastName with string.
* @param firstName
* @return none
**/
void Customer::setLastName(string lastName){
    this->lastName = lastName;
}

/**
* Fucntion returns the lastName of Customer.
* @return lastName
**/
string Customer::getLastName(){
    return lastName;
}

/**
* Function populates customerID with integer.
* @param customerID
* @return none
**/
void Customer::setCustomerID(int customerID){
    this->customerID = customerID;
}

/**
* Fucntion returns the customerID of Customer.
* @return customerID
**/
int Customer::getCustomerID(){
    return customerID;
}

/**
* Fucntion returns a string formated to "firstName lastName customerID"
**/
string Customer::toString(){
    return firstName + " " + lastName + " " + to_string(customerID);
}
