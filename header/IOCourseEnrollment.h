#ifndef _IOCOURSEENROLLMENT_H_
#define _IOCOURSEENROLLMENT_H_

#include "IOHandler.h"
#include "CourseApplication.h"

class IOCourseEnrollment : public IOHandler {
public:
	IOCourseEnrollment(string fileName = "");

	//	�������� �Լ�
	void save(void* object);
	//	���ϻ��� �Լ�
	void erase(void* object);
	//	ã���� �ϴ� ��ġ�� ã�� �Լ�
	int find(void* object);

	virtual void* load(string key = "");
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);

private:
	virtual void initialization(void* object);

	string stNum;
	list<string> subNum;
};

#endif