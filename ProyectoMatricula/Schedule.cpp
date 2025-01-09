#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule()
{
	day = "";
	startHour = 0;
	endHour = 0;
	classroom = "";
}

void Schedule::setDay(string day)
{
	this->day = day;
}

void Schedule::setStartHour(int startHour)
{
	this->startHour = startHour;
}

void Schedule::setEndHour(int endHour)
{
	this->endHour = endHour;
}

void Schedule::setClassroom(string classroom)
{
	this->classroom = classroom;
}

string Schedule::getDay()
{
	return day;
}

int Schedule::getStartHour()
{
	return startHour;
}

int Schedule::getEndHour()
{
	return endHour;
}

string Schedule::getClassroom()
{
	return classroom;
}