#pragma once
#include <iostream>
#include <stack>
#include <map>
#include <queue>

using namespace std;

//pre: accepts a filled queue 
//post: modifies the queue and moves the first element to the back
void move_to_rear(queue<int>& aqueue);

//pre: takes a stack and a word 
//post: puts the characters of the string in a stack
void fill_stack(stack <char>& que, string wor);

//pre: takes a stack of a string 
//post: returns the reverse of the word 
string build_reverse(stack<char> word);

//pre: takes in two seperate stacks 
//post: returns if the stacks are equal to eachother 
bool ispal(stack<char> wor, stack<char> w2);

//pre: takes in a map 
//post: prints both keys and their values 
void print_map(map <string, string> mp);

//pre: takes in the user's argument and accepts a map 
//post: returns the value found at the user's key, or outputs if it is not found
string capitalFinder(map <string, string> mp, string userkey);

//pre: accepts a queue 
//post: outputs the values 
void print_queue(queue<int> quea);