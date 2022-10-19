// cs303assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "employee.h"
#include "functions.h";

int main()
{
    // initializes a vector of employees 
    vector<Employee*> employees;
    
    // here is a simple while loop -- while the user so desires, it will keep adding employees & printing the list of current employees
    // Q will make it stop. It distinguishes professional vs nonprofessional here as well. 
    // also the is digits catch is here to make sure that nothing goes to hours / hours worked that isn't supposed to
    char userchoice = menu(); 
    while (userchoice != 'Q') {
        if (userchoice == 'A') {
            char employeetype;
            string employeename, hoursworked;
            cout << "P for professional, N for Non-professional." << endl;
            cout << "Which kind of employee would you like to add? : ";
            cin >> employeetype;
            cout << "What is the name of the employee? : ";
            cin >> employeename;
            cout << "How many hours have they worked this week? Enter an integer: ";
            cin >> hoursworked;
            if (employeetype == 'P') {
                if (isDigits(hoursworked) == true) {
                    int hours = stoi(hoursworked);
                    Employee* temp = new Professional(employeename, hours);
                    employees.push_back(temp);
                }
                   
            }
            if (employeetype == 'N') {
                int hours = stoi(hoursworked);
                Employee* temp = new Nonprofessional(employeename, hours);
                employees.push_back(temp);
            }
        }
        // prints. the -> makes it so that each employee subclass' individual print is utilized. 
        if (userchoice == 'B') {
            for (int i = 0; i < employees.size(); i++) {
                employees.at(i)->print();
            }
        }
        // asks for user choice again here to prevent in infitive loop. 
        userchoice = menu();
    }
    cout << "Thank you!" << endl;
       
     
}
