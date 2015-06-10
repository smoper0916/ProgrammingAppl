#pragma once

#include <string>
using namespace std;

class Lecturer
{
public:
	Lecturer(string lecCode, string name){
		this->lecCode = lecCode;
		this->name = name;
	}

	void setLecCode(string lecCode){ this->lecCode = lecCode; }
	void setName(string name){ this->name = name; }

	string getLecCode(){ return lecCode;  }
	string getName(){ return name; }
private:
	string lecCode;
	string name;
};