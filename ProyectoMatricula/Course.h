#pragma once
#include <iostream>

using namespace std;

class Course
{
private:
	string code;
	string name;
	string teacher;
	int credits;

public:
	Course();
	void setCode(string code);
	void setName(string name);
	void setTeacher(string teacher);
	void setCredits(int credits);
	string getCode();
	string getName();
	string getTeacher();
	int getCredits();
};

