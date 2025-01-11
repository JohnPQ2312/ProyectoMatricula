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

void Course::setSchedule(int scheduleN, Schedule schedule)
{
	if (scheduleN >= 0 && scheduleN < 2) {
		schedules[scheduleN] = schedule;
	}
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

Schedule Course::getSchedule(int scheduleN)
{
	if (scheduleN >= 0 && scheduleN < 2) {
		return schedules[scheduleN];
	}
}

void Course::coursebyLevel(int level)
{
	if (level == 1)
	{
		cout << "1. Introducción a la Programación" << endl;
		cout << "2. Matemática General" << endl;
		cout << "3. Química General" << endl;
		cout << "4. Taller de Ingeniería" << endl;
		cout << "5. Inglés I" << endl;
	}
	else if (level == 2)
	{
		cout << "1. Programación Orientada a Objetos" << endl;
		cout << "2. Cálculo Diferencial e Integral" << endl;
		cout << "3. Física General" << endl;
		cout << "4. Algebra Lineal" << endl;
		cout << "5. Inglés II" << endl;
	}
	else if (level == 3)
	{
		cout << "1. Estructuras de Datos" << endl;
		cout << "2. Cálculo Vectorial" << endl;
		cout << "3. Física II" << endl;
		cout << "4. Matemática Discreta" << endl;
		cout << "5. Inglés III" << endl;
	}
	else if (level == 4)
	{
		cout << "1. Análisis de Algoritmos" << endl;
		cout << "2. Ecuaciones Diferenciales" << endl;
		cout << "3. Física III" << endl;
		cout << "4. Probabilidad y Estadística" << endl;
		cout << "5. Inglés IV" << endl;
	}
	else if (level == 5)
	{
		cout << "1. Bases de Datos" << endl;
		cout << "2. Redes de Computadoras" << endl;
		cout << "3. Sistemas Operativos" << endl;
		cout << "4. Ingeniería de Software" << endl;
		cout << "5. Inglés V" << endl;
	}
	else
	{
		cout << "Nivel no encontrado" << endl;
	}
}