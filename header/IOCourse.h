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

	//	받을 과목코드, 과목명
	string subNum, subName;
	//	받을 학년, 학점, 년도, 학기
	int grade, credit, years, semester;
};
#endif