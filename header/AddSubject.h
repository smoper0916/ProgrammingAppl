#ifndef _ADDSUBJECT_H_
#define _ADDSUBJECT_H_

#include "Transaction.h"
#include "IOCourseEnrollment.h"
#include "IOEstablishedCourse.h"

class AddSubject : public Transaction {
public:
	AddSubject(string fileName = "");

	virtual void execute();
};

#endif