#ifndef _IOCOURSE_H_
#define _IOCOURSE_H_

#include "IOHandler.h"
#include "Subject.h"

class IOCourse : public IOHandler {
public:
	IOCourse(string fileName = "");
	
	virtual void* load(string key = "");
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);

private:

	//	���� �����ڵ�, �����
	string subNum, subName;
	//	���� �г�, ����, �⵵, �б�
	int grade, credit, years, semester;
};
#endif