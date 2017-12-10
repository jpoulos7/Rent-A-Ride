#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 7) {
        cout << "Usage: " << argv[0] << " <inputfile> <outputfile> <numberofwheels> <type> <maxnum> <minnum>" << endl;
    }

    srand(time(NULL));
    //Make model year color wheels id
    string colors[] = {"Black", "Blue", "Red", "Yellow", "White", "Silver", "Gray", "Green", "Brown"};
    string outfile = argv[2];
    FILE *output_file = fopen(outfile.c_str(), "a+");

    ifstream file(argv[1]);
    string linebuffer;

    int wheels = atoi(argv[3]);
    int maxnum = atoi(argv[5]);
    int minnum = atoi(argv[6]);
    string type = argv[4];
    while(getline(file, linebuffer, '\r')) {

        int numCarsRand = rand() % maxnum + minnum;

        for (int i = 0; i < numCarsRand; i++){
            int colorRand = 0 + rand() % 9;
            int yearRand = 1999 + rand() % 19;
            const int arrayNum[4] = {-1, 0, 1, 2};
            int RandIndex = rand() % 4;
            if (RandIndex == 1){
                int cust = rand() % 499;
                fprintf(output_file, "%s,%d,%s,%d,%d,%d,%s\n", linebuffer.c_str(), yearRand, colors[colorRand].c_str(), wheels, cust, 0, type.c_str());
            } else {
                fprintf(output_file, "%s,%d,%s,%d,%d,%d,%s\n", linebuffer.c_str(), yearRand, colors[colorRand].c_str(), wheels, -1, arrayNum[RandIndex], type.c_str());
            }
            //make model year color wheels id status type

        }
    }
    fclose(output_file);
}
