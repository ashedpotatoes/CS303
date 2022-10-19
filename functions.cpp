#include <iostream> 
#include <string>
#include <stdexcept>
#include "functions.h"
using namespace std;


// because isdigits isn't purely boolean or accurate, this function is implemented to check if the 
// string that is entered is comprised of digits, and returns true if so and false if yes 
bool isDigits(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

int search(int arr[], int size) {
    string target; 
    cout << "Which value would you like to search for?" << endl;
    cin >> target;
    // i decided to implement a catch to see if an undesired value (char or string) was inputed 
    if (isDigits(target) == false) {
        throw logic_error("Invalid data type.");
    }
    // converts string to integer, which is desired for calculations. this is repeated for the other functions. 
    int value = stoi(target);
    for (int i = 0; i < size; i++) {
        // sees if the index at a point is equal to what the user wants
        if (arr[i] == value) {
            cout << "Target value found at index: ";
            return i;
        }
    }
    // if nothing else is returned -- returns -1 
    return -1;
}


void modify(int arr[], int size) {
    string usernum, userindex;
    cout << "Which index # would you like to modify?" << endl;
        cin >> userindex;
        if (isDigits(userindex) == false) {
            throw logic_error("Invalid index type in modify.");
        }
        int userind = stoi(userindex);
        // this also checks to see if the value provided is out of bounds for the array, then throws an error to prevent problems down the road
        if (userind < 0 || userind >= size)
            throw logic_error("Invalid index in modify");

        for (int i = 0; i < size; i++) {
            if (i == userind) {
               cout << "Which number would you like to change this to?" << endl;
               cin >> usernum;
               // checks to see if the value added is an integer, if so, then proceeds. 
               if (isDigits(usernum) == false) {
                  throw logic_error("Invalid object type was added.");
               }
               int added = stoi(usernum);
               cout << "Value of the array before modification: " << endl;
               printArr(arr, size);
               cout << endl;
               arr[i] = added;
               // outputs array after the new number has been assigned to the user specified index 
               cout << "Value of the array after modification: " << endl;
               printArr(arr, size);
             }
        }
}

// adds a value to the end of the array then adds +1 to the size of the array, modifying the capacity
// which is why size is passed by reference
// also checks to make sure user entered a number to proceed. 
void addEnd(int arr[], int& size) {
    string usernum;
    cout << "Which value would you like to add to the end of this array?" << endl;
    cin >> usernum;
    if (isDigits(usernum) == true) {
       int newnum = stoi(usernum);
       arr[size] = newnum;
       size += 1;
       printArr(arr, size);
       cout << endl;
     }
     else {
       throw logic_error("Invalid data type in addEnd.");
     }
}

void eraseIndex(int arr[], int& size) {
    string userind;
    cout << "Please enter the index of the number you want to delete." << endl;
        cin >> userind;
        if (isDigits(userind) == false) {
            throw logic_error("Wrongful data type in eraseIndex.");
        }
        int userindex = stoi(userind);
        // alters size beforehand to delete last element space 
        size -= 1;
        // just a simple check here if userindex is within bounds
        if (userindex >= 0 && userindex < size) {
            for (int i = userindex; i < size; ++i) {
                // copies everything to the right one 
                arr[i] = arr[i + 1];
            }
            cout << "The new array with the deleted value is: " << endl;
            printArr(arr, size);
            cout << endl;
        }
        else {
            throw logic_error("Index out of bounds.");
        }
    
}

// plain and simple -- prints out each index of the array. if i+1 %10 is only there
// for presentation. 
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}
