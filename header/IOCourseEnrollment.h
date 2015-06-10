#ifndef _IOCOURSEENROLLMENT_H_
#define _IOCOURSEENROLLMENT_H_

#include "IOHandler.h"
#include "CourseApplication.h"

class IOCourseEnrollment : public IOHandler {
public:
	IOCourseEnrollment(string fileName = "");

	//	파일저장 함수
	void save(void* object);
	//	파일삭제 함수
	void erase(void* object);
	//	찾고자 하는 위치를 찾는 함수
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