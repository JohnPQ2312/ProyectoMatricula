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
	void getAllStudents();
	void getAllCourses();

	struct Registration
	{
		Student student;
		Course courses[5];
		int cost = 0;
	}; Registration registrations[30];
	int registeredCount;

	void addRegistration(int studentIndex, int courseIndex1, int courseIndex2, int courseIndex3, int courseIndex4, int courseIndex5);
	void showRegisteredStudent(string input);
	void showCourse(string input);
};