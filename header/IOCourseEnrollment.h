#ifndef _IOCOURSEENROLLMENT_H_
#define _IOCOURSEENROLLMENT_H_

#include "IOHandler.h"
#include "CourseApplication.h"

class IOCourseEnrollment : public IOHandler {
public:
	IOCourseEnrollment(string fileName = "");

	//	�������� �Լ�
	void save(void* object);
	//	ã���� �ϴ� ��ġ�� ã�� �Լ�
	int find(void* object);

	virtual void* load(string key = "");

private:
	virtual void initialization(void* object);

	string stNum;
	list<string> subNum;
};

#endif