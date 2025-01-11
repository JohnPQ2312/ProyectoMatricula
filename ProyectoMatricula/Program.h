#pragma once
#include "Register.h"
#include <iostream>
class Program
{
private:
	string registers[30];
	int registerCount;

public:
	Program();
	void addRegister(Student student, Course course);
};

