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

void Register::getAllStudents()
{
	for (int i = 0; i < studentCount; i++)
	{
		cout << "Estudiante: " << i << endl;
		cout << "Nombre: " << students[i].getName() << endl;
		cout << "ID: " << students[i].getId() << endl;
		cout << "Carrera: " << students[i].getCareer() << endl;
		cout << "Nivel: " << students[i].getLevel() << endl;
		cout << endl;
	}
}

void Register::getAllCourses()
{
	for (int i = 0; i < courseCount; i++)
	{
		cout << "Curso: " << i << endl;
		cout << "Nombre: " << courses[i].getName() << endl;
		cout << "Codigo: " << courses[i].getCode() << endl;
		cout << "Profesor: " << courses[i].getTeacher() << endl;
		cout << "Creditos: " << courses[i].getCredits() << endl;
		cout << "Horario: " << courses[i].getDay() << " de " << courses[i].getStartHour() << " a " << courses[i].getEndHour() << " en el aula " << courses[i].getClassroom() << endl;
		cout << endl;
	}
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
			for (int i = 0; i < registeredCount; i++)
			{
				if (registrations[i].student.getId() == students[studentIndex].getId())
				{
					cout << "El estudiante ya está matriculado, por favor, registre a otro estudiante." << endl;
					return;
				}
			}

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

			registrations[registeredCount] = registration;
			registeredCount++;

			cout << "Matricula realizada con exito" << endl;
		}
		else
		{
			cout << "No se pueden agregar más matrículas" << endl;
		}
	}
	else {
		cout << "Hay conflicto en los horarios, realice la matricula nuevamente." << endl;
	}
}

void Register::showRegisteredStudent(string input)
{
	bool studentFound = false;
	for (int i = 0; i < registeredCount; i++)
	{
		if ((registrations[i].student.getId() == input) || (registrations[i].student.getName() == input))
		{
			cout << "Matricula: " << i << endl;
			cout << "Estudiante: " << registrations[i].student.getName() << endl;
			cout << "Carrera: " << registrations[i].student.getCareer() << endl;
			cout << "Nivel: " << registrations[i].student.getLevel() << endl;
			cout << "ID: " << registrations[i].student.getId() << endl;
			cout << endl;
			cout << "Cursos matriculados: " << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << "Nombre: " << registrations[i].courses[j].getName() << endl;
			}
			cout << "Costo: " << registrations[i].cost << endl;
			cout << endl;
			studentFound = true;
		}
	}
	if (studentFound == false)
	{
		cout << "Estudiante no encontrado" << endl;
	}
}

void Register::showCourse(string input) {
	bool courseFound = false;
	for (int i = 0; i < courseCount; i++) {
		if ((courses[i].getCode() == input) || (courses[i].getName() == input)) {
			cout << "Curso: " << i << endl;
			cout << "Nombre: " << courses[i].getName() << endl;	
			cout << "Codigo: " << courses[i].getCode() << endl;
			cout << "Profesor: " << courses[i].getTeacher() << endl;
			cout << "Creditos: " << courses[i].getCredits() << endl;
			cout << "Horario: " << courses[i].getDay() << " de " << courses[i].getStartHour() << " a " << courses[i].getEndHour() << " en el aula " << courses[i].getClassroom() << endl;
			cout << endl;
			courseFound = true;
		}
	}
	if (courseFound == false) {
		cout << "Curso no encontrado" << endl;
	}
}