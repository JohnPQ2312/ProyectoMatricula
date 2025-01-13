#pragma once
#include "Schedule.h"
#include <iostream>

using namespace std;

class Course
{
private:
	Schedule schedule;
	string code;
	string name;
	string teacher;
	int credits;

public:
	Course();
	void setSchedule(string day, int startHour, int endHour, string classroom);
	void setCode(string code);
	void setName(string name);
	void setTeacher(string teacher);
	void setCredits(int credits);
	string getCode();
	string getName();
	string getTeacher();
	int getCredits();
	string getDay();
	int getStartHour();
	int getEndHour();
	string getClassroom();
};

