#pragma once
#include <string>

using namespace std;

class Student
{
public:
	Student(string stNum, string name){ 
		this->stNum = stNum;  
		this->name = name;
	}

	void setStNum(string stNum){ this->stNum = stNum; }
	void setName(string name){ this->name = name; }

	string getStNum(){ return stNum; }
	string getName(){ return name; }
private:
	string stNum;
	string name;
};