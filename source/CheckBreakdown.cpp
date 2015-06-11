#include "CheckBreakdown.h"

void CheckBreakdown::execute(string stNum){
	Screen().BreakdownMenu();
	int menuNum = Keypad().getNextInt();

	switch (menuNum)
	{
	case 1:
		printByStNum();
		break;
	case 2:
		printBySubject();
		break;
	default:
		break;
	}
}

void CheckBreakdown::printByStNum()
{
	IOCourseEnrollment ice(getFileName());
	vector<CourseApplication>* v = (vector<CourseApplication>*)ice.load();
	if (!v)
		throw "아직 수강 신청을 한 사람이 없습니다.";
	cout << "< 수강신청 내역(학생별) >" << endl;
	for (vector<CourseApplication>::iterator iterPos = v->begin(); iterPos != v->end(); ++iterPos)
		cout << *iterPos << endl;
}

void CheckBreakdown::printBySubject()
{
	IOCourseEnrollment ice(getFileName());
	vector<CourseApplication>* cv = (vector<CourseApplication>*)ice.load();
	IOEstablishedCourse iec(getEstSubFileName());
	vector<EstablishSubject>* ev = (vector<EstablishSubject>*)iec.load();

	if (!cv)
		throw "아직 수강 신청을 한 사람이 없습니다.";
	else if (!ev)
		throw "아직 개설된 교과목이 존재하지 않습니다.";

	cout << "< 수강신청 내역(개설과목별) >" << endl;
	for (vector<EstablishSubject>::iterator iterPos = ev->begin(); iterPos != ev->end(); ++iterPos){
		int count = 0;
		list<string> subNum;
		for (vector<CourseApplication>::iterator iterPos2 = cv->begin(); iterPos2 != cv->end(); ++iterPos2){
			subNum = (*iterPos2).getSubNum();
			for (list<string>::iterator iterPos3 = subNum.begin(); iterPos3 != subNum.end(); ++iterPos3)
				if (*iterPos3 == (*iterPos).getSubject().getSubNum())
					count++;
		}
		cout << "개설과목코드 : " << (*iterPos).getSubject().getSubNum() << " 수강자 수 : " << count << endl;
	}
}

