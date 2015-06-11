#ifndef _PLAYREGISTCOURSESP_H_
#define _PLAYREGISTCOURSESP_H_

#include "Screen.h"
#include "Keypad.h"
#include "CancelSubject.h"
#include "AddSubject.h"
#include "CheckBreakdown.h"
#include "EnrollCourse.h"
#include "IOStudent.h"

/*
	������û ���α׷� ��ü ��Ʈ�ѷ�
*/

class PlayRegistCoursesP {
public:
	// ��ü ���� �Լ�
	void run();
private:
	//	�ֿ� �޴� ���� �Լ�
	void playMainMenu(string stNum);
	//	������û ���漱�� �Լ�
	void playChangeCourse(string stNum);
	//	���� ��ȸ �����Լ�
	void playCheckCourse(string stNum);

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

	// file names
	const string CE_FILE = "CourseEnrollment.dat";
	const string EC_FILE = "EstablishedCourse.dat";
	const string ST_FILE = "Student.dat";
	const string LE_FILE = "Lecturer.dat";
	const string CO_FILE = "Course.dat";
};

#endif