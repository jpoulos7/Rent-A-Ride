#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 6){
        cout << "Usage: " << argv[0] << " <inputfile> <outputfile> <numberofwheels> <maxnum> <minnum>" << endl;
    }

    srand(time(NULL));
    //Make model year color wheels id
    string colors[] = {"Black", "Blue", "Red", "Yellow", "White", "Silver", "Gray", "Green", "Brown"};
    string outfile = argv[2];
    FILE *output_file = fopen(outfile.c_str(), "a+");

    ifstream file(argv[1]);
    string linebuffer;

    int wheels = atoi(argv[3]);
    int maxnum = atoi(argv[4]);
    int minnum = atoi(argv[5]);
    while(getline(file, linebuffer, '\r')) {

        int numCarsRand = rand() % maxnum + minnum;

        for (int i = 0; i < numCarsRand; i++){
            int colorRand = 0 + rand() % 9;
            int yearRand = 1999 + rand() % 19;
            fprintf(output_file, "%s,%d,%s,%d,%d\n", linebuffer.c_str(), yearRand, colors[colorRand].c_str(), wheels, -1);
        }
    }
    fclose(output_file);
}
