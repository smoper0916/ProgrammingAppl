#ifndef _ESTABLISHSUBJECT_H_
#define _ESTABLISHSUBJECT_H_

#include <vector>
#include "Lecturer.h"
#include "Subject.h"

struct lectTime {
	lectTime(string d, int t) : day(d), time(t) { }

	string day;
	int time;
};

class EstablishSubject {
public:
	EstablishSubject(Subject s, string lecN, vector<lectTime> lec):sub(s), lectureTime(lec), lecNum(lecN){}

	Subject getSubject(){ return sub; }

private:
	Subject sub;
	string lecNum;
	vector<lectTime> lectureTime;
};

#endif