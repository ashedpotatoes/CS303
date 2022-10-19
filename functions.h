#pragma once 
#include <iostream> 
#include <fstream> 
#include <string>
using namespace std;

//pre: takes in a string 
//post: returns if whether or not a provided string is a digit
bool isDigits(string s);

// pre: takes in the array & size
// post: returns index of the value if found, returns -1 otherwise   
int search(int arr[], int size);

// pre: takes in the array and size
// post: changes the value of the array at an index
void modify(int arr[], int size);

// pre: takes in the array and size
// post: adds a user specified number at the end of the array & modifies array size 
void addEnd(int arr[], int& size);

// pre: takes in the array and size
// post: deletes a value at the user specified index, modifies array size 
void eraseIndex(int arr[], int& size);

// pre: takes in array and size
// post: nothing 
void printArr(int arr[], int size);
