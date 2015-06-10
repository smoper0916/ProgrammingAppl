#include "CourseApplication.h"

CourseApplication::CourseApplication(string grad, list<string> subNum)
	: gradNum(grad), subjectNum(subNum) { }

string CourseApplication::getGradNum() { return gradNum; }

list<string> CourseApplication::getSubNum() { return subjectNum; }