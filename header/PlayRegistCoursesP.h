#ifndef _PLAYREGISTCOURSESP_H_
#define _PLAYREGISTCOURSESP_H_

#include "Screen.h"
#include "Keypad.h"

/*
	수강신청 프로그램 전체 컨트롤러
*/

class PlayRegistCoursesP {
public:
	// 전체 실행 함수
	void run();
private:
	//	주요 메뉴 실행 함수
	void playMainMenu(int grad, string pw);
	//	수강신청 변경선택 함수
	void playChangeCourse();
	//	내역 조회 선택함수
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