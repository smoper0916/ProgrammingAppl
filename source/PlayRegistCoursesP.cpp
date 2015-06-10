#include "PlayRegistCoursesP.h"

void PlayRegistCoursesP::run() {
	int gradNum;
	string password;
	
	while (1) {
		try {
			Screen::displayMessage("학번과 비번을 입력하세요 : ");
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
			throw "\n종료합니다.";
		default:
			Screen::displayMessageLine("\n[오류] 선택 오류");
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
		Screen::displayMessageLine("\n[오류] 선택 오류");
	}
}

void PlayRegistCoursesP::playCheckCourse() {
	Screen::BreakdownMenu();

	switch (Keypad::getNextInt()) {
	case STUDENTS: case COURSES:
		break;
	default:
		Screen::displayMessageLine("\n[오류] 선택 오류");
	}
}