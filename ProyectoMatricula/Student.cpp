#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
	name = "";
	id = "";
	career = "";
	level = 0;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setId(string id)
{
	this->id = id;
}

void Student::setCareer(string career)
{
	this->career = career;
}

void Student::setLevel(int level)
{
	this->level = level;
}

string Student::getName()
{
	return name;
}

string Student::getId()
{
	return id;
}

string Student::getCareer()
{
	return career;
}

int Student::getLevel()
{
	return level;
}