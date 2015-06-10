#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include <iostream>
#include <string>
using namespace std;

class Keypad {
public:
	static int getNextInt() { 
		cin >> inputInt;
		return inputInt; 
	}
	static string getNextStr() {
		cin >> inputStr;
		return inputStr;
	}
private:
	static int inputInt;
	static string inputStr;
};

#endif