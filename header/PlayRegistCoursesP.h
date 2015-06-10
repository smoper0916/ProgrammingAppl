#ifndef _PLAYREGISTCOURSESP_H_
#define _PLAYREGISTCOURSESP_H_

#include "Screen.h"
#include "Keypad.h"

/*
	������û ���α׷� ��ü ��Ʈ�ѷ�
*/

class PlayRegistCoursesP {
public:
	// ��ü ���� �Լ�
	void run();
private:
	//	�ֿ� �޴� ���� �Լ�
	void playMainMenu(int grad, string pw);
	//	������û ���漱�� �Լ�
	void playChangeCourse();
	//	���� ��ȸ �����Լ�
	void playCheckCourse();

	//	contants corresponding of mainmenu
	const static int REGISTCOURSE = 1;
	const static int CHANGECOURSE = 2;
	const static int CHECKCOURSE = 3;
	const static int EXIT = 4;

	//	contants correspoding of changecourse
	const static int CANCELSUBJECT = 1;
	const static int ADDSUBJECT = 2;
	const static int CHANGESUBJECT = 3;

	//	contants correspoding of checkcourse
	const static int STUDENTS = 1;
	const static int COURSES = 2;
};

#endif