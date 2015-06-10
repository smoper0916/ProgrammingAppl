#pragma once
 
#include <string>
#include <fstream>

using namespace std;

class IOHandler
{
public:
	IOHandler(string fileName = ""){ this->fileName = fileName; }
	~IOHandler();

	void setFileName(string fileName){ this->fileName = fileName; }
	string getFileName(){ return fileName; }

	virtual void save(void* object) = 0;
	virtual void* load(string key="") = 0;
	virtual void initialization(void* object) = 0;
private:
	string fileName;
};