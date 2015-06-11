#include "AddSubject.h"

AddSubject::AddSubject(string fileName, string esFileName) : Transaction(fileName), estSubFileName(esFileName) { }

void AddSubject::execute(string stNum) {
	IOCourseEnrollment ioEnroll(getEstSubFileName());
	string num;

	Screen::displayMessage("�߰��ϰ��� �����ڵ带 �Է��ϼ��� : ");
	cin >> num;

	if (!find(num))	throw "�������� �ʰų� �������� ���� �������Դϴ�.";
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