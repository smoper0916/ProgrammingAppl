#include "PlayRegistCoursesP.h"

void PlayRegistCoursesP::run() {
	string stNum;
	
	while (1) {
		try {
			Screen::displayMessage("학번을 입력하세요 : ");
			stNum = Keypad::getNextStr();

			Student* st = (Student*)IOStudent(ST_FILE).load(stNum);
			if (!st)
				throw "존재하지 않는 학번입니다.";
			playMainMenu(stNum);
		}
		catch (const char* c) {
			system("cls");
			Screen::displayMessageLine(c);
		}
	}
}

void PlayRegistCoursesP::playMainMenu(string stNum) {
	Screen::MainMenu();

	while (1) {
		switch (Keypad::getNextInt()) {
		case REGISTCOURSE:	
			EnrollCourse(CE_FILE).execute(stNum);
			break;
		case CHANGECOURSE:	
			playChangeCourse(stNum);		
			break;
		case CHECKCOURSE:	
			playCheckCourse(stNum);		
			break;
		case EXIT:
			exit(1);
		default:
			Screen::displayMessageLine("\n[오류] 선택 오류");
			break;
		}
	}
}

void PlayRegistCoursesP::playChangeCourse(string stNum)
{
	CourseApplication* ca = (CourseApplication*)IOCourseEnrollment(CE_FILE).load(stNum);
	if (!ca)
		throw "아직 수강 신청을 하지 않으셨습니다. 수강 신청 후 수강 변경 해주세요.";
	
	Screen::ChangeCourseMenu();
	Transaction* tr = NULL;

	switch (Keypad::getNextInt()) {
	case CANCELSUBJECT:		
		tr = new CancelSubject(CE_FILE);
		tr->execute(stNum);
		break;
	case ADDSUBJECT:
		tr = new AddSubject(CE_FILE, EC_FILE);
		tr->execute(stNum);
		break;
	case CHANGESUBJECT:
		Screen::displayMessageLine("과목 취소 후 과목 추가를 합니다.");
		tr = new CancelSubject(CE_FILE);
		tr->execute(stNum);
		delete tr;
		tr = new AddSubject(CE_FILE, EC_FILE);
		tr->execute(stNum);
		break;
	default:
		Screen::displayMessageLine("\n[오류] 선택 오류");
	}
}

void PlayRegistCoursesP::playCheckCourse(string stNum)
{
	Transaction* tr = NULL;

	tr = new CheckBreakdown(CE_FILE, EC_FILE);
	tr->execute(stNum);
}