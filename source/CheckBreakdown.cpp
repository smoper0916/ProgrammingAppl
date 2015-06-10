#include "CheckBreakdown.h"

void CheckBreakdown::execute(){
	Screen().BreakdownMenu();
	int menuNum = Keypad().getNextInt();

	IOCourseEnrollment ice(getFileName());
	vector<CourseApplication>* v = ice.load();


}