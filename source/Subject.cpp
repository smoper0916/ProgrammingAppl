#include "Subject.h"

Subject::Subject(string subNum, string subName, int g, int cred, int y, int se)
	: subjectNum(subNum), subjectName(subName), grade(g), credit(cred), years(y), semester(se) { }

string Subject::getSubNum() { return subjectNum; }
string Subject::getSubName() { return subjectName; }
int Subject::getGrade() { return grade; }
int Subject::getCredit() { return credit; }
int Subject::getYears() { return years; }
int Subject::getSemester() { return semester; }

