#ifndef _IOESTABLISHEDCOURSE_H_
#define _IOESTABLISHEDCOURSE_H_

#include "EstablishSubject.h"
#include "IOCourse.h"

class IOEstablishedCourse : public IOHandler {
public:
	IOEstablishedCourse(string fileName):IOHandler(fileName){}

	virtual void* load(string key = "");
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);

private:
	string subNum, subName, lecNum;
	int years, semester, credit, grade;
	vector<lectTime> lectTimeTemp;
};
#endif