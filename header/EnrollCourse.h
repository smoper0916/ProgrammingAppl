#pragma once

#include "Transaction.h"
#include "AddSubject.h"
#include "CancelSubject.h"

using namespace std;

class EnrollCourse : public Transaction
{
public:
	EnrollCourse(string fileName):Transaction(fileName){
		as = new AddSubject(fileName, "EstablishedCourse.dat");
		cs = new CancelSubject(fileName);
	}

	virtual void execute(string stNum);
	void processMenu(int);
private:
	AddSubject* as;
	CancelSubject* cs;
};
