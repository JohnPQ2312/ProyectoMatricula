#pragma once
#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include <iostream>

using namespace std;

class Register
{
private:
	Student students[30];
	Course courses[5];
	Schedule schedules[10];
	int studentCount;
	int courseCount;
	int scheduleCount;
	int registerCost;
	int credits;

public:
	Register();
	void addStudent(string name, string id, string career, int level);
	void addCourse(string code, string name, string teacher, int credits);
	void addSchedule(string day, int startHour, int endHour, string classroom);
	void calculateCost();
	void assignSchedule(int i, int j, int course);

	void showCourses();
};