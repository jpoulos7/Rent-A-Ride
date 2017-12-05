CC = g++
CPPFLAGS = -Wall -std=c++11

main: car.o truck.o suv.o motorcycle.o vehicle.o customer.o

car.o: car.h

truck.o: truck.h

suv.o: suv.h

motorcycle.o: motorcycle.h

vehicle.o: vehicle.h

customer.o: customer.h

git:
	rm *.o
	rm main
