#pragma once

#include "IOHandler.h"
#include "Student.h"
#include <iostream>

using namespace std;

class IOStudent : public IOHandler
{
public:
	IOStudent(string fileName):IOHandler(fileName){}
	virtual void* load(string key = "");
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);
private:
	string stNum, name;
};