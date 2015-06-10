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
	EstablishSubject();
	EstablishSubject(int y, int seme, string subNum, string lectNum, vector<lectTime> lcTime);

	Subject getSubject();

private:
	Subject subject;
	
	vector<lectTime> lectureTime;
};

#endif