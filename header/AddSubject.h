#ifndef _ADDSUBJECT_H_
#define _ADDSUBJECT_H_

#include "Transaction.h"
#include "IOCourseEnrollment.h"
#include "IOEstablishedCourse.h"

class AddSubject : public Transaction {
public:
	AddSubject(string fileName = "", string esFileName);

	virtual void execute(string stNum);

private:
	bool find(string num);

	//	getter, setter
	string getEstSubFileName(){ return estSubFileName; }
	void setEstSubFileName(string estSubFileName) { this->estSubFileName = estSubFileName; }

	string estSubFileName; // EstablishedSubject ����Ʈ�� ���ϸ�

};

#endif