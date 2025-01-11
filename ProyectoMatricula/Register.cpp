#include "Register.h"
#include <iostream>

using namespace std;

Register::Register()
{
	studentCount = 0;
	courseCount = 0;
	scheduleCount = 0;
	registerCost = 0;
	credits = 0;
}

void Register::addStudent(string name, string id, string career, int level)
{
	Student student;

	student.setName(name);

	student.setId(id);

	student.setCareer(career);

	student.setLevel(level);

	students[studentCount] = student;
	studentCount++;
}

void Register::addCourse(string code, string name, string teacher, int credits)
{
	Course course;

	course.setName(name);

	course.setCode(code);

	course.setTeacher(teacher);

	course.setCredits(credits);
	this->credits = credits;

	courses[courseCount] = course;
	courseCount++;
}

void Register::addSchedule(string day, int startHour, int endHour, string classroom)
{
	Schedule schedule;

	schedule.setDay(day);

	schedule.setStartHour(startHour);

	schedule.setEndHour(endHour);

	schedule.setClassroom(classroom);

	schedules[scheduleCount] = schedule;
	scheduleCount++;
}

void Register::calculateCost()
{
	registerCost = credits * 12500;
	cout << "El costo de la matricula es: " << registerCost << endl;
}

void Register::assignSchedule(int i, int j, int course)
{
	courses[course].setSchedule(0, schedules[i]);
	courses[course].setSchedule(1, schedules[j]);
}

void Register::showCourses()
{
	for (int i = 0; i < courseCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Schedule schedule = courses[i].getSchedule(j);
			cout << "Horario " << j + 1 << ": " << schedule.getDay() << " de " << schedule.getStartHour() << " a " << schedule.getEndHour() << " en " << schedule.getClassroom() << endl;
		}
		cout << endl;
	}
}