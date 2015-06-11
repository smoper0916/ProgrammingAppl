#include "PlayRegistCoursesP.h"

void PlayRegistCoursesP::run() {
	string stNum;
	
	while (1) {
		try {
			Screen::displayMessage("�й��� �Է��ϼ��� : ");
			stNum = Keypad::getNextStr();

			Student* st = (Student*)IOStudent(ST_FILE).load(stNum);
			if (!st)
				throw "�������� �ʴ� �й��Դϴ�.";
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
			Screen::displayMessageLine("\n[����] ���� ����");
			break;
		}
	}
}

void PlayRegistCoursesP::playChangeCourse(string stNum)
{
	CourseApplication* ca = (CourseApplication*)IOCourseEnrollment(CE_FILE).load(stNum);
	if (!ca)
		throw "���� ���� ��û�� ���� �����̽��ϴ�. ���� ��û �� ���� ���� ���ּ���.";
	
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
		Screen::displayMessageLine("���� ��� �� ���� �߰��� �մϴ�.");
		tr = new CancelSubject(CE_FILE);
		tr->execute(stNum);
		delete tr;
		tr = new AddSubject(CE_FILE, EC_FILE);
		tr->execute(stNum);
		break;
	default:
		Screen::displayMessageLine("\n[����] ���� ����");
	}
}

void PlayRegistCoursesP::playCheckCourse(string stNum)
{
	Transaction* tr = NULL;

	tr = new CheckBreakdown(CE_FILE, EC_FILE);
	tr->execute(stNum);
}