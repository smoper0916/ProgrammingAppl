#include "IOCourse.h"

IOCourse::IOCourse(string fileName) : IOHandler(fileName) {

}

void* IOCourse::load(string key = "") {
	ifstream is;

	is.open(getFileName());

	if (!is) throw "";
	
	while (1) {
		is >> subNum >> subName >> grade >> credit >> years >> semester;
		if (is.eof())	break;

		if (subNum == key) {
			is.close();
			return new Subject(subNum, subName, grade, credit, years, semester);
		}
	}

	is.close();

	return NULL;
}

void* IOCourse::get(ifstream& is) {
	vector<Subject>* subjects = new vector < Subject >();

	while (1) {
		is >> subNum >> subName >> grade >> credit >> years >> semester;
		if (is.eof())	break;
		
		subjects->push_back(Subject(subNum, subName, grade, credit, years, semester));
	}
}

void* IOCourse::get(ifstream& is, string key) {

}