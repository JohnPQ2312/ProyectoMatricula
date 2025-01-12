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
};
