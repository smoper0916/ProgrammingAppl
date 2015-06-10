#include "AddSubject.h"

AddSubject::AddSubject(string fileName) : Transaction(fileName) { }

void AddSubject::execute() {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("추가하고픈 과목코드를 입력하세요 : ");
	cin >> num;

	ioEnroll.save(new CourseApplication("", num));
}
