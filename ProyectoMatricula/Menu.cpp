#include "Menu.h"

void Menu::mostrarMenuPrincipal() {
    char opcion;

    do {
        system("cls");
        cout << "--- Menu Principal ---\n";
        cout << "a. Archivo\n";
        cout << "b. Mantenimiento\n";
        cout << "c. Matricula\n";
        cout << "d. Consulta\n";
        cout << "e. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 'a':
			system("cls");
            menuArchivo();
            break;
        case 'b':
            system("cls");
            menuMantenimiento();
            break;
        case 'c':
            system("cls");
            menuMatricula();
            break;
        case 'd':
            system("cls");
            menuConsulta();
            break;
        case 'e':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
			system("pause");
        }
    } while (opcion != 'e');
}

void Menu::menuArchivo() {
    char opcion;
    do {
        system("cls");
        cout << "--- Menu Archivo ---\n";
        cout << "1. Acerca de\n";
        cout << "2. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            cout << "Informacion del programa...\n";
            break;
        case '2':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '2');
}

void Menu::menuMantenimiento() {
    char opcion;
    do {
        system("cls");
        cout << "--- Menu Mantenimiento ---\n";
        cout << "1. Estudiantes\n";
        cout << "2. Cursos\n";
        cout << "3. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
			Menu::studentInput();
            break;
        case '2':
            Menu::courseInput();
            break;
        case '3':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '3');
}

void Menu::menuMatricula() {
	if (reg.getCurrStudent() == 0) {
		cout << "No hay estudiantes registrados. Registre al menos uno para continuar.\n";
		system("pause");
		return;
	}
	else if (reg.getCurrCourse() == 0) {
		cout << "No hay cursos registrados. Registre al menos uno para continuar.\n";
		system("pause");
		return;
	}
    else {
        char opcion;
        do {
            system("cls");
            cout << "--- Menu Matricula ---\n";
            cout << "1. Registro de Matricula\n";
            cout << "2. Regresar al menu principal\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case '1':
                Menu::makeRegistration();
                break;
            case '2':
                return;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
            }
        } while (opcion != '2');
    }
}

void Menu::menuConsulta() {
    char opcion;
    do {
        system("cls");
        cout << "--- Menu Consulta ---\n";
        cout << "1. Estudiantes\n";
        cout << "2. Cursos\n";
        cout << "3. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
			if (reg.getCurrStudent() == 0) {
				cout << "No hay estudiantes registrados.\n";
                system("pause");
			}
			else {
                Menu::consultStudents();
			}
            break;
        case '2':
			if (reg.getCurrCourse() == 0) {
				cout << "No hay cursos registrados.\n";
                system("pause");
			}
			else {
				Menu::consultCourses();
			}
            break;
        case '3':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '3');
}



void Menu::studentInput() {
	string name, id, career;
	int level;
	cout << "Ingrese el nombre del estudiante: ";
	cin >> name;
	cout << "Ingrese el ID del estudiante: ";
	cin >> id;
	cout << "Ingrese la carrera del estudiante: ";
	cin >> career;
	cout << "Ingrese el nivel del estudiante (del 1 al 5): ";
	cin >> level;
	reg.addStudent(name, id, career, level);
}

void Menu::courseInput() {
	string code, name, teacher, day, classroom;
	int credits, startHour, endHour;
	cout << "Ingrese el codigo del curso: ";
	cin >> code;
	cout << "Ingrese el nombre del curso: ";
	cin >> name;
	cout << "Ingrese el nombre del profesor: ";
	cin >> teacher;
	cout << "Ingrese la cantidad de creditos: ";
	cin >> credits;
	cout << "Ingrese el dia del curso (Lunes, Martes, Miercoles, Jueves, Viernes): ";
	cin >> day;

    while (day != "Lunes" && day != "Martes" && day != "Miercoles" && day != "Jueves" && day != "Viernes")
    {
        cout << "Dia no valido o mal escrito, ingrese un dia valido (Lunes, Martes, Miercoles, Jueves, Viernes): ";
        cin >> day;
    }
	
    cout << "Ingrese la hora de inicio del curso: ";
	cin >> startHour;
	cout << "Ingrese la hora de finalizacion del curso: ";
	cin >> endHour;
	cout << "Ingrese el salon del curso: ";
	cin >> classroom;
	reg.addCourse(code, name, teacher, credits, day, startHour, endHour, classroom);
}

void Menu::consultStudents() {
	string input;
	cout << "Ingrese el ID o nombre del estudiante a consultar, o ingrese 'all' para mostrar todos los estudiantes: ";
	cin >> input;

	if (input == "all") {
		reg.getAllStudents();
	}
	else {
		reg.showRegisteredStudent(input);
	}
}

void Menu::consultCourses() {
	string input;
	cout << "Ingrese el codigo o nombre del curso a consultar, o ingrese 'all' para mostrar todos los cursos: ";
	cin >> input;
	if (input == "all") {
		reg.getAllCourses();
	}
	else {
		reg.showCourse(input);
	}
}


void Menu::makeRegistration() {
    string confirmation;
    cout << "Para realizar el registro de matricula, debe revisar primero la consulta para saber cual estudiante y cuales cursos desea registrar. " << endl;
	cout << "Desea continuar con la matricula? (si/no): ";
	cin >> confirmation;

	if (confirmation == "si") {
        int studentNumber;
        int courseIndex1, courseIndex2, courseIndex3, courseIndex4, courseIndex5;
        cout << "Ingrese el numero del estudiante: ";
        cin >> studentNumber;
        cout << "Ingrese el numero del primer curso: ";
        cin >> courseIndex1;
        cout << "Ingrese el numero del segundo curso: ";
        cin >> courseIndex2;
        cout << "Ingrese el numero del tercer curso: ";
        cin >> courseIndex3;
        cout << "Ingrese el numero del cuarto curso: ";
        cin >> courseIndex4;
        cout << "Ingrese el numero del quinto curso: ";
        cin >> courseIndex5;
        reg.addRegistration(studentNumber, courseIndex1, courseIndex2, courseIndex3, courseIndex4, courseIndex5);
	}
	else {
		cout << "Matricula cancelada.\n";
	}
}