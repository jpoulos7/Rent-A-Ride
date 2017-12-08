#include <iostream>
#include <string>
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "motorcycle.h"
#include "customer.h"
#include "rentalManager.h"
#include <unordered_set>

using namespace std;

RentalManager::RentalManager(){
    
}

void RentalManager::importVehicles(string filename) {

}

void RentalManager::rentVehicle(Vehicle v) {
    v.setCustomerID(2);
    cout << v.getCustomerID() << endl;
}


int main() {
    RentalManager manager;
    Car car1("Toyota", "Camry", 2016, "Blue", 4, -1);
    manager.rentVehicle(car1);

}

