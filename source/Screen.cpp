#include "Screen.h"

void Screen::MainMenu() {
	cout << "=======================" << endl;
	cout << "[1] 수강신청" << endl;
	cout << "[2] 수강신청 변경" << endl;
	cout << "[3] 수강신청 내역 조회" << endl;
	cout << "[4] 종료" << endl;
	cout << "=======================" << endl;
	cout << "원하는 기능을 선택하세요 : ";
}

void Screen::ChangeCourseMenu() {
	cout << "======================" << endl;
	cout << "[1] 과목 취소" << endl;
	cout << "[2] 과목 추가" << endl;
	cout << "[3] 과목 변경" << endl;
	cout << "======================" << endl;
	cout << "원하는 기능을 선택하세요 : ";
}

void Screen::BreakdownMenu() {
	cout << "====================" << endl;
	cout << "[1] 학생별" << endl;
	cout << "[2] 개설 과목별" << endl;
	cout << "====================" << endl;
	cout << "원하는 기능을 선택하세요 : ";
}

void Screen::displayMessage(string message) {
	cout << message;
}

void Screen::displayMessageLine(string message) {
	cout << message << endl;
}