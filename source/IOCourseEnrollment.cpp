#include "IOCourseEnrollment.h"

IOCourseEnrollment::IOCourseEnrollment(string fileName) : IOHandler(fileName) {

}

void IOCourseEnrollment::save(void* object) {
	if (typeid(object) != typeid(CourseApplication))
		throw "";
	else {
		CourseApplication* cApp = (CourseApplication*)object;
		ofstream os;
		string temp;

		initialization(object);

		os.open(getFileName(), ios::in || ios::out);

		if (!os) throw "";

		os.seekp(find(object), ios::beg);
		os << stNum << " ";
		
		for (list<string>::iterator iterPos = subNum.begin(); iterPos != subNum.end(); ++iterPos) {
			os << *iterPos << " ";
		}

		os << endl;
	}
}

int IOCourseEnrollment::find(void* object) {
	ifstream is;
	string temp;	int pos = 0;

	if (typeid(object) != typeid(CourseApplication))
		throw "";
	else {
		CourseApplication* cApp = (CourseApplication*)object;

		is.open(getFileName());

		if (!is) throw "";

		while (1) {
			is >> temp;

			if (temp == cApp->getGradNum()) {
				pos = is.tellg();
				pos--;

				is.close();
				return pos;
			}
		}
	}

	is.close();
	return NULL;
}

void* IOCourseEnrollment::load(string key) {
	ifstream is;
	string temp;

	is.open(getFileName());

	if (!is) throw "";

	while (1) {
		is >> stNum;

		while (1) {
			is >> temp;
			if (temp == "\n\r")	break;

			subNum.push_back(temp);
		}

		if (is.eof())	break;

		if (stNum == key) {
			is.close();
			return new CourseApplication(stNum, subNum);
		}
	}

	is.close();

	return NULL;
}

void IOCourseEnrollment::initialization(void* object) {
	if (typeid(object) != typeid(CourseApplication))
		throw "";
	else {
		CourseApplication* cApp = (CourseApplication*)object;

		stNum = cApp->getGradNum();
		subNum = cApp->getSubNum();
	}
}