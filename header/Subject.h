#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <iostream>
#include <string>
using namespace std;

class Subject {
public:
	Subject();
	Subject(string subNum, string subName, int g, int cred, int y, int se);
	
	//	getter
	string getSubNum();
	string getSubName();
	int getGrade();
	int getCredit();
	int getYears();
	int getSemester();

private:
	//	�����ڵ�, �����
	string subjectNum, subjectName;
	//	�г�, ����, �⵵, �б�
	int grade, credit, years, semester;
};

#endif