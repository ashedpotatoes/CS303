#include <queue>
#include <string>
#include <stack>
#include "functions.h"

// takes the first value of the queue and moves it to the end, and then deletes it
// effectively moving everything up a spot 
void move_to_rear(queue<int>& aqueue) {
    aqueue.push(aqueue.front());
    aqueue.pop();
}

// traverses through the map and outputs the state name (key) then capital (value)
void print_map(map <string, string> mp) {
    for (auto x : mp) {
        cout << x.first << ", " << x.second << endl;
    }
}

// traverses through the map and compares the keys, if a match is found it returns the capital's name
// if not found, returns an error message
string capitalFinder(map <string, string> mp, string userkey) {
    for (auto x : mp) {
        if (x.first == userkey) {
            return x.second;
        }
    }
    string errormsg = "Sorry, but the state you entered doesn't exist. Try altering your punctuation/ spelling.";
    return errormsg;
}


// creates a string then adds characters onto it 
// because stacks are first in first out, the created string is a reverse of the original 
// string fed into it. then it deletes the original stack values to keep the loop going
// because the stack isn't passed by reference, nothing of the original word is actually deleted 
string build_reverse(stack<char> word) {
    string result;
    while (!word.empty()) {
        result += word.top();
        word.pop();
    }
    return result;
}


// takes a word and pushes the values onto queue 
void fill_stack(stack <char>& que, string wor) {
    for (char c : wor) {
        que.push(c);
    }
}

// result is initiated to be true because if a string is empty, then inherently it is a palindrome
// but the basecase is if both stacks are empty
// it compares the top elements of the reversed word & regular word (uppercase), then it deletes that character to 
// avoid an infinite loop. at the first instance of the characters not being equal, it returns false. 
// if everything matches up, then there is a palindrome
bool ispal(stack<char> wor, stack<char> w2) {
    bool result = true;
    while (!wor.empty() && !w2.empty()) {
        if (toupper(wor.top()) == toupper(w2.top())) {
            wor.pop();
            w2.pop();
            ispal(wor, w2);
        }
        else {
            return false;
        }
    }
    return result;
}

// same logic, because this is a shallow copy, nothing from main is modified, and therefore isn't deleting
// any values so it can be used multiple time in main without obstructing the queue 
void print_queue(queue<int> quea) {
    while (!quea.empty()) {
        cout << " " << quea.front();
        quea.pop();
    }
}
