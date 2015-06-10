#include "CancelSubject.h"

CancelSubject::CancelSubject(string fileName) : Transaction(fileName) { }

void CancelSubject::execute() {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("�����ϰ��� �����ڵ带 �Է��ϼ��� : ");
	cin >> num;

	if (typeid(CourseApplication) == typeid(ioEnroll.load(num))) {
		ioEnroll.erase(new CourseApplication("", num));
	}
	else throw "";	
}