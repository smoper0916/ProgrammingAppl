#include "AddSubject.h"

AddSubject::AddSubject(string fileName) : Transaction(fileName) { }

void AddSubject::execute() {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("�߰��ϰ��� �����ڵ带 �Է��ϼ��� : ");
	cin >> num;

	ioEnroll.save(new CourseApplication("", num));
}
