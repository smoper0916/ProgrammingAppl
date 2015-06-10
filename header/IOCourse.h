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

	//	받을 과목코드, 과목명
	string subNum, subName;
	//	받을 학년, 학점, 년도, 학기
	int grade, credit, years, semester;

};
#endif