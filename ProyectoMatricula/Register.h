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
	int studentCount;
	int courseCount;
	int registerCost;
	int credits;

public:
	Register();
	void addStudent(string name, string id, string career, int level);
	void addCourse(string code, string name, string teacher, int credits, string day, int startHour, int endHour, string classroom);
	int getCurrStudent();
	int getCurrCourse();
	void calculateCost();
};