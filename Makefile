CC = g++
CPPFLAGS = -Wall -std=c++11

main: car.o truck.o vehicle.o

car.o: car.h

truck.o: truck.h

vehicle.o: vehicle.h

