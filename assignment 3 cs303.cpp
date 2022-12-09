#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include "functions.h"
using namespace std;


int main()
{
    //creating the variables for user input 
    string userstate;
    string aword;
    map<string, string> stateDataMap;
    // creates the stacks for the word and sets up the stack for the reverse 
    stack<char> word;
    stack<char> word2;
    // user inputs what they want to test
    cout << "Please enter the word you want to test to see if its a palindrome: ";
    cin >> aword;

    // fills stack, reverse, then a stack of the reverse 
    fill_stack(word, aword);
    string wordd = build_reverse(word);
    fill_stack(word2, wordd);

    if (ispal(word, word2)) {
        cout << "congrats you have a palindrome!" << endl;
    }
    else {
        cout << "the word you entered is not a palindrome." << endl;
    }
    // just statements declaring the map & altering the capital of Cali
    stateDataMap = { {"Nebraska", "Lincoln"}, {"New York", "Albany"},
    {"Ohio", "Columbus"},  {"California", "Sacramaneto"},  {"Boston", "Massachussetts"},
     {"Texas", "Austin"} };
    stateDataMap["California"] = "Los Angeles";
    print_map(stateDataMap);

    cout << "Please enter a state: ";
    // get line is used here because New York would escape regular cin 
    cin.ignore();
    getline(cin, userstate);
    cout << "The capital of the state you entered is: " << capitalFinder(stateDataMap, userstate) << endl;

    // fills the queue with numbers 
    queue <int> numbers;
    int size = 25;
    // because this operation only needed to be done once, it's in main. 
    for (int i = 0; i < size; i++) {
        numbers.push(i);
    }
    // outputs the results pre and post function 
    cout << "Queue before modification: ";
    print_queue(numbers);
    cout << endl;
    move_to_rear(numbers);
    cout << "Queue after modification: ";
    print_queue(numbers);

}
