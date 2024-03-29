/**
 *
 * @file RaRGUI.cpp
 * @author John Poulos, jpoulos2
 * @author Mohammad Salad
 * @date Oct 16, 2017
 *
 * @brief ITCS 3112 Rent-A-Ride Final Project
 *
 * @section DESCRIPTION
 *
 * Header file for the Truck object.
 *
 */

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_ask.H>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "motorcycle.h"
#include "customer.h"
#include "rentalManager.h"
#include "customer.h"

/**Creating the main window*/
Fl_Double_Window win(1500, 700, "Rent-A-Ride");
/**Creating a listview for the customers*/
Fl_Hold_Browser customerView(40,80,200,200,"Customers");
/**Creating a listview for the available vehicles*/
Fl_Hold_Browser avail(280,80,225,200,"Available Vehicles");
/**Creating a listview for the cars out for rent*/
Fl_Hold_Browser rent(545,80,270,200,"Rent");
/**Creating a listview for the cars out for detail*/
Fl_Hold_Browser detail(855,80,240,200,"Out for detail");
/**Creating a listview for the cars out for repair*/
Fl_Hold_Browser repair(1135,80,240,200,"Out for repair");

Fl_Button rentVehicle(40,300,200,30,"Rent vehicle");
Fl_Button returnVehicle(280,300,225,30,"Return vehicle");
Fl_Button returnVehicleProblem(545,300,270,30,"Return Vehicle (With problem)");
Fl_Button repairVehicle(1135,300,240,30,"Repair vehicle");
Fl_Button detailVehicle(855,300,240,30,"Detail vehicle");

Fl_Input personName(100,400,300,30,"First Name");
Fl_Input personLastName(100,450,300,30,"Last Name");
Fl_Button addCustomer(100,500,300,30,"Add customer");

Fl_Input vehMake(600,400,200,30,"Vehicle Make");
Fl_Input vehModel(600,450,200,30,"Vehicle Model");
Fl_Input vehYear(600,500,200,30,"Vehicle Year");
Fl_Choice vehColor(600,550,200,30,"Vehicle Color");
Fl_Choice vehType(600,600,200,30,"Type");
Fl_Button addVehicle(600,650,200,30,"Add Vehicle");
//Search
Fl_Input searchPerson(920,400,200,30,"Search by Name: ");
Fl_Button searchPersonButton(1140,400,100,30,"Search");
Fl_Hold_Browser results(920,450,325,100,"Results");

/** RentalManager instance */
RentalManager manager;

/**
 * This function will handle updating all listview contents
 * @param none
 * @return none
 **/
void updateView() {

    customerView.clear();
    avail.clear();
    rent.clear();
    detail.clear();
    repair.clear();
    results.clear();

    vector<Customer> customerList = manager.getAllCustomers();
    for (int i = 0; i < customerList.size(); i++){
        customerView.insert(i,customerList[i].toString().c_str());
    }

    vector<Vehicle> availableList = manager.getAvailable();
    for (int i = 0; i < availableList.size(); i++){
        avail.insert(i,availableList[i].toString().c_str());
    }

    vector<Vehicle> rentedList = manager.getRented();
    for (int i = 0; i < rentedList.size(); i++){
        rent.insert(i,rentedList[i].toStringRented().c_str());
    }

    vector<Vehicle> detailList = manager.getDetail();
    for (int i = 0; i < detailList.size(); i++){
        detail.insert(i,detailList[i].toString().c_str());
    }

    vector<Vehicle> repairList = manager.getRepair();
    for (int i = 0; i < repairList.size(); i++){
        repair.insert(i,repairList[i].toString().c_str());
    }

    vector<Vehicle> foundList = manager.getFound();
    for (int i = 0; i < foundList.size(); i++){
        results.insert(i,foundList[i].toStringRented().c_str());
    }
}

/**
 * Rental callback that will shift the selected vehicle from available to rented under customer
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void rentCallback(Fl_Widget* widget, void* v){
    //std::string postSelect = (std::string) avail.text(vehicleFound) + " --- "+customer.text(customerFound);
    int cSize = customerView.size();
    int customerFound = -1;
    int vehicleFound = -1;
    int vSize = avail.size();
    //Looping through the customer list
    for(int i = 0; i < cSize; i++){
        //If the customer is selected
        if(customerView.selected(i+1)){
            //Update customerFound to store position of customer
            customerFound = (i+1);
            //Break from for loop
            i = cSize+1;
        }
    }
    for(int i = 0; i < vSize; i++){
        if(avail.selected(i+1)){
            vehicleFound = (i+1);
            i = vSize+1;
        }
    }

    if(customerFound == -1){
        fl_alert("Select the customer who will rent the vehicle");
    }
    else if(vehicleFound == -1){
        fl_alert("Select the vehicle to be rented");
    }
    else{
        std::string custSelect = (std::string) customerView.text(customerFound);
        std::string vehSelect = (std::string) avail.text(vehicleFound);
        std::string token;
        std::string cust[3];
        int count = 0;
        istringstream ss(custSelect);
        while(getline(ss, token, ' ')) {
            cust[count] = token;
            count++;
        }
        Customer tempCust(cust[0], cust[1], atoi(cust[2].c_str()));

        std::string veh[5];
        count = 0;
        istringstream sd(vehSelect);
        while(getline(sd, token, ' ')) {
            veh[count] = token;
            count++;
        }
        if(veh[4] == "C") {
            Car tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,-1,-1,"C");
            manager.rentVehicle(&tempVeh, &tempCust);
        }
        if(veh[4] == "T") {
            Truck tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,-1,-1,"T");
            manager.rentVehicle(&tempVeh, &tempCust);
        }
        if(veh[4] == "S") {
            SUV tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,-1,-1,"S");
            manager.rentVehicle(&tempVeh, &tempCust);
        }

        updateView();
    }
}

/**
 * Customer callback that will add a new customer to the browser
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void customerCallback(Fl_Widget* widget, void* v){
    //Set customerID to -1
    //Fl_Hold_Browser* customer = (Fl_Hold_Browser*)v;
    //int cSize = customer->size();
    string fname = (std::string) personName.value();
    string lname = (std::string) personLastName.value();
    if (fname == "" || lname == ""){
        fl_alert("Please enter a first and last name");
        return;
    }

    Customer temp(fname, lname, -1);
    manager.addCustomer(temp);
    updateView();
}

/**
 * Return callback that will return a vehicle to the out for detail shop
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void returnCallback(Fl_Widget* widget, void* v){
    int vSize = rent.size();
    int vehicleFound = -1;
    for(int i = 0; i < vSize; i++){
        if(rent.selected(i+1)){
            vehicleFound = (i+1);
            i = vSize+1;
        }
    }

    if(vehicleFound == -1){
        fl_alert("No vehicle selected!");
        return;
    }
    else{
        std::string vehSelect = (std::string) rent.text(vehicleFound);
        std::string token;
        std::string veh[6];
        int count = 0;
        istringstream sd(vehSelect);
        while(getline(sd, token, ' ')) {
            veh[count] = token;
            count++;
        }

        if(veh[4] == "C") {
            Car tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"C");
            manager.returnVehicle(tempVeh);
        } else if(veh[4] == "T") {
            Truck tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"T");
            manager.returnVehicle(tempVeh);
        } else if(veh[4] == "S") {
            SUV tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"S");
            manager.returnVehicle(tempVeh);
        }
        updateView();
    }
}

/**
 * Return callback that will shift the selected vehicle from available to out under repair
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void returnProblemCallback(Fl_Widget* widget, void* v){
    int vSize = rent.size();
    int vehicleFound = -1;
    for(int i = 0; i < vSize; i++){
        if(rent.selected(i+1)){
            vehicleFound = (i+1);
            i = vSize+1;
        }
    }
    if(vehicleFound == -1){
        fl_alert("No vehicle selected!");
        return;
    }
    else{
        std::string vehSelect = (std::string) rent.text(vehicleFound);

        std::string token;
        std::string veh[6];
        int count = 0;
        istringstream sd(vehSelect);
        while(getline(sd, token, ' ')) {
            veh[count] = token;
            count++;
        }

        if(veh[4] == "C") {
            Car tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"C");
            manager.returnVehicleProblems(tempVeh);
        } else if(veh[4] == "T") {
            Truck tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"T");
            manager.returnVehicleProblems(tempVeh);
        } else if(veh[4] == "S") {
            SUV tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"S");
            manager.returnVehicleProblems(tempVeh);
        }
        updateView();
    }
}

/**
 * Detail callback that will shift the selected vehicle from detail to available
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void detailCallback(Fl_Widget* widget, void* v){
    int vSize = detail.size();
    int vehicleFound = -1;
    for(int i = 0; i < vSize; i++){
        if(detail.selected(i+1)){
            vehicleFound = (i+1);
            i = vSize+1;
        }
    }

    if(vehicleFound == -1){
        fl_alert("No vehicle selected!");
        return;

    } else{
        std::string vehSelect = (std::string) detail.text(vehicleFound);
        std::string token;
        std::string veh[5];
        int count = 0;
        istringstream sd(vehSelect);
        while(getline(sd, token, ' ')) {
            veh[count] = token;
            count++;
        }

        if(veh[4] == "C") {
            Car tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"C");
            manager.detailVehicle(tempVeh);
        } else if(veh[4] == "T") {
            Truck tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"T");
            manager.detailVehicle(tempVeh);
        } else if(veh[4] == "S") {
            SUV tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"S");
            manager.detailVehicle(tempVeh);
        }
        updateView();
    }
}

/**
 * Repair callback that will shift the selected vehicle from repair to available
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void repairCallback(Fl_Widget* widget, void* v){
    int vSize = repair.size();
    int vehicleFound = -1;
    for(int i = 0; i < vSize; i++){
        if(repair.selected(i+1)){
            vehicleFound = (i+1);
            i = vSize+1;
        }
    }
    if(vehicleFound == -1){
        fl_alert("No vehicle selected!");
        return;
    }
    else{
        std::string vehSelect = (std::string) repair.text(vehicleFound);

        std::string token;
        std::string veh[5];
        int count = 0;
        istringstream sd(vehSelect);
        while(getline(sd, token, ' ')) {
            veh[count] = token;
            count++;
        }

        if(veh[4] == "C") {
            Car tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"C");
            manager.repairVehicle(tempVeh);
        } else if(veh[4] == "T") {
            Truck tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"T");
            manager.repairVehicle(tempVeh);
        } else if(veh[4] == "S") {
            SUV tempVeh(veh[0],veh[1],atoi(veh[2].c_str()),veh[3],4,atoi(veh[5].c_str()),0,"S");
            manager.repairVehicle(tempVeh);
        }
        updateView();
    }
}

/**
 * addVehicle callback that will add a new vehicle to the list
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void addVehCallback(Fl_Widget* widget, void* v){
    string colors[] = {"Black", "Blue", "Red", "Yellow", "White", "Silver", "Gray", "Green", "Brown"};
    string make = (std::string) vehMake.value();
    string model = (std::string) vehModel.value();
    string year = (string) vehYear.value();
    int color = vehColor.value();
    int type = vehType.value();

    if (make == "" || model == "" || year == "" || color == -1 || type == -1){
        fl_alert("Please fill out the entire form");
        return;
    }

    if (type == 0){
        Car temp(make, model, atoi(year.c_str()), colors[color], 4, -1, -1, "C");
        manager.addVehicle(temp);
    } else if (type == 1) {
        Truck temp(make, model, atoi(year.c_str()), colors[color], 4, -1, -1, "C");
        manager.addVehicle(temp);
    } else if (type == 2) {
        SUV temp(make, model, atoi(year.c_str()), colors[color], 4, -1, -1, "C");
        manager.addVehicle(temp);
    }

    updateView();
}

/**
 * Search callback that will shift the selected vehicle from available to rented under customer
 *
 * @param widget, the widget to be editted as a result of clicking
 * @param v pointer to the button being clicked
 *
 **/
void searchNameCallback(Fl_Widget* widget, void* v){
    string token = (string) searchPerson.value();
    if (token == "") {
        fl_alert("Please enter a first name, last name, or id to search for.");
        return;
    }
    manager.searchName(token);
    updateView();
}

int main(int argc, char **argv) {

    addCustomer.callback(customerCallback, &customerView);
    rentVehicle.callback(rentCallback, NULL);
    returnVehicle.callback(returnCallback, NULL);
    returnVehicleProblem.callback(returnProblemCallback, NULL);
    detailVehicle.callback(detailCallback, NULL);
    repairVehicle.callback(repairCallback, NULL);
    addVehicle.callback(addVehCallback, &avail);
    searchPersonButton.callback(searchNameCallback, NULL);

    vehType.add("Car");
    vehType.add("Truck");
    vehType.add("SUV");

    vehColor.add("Black");
    vehColor.add("Blue");
    vehColor.add("Red");
    vehColor.add("Yellow");
    vehColor.add("White");
    vehColor.add("Silver");
    vehColor.add("Gray");
    vehColor.add("Green");
    vehColor.add("Brown");
    manager.importVehicles("dataset/rand_out.csv");
    manager.importCustomers("dataset/customers.csv");
    updateView();
    win.end();
    //win.resizable(browser);
    win.show(argc,argv);
    return(Fl::run());
}
