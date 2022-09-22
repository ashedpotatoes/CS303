#include <iostream> 
#include "functions.h"
using namespace std;


int search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        // sees if the index at a point is equal to what the user wants
        if (arr[i] == target) {
            return i;
        }
    }
    // if nothing else is returned -- returns -1 
    return -1;
}


void modify(int arr[], int size) {
    int usernum, userindex;
    cout << "Which index # would you like to modify?" << endl;
    cin >> userindex;
    // the if and else if statements are here to catch a valid index is entered  
    if (0 <= userindex && userindex < size) {
        for (int i = 0; i < size; i++) {
            if (i == userindex) {
                cout << "Which number would you like to change this to?" << endl;
                cin >> usernum;
                cout << "Value of the array before modification: " << endl;
                printArr(arr, size);
                cout << endl;
                arr[i] = usernum;
                // outputs array after the new number has been assigned to the user specified index 
                cout << "Value of the array after modification: " << endl;
                printArr(arr, size);
            }
        }
    }
    else {
        cout << "Invalid index." << endl;
    }
}

// adds a value to the end of the array then adds +1 to the size of the array, modifying the capacity
// which is why size is passed by reference
// also checks to make sure user entered a number to proceed. 
void addEnd(int arr[], int& size) {
    int usernum;
    cout << "Which value would you like to add to the end of this array?" << endl;
    cin >> usernum;
    arr[size] = usernum;
    size += 1;
    printArr(arr, size); 
}

void eraseIndex(int arr[], int& size) {
    int userind;
    cout << "Please enter the index of the number you want to delete." << endl;
    cin >> userind;
    // the primary if statement & else statements are there to make sure a digit is entered by the user
    // then proceeds with copying the information from each digit on the left onto the one
    // to the right -- then deletes the size by 1 (passed by ref again) to change capacity
    // because it's a void function there is no harm no foul in just outputting the errors in console 
    if (userind >= 0 && userind < size) {
        for (int i = userind; i < size; ++i) {
            arr[i] = arr[i + 1];
            size -= 1;
        }
        cout << "The new array with the deleted value is: " << endl;
        printArr(arr, size);
        cout << endl;
    }
    else {
        cout << "Invalid index." << endl;
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