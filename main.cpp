#include <iostream>
#include <fstream> 
#include <exception>
#include "functions.h" 
using namespace std;

int main() {
    ifstream infile;
    // size is declared here in main so it can easily be accessed by the other functions as they are being called 
    int size = 0;
    infile.open("numbers.txt");
    // initializes an array -- then the while statement reads in the values and assigns it to an index 
    // as size increases
    int intarr[100];
    while (infile.good()) {
        int val;
        infile >> val;
        intarr[size] = val;
        size += 1;
    }
    // closes file in good practice
    infile.close();
    // tests! 
    // all of these are different try and catch blocks so that way the program can proceed & doesn't halt everything. 
    // e.what() prints out the statements that are supplied in functions.cpp, notifies user exactly where the error is and why it occured.
    try {
        cout << "Search test result." << endl;
        cout << search(intarr, size) << endl;
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
    try {
        modify(intarr, size);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    try {
        eraseIndex(intarr, size);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    try {
        addEnd(intarr, size);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    
}
