#include "EnrollCourse.h"

void EnrollCourse::processMenu(int menuNum){
	switch (menuNum)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	default:
		break;
	}
}
void EnrollCourse::execute(string stNum){
	int menuNum;
	as.execute(stNum);

	Screen().ChangeCourseMenu();
	menuNum = Keypad().getNextInt();

	if (menuNum == 4)
		return;
	processMenu(menuNum);
	
	Screen::displayMessageLine("수강신청이 완료되었습니다.");
}