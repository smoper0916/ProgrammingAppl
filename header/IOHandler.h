#pragma once
 
#include <string>
#include <fstream>

using namespace std;

class IOHandler
{
public:
	IOHandler(string fileName = ""){ this->fileName = fileName; }
	~IOHandler();

	void setFileName(string fileName){ this->fileName = fileName; }
	string getFileName(){ return fileName; }

	virtual void save(void* object) = 0;
	virtual void* load(string key="") = 0;
	// key == ""면 파일 내용 전체를 불러옴. 리스트로 리턴할 때는 Vector로 Return
	// void*는 모든 type을 받아오고 리턴할 수 있음. 쓸 때는 (객체*) 이렇게 캐스트 해주면 정상적으로 사용가능.
	// 해당 객체가 어떤 객체인지 알고 싶으면 typeid(객체) == typeid(Class명) 을 이용하자. 해당 Class로 만든 객체이면 저게 true로 나옴.

private:
	string fileName;
};