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

		while (true) {
			is >> day >> time;
			if (is.peek() == '\n')	break;

			lectTimeTemp.push_back(lectTime(day, time));
		}

		estSub->push_back(EstablishSubject(years, semester, subNum, lecNum, lectTimeTemp));
	}

	is.close();
	return estSub;
}

void* IOEstablishedCourse::get(ifstream& is, string key) {
	string day;
	int time;

	while (true) {
		is >> years >> semester >> subNum >> lecNum;
		if (is.eof())	break;

		while (true) {
			is >> day >> time;
			if (is.peek() == '\n')	break;

			lectTimeTemp.push_back(lectTime(day, time));
		}

		if (subNum == key) {
			is.close();
			return new EstablishSubject(years, semester, subNum, lecNum, lectTimeTemp);
		}
	}

	is.close();
	return NULL;
}