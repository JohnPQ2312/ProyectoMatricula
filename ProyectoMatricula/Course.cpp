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
		cout << "1. Introducci�n a la Programaci�n" << endl;
		cout << "2. Matem�tica General" << endl;
		cout << "3. Qu�mica General" << endl;
		cout << "4. Taller de Ingenier�a" << endl;
		cout << "5. Ingl�s I" << endl;
	}
	else if (level == 2)
	{
		cout << "1. Programaci�n Orientada a Objetos" << endl;
		cout << "2. C�lculo Diferencial e Integral" << endl;
		cout << "3. F�sica General" << endl;
		cout << "4. Algebra Lineal" << endl;
		cout << "5. Ingl�s II" << endl;
	}
	else if (level == 3)
	{
		cout << "1. Estructuras de Datos" << endl;
		cout << "2. C�lculo Vectorial" << endl;
		cout << "3. F�sica II" << endl;
		cout << "4. Matem�tica Discreta" << endl;
		cout << "5. Ingl�s III" << endl;
	}
	else if (level == 4)
	{
		cout << "1. An�lisis de Algoritmos" << endl;
		cout << "2. Ecuaciones Diferenciales" << endl;
		cout << "3. F�sica III" << endl;
		cout << "4. Probabilidad y Estad�stica" << endl;
		cout << "5. Ingl�s IV" << endl;
	}
	else if (level == 5)
	{
		cout << "1. Bases de Datos" << endl;
		cout << "2. Redes de Computadoras" << endl;
		cout << "3. Sistemas Operativos" << endl;
		cout << "4. Ingenier�a de Software" << endl;
		cout << "5. Ingl�s V" << endl;
	}
	else
	{
		cout << "Nivel no encontrado" << endl;
	}
}