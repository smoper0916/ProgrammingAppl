#include "AddSubject.h"

AddSubject::AddSubject(string fileName, string esFileName) : Transaction(fileName), estSubFileName(esFileName) { }

void AddSubject::execute(string stNum) {
	IOCourseEnrollment ioEnroll(getEstSubFileName());
	string num;

	Screen::displayMessage("추가하고픈 과목코드를 입력하세요 : ");
	cin >> num;

	if (!find(num))	throw "존재하지 않거나 개설되지 않은 교과목입니다.";
	else 
		ioEnroll.save(new CourseApplication(stNum, num));
}

bool AddSubject::find(string num) {
	IOEstablishedCourse ioEC(getEstSubFileName());
	
	if (typeid(*(EstablishSubject*)ioEC.load(num)) == typeid(EstablishSubject))
		return true;
	else if (typeid(*(vector<EstablishSubject>*)ioEC.load(num)) == typeid(vector<EstablishSubject>))
		return false;
	else
		return false;
}