#include "Screen.h"

void Screen::MainMenu() {
	cout << "=======================" << endl;
	cout << "[1] ������û" << endl;
	cout << "[2] ������û ����" << endl;
	cout << "[3] ������û ���� ��ȸ" << endl;
	cout << "[4] ����" << endl;
	cout << "=======================" << endl;
	cout << "���ϴ� ����� �����ϼ��� : ";
}

void Screen::ChangeCourseMenu() {
	cout << "======================" << endl;
	cout << "[1] ���� ���" << endl;
	cout << "[2] ���� �߰�" << endl;
	cout << "[3] ���� ����" << endl;
	cout << "======================" << endl;
	cout << "���ϴ� ����� �����ϼ��� : ";
}

void Screen::BreakdownMenu() {
	cout << "====================" << endl;
	cout << "[1] �л���" << endl;
	cout << "[2] ���� ����" << endl;
	cout << "====================" << endl;
	cout << "���ϴ� ����� �����ϼ��� : ";
}

void Screen::displayMessage(string message) {
	cout << message;
}

void Screen::displayMessageLine(string message) {
	cout << message << endl;
}