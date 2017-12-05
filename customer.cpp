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

Customer::Customer(){

}

Customer::Customer(string firstName, string lastName, int customerID){

}

void Customer::setFirstName(string firstName){
    this->firstName = firstName;
}

string Customer::getFirstName(){
    return firstName;
}

void Customer::setLastName(string lastName){
    this->lastName = lastName;
}

string Customer::getLastName(){
    return lastName;
}

void Customer::setCustomerID(int customerID){
    this->customerID = customerID;
}

int Customer::getCustomerID(){
    return customerID;
}

string Customer::toString(){
    return firstName + " " + lastName + " " + to_string(customerID);
}
