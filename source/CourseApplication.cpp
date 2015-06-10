#include "CourseApplication.h"

ostream& operator<<(ostream& os, CourseApplication& ca) {
	string temp = ca.getGradNum();
	list<string> tempList = ca.getSubNum();
	
	os << temp << " ";

	for (list<string>::iterator iterPos = tempList.begin(); iterPos != tempList.end(); ++iterPos)
		os << *iterPos << " ";	
	os << endl;

	return os;
}

CourseApplication::CourseApplication(string grad, list<string> subNum)
	: gradNum(grad), subjectNum(subNum) { }

string CourseApplication::getGradNum() { return gradNum; }

list<string> CourseApplication::getSubNum() { return subjectNum; }