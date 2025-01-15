#pragma once
#include "Register.h"

using namespace std;

class Menu
{
public:
	Register reg;
	void showMainMenu();
	void menuFile();
	void menuMaintance();
	void menuRegister();
	void menuConsult();

	void studentInput();
	void courseInput();
	void consultStudents();
	void consultCourses();
	void consultRegistrations();

	void makeRegistration();

	void about();
};
