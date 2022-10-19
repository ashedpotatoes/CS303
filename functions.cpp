#include "employee.h"
#include <iostream>
using namespace std; 

char menu() {
	cout << "What would you like to do?" << endl;
	cout << "A - add employee" << endl;
	cout << "B - print out employee list." << endl;
	cout << "Q - quit the function." << endl;
	char userinput; 
	cout << "Enter your choice here: " << endl;
	cin >> userinput; 
	return userinput; 
}

bool isDigits(string str) {
	return str.find_first_not_of("0123456789.") == string::npos;
}