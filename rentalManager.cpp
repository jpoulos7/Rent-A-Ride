#include <iostream>
#include <string>
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "motorcycle.h"
#include "customer.h"

using namespace std;




int main() {
    Car myCar("toyota", "prius", "blue", 4, -1);
    cout << myCar.getColor() << endl;

}
