#ifndef _IOCOURSEENROLLMENT_H_
#define _IOCOURSEENROLLMENT_H_

#include "IOHandler.h"
#include "CourseApplication.h"

class IOCourseEnrollment : public IOHandler {
public:
	IOCourseEnrollment();

	virtual void save(void* object);
	virtual void* load(string key = "");

private:
	virtual void initialization(void* object);


};

#endif