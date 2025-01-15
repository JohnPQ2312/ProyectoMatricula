#pragma once
#include "Schedule.h"
#include <iostream>

using namespace std;

class Course
{
private:
	string code;
	string name;
	string teacher;
	int credits;
	Schedule schedule;

public:
	Course();
	void setCode(string code);
	void setName(string name);
	void setTeacher(string teacher);
	void setCredits(int credits);
	string getCode();
	string getName();
	string getTeacher();
	int getCredits();

	void setSchedule(string day, int startHour, int endHour, string classroom);
	string getDay();
	int getStartHour();
	int getEndHour();
	string getClassroom();
};

