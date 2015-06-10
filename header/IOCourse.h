#ifndef _IOCOURSE_H_
#define _IOCOURSE_H_

#include "IOHandler.h"
#include "Subject.h"

class IOCourse : public IOHandler {
public:
	IOCourse();
	
	virtual void save(void* object);
	virtual void* load(string key = "");

private:
	virtual void initialization(void* object);

	//	���� �����ڵ�, �����
	string subNum, subName;
	//	���� �г�, ����, �⵵, �б�
	int grade, credit, years, semester;

};
#endif