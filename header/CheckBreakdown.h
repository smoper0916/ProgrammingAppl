#ifndef _CHECKBREAKDOWN_H_
#define _CHECKBREAKDOWN_H_

#include "Transaction.h"
#include "IOCourseEnrollment.h"
#include "IOEstablishedCourse.h"

class CheckBreakdown : public Transaction {
public:
	CheckBreakdown(string fileName, string esFileName):Transaction(fileName), estSubFileName(esFileName){}
	virtual void execute(string stNum);
private:
	void printByStNum();
	void printBySubject();
	string getEstSubFileName(){ return estSubFileName; }
	void setEstSubFileName(string estSubFileName){ this->estSubFileName = estSubFileName; }

	string estSubFileName; // EstablishedSubject 리스트의 파일명
};

#endif