#pragma once

#include "Transaction.h"

class EnrollCourse : public Transaction
{
public:
	EnrollCourse();
	~EnrollCourse();
	virtual void execute();
private:

};
void EnrollCourse::execute(){

}
EnrollCourse::EnrollCourse()
{

}

EnrollCourse::~EnrollCourse()
{

}