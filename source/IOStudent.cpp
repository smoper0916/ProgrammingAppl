#include "IOStudent.h"

void* IOStudent::load(string key = ""){
	ifstream is(getFileName());
	
	if (is.fail()){
		cerr << "File Open Failed" << endl;
		return NULL;
	}
	if (key == "")
		return get(is);
	else
		return get(is, key);
}
void* IOStudent::get(ifstream& is){
	vector<Student>* v = new vector<Student>();
	while (true){
		is >> stNum >> name;
		if (is.eof())
			break;
		v->push_back(Student(stNum, name));
	}
	return v;
}
void* IOStudent::get(ifstream& is, string key){
	while (true){
		is >> stNum >> name;
		if (is.eof())
			break;
		if (stNum == key)
			return new Student(stNum, name);
	}
	return NULL;
}