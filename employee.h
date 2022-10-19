#pragma once
#include <iostream>
using namespace std;


// the base class for employees
class Employee {
	// attribute 
protected:
	char type;
	string employeeName;
	int hoursWorked;
public:
	// base constructor 
	Employee() { type = ' '; employeeName = " ";hoursWorked = 0; }
	Employee(char t, string name, int hours) {
		type = t;
		employeeName = name;
		hoursWorked = hours;
	}
	// all of these are virtual so the specifics could be defined in the derived classes, each calculation is different
	virtual double Salary() = 0;
	virtual double healthCareContributions() = 0;
	virtual double vacationDays() = 0;
	virtual void print() {
		cout << employeeName << " is an employee who has worked " << hoursWorked << " this week.";
	}
};

class Professional : public Employee {
public:
	Professional() : Employee() {};
	// constructor for Professional, initializes names and hours but the type is cemented as P.
	Professional( string name, int hours) :Employee('P', name, hours) {
		employeeName = name;
		hoursWorked = hours;
	}
	// here are all of the rules that i made -- professional vs nonprofessional are going to have different scalars. 
	// their monthly salary is 6000
	double Salary() {
		return 6000.00;
	}
	// their healthcare contribution is dependent on how much they worked. 
	double healthCareContributions() {
		return hoursWorked * 40* .12;
	}
	// they get a solid 50 vacation days a year. 
	double vacationDays() {
		return 50.00;
	}
	void print() {
		cout << employeeName << " is a professional employee" << endl;
		cout << "who has worked " << hoursWorked << " hours this week. " << endl;
		cout << "and has made $" << Salary() << " this month and has " << endl;
		cout << vacationDays() << " vacation days and contributed $" << healthCareContributions() << " to their healthcare." << endl << endl;

	}
};

class Nonprofessional : public Employee {
public:
	Nonprofessional() : Employee() {};
	// constructor -- takes in everything but the type is cemented as n
	Nonprofessional(string name,  int hours) :Employee('N', name,hours) {
		employeeName = name;
		hoursWorked = hours;
	}
	// values that are unique to the nonprofessional subclass of employee. 
	double Salary() {
		return hoursWorked * 25.00;
	}
	// same deal as professional but with different adjustments
	double healthCareContributions() {
		return hoursWorked * 25 * .12;
	}
	// not a set value, 5% of their hours worked goes into their vacation days. 
	double vacationDays() {
		return hoursWorked * .05;
	}
	void print() {
		cout << employeeName << " is a nonprofessional employee" << endl;
		cout << "who has worked " << hoursWorked << " hours this week " << endl;
		cout << "and has made $" << Salary() << " this week and earned " << endl;
		cout << vacationDays() << " extra hours to their vacation and contributed $" << healthCareContributions() <<  " to their healthcare." << endl << endl;

	}
};

