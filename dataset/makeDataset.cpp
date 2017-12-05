//Read in csv with make, model, numwheels
//do this for car, truck, suv, and motorcycle
//Randomly pick a color and set customer num -1
//generate a range of this type of vehicle (maybe 50-125?)
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    string infile = argv[1];
    string outfile = argv[2];

    ifstream inFile;
    inFile.open(infile.c_str());
    string line;

    while(getline(inFile, line)){
        cout << line << endl;
    }
}
