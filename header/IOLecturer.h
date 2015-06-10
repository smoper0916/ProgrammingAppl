#pragma once

#include "IOHandler.h"
#include "Lecturer.h"

class IOLecturer : public IOHandler
{
public:
	IOLecturer(string fileName) :IOHandler(fileName){}
	virtual void* load(string key = "");
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);
private:
	string lecCode, name;
};