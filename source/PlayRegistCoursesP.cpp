#include "PlayRegistCoursesP.h"

void PlayRegistCoursesP::run() {
	int gradNum;
	string password;
	
	while (1) {
		try {
			Screen::displayMessage("�й��� ����� �Է��ϼ��� : ");
			gradNum = Keypad::getNextInt();
			password = Keypad::getNextStr();

			playMainMenu(gradNum, password);
		}
		catch (const char* c) {
			Screen::displayMessageLine(c);
		}
	}
}

void PlayRegistCoursesP::playMainMenu(int grad, string pw) {
	Screen::MainMenu();
	
	while (1) {
		switch (Keypad::getNextInt()) {
		case REGISTCOURSE:	break;
		case CHANGECOURSE:	playChangeCourse();		break;
		case CHECKCOURSE:	playCheckCourse();		break;
		case EXIT:
			throw "\n�����մϴ�.";
		default:
			Screen::displayMessageLine("\n[����] ���� ����");
			break;
		}
	}
}

void PlayRegistCoursesP::playChangeCourse() {
	Screen::ChangeCourseMenu();

	switch (Keypad::getNextInt()) {
	case CANCELSUBJECT:		case ADDSUBJECT:	case CHANGESUBJECT:
		break;
	default:
		Screen::displayMessageLine("\n[����] ���� ����");
	}
}

void PlayRegistCoursesP::playCheckCourse() {
	Screen::BreakdownMenu();

	switch (Keypad::getNextInt()) {
	case STUDENTS: case COURSES:
		break;
	default:
		Screen::displayMessageLine("\n[����] ���� ����");
	}
}