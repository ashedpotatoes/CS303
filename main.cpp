#include <iostream>
#include <fstream> 
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
    modify(intarr, size);
    modify(intarr, size);
    cout << "Erasing the index test: " << endl;
    eraseIndex(intarr, size);
    cout << "Adding the end to the array: " << endl;
    addEnd(intarr, size);
    cout << "testing for a value that isn't in the array: " << endl;
    cout << search(intarr, size, 300) << endl;
    cout << "testing for a value in the array: " << endl;
    cout << search(intarr, size, 5) << endl;
}