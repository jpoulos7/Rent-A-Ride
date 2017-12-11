CC = g++
CPPFLAGS = -Wall -std=c++11
LDFLAGS = -lfltk

RaRGUI: RaRGUI.o rentalManager.o car.o truck.o suv.o motorcycle.o vehicle.o customer.o rentalManager.o
	rm *.o

rentalManager.o: rentalManager.h

car.o: car.h

truck.o: truck.h

suv.o: suv.h

motorcycle.o: motorcycle.h

vehicle.o: vehicle.h

customer.o: customer.h

rentalManager.o: rentalManager.h

git:
	rm *.o
