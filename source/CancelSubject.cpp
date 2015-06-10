#include "CancelSubject.h"

CancelSubject::CancelSubject(string fileName) : Transaction(fileName) { }

void CancelSubject::execute(string stNum) {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("������ ������ �ڵ带 �Է��ϼ��� : ");
	cin >> num;

	vector<CourseApplication>* v = (vector<CourseApplication>*)ioEnroll.load();

	if (v->empty())
		throw "������û ����Ʈ�� ����ֽ��ϴ�.";

	for (vector<CourseApplication>::iterator iterPos = v->begin(); iterPos != v->end(); ++iterPos)
	{
		if ((*iterPos).getGradNum() == stNum){
			list<string>& subNum = (*iterPos).getSubNum();
			for (list<string>::iterator iterPos2 = subNum.begin(); iterPos2 != subNum.end(); ++iterPos2){
				if (*iterPos2 == num){
					subNum.erase(iterPos2);
					saveVector(ioEnroll, v);
					return;
				}
			}
		}
	}
	Screen::displayMessageLine("�ش� ���� �ڵ带 ã�� �� �����ϴ�.");
}
void CancelSubject::saveVector(IOCourseEnrollment& io, vector<CourseApplication>* v){
	for (vector<CourseApplication>::iterator iterPos = v->begin(); iterPos != v->end(); ++iterPos)
		io.save(new CourseApplication(*iterPos));
}