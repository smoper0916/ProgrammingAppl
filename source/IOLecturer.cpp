#include "IOLecturer.h"


void* IOLecturer::load(string key = ""){
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
void* IOLecturer::get(ifstream& is){
	vector<Lecturer>* v = new vector<Lecturer>();
	while (true){
		is >> lecCode >> name;
		if (is.eof())
			break;
		v->push_back(Lecturer(lecCode, name));
	}
	return v;
}
void* IOLecturer::get(ifstream& is, string key){
	while (true){
		is >> lecCode >> name;
		if (is.eof())
			break;
		if (lecCode == key)
			return new Lecturer(lecCode, name);
	}
	return NULL;
}