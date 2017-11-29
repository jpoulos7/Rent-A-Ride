CC = g++
CPPFLAGS = -Wall -std=c++11

main: car.o vehicle.o

car.o: car.h

vehicle.o: vehicle.h

