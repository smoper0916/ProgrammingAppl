#ifndef _IOESTABLISHEDCOURSE_H_
#define _IOESTABLISHEDCOURSE_H_

#include "IOHandler.h"
#include "EstablishSubject.h"

class IOEstablishedCourse : public IOHandler {
public:
	IOEstablishedCourse();

	virtual void* load(string key = "");
	virtual void* get(ifstream& is);
	virtual void* get(ifstream& is, string key);

private:
	virtual void initialization(void* object);
	
	string subNum, lecNum;
	int years, semester;
	vector<lectTime> lectTimeTemp;
};
#endif