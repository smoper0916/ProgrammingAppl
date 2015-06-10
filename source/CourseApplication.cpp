#include "CourseApplication.h"

CourseApplication::CourseApplication(string grad, list<string> subNum)
	: gradNum(grad), subjectNum(subNum) { }

string CourseApplication::getGradNum() { return gradNum; }

list<string> CourseApplication::getSubNum() { return subjectNum; }

ostream& operator<<(ostream& os, CourseApplication& ca){
	os << "�й� : " << ca.getGradNum() << " ������ �ڵ� : ";

	list<string> subNum = ca.getSubNum();
	for (list<string>::iterator iterPos = subNum.begin(); iterPos != subNum.end(); ++iterPos)
		os << *iterPos << " ";
	os << endl;
	return os;
}