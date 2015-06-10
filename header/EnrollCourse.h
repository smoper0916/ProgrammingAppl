#pragma once

#include "Transaction.h"
#include "AddSubject.h"
#include "CancelSubject.h"

using namespace std;

class EnrollCourse : public Transaction
{
public:
	EnrollCourse(string fileName):Transaction(fileName){}
	~EnrollCourse();
	virtual void execute(string stNum);
	void processMenu(int);
private:
	AddSubject as;
	CancelSubject cs;
};
