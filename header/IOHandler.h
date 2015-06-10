#ifndef _IOHandler_H_
#define _IOHandler_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class IOHandler {
public:
	IOHandler(string fileName = "") { this->fileName = fileName; }
	~IOHandler();

	void setFileName(string fileName){ this->fileName = fileName; }
	string getFileName(){ return fileName; }

	virtual void* load(string key = "") = 0;
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);

private:
	string fileName;
};

#endif