#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
	static void MainMenu();
	static void ChangeCourseMenu();
	static void BreakdownMenu();
	static void displayMessage(string message);
	static void displayMessageLine(string message);
};

#endif