#include "EnrollCourse.h"

void EnrollCourse::processMenu(int menuNum){
	switch (menuNum)
	{
	case 1:

	case 2:
	case 3:
	default:
		break;
	}
}
void EnrollCourse::execute(){
	int menuNum;
	Screen().ChangeCourseMenu();
	menuNum = Keypad().getNextInt();

	if (menuNum == 4)
		return;
	processMenu(menuNum);
}