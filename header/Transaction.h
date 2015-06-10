#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <iostream>
#include "Keypad.h"
#include "Screen.h"

class Transaction {
public:
	Transaction(string fileName){}
	virtual void execute() = 0;

	string getFileName(){ return fileName; }
	void setFIleName(string fileName){ this->fileName = fileName; }
private:
	string fileName;
};
#endif