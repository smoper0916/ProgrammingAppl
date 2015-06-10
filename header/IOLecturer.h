#pragma once

#include "IOHandler.h"

class IOLecturer : public IOHandler
{
public:
	IOLecturer();
	virtual void save(void* object);
	virtual void* load(string key = "");
private:

};

IOLecturer::IOLecturer()
{

}
