#include "IOEstablishedCourse.h"

void* IOEstablishedCourse::load(string key) {
	ifstream is(getFileName());

	if (!is)	return NULL;

	if (key == "")	return get(is);
	else			return get(is, key);

	return NULL;
}

void* IOEstablishedCourse::get(ifstream& is) {
	vector<EstablishSubject>* estSub = new vector<EstablishSubject>();
	string day;
	int time;


	while (true) {
		is >> years >> semester >> subNum >> lecNum;
		if (is.eof())	break;

		IOCourse ioc("Course.dat");
		vector<Subject>* v = (vector<Subject>*)ioc.load();
		if (v->empty())
			throw "교과목 리스트가 비어있습니다.";
		for (vector<Subject>::iterator iterPos = v->begin(); iterPos != v->end(); ++iterPos){
			if ((*iterPos).getSubNum() == subNum){
				subName = (*iterPos).getSubName();
				credit = (*iterPos).getCredit();
				grade = (*iterPos).getGrade();
			}
		}

		while (true) {
			is >> day >> time;
			if (is.peek() == '\n')	break;

			lectTimeTemp.push_back(lectTime(day, time));
		}
		estSub->push_back(EstablishSubject(Subject(subNum,subName,grade,credit,years,semester), lecNum, lectTimeTemp));
	}

	is.close();
	return estSub;
}

void* IOEstablishedCourse::get(ifstream& is, string key) {
	string day;
	int time;

	//is.clear(ios::beg);
	IOCourse ioc("Course.dat");
	vector<Subject>* v = (vector<Subject>*)ioc.load();
	if (v->empty())
		throw "교과목 리스트가 비어있습니다.";

	while (true) {
		is >> years >> semester >> subNum >> lecNum;
		if (is.eof())	break;



		lectTimeTemp.clear();
		while (true) {
			is >> day >> time;
			if (is.peek() == '\n')	break;

			lectTimeTemp.push_back(lectTime(day, time));
		}

		if (subNum == key) {
			for (vector<Subject>::iterator iterPos = v->begin(); iterPos != v->end(); ++iterPos){
				if ((*iterPos).getSubNum() == subNum){
					subName = (*iterPos).getSubName();
					credit = (*iterPos).getCredit();
					grade = (*iterPos).getGrade();
				}
			}
			is.close();
			return new EstablishSubject(Subject(subNum, subName, grade, credit, years, semester), lecNum, lectTimeTemp);
		}
	}
	is.close();
	return NULL;
}