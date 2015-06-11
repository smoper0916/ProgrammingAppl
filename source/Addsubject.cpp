#include "AddSubject.h"

AddSubject::AddSubject(string fileName, string esFileName) : Transaction(fileName), estSubFileName(esFileName) { }

void AddSubject::execute(string stNum) {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("추가하고픈 과목코드를 입력하세요 : ");
	cin >> num;

	if (!find(num))	throw "";
	else 
		ioEnroll.save(new CourseApplication(stNum, num));
}

bool AddSubject::find(string num) {
	IOEstablishedCourse ioEC(getEstSubFileName());

	if (typeid(ioEC.load(num)) == typeid(EstablishSubject))
		return true;
	else if (typeid(ioEC.load(num)) == typeid(vector<EstablishSubject>))
		return false;
	else
		return false;
}