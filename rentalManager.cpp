#include <iostream>
#include <string>
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "motorcycle.h"
#include "customer.h"
#include "rentalManager.h"

using namespace std;

RentalManager::RentalManager(){

}


int main() {
    Car myCar("toyota", "prius", "blue", , -1);
    cout << myCar.getColor() << endl;

}
