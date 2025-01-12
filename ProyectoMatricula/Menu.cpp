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
        cout << "\--- Menu Archivo ---\n";
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
        cout << "--- Menu Mantenimiento ---\n";
        cout << "1. Estudiantes\n";
        cout << "2. Cursos\n";
        cout << "3. Horarios\n";
        cout << "4. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            cout << "Gestion de estudiantes...\n";
            break;
        case '2':
            cout << "Gestion de cursos...\n";
            break;
        case '3':
            cout << "Gestion de horarios...\n";
            break;
        case '4':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '4');
}

void Menu::menuMatricula() {
    char opcion;
    do {
        cout << "--- Menu Matricula ---\n";
        cout << "1. Registro de Matricula\n";
        cout << "2. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            cout << "Registrando matricula...\n";
            break;
        case '2':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '2');
}

void Menu::menuConsulta() {
    char opcion;
    do {
        cout << "--- Menu Consulta ---\n";
        cout << "1. Estudiantes\n";
        cout << "2. Cursos\n";
        cout << "3. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            cout << "Consultando estudiantes...\n";
            break;
        case '2':
            cout << "Consultando cursos...\n";
            break;
        case '3':
            return;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '3');
}