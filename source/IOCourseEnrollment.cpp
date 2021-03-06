#include "IOCourseEnrollment.h"

IOCourseEnrollment::IOCourseEnrollment(string fileName) : IOHandler(fileName) {

}

void IOCourseEnrollment::save(void* object) {
	if (typeid(*(CourseApplication*)object) != typeid(CourseApplication))
		throw "알맞지 않은 타입입니다.";
	else {
		CourseApplication* cApp = (CourseApplication*)object;
		ofstream os;
		string temp;

		os.open(getFileName(), ios::in || ios::out);
		initialization(object);

		if (os.fail()) throw "파일을 열 수 없습니다.";
		if (find(object) == NULL)	throw "찾을 수 없습니다.";
				
		os.seekp(find(object), ios::beg);
		os << stNum << " ";
		
		for (list<string>::iterator iterPos = subNum.begin(); iterPos != subNum.end(); ++iterPos) {
			os << *iterPos << " ";
		}

		os << endl;
	}
}

void IOCourseEnrollment::erase(void* object) {
	if (typeid(object) != typeid(CourseApplication))
		throw "";
	else {
		CourseApplication* cA = (CourseApplication*)object;
		ofstream os;
		string temp;

		os.open(getFileName(), ios::in || ios::out);
		initialization(object);

		if (!os) throw "";
		if (find(object) == NULL)	throw "";

		os.seekp(find(object), ios::beg);
		os << " ";
	}
}

int IOCourseEnrollment::find(void* object) {
	ifstream is(getFileName());
	string temp;	int pos = 0;
	CourseApplication* cApp = (CourseApplication*)object;

	if (!is) throw "파일을 찾을 수 없습니다.";

	if (typeid(*cApp) != typeid(CourseApplication))
		throw "알맞지 않은 타입입니다.";
	else {
		while (1) {
			is >> temp;

			if (temp == cApp->getGradNum()) {
				pos = is.tellg();
				pos--;

				is.close();
				return pos;
			}
			else {
				is.seekg(0, ios::end);
				pos = is.tellg();

				is.close();
				return pos;
			}
		}
	}

	is.close();
	return NULL;
}

void* IOCourseEnrollment::load(string key) {
	ifstream is(getFileName());

	if (!is)	return NULL;

	if (key == "")		return get(is);
	else				return get(is, key);

	is.close();
	return NULL;
}

void* IOCourseEnrollment::get(ifstream& is) {
	vector<CourseApplication>* v = new vector<CourseApplication>();
	string temp;

	while (true) {
		is >> stNum;

		while (true) {
			is >> temp;
			if (temp == "\n\r")	break;

			subNum.push_back(temp);
		}

		if (is.eof())	break;
		
		v->push_back(CourseApplication(stNum, subNum));

		subNum.clear();
	}

	is.close();
	return v;
}

void* IOCourseEnrollment::get(ifstream& is, string key) {
	string temp;

	while (true) {
		is >> stNum;
		if (is.eof())	break;

		while (true) {
			is >> temp;
			if (is.peek() == '\n')	break;

			subNum.push_back(temp);
		}

		if (stNum == key)	return new CourseApplication(stNum, subNum);
	}

	is.close();
	return NULL;
}

void IOCourseEnrollment::initialization(void* object) {
	CourseApplication* cApp = (CourseApplication*)object;
	if (typeid(*cApp) != typeid(CourseApplication))
		throw "알맞지 않은 타입입니다.";
	else {
		stNum = cApp->getGradNum();
		subNum = cApp->getSubNum();
	}
}