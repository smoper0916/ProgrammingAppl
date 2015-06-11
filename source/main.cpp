#include "PlayRegistCoursesP.h"

int main(){
	try{
		PlayRegistCoursesP p;
		p.run();
	}
	catch (char* msg){
		Screen::displayMessageLine(msg);
	}
	return 0;
}