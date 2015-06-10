#ifndef _IOESTABLISHEDCOURSE_H_
#define _IOESTABLISHEDCOURSE_H_

#include "IOHandler.h"
#include "EstablishSubject.h"

class IOEstablishedCourse : public IOHandler {
public:
	IOEstablishedCourse();

	virtual void save(void* object);
	virtual void* load(string key = "");

private:
	virtual void initialization(void* object);
	

};
#endif