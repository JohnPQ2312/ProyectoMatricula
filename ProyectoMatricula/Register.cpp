#include "Register.h"
#include <iostream>

using namespace std;

Register::Register()
{
	studentCount = 0;
	courseCount = 0;
	registerCost = 0;
	credits = 0;
	registeredCount = 0;
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

void Register::addRegistration(int studentIndex, int courseIndex1, int courseIndex2, int courseIndex3, int courseIndex4, int courseIndex5)
{
	bool scheduleConflict = false;

	int courseVector[5] = { courseIndex1, courseIndex2, courseIndex3, courseIndex4, courseIndex5 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i != j)
			{
				if (courses[courseVector[i]].getDay() == courses[courseVector[j]].getDay())
				{
					if (courses[courseVector[i]].getStartHour() >= courses[courseVector[j]].getStartHour() && courses[courseVector[i]].getStartHour() <= courses[courseVector[j]].getEndHour())
					{
						scheduleConflict = true;
					}
					else if (courses[courseVector[i]].getEndHour() >= courses[courseVector[j]].getStartHour() && courses[courseVector[i]].getEndHour() <= courses[courseVector[j]].getEndHour())
					{
						scheduleConflict = true;
					}
				}
			}
		}
	}

	if (scheduleConflict == false) {
		if (registeredCount < 30)
		{
			Registration registration;
			registration.student = students[studentIndex];

			registration.courses[0] = courses[courseIndex1];
			registration.courses[1] = courses[courseIndex2];
			registration.courses[2] = courses[courseIndex3];
			registration.courses[3] = courses[courseIndex4];
			registration.courses[4] = courses[courseIndex5];

			for (int i = 0; i < 5; i++)
			{
				registration.cost += registration.courses[i].getCredits() * 12500;
			}

			for (int i = 0; i < registeredCount; i++)
			{
				if (registrations[i].student.getId() == registration.student.getId())
				{
					cout << "El estudiante ya esta matriculado, porfavor, registre a otro estudiante." << endl;
					return;
				}
				else {
					registrations[registeredCount] = registration;
					registeredCount++;
				}
			}
		}
		else
		{
			cout << "No se pueden agregar mas matriculas" << endl;
		}
	}
	else {
		cout << "Hay conflicto en los horarios, realice la matricula nuevamente." << endl;
	}
}

void Register::showRegisteredStudent(int studentIndex)
{
	cout << "Matricula: " << studentIndex << endl;
	cout << "Estudiante: " << students[studentIndex].getName() << endl;
	cout << "Carrera: " << students[studentIndex].getCareer() << endl;
	cout << "Nivel: " << students[studentIndex].getLevel() << endl;
	cout << "ID: " << students[studentIndex].getId() << endl;
	cout << endl;
	cout << "Cursos matriculados: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Nombre: " << registrations[studentIndex].courses[i].getName() << endl;
	}
	cout << "Costo: " << registrations[studentIndex].cost << endl;
}