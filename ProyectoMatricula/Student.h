#pragma once
#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	string id;
	string career;
	int level;

public:
	Student();
	void setName(string name);
	void setId(string id);
	void setCareer(string career);
	void setLevel(int level);
	string getName();
	string getId();
	string getCareer();
	int getLevel();
};

