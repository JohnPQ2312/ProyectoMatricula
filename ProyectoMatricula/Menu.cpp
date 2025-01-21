#include "Menu.h"

void Menu::showMainMenu() {
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
            menuFile();
            break;
        case 'b':
            system("cls");
            menuMaintance();
            break;
        case 'c':
            system("cls");
            menuRegister();
            break;
        case 'd':
            system("cls");
            menuConsult();
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

void Menu::menuFile() {
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
			Menu::about();
			system("pause");
            break;
        case '2':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '2');
}

void Menu::menuMaintance() {
    char opcion;
    do {
        system("cls");
        cout << "--- Menu Mantenimiento ---\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Agregar curso\n";
        cout << "3. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
			system("cls");
			Menu::studentInput();
            break;
        case '2':
			system("cls");
            Menu::courseInput();
            break;
        case '3':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '3');
}

void Menu::menuRegister() {
	if (reg.getCurrStudent() == 0) {
		cout << "No hay estudiantes registrados. Registre al menos uno para continuar.\n";
		system("pause");
		return;
	}
	else if (reg.getCurrCourse() == 0) {
		cout << "No hay cursos registrados. Registre al menos 5 para continuar.\n";
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

void Menu::menuConsult() {
    char opcion;
    do {
        system("cls");
        cout << "--- Menu Consulta ---\n";
        cout << "1. Estudiantes\n";
        cout << "2. Cursos\n";
		cout << "3. Matriculas\n";
        cout << "4. Regresar al menu principal\n";
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
			if (reg.registeredCount == 0) {
				cout << "No hay matriculas registradas.\n";
				system("pause");
			}
			else {
				Menu::consultRegistrations();
			}
            break;
        case '4':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '4');
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
		system("cls");
		reg.getAllStudents();
		system("pause");
	}
	else {
		system("cls");
		reg.showStudent(input);
		system("pause");
	}
}

void Menu::consultCourses() {
	string input;
	cout << "Ingrese el codigo o nombre del curso a consultar, o ingrese 'all' para mostrar todos los cursos: ";
	cin >> input;
	if (input == "all") {
		system("cls");
		reg.getAllCourses();
        system("pause");
	}
	else {
		system("cls");
		reg.showCourse(input);
        system("pause");
	}
}


void Menu::makeRegistration() {
    if (reg.getCurrCourse() < 5) {
        system("cls");
		cout << "No se pueden hacer matriculas, no hay suficientes cursos registrados.\n";
		system("pause");
    }
    else {
        string confirmation;
		system("cls");
        cout << "Para realizar el registro de matricula, debe revisar primero la consulta para saber cual estudiante y cuales cursos desea registrar. " << endl;
        cout << "Desea continuar con la matricula? (si/no): ";
        cin >> confirmation;

        if (confirmation == "si") {
            int studentNumber;
            int courseIndex1, courseIndex2, courseIndex3, courseIndex4, courseIndex5;
            cout << "Ingrese el numero del estudiante: ";
            cin >> studentNumber;
			studentNumber--;
            cout << "Ingrese el numero del primer curso: ";
            cin >> courseIndex1;
			courseIndex1--;
            cout << "Ingrese el numero del segundo curso: ";
            cin >> courseIndex2;
            courseIndex2--;
            cout << "Ingrese el numero del tercer curso: ";
            cin >> courseIndex3;
            courseIndex3--;
            cout << "Ingrese el numero del cuarto curso: ";
            cin >> courseIndex4;
            courseIndex4--;
            cout << "Ingrese el numero del quinto curso: ";
            cin >> courseIndex5;
            courseIndex5--;
            reg.addRegistration(studentNumber, courseIndex1, courseIndex2, courseIndex3, courseIndex4, courseIndex5);
        }
        else {
			system("cls");
            cout << "Matricula cancelada.\n";
			system("pause");

        }
    }
}

void Menu::consultRegistrations() {
	string input;
	cout << "Ingrese el ID o nombre del estudiante a consultar, o ingrese 'all' para mostrar todas las matriculas: ";
	cin >> input;
	if (input == "all") {
		system("cls");
		reg.getAllRegistrations();
		system("pause");
	}
	else {
        system("cls");
		reg.showRegisteredStudent(input);
		system("pause");
	}
}

void Menu::about() {
	system("cls");
	cout << "---Proyecto de Matricula---" << endl;
	cout << "Fecha de creacion: 08/01/2025" << endl;
	cout << "Version: 1.0" << endl;
    cout << "Link del repositorio en GitHub: https://github.com/JohnPQ2312/ProyectoMatricula" << endl;
    cout << "Este programa fue creado por: John Perez. Github: https://github.com/JohnPQ2312" << endl;
}   

