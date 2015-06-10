#ifndef _CHECKBREAKDOWN_H_
#define _CHECKBREAKDOWN_H_

#include "Transaction.h"
#include "IOCourseEnrollment.h"
#include "IOEstablishedCourse.h"

class CheckBreakdown : public Transaction {
public:
	CheckBreakdown(string fileName):Transaction(fileName){}
	virtual void execute();
private:
	void printByStNum();
	void printBySubject();
};

#endif