#ifndef _COURSEAPPLICATION_H_
#define _COURSEAPPLICATION_H_

#include <list>
#include "Student.h"

class CourseApplication {
	friend ostream& operator<<(ostream& os, CourseApplication& ca);
public:
	CourseApplication(string grad, string num);
	CourseApplication(string grad, list<string> subNum);

	string getGradNum();
	list<string> getSubNum();

private:
	string gradNum;
	list<string> subjectNum;
};
#endif