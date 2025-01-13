#pragma once
#include "Register.h"

using namespace std;

class Menu
{
public:
	Register reg;
	void mostrarMenuPrincipal();
	void menuArchivo();
	void menuMantenimiento();
	void menuMatricula();
	void menuConsulta();

	void studentInput();
	void courseInput();
	void consultStudents();
	void consultCourses();

	void makeRegistration();
};
