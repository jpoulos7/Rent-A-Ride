CC = g++
CPPFLAGS = -Wall -std=c++11

main: car.o truck.o suv.o vehicle.o

car.o: car.h

truck.o: truck.h

suv.o: suv.h

vehicle.o: vehicle.h

