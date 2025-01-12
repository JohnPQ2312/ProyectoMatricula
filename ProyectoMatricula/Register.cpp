#include "Register.h"
#include <iostream>

using namespace std;

Register::Register()
{
	studentCount = 0;
	courseCount = 0;
	registerCost = 0;
	credits = 0;
}



void Register::addStudent(string name, string id, string career, int level)
{
	if (studentCount < 30)
	{
		Student student;

		student.setName(name);

		student.setId(id);

		student.setCareer(career);

		student.setLevel(level);

		students[studentCount] = student;
		studentCount++;
	}
	else
	{
		cout << "No se pueden agregar mas estudiantes" << endl;
	}
}

int Register::getCurrStudent()
{
	return studentCount;
}

void Register::addCourse(string code, string name, string teacher, int credits, string day, int startHour, int endHour, string classroom)
{
	if (courseCount < 5)
	{
		Course course;

		course.setName(name);

		course.setCode(code);

		course.setTeacher(teacher);

		course.setCredits(credits);
		this->credits = credits;

		course.setSchedule(day, startHour, endHour, classroom);

		courses[courseCount] = course;
		courseCount++;
	}
	else
	{
		cout << "No se pueden agregar mas cursos" << endl;
	}
}

int Register::getCurrCourse()
{
	return courseCount;
}

void Register::calculateCost()
{
	registerCost = credits * 12500;
	cout << "El costo de la matricula es: " << registerCost << endl;
}