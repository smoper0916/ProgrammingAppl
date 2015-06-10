#pragma once

#include "Transaction.h"
#include "AddSubject.h"
#include "CancelSubject.h"

using namespace std;

class EnrollCourse : public Transaction
{
public:
	EnrollCourse();
	~EnrollCourse();
	virtual void execute();
	void processMenu(int);
private:
	AddSubject as;
	CancelSubject cs;
};
void EnrollCourse::execute(){
	int menuNum;
	Screen().ChangeCourseMenu();
	menuNum = Keypad().getNextInt();

	if (menuNum == 4)
		return;
	processMenu(menuNum);
}