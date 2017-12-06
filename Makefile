CC = g++
CPPFLAGS = -Wall -std=c++11

rentalManager: car.o truck.o suv.o motorcycle.o vehicle.o customer.o rentalManager.o

car.o: car.h

truck.o: truck.h

suv.o: suv.h

motorcycle.o: motorcycle.h

vehicle.o: vehicle.h

customer.o: customer.h

rentalManager.o: rentalManager.h

git:
	rm *.o
	rm main
	rm rentalManager
