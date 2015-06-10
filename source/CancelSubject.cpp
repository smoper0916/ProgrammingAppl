#include "CancelSubject.h"

CancelSubject::CancelSubject(string fileName) : Transaction(fileName) { }

void CancelSubject::execute(string stNum) {
	IOCourseEnrollment ioEnroll(getFileName());
	string num;

	Screen::displayMessage("삭제할 과목의 코드를 입력하세요 : ");
	cin >> num;

	vector<CourseApplication>* v = (vector<CourseApplication>*)ioEnroll.load();

	if (v->empty())
		throw "수강신청 리스트가 비어있습니다.";

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
	Screen::displayMessageLine("해당 과목 코드를 찾을 수 없습니다.");
}
void CancelSubject::saveVector(IOCourseEnrollment& io, vector<CourseApplication>* v){
	for (vector<CourseApplication>::iterator iterPos = v->begin(); iterPos != v->end(); ++iterPos)
		io.save(new CourseApplication(*iterPos));
}