#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include <iostream>
#include <string>
using namespace std;

class Keypad {
public:
	static int getNextInt() { 
		int inputInt;
		cin >> inputInt;
		return inputInt; 
	}
	static string getNextStr() {
		string inputStr;
		cin >> inputStr;
		return inputStr;
	}
};

#endif