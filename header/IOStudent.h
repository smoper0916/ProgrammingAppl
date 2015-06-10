#pragma once

#include "IOHandler.h"

class IOStudent : public IOHandler
{
public:
	IOStudent();
	virtual void save(void* object);
	virtual void* load(string key = "");
private:

};

IOStudent::IOStudent()
{

}
