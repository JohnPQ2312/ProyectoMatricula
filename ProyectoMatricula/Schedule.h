#pragma once
#include <iostream>

using namespace std;

class Schedule
{
private:
	string day;
	int startHour;
	int endHour;
	string classroom;

public:
	Schedule();
	void setDay(string day);
	void setStartHour(int startHour);
	void setEndHour(int endHour);
	void setClassroom(string classroom);
	string getDay();
	int getStartHour();
	int getEndHour();
	string getClassroom();
};

