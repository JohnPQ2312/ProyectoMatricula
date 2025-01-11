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
	Schedule schedules[2];

public:
	Course();
	void coursebyLevel(int level);
	void setCode(string code);
	void setName(string name);
	void setTeacher(string teacher);
	void setCredits(int credits);
	void setSchedule(int scheduleN, Schedule schedule);
	string getCode();
	string getName();
	string getTeacher();
	int getCredits();
	Schedule getSchedule(int scheduleN);
};

