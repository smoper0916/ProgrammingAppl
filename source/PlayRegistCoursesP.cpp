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
	string stNum = to_string(grad);

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
			throw "\n�����մϴ�.";
		default:
			Screen::displayMessageLine("\n[����] ���� ����");
			break;
		}
	}
}

void PlayRegistCoursesP::playChangeCourse(string stNum)
{
	Screen::ChangeCourseMenu();
	Transaction* tr = NULL;

	switch (Keypad::getNextInt()) {
	case CANCELSUBJECT:		
		tr = new CancelSubject(CE_FILE);
		tr->execute(stNum);
		break;
	case ADDSUBJECT:
		tr = new AddSubject(CE_FILE);
		tr->execute(stNum);
		break;
	case CHANGESUBJECT:
		Screen::displayMessageLine("���� ��� �� ���� �߰��� �մϴ�.");
		tr = new CancelSubject(CE_FILE);
		tr->execute(stNum);
		delete tr;
		tr = new AddSubject(CE_FILE);
		tr->execute(stNum);
		break;
	default:
		Screen::displayMessageLine("\n[����] ���� ����");
	}
}

void PlayRegistCoursesP::playCheckCourse(string stNum)
{
	Screen::BreakdownMenu();
	Transaction* tr = NULL;

	tr = new CheckBreakdown(CE_FILE, ES_FILE);
	tr->execute(stNum);
}