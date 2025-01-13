#include "Course.h"
#include <iostream>

using namespace std;

Course::Course()
{
	code = "";
	name = "";
	teacher = "";
	credits = 0;
}

void Course::setSchedule(string day, int startHour, int endHour, string classroom)
{
	Schedule schedule;

	schedule.setDay(day);

	schedule.setStartHour(startHour);

	schedule.setEndHour(endHour);

	schedule.setClassroom(classroom);

	this->schedule = schedule;
}

void Course::setCode(string code)
{
	this->code = code;
}

void Course::setName(string name)
{
	this->name = name;
}

void Course::setTeacher(string teacher)
{
	this->teacher = teacher;
}

void Course::setCredits(int credits)
{
	this->credits = credits;
}

string Course::getCode()
{
	return code;
}

string Course::getName()
{
	return name;
}

string Course::getTeacher()
{
	return teacher;
}

int Course::getCredits()
{
	return credits;
}

string Course::getDay()
{
	return schedule.getDay();
}

int Course::getStartHour()
{
	return schedule.getStartHour();
}

int Course::getEndHour()
{
	return schedule.getEndHour();
}

string Course::getClassroom()
{
	return schedule.getClassroom();
}