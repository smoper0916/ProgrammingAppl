#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <iostream>
#include "Keypad.h"
#include "Screen.h"

class Transaction {
public:
	virtual void execute() = 0;
private:


};
#endif