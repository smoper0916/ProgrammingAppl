#include "CancelSubject.h"

CancelSubject::CancelSubject(string fileName) : Transaction(fileName) { }

void CancelSubject::execute() {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("삭제하고픈 과목코드를 입력하세요 : ");
	cin >> num;

	if (typeid(CourseApplication) == typeid(ioEnroll.load(num))) {
		ioEnroll.erase(new CourseApplication("", num));
	}
	else throw "";	
}