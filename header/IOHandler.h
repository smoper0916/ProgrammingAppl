#ifndef _IOHandler_H_
#define _IOHandler_H_

#include <string>
#include <fstream>

#include <vector>
using namespace std;

class IOHandler {
public:
	IOHandler(string fileName = "") { this->fileName = fileName; }
	~IOHandler();

	void setFileName(string fileName){ this->fileName = fileName; }
	string getFileName(){ return fileName; }

	virtual void* load(string key = "") = 0;

private:
	string fileName;
};

#endif