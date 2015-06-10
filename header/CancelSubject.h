#ifndef _CANCELSUBJECT_H_
#define _CANCELSUBJECT_H_

#include "Transaction.h"
#include "IOCourseEnrollment.h"
#include "Screen.h"

class CancelSubject : public Transaction {
public:
	CancelSubject(string fileName);

	virtual void execute(string stNum);
	void saveVector(IOCourseEnrollment& io, vector<CourseApplication>* v);
};

#endif